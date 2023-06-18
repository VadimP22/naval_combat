#include <string>
#include <iostream>
#include <vector>

#include "core/net/server_socket.h"
#include "core/notifier.h"


int main() {
    core::net::ServerSocket server_socket{"8089"};
    server_socket.Bind();
    server_socket.Listen(1);
    auto client = server_socket.Accept();
    core::Notifier notifier{client};

    while (true) {
        std::string buff{};
        bool recieved = false;
        do {
             recieved = client.Recv(buff);
        } while (!recieved);
        std::cout << "recieved: " << buff << std::endl;

        std::vector<std::string> response{};
        response.push_back("this");
        response.push_back("is");
        response.push_back("response");

        notifier.Notify(response);
    }

    return 0;
}
