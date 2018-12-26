//
// Created by jennie on 12/17/18.
//

#include "OpenDataServerCommand.h"
#include "ShuntingYard.h"
#include "ServerSocket.h"
#include <pthread.h>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>


void OpenDataServerCommand::setParameters(vector<string> params, Data* data) {
    ShuntingYard shuntingYard(data);
    this->port = (int)shuntingYard.infixToPostfix(params[0])->Calculate();
    this->HZ = (int)shuntingYard.infixToPostfix(params[1])->Calculate();
    this->data = data;
}

void OpenDataServerCommand::doCommand() {

    vector<string> paths = data->getPathList();

    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    string temp;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

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
    data->setServerId(newsockfd);
    std::cout << "hii" << endl;

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    //creating thread and sending to read from the socket
    struct MyParams* params = new MyParams();
    params->data = this->data;
    pthread_t id;
    pthread_create(&id, nullptr, ServerSocket::openSocket, params);
}

OpenDataServerCommand::~OpenDataServerCommand() {
    close(this->data->getServerId());
}