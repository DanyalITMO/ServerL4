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

    while (true)
    {
        auto sock = socketWrapper.accept();
        DataSocket dataSocket{sock};

        auto r = dataSocket.recv();
        try {
            Statistic stats;
            auto numbers = filterNumber(r);
            if (numbers.empty()) {
                dataSocket.send("Can't find number in the incoming message");
                continue;
            }
            stats.add(numbers);
            std::string res;
            res += "Max: " + std::to_string(stats.getMax()) + "\n"
                   + " Min: " + std::to_string(stats.getMin()) + "\n"
                   + " Sum: " + std::to_string(stats.getSum()) + "\n";

            res += "Sort: \n";
            for (auto &&it : stats.getSort()) {
                res += std::to_string(it) + ",";
            }
            res.pop_back();
            dataSocket.send(res);
        }
        catch (const std::exception &ex) {
            dataSocket.send("Error");
            std::cerr << ex.what();
        }
    }

    return 0;
}