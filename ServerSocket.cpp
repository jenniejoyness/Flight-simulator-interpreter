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


    string buff;
    string leftOvers;

    /* If connection is established then start communicating */
    while (true) {
        bzero(buffer, 256);
        n = read(data->getServerId(), buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        // split each line it get from the file to list of separate strings
        vector<string> info;
        size_t pos = 0;
        string delimiter = ",";
        string delimiter2 = "\n";
        buff += buffer;
        pos = buff.find(delimiter2);
        leftOvers += buff.substr((0, pos));

        // to remove the \n from the beginning of the string
        leftOvers = leftOvers.substr(1);
        buff.erase(pos + delimiter2.length() - 1);
        pos = 0;
        while ((pos = buff.find(delimiter)) != string::npos) {
            info.push_back(buff.substr(0, pos));
            buff.erase(0, pos + delimiter.length());
        }
        info.push_back(buff.substr(0, pos));
        buff = "";
        for (int i = 0; i < paths.size(); ++i) {
            data->updateValuePathMap(paths[i], stod(info[i]));
        }
        buff += leftOvers;
        leftOvers = "";
    }
}

