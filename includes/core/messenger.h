#pragma once

#include <vector>
#include <string>

#include "core/net/client_socket.h"
#include "net/socket.h"


namespace core {
    /// SUMMARY:
    /// Used to send messages and block until response recieved.
    /// To non-blocking messaging see core/notifier.h and core/reciever.h
    class Messenger {
    public:
        Messenger(net::ClientSocket& socket) : socket_(socket) {}

        /// SUMMARY:
        /// Make an request to socket using internal protocol.
        /// Blocks thread.
        std::vector<std::string> Request(std::vector<std::string> message);

    private:
        net::ClientSocket& socket_;
    };
}
