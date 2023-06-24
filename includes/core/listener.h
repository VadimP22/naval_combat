#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "core/net/client_socket.h"
#include "core/notifier.h"
#include "core/utils.h"
#include "config.h"


namespace core {
    template<typename Handler> class Listener {
    public:
        Listener(
                Handler& handler,
                std::vector<net::ClientSocket*> sockets) :
            handler_(handler),
            sockets_(sockets) {}

        /// SUMMARY:
        /// Process all sockets (call handler for each)
        /// TODO:
        /// Add Messenger to handler function signature.
        void Process() {
            int id = 0;
            for (auto sock : sockets_) {
                Notifier notifier{*sock};
                std::string buff{};

                bool recieved = sock->Recv(buff);

                if (recieved) {
                    std::cout << "id: " << id << std::endl
                        << "recieved: " << buff << std::endl;

                    auto deserialized = core::SplitByChar(buff, '/');
                
                    handler_.Handle(id, deserialized, notifier);
                }

                id += 1;
            }
        }

    private:
        std::vector<net::ClientSocket*> sockets_;
        Handler& handler_;
    };
}
