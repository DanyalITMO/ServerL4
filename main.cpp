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

void printNumber(const std::string& str) {
    std::smatch match;
    if (std::regex_search(str, match, std::regex{"\\d"})) {
        for(std::size_t  i = 0; i < match.size(); i++)
        {
            std::cout<<match[i];
        }
    }

}

int main(int argc, char *argv[]) {
    const int  buff_size = 1025;
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char sendBuff[buff_size];
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    listen(listenfd, 10);

    struct sockaddr_in client;
    int client_fd, server_fd;
    while (1) {
        socklen_t client_len = sizeof(client);
        client_fd = accept(server_fd, (struct sockaddr *) &client, &client_len);

        if (client_fd < 0) std::cerr << "Could not establish new connection\n";

        while (1) {
            int read = recv(client_fd, sendBuff, buff_size, 0);

            if (!read) break; // done reading
            if (read < 0) std::cerr<<"Client read failed\n";

            int err = send(client_fd, sendBuff, read, 0);
            if (err < 0) std::cerr << "Client write failed\n";
        }
    }
    /*
    while (1) {
        connfd = accept(listenfd, (struct sockaddr *) NULL, NULL);

        ticks = time(NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
        write(connfd, sendBuff, strlen(sendBuff));

        close(connfd);
        sleep(1);
    }*/
}