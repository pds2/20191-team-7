#include <iostream>
#include <cstdlib>
#include <ctime>

#include "character.h"
#include "game.h"

int main(void) {
    Game game = Game();
    Character warrior = Character(100, 10, 0, 30, 20, "Hercules");
    Character archer = Character(80, 30, 0,50, 10, "Legolas");

    while(game.runGame()) {
        // Toss the coin to see who starts.
        srand(time(0));
        int r = (rand() % 2) + 1;

        game.gameBattle(warrior.BaseAtk(1), archer.BaseDef(1));
    }

    return 0;
}