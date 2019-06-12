#include <iostream>
#include "Personagem.h"

#include "Guerreiro.h"
#include "Feiticeiro.h"
#include "Druida.h"


#include "Jogo.h"
#include "Partida.h"

int main() {
    Guerreiro a0 = Guerreiro("Crassus",16,8,7);
    Druida a1 = Druida("Disjktra",11,12,13);
    Feiticeiro a2 = Feiticeiro("Bloodraven",8,11,16);
    Guerreiro a3 = Guerreiro("Jarred",15,9,8);

    Monstro b0 = Monstro("Goblin", 10, 14, 5);        // um inimigo fraco para morrer rápido
    Monstro b1 = Monstro("Orc", 14, 12, 6);    // um inimigo igual ao hérois
    Monstro b2 = Monstro("Troll", 18, 11, 4);   // um inimigo forte
    Monstro b3 = Monstro("Dragao", 22, 6, 15);

    //Inicia partida com os personagens escolhidos
    std::vector <Personagem*> grupo_a = { &a0, &a1, &a2, &a3};
    std::vector <Personagem*> grupo_b = { &b0, &b1, &b2, &b3};

    // grupo_a[3]->ataque_basico(grupo_b[2]);

    Partida partida = Partida(grupo_a, grupo_b, 2);

    partida.inicia();
    return 0;
}

