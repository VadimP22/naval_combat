#pragma once

#include <vector>

#include "core/panic.h"


namespace core {
    using Turn = int;


    enum TileType {
        kSea,
        kShip,
        kDestroyedShip,
    };


    class Tile {
    public:
        Tile(TileType type) : type_(type), destruction_time_(0) {}
        
        void Destroy();

        inline TileType type() const { return type_; }
        inline void set_type(TileType type) { type_ = type; }
        inline Turn destruction_time() const { return destruction_time_; }

    private:
        TileType type_;
        Turn destruction_time_;
    };


    class GameBoard {
    public:
        GameBoard(TileType fill_type) : board_(100, Tile(TileType::kSea)) {}

        inline const Tile& inspect_tile(unsigned col, unsigned row) const { return board_.at(TilePosition(col, row)); }
        inline Tile& tile(unsigned col, unsigned row) { return board_.at(TilePosition(col, row)); }

    private:
        static inline int TilePosition(unsigned col, unsigned row) { 
            int index = (row * 10) + col;
            if (index > 100)
                Panic("Index out of range");
            return index;
        }
        
        std::vector<Tile> board_;
    };
}
