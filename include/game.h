#include "character.h"

#ifndef PDS2_GAME_H
#define PDS2_GAME_H

class Game {
    private:
        int _gameStatus;
    public:
        Game();
        bool runGame();
        void gameBattle(Character *atk, Character *def);
};

#endif