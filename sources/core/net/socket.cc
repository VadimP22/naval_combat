#include "core/net/socket.h"

#include <cstring>
#include <netdb.h>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>

#include "core/panic.h"
#include "config.h"


core::net::Socket::Socket(const char* ip_addr, const char* port) {
    port_ = port;
    ip_addr_ = ip_addr;

    memset(&hints_, 0, sizeof hints_);
    hints_.ai_family = AF_UNSPEC;
    hints_.ai_socktype = SOCK_STREAM;

    auto status = getaddrinfo(ip_addr, port, &hints_, &res_);
    if (status != 0)
        Panic("failed getaddrinfo at core::net::Socket constructor");

    socket_fd_ = socket(res_->ai_family, res_->ai_socktype, res_->ai_protocol);
    if (socket_fd_ == 0)
        Panic("failed socket at core::net::Socket constructor");

    #ifdef DEBUG_SOCKET
        std::cout << "Socket successfully created:" << std::endl;
        std::cout << "  ip    " << ip_addr << std::endl;
        std::cout << "  port  " << port << std::endl;
        std::cout << "  fd    " << socket_fd_ << std::endl;
    #endif
}


core::net::Socket::Socket(int socket_fd) {
    created_by_server_socket_ = true;
    socket_fd_ = socket_fd;
}


core::net::Socket::~Socket() {
    if (!created_by_server_socket_)
        ::freeaddrinfo(res_);

    if (is_valid_) {
        ::close(socket_fd_);

        #ifdef DEBUG_SOCKET
            std::cout << "Socket closed" << std::endl
                << "  fd  " << socket_fd_ << std::endl;
        #endif
    }
}


void core::net::Socket::Devalidate() {
    is_valid_ = false;
}
