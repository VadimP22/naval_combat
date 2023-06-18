#pragma once

#include <netdb.h>
#include <sys/socket.h>

#include "core/net/socket.h"
#include "core/net/client_socket.h"


namespace core::net {
    /// SUMMARY:
    /// Socket for listening incoming connection on some port.
    /// USAGE:
    /// First call Bind(), then call Listen(int).
    /// After that you can call Accept()
    /// WARN: Accept() call is blocking
    class ServerSocket {        
    public:
        ServerSocket(const char * port) : socket_("127.0.0.1", port) {}
        
        void Bind();
        void Listen(int queue_length);

        /// WARN: Accept() call is blocking
        ClientSocket Accept();

    protected:
        core::net::Socket socket_;
        sockaddr_storage sockaddr_storage_;
        socklen_t sockaddr_size_;
    };
}
