//
// Created by danyal on 16.06.18.
//

#ifndef SERVER_SOCKETWRAPPER_H
#define SERVER_SOCKETWRAPPER_H


#include "string_view"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


class SocketWrapper {
public:
    explicit SocketWrapper(int port);
};


#endif //SERVER_SOCKETWRAPPER_H
