//
// Created by renana on 12/18/18.
//

#include "Socket.h"
#include <iostream>
#include "Socket.h"
#include <pthread.h>

void* Socket::openFlightSocket(void* arg) {
    //int sockfd, newsockfd, portno, clilen;
    // char buffer[256];
  /*  struct sockaddr_in cli_addr;
    int n;*/

    /* First call to socket() function */
/*    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    this->id = sockfd;

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }*/

    /* Initialize socket structure */
/*    bzero((char *) &this->planeSocket, sizeof(this->planeSocket));
    portno = atoi(s.c_str());

    this->planeSocket.sin_family = AF_INET;
    this->planeSocket.sin_addr.s_addr = INADDR_ANY;
    this->planeSocket.sin_port = htons(portno);*/

    /* Now bind the host address using bind() call.*/
 /*   if (bind(sockfd, (struct sockaddr *) &this->planeSocket, sizeof(this->planeSocket)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }*/

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    //listen(sockfd,5);
    //DataReader();
    /*clilen = sizeof(cli_addr);

    // Accept actual connection from the client //
    newsockfd = accept(sockfd, (struct sockaddr )&cli_addr, (socklen_t)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

*/
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5400;

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

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    std::cout << "hii" << endl;

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    std::cout << "hii" << endl;
    bzero(buffer,256);
    n = read( newsockfd,buffer,255 );


}

void *Socket::getFlightSocket(void *arg) {

}

void Socket::DataReader() {
    /*std::cout<<"Waiting"<<endl;
    sockaddr_in client_sock;
    int client;
    int client_sock_fd = accept(id,(struct sockaddr*)&client_sock,(socklen_t*)&client);
    if(client_sock_fd < 0) {

    } else {
        std::cout << "hii" << endl;
    }*/
    //struct MyParams* params = new MyParams();
    //params->port = this->port;
    //params->hz = this->HZ;
    pthread_t id;
    pthread_create(&id, nullptr, openFlightSocket, nullptr);
}