#include "game.h"
#include <iostream>

Game::Game() {
    _gameStatus = 1;
}

bool Game::runGame() {
    if (_gameStatus == 1) {
        return true;
    } else {
        return false;
    }
}

void Game::gameBattle(int atk, int def) {
    std::cout << "Batalha: " << atk << " contra " << def << std::endl;
    _gameStatus = 0; 
}