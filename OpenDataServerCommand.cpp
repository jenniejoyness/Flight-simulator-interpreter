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
    ShuntingYard shuntingYard;
    this->port = (int)shuntingYard.infixToPostfix(params[0])->Calculate();
    this->HZ = (int)shuntingYard.infixToPostfix(params[1])->Calculate();
    this->data = data;
}

void OpenDataServerCommand::doCommand() {
    struct MyParams* params = new MyParams();
    params->port = this->port;
    params->hz = this->HZ;
    params->data = this->data;
    pthread_t id;
    pthread_create(&id, nullptr, ServerSocket::openSocket, params);
}
