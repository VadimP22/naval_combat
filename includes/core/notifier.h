#pragma once

#include <vector>
#include <string>

#include "core/net/client_socket.h"
#include "config.h"
#include "core/utils.h"


namespace core {
    class Notifier {
    public:
        Notifier(net::ClientSocket& socket) : socket_(socket) {}

        /// SUMMARY:
        /// Send message. Non-blocking
        void Notify(std::vector<std::string>& msg) {
            auto serialized = core::Serialize(msg);
            socket_.Send(serialized);
        }

    private:
        net::ClientSocket& socket_;
    };
}
