#pragma once 

#include <iostream>

#include "core/game_state.h"
#include "core/net/client_socket.h"
#include "core/net/server_socket.h"


namespace server {
    struct Player {
        Player(core::net::ServerSocket& server_socket, int id) :
            client_socket(server_socket.Accept()),
            game_board(core::TileType::kSea),
            id(id) {}
        
        core::net::ClientSocket client_socket;
        core::GameBoard game_board;
        const int id;
    };
}