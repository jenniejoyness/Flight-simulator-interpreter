//
// Created by renana on 12/18/18.
//

#ifndef MILLSTONE_SOCKET_H
#define MILLSTONE_SOCKET_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include <map>
#include <netinet/in.h>
#include "Socket.h"
#include "Data.h"


using namespace std;

class ServerSocket{

    struct sockaddr_in serverSocket;

public:
    ServerSocket();
    static void* openSocket(void* arg);

};


#endif //MILLSTONE_SOCKET_H
