#include "core/net/server_socket.h"

#include <netdb.h>
#include <sys/socket.h>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include "core/net/client_socket.h"
#include "core/net/socket.h"
#include "core/panic.h"
#include "config.h"

void core::net::ServerSocket::Bind() {
    auto status = ::bind(
        socket_.socket_fd(),
        socket_.res()->ai_addr,
        socket_.res()->ai_addrlen);

    if (status == -1)
        Panic("Error during socket binding");

    #ifdef DEBUG_SERVER_SOCKET
        std::cout << "Socket succesfully bound" << std::endl 
            << "  port  " << socket_.port() << std::endl
            << "  fd    " << socket_.socket_fd() << std::endl;
    #endif
}


void core::net::ServerSocket::Listen(int queue_length) {
    auto status = ::listen(socket_.socket_fd(), queue_length);

    if (status != 0)
        Panic("Error during socket listening");

    #ifdef DEBUG_SERVER_SOCKET
        std::cout << "Socket is listening" << std::endl
            << "  port          " << socket_.port() << std::endl
            << "  queue length  " << queue_length << std::endl
            << "  fd            " << socket_.socket_fd() << std::endl; 
    #endif
}


core::net::ClientSocket core::net::ServerSocket::Accept() {
    #ifdef DEBUG_SERVER_SOCKET
        std::cout << "Socket is waiting to accept connection" << std::endl
            << "  port  " << socket_.port() << std::endl
            << "  fd    " << socket_.socket_fd() << std::endl;
    #endif
    
    sockaddr_size_ = sizeof sockaddr_storage_;
    auto new_fd = ::accept(socket_.socket_fd(), (sockaddr *) &sockaddr_storage_, &sockaddr_size_);

    if (new_fd == -1)
        Panic("Error during socket accepting");
    
    #ifdef DEBUG_SERVER_SOCKET
        std::cout << "Socket have got new connection" << std::endl
            << "  fd  " << new_fd << std::endl;
    #endif

    return ClientSocket(new_fd);
}


