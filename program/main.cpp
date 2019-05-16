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
        // Generate random number between 1 and 2
        int r = (rand() % 2) + 1;

        // Player 1 attacks
        if (r == 1) {
            game.gameBattle(&warrior, &archer);
        }
        // Player 2 attacks
        else {
            game.gameBattle(&archer, &warrior);
        }
    }

    return 0;
}