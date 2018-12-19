//
// Created by renana on 12/19/18.
//

#include <strings.h>
#include <cstring>
#include <unistd.h>
#include "EqualCommand.h"
#include "ShuntingYard.h"

void EqualCommand::doCommand() {
    data->updateSymbleTable(varTarget, value);

}

void EqualCommand::setParameters(vector<string> params, Data *data) {
    ShuntingYard shuntingYard;
    this->data = data;
    this->varTarget = params[0];
    this->value = shuntingYard.infixToPostfix(params[1])->Calculate();
}

void EqualCommand::sendMessage(string str) {
    int sockfd =  this->data->getClientId();
    int n;
    char buffer[256];
    /* Now ask for a message from the user, this message
       * will be read by server
    */
    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    /* Send message to the server */
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);
}