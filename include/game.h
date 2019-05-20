#include "character.h"
#include "monster.h"

#ifndef PDS2_GAME_H
#define PDS2_GAME_H

class Game {
    private:
        int _GameStatus;
        std::string _Local;
    public:
        Game(std::string Local);
        bool RunGame();
        void GameBattle(Character *atk, Monster *def);
        void GameBattle(Monster *atk, Character *def);
};

#endif