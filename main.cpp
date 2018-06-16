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
#include "DataSocket.h"




void printNumber(const std::string &str) {
    std::regex r{R"((\d))"};

    for(std::sregex_iterator pos(std::cbegin(str), std::cend(str), r); pos != std::sregex_iterator{}; ++pos)
    {
        std::cout<<pos->str(1)<<std::endl;
    }
}

int main() {

    ServerSocket socketWrapper{3425};
    auto sock = socketWrapper.accept();
    DataSocket dataSocket{sock};
    auto r = dataSocket.recv();
    std::cout<<r<<std::endl;
    dataSocket.send(r);



    return 0;
}