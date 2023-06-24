#include <string>
#include <iostream>
#include <vector>

#include "core/net/client_socket.h"
#include "core/net/server_socket.h"
#include "core/notifier.h"
#include "core/listener.h"

#include "server/player.h"
#include "server/handler.h"


// class Handler {
// public:
//     void Handle(int id, std::vector<std::string>& msg, core::Notifier& notifier) {
//         std::vector<std::string> response{};
//         response.push_back("fuckubro");
//         response.push_back(msg[0]);
//         notifier.Notify(response);
//     }
// };


int main() {
    core::net::ServerSocket server_socket{"8089"};
    server_socket.Bind();
    server_socket.Listen(2);

    // Wait for players
    std::cout << "Waiting for players..." << std::endl;
    server::Player player0{server_socket, 0};
    server::Player player1{server_socket, 1};
    std::cout << "Players connected!" << std::endl;
    
    // Id in handler fucntion is index in this vector
    std::vector<core::net::ClientSocket*> sockets{}; 
    sockets.push_back(&player0.client_socket);
    sockets.push_back(&player1.client_socket);

    server::Handler handler{};
    core::Listener<server::Handler> listener{handler, sockets};

    while (true) {
        listener.Process();
    }

    return 0;
}
