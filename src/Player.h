//
// Created by Konstantin Gredeskoul on 11/25/18.
//

#ifndef BINARY_TREE_PLAYER_HPP
#define BINARY_TREE_PLAYER_HPP

#include "Move.h"
#include "Board.h"

class Player {
public:
    Player() = default;
    Move& chooseMove(const Board &board);
private:
    Move move;
};


#endif //BINARY_TREE_PLAYER_HPP
