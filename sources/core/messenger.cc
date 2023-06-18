#include "core/messenger.h"

#include <vector>
#include <string>
#include <iostream>

#include "core/utils.h"
#include "config.h"


std::vector<std::string> core::Messenger::Request(
        std::vector<std::string> msg) {

    auto serialized = core::Serialize(msg);
    std::string response{""};

    #ifdef DEBUG_MESSENGER
        std::cout << "serialized: " << serialized << std::endl;
    #endif

    socket_.Send(serialized);
    
    bool recieved = false;
    do {
        recieved = socket_.Recv(response);
    } while (!recieved);

    #ifdef DEBUG_MESSENGER
        std::cout << "recieved: " << response << std::endl;
    #endif

    auto parsed = core::SplitByChar(response, SEPARATOR);

    #ifdef DEBUG_MESSENGER
        for (auto& str : parsed)
            std::cout << "arg: " << str << std::endl;
    #endif

    return parsed;
}
