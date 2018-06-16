//
// Created by danyal on 16.06.18.
//

#ifndef SERVER_DATASOCKET_H
#define SERVER_DATASOCKET_H

#include <string>

class DataSocket {
public:
    explicit DataSocket(int);
    std::string recv();
    void send(std::string);

    ~DataSocket();
private:
    const int _buf_size{1024};
    int _sock;
};


#endif //SERVER_DATASOCKET_H
