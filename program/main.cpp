#include <iostream>
#include <cstdlib>
#include <ctime>

#include "character.h"
#include "monster.h"
#include "game.h"

int main(void) {
    Game game = Game("Pantano");
    Character warrior = Character(100, 10, 30, 20, "Hercules");
    Monster monster = Monster(80, 30, 50, 10, "Monster", "Pantano", 1.2);

    // Toss the coin to see who starts.
    srand(time(0));

    while(game.RunGame()) {
        // Generate random number between 1 and 2
        int r = (rand() % 2) + 200;

        // Player 1 attacks
        if (r % 2 == 0) {
            game.GameBattle(&warrior, &monster);
        }
        // Player 2 attacks
        else {
            game.GameBattle(&monster, &warrior);
        }
        std::cout << std::endl;
    }

    return 0;
}