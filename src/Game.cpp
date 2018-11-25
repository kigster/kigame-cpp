//
// Created by Konstantin Gredeskoul on 11/25/18.
//

#include "Game.h"

Game::Game(Board &board, const std::vector<Player *> &players) :
        board(board), players(players) {
    this->state = GameState::GameOn;
}

GameState Game::getState() const {
    return state;
}

const Board &Game::getBoard() const {
    return board;
}



