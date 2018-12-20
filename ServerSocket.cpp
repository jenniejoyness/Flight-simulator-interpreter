//
// Created by renana on 12/18/18.
//

#include "ServerSocket.h"
#include <iostream>
#include "ServerSocket.h"
#include <pthread.h>
#include <vector>

struct MyParams {
    int port;
    int hz;
    Data *data;
};

/*
 * opens the server socket and waits for the flight simulators connection.
 * reads the updates that the simulator sends to this socket
 * we will update the info given to the symbolmap in data
 * TODO ADD VARS TO VECTOR
 */
void *ServerSocket::openSocket(void *arg) {
    vector<string> vars;
    struct MyParams *params = (struct MyParams *) arg;
    Data *data = params->data;

    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = params->port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    std::cout << "hii" << endl;

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    //If connection is established then start communicating */
    bzero(buffer, 1024);

    //sleep for this->Hz
    while (true) {
        n = read(newsockfd, buffer, 1024);
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

        //update the map with new values read from the simulator
        for (int i = 0; i < line.size(); ++i) {
            data->updateSymbleTable(vars[i], stod(line[i]));
        }
    }
}


