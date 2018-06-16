//
// Created by danyal on 16.06.18.
//

#ifndef SERVER_SOCKETWRAPPER_H
#define SERVER_SOCKETWRAPPER_H


#include "string_view"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


class ServerSocket {
public:
    explicit ServerSocket(int port);
    ~ServerSocket();
    int accept();

private:
    std::size_t _buf_size{1024};
    int _listener;
};


#endif //SERVER_SOCKETWRAPPER_H
