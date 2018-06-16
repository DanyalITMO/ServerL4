#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include "ServerSocket.h"
#include "DataSocket.h"
#include "Helper.h"
#include "Statistic.h"

int main() {

    ServerSocket socketWrapper{3425};
    auto sock = socketWrapper.accept();
    DataSocket dataSocket{sock};
    auto r = dataSocket.recv();
//TODO if r empty
    Statistic stats;
    auto numbers = filterNumber(r);
    stats.add(numbers);
    std::string res;
    res += "Max: " + std::to_string(stats.getMax()) + "\n"
            + " Min: " + std::to_string(stats.getMin()) + "\n"
           + " Sum: " + std::to_string(stats.getSum()) + "\n";

    res += "Sort: \n";
    for(auto&& it : stats.getSort())
    {
        res += std::to_string(it) + ",";
    }
    res.pop_back();

//    for(auto&& it : numbers)
//        std::cout<<"ret it: " << it<<std::endl;
//    std::cout<<r<<std::endl;
    dataSocket.send(res);



    return 0;
}