
//
// Created by Konstantin Gredeskoul on 11/25/18.
//

#ifndef KIGAME__GAME_H
#define KIGAME__GAME_H

#include "Board.h"
#include "Player.h"

enum GameState {
    GameOn,
    GameOver
};

#include <vector>

class Game {
public:
    Game(Board &board, const std::vector<Player *> &players);

    GameState state;

    GameState getState() const;

    const Board &getBoard() const;

protected:
    Board board;
    std::vector<Player *> players;
};

#endif // KIGAME__GAME_H
