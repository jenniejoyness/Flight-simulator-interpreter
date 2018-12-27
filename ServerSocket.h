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
#include "Socket.h"
#include "Data.h"


using namespace std;

class ServerSocket {
public:
    static void *openSocket(void *arg);
};


#endif //MILLSTONE_SOCKET_H
