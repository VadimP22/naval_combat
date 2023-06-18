#pragma once

#include <netdb.h>
#include <sys/socket.h>
#include <string>

#include "socket.h"
#include "core/panic.h"


namespace core::net {
    class ClientSocket {
        public:

        /// SUMMARY:
        /// Creates socket from existing fd.
        /// WARN:
        ///Very unsafe. You should use another constructor if possible.
        ClientSocket(int from_socket_fd) : socket_(from_socket_fd) {}
        ClientSocket(const char * ip_addr, const char * port) : 
            socket_(ip_addr, port) {}

        bool Connect();
        void Send(std::string& data);
        bool Recv(std::string& buffer);

        template <typename T> int Recv(T * buffer) {
            auto len_bytes = ::recv(socket_.socket_fd(), buffer, sizeof(T), 0);

            if (len_bytes == -1)
                Panic("Error during recieving");

            return len_bytes;
        }

        template <typename T> void Send(T * data) {
            auto status = ::send(socket_.socket_fd(), data, sizeof(T), 0);

            if (status == -1)
                Panic("Error during sending data");
        }
    protected:
        core::net::Socket socket_;
    };
}
