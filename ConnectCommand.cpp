#include "ConnectCommand.h"
#include "ShuntingYard.h"
#include "ClientSocket.h"

void ConnectCommand::setParameters(vector<string> params, Data *data) {
    ShuntingYard shuntingYard(data);
    this->ipAddress = params[0];
    this->port = (int) shuntingYard.infixToPostfix(params[1])->Calculate();
    this->data = data;
}

void ConnectCommand::doCommand() {
    struct MyParams *params = new MyParams();
    params->port = this->port;
    params->ipAddress = this->ipAddress;
    params->data = this->data;
    //pthread_t id;
    //pthread_create(&id, nullptr, ClientSocket::openSocket, params);
    ClientSocket::openSocket(params);
    //delete params;
}

