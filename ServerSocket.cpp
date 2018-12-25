//
// Created by renana on 12/18/18.
//

#include "ServerSocket.h"
#include <iostream>
#include "ServerSocket.h"
#include <pthread.h>
#include <vector>
#include <list>

struct MyParams {
    Data *data;
};

/*
 * opens the server socket and waits for the flight simulators connection.
 * reads the updates that the simulator sends to this socket
 * we will update the info given to the symbolmap in data
 * TODO ADD VARS TO VECTOR
 * TODO - DO WE NEED A LOCK??
 */
void *ServerSocket::openSocket(void *arg) {
    struct MyParams *params = (struct MyParams *) arg;
    Data *data = params->data;
    vector<string> paths = data->getPathList();

    char buffer[256];
    int n;

    vector<string> insertToMap;
    vector<string> temp;
    while (true) {
        //If connection is established then start communicating
        bzero(buffer, 256);
        n = read(data->getServerId(), buffer, 256);
        string b = buffer;
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        vector<string> line;
        size_t pos = 0;
        string delimiter = ",";
        //splitting by ","
        while ((pos = b.find(delimiter)) != string::npos) {
            line.push_back(b.substr(0, pos));
            b.erase(0, pos + delimiter.length());
        }
        line.push_back(b.substr(0, pos));

        for (int j = 0; j < line.size(); ++j) {
            int x = line[j].find("\n");
            if (x != -1) {
                insertToMap.push_back(line[j].substr(0, x - 1));
                if (x != line[j].size()) {
                    line[j] = line[j].substr(x + 1, line.size());
                }
            }
            if (insertToMap.size() < 23) {
                insertToMap.push_back(line[j]);
            } else {
                temp.push_back(line[j]);
            }
        }

        //update the map with new values read from the simulator
        for (int i = 0; i < paths.size(); ++i) {
            data->updateValuePathMap(paths[i], stod(insertToMap[i]));
        }
        insertToMap.clear();
        for (auto &t: temp) {
            insertToMap.push_back(t);
        }
        temp.clear();
    }
}