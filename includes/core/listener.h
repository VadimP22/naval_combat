#pragma once

#include <string>

#include "core/net/client_socket.h"
#include "core/notifier.h"


namespace core {
    template<int socket_count_, typename Handler> class Listener {
    public:
        Listener(
            Handler& handler,
            net::ClientSocket* sockets[socket_count_]) :
        handler_(handler), sockets_(sockets) {}

        /// SUMMARY:
        /// Process all sockets (call handler for each)
        void Process() {
            int id = 0;
            for (auto& sock : sockets_) {
                Notifier notifier{sock};
                std::string buff{};

                bool recieved = sock.Recv(buff);

                if (recieved)
                    handler_.Handle(id, notifier);

                id += 1;
            }
        }

    private:
        net::ClientSocket* sockets_[socket_count_];
        Handler& handler_;
    };
}
