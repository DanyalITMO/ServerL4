//
// Created by danyal on 16.06.18.
//
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <regex>
#include <iostream>
#include "ServerSocket.h"

#include <cstdio>
#include <cstdlib>
#include "ServerSocket.h"

ServerSocket::ServerSocket(int port) {
    struct sockaddr_in addr;

    _listener = socket(AF_INET, SOCK_STREAM, 0);
    if (_listener < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(_listener, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(2);
    }

    listen(_listener, 1);
}

void printNumber(const std::string &str) {
    std::regex r{R"((\d))"};

    for(std::sregex_iterator pos(std::cbegin(str), std::cend(str), r); pos != std::sregex_iterator{}; ++pos)
    {
        std::cout<<pos->str(1)<<std::endl;
    }
}

void ServerSocket::accept() {
    int sock;
//    std::size_t bytes_read;
    char buf[_buf_size];

    sock = ::accept(_listener, nullptr, nullptr);
    if (sock < 0) {
        perror("accept");
        exit(3);
    }

    auto bytes_read = recv(sock, buf, _buf_size, 0);// ret ssize t
    std::string t(buf);
    printNumber(t);

    if(bytes_read <= 0) return;
    send(sock, buf, bytes_read, 0);
//        }

    close(sock);
}


