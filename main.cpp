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



int main() {

    ServerSocket socketWrapper{3425};
    socketWrapper.accept();

    return 0;
}