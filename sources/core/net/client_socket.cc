#include "core/net/client_socket.h"

#include <unistd.h>
#include <sys/socket.h>
#include <iostream>
#include <cstring>

#include "core/panic.h"

#define SOCK_R_BUFF_SIZE 100


bool core::net::ClientSocket::Connect() {
    auto status = ::connect(
        socket_.socket_fd(),
        socket_.res()->ai_addr,
        socket_.res()->ai_addrlen);

    if (status == -1)
        return false;

    return true;
}


void core::net::ClientSocket::Send(std::string& data) {
    auto status = ::send(socket_.socket_fd(), data.c_str(), data.size(), 0);
    if (status == -1)
        Panic("Error during sending std::string");
}


bool core::net::ClientSocket::Recv(std::string& buffer) {
    char temp_buff[SOCK_R_BUFF_SIZE];
    auto len_bytes = ::recv(socket_.socket_fd(), temp_buff, sizeof temp_buff, 0);

    if (len_bytes == -1)
        Panic("Error during recieving to std::string");

    if (len_bytes == 0)
        return false;

    buffer.append(temp_buff, len_bytes);
    
    return true;
}



