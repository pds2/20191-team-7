#include "game.h"
#include "character.h"
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

void Game::gameBattle(Character *atk, Character *def) {
    std::cout << atk->GetName() << " ataca " << def->GetName() << std::endl;
    
    // Verifica se atacante é mais forte que o defensor
    if (atk->BaseAtk(1) > def->BaseDef(1)) {
        int hpLoss = atk->BaseAtk(1) - def->BaseDef(1);
        def->SetHP(def->GetHP() - hpLoss);

        std::cout << def->GetName() << " perde " << hpLoss << " pontos de vida!" << std::endl;
        std::cout << def->GetName() << " agora possui " << def->GetHP() << " pontos de vida." << std::endl; 
    } else {
        std::cout << def->GetName() << " não sofreu dano!" << std::endl;
        std::cout << def->GetName() << " tem " << def->GetHP() << " pontos de vida." << std::endl;
    }

    if (!def->CharacterAlive()) {
        _gameStatus = 0; 
        std::cout << def->GetName() << " está morto!" << std::endl;
        std::cout << atk->GetName() << " venceu a batalha!" << std::endl;
    }
}