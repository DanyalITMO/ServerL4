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
#include "SocketWrapper.h"

void printNumber(const std::string &str) {
    std::regex r{R"((\d))"};

    for(std::sregex_iterator pos(std::cbegin(str), std::cend(str), r); pos != std::sregex_iterator{}; ++pos)
    {
        std::cout<<pos->str(1)<<std::endl;
    }
}

int main() {

    SocketWrapper socketWrapper{};
    int sock;
    while (1) {
        sock = accept(listener, NULL, NULL);
        if (sock < 0) {
            perror("accept");
            exit(3);
        }

//        while(1)
//        {
        bytes_read = recv(sock, buf, 1024, 0);
        std::string t(buf);
        printNumber(t);
//            if(bytes_read <= 0) break;
        send(sock, buf, bytes_read, 0);
//        }

        close(sock);
    }

    return 0;
}