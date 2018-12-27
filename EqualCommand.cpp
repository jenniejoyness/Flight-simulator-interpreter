#include <strings.h>
#include <cstring>
#include <unistd.h>
#include "EqualCommand.h"
#include "ShuntingYard.h"

/*
 * change the values in the symboltable
 * calls sendmessage to write to the simulator
 */
void EqualCommand::doCommand() {
    //updating the value in symbolmap
    data->updateSymbleTable(varTarget, value);
    //getting the path of the var
    string path = data->getPath(varTarget);
    path = path.substr(1, path.size() - 2);
    string message = "set " + path + " " + to_string(value) + "\r\n";
    //sending message to simulator
    sendMessage(message);
}


void EqualCommand::setParameters(vector<string> params, Data *data) {
    ShuntingYard shuntingYard(data);
    this->data = data;
    this->varTarget = params[0];
    this->value = shuntingYard.infixToPostfix(params[1])->Calculate();
}

/*
 * sends a message to the simulator, updating the simulator on the changes made by the client
 */
void EqualCommand::sendMessage(string str) {
    int sockfd = this->data->getClientId();
    int n;
    char *s = const_cast<char *>(str.c_str());
    /* Send message to the server */
    n = write(sockfd, s, strlen(s));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}