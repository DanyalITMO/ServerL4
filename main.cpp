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

void printNumber(const std::string &str) {
    std::regex r{R"((\d))"};

    for(std::sregex_iterator pos(std::cbegin(str), std::cend(str), r); pos != std::sregex_iterator{}; ++pos)
    {
        std::cout<<pos->str(1)<<std::endl;
    }
}

int main() {
    int sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listener, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);

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