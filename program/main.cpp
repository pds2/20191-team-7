#include <iostream>
#include "Personagem.h"

#include "Guerreiro.h"
#include "Feiticeiro.h"
#include "Druida.h"


#include "Jogo.h"
#include "Partida.h"

int main() {
    Guerreiro a0 = Guerreiro("Jon Snow",10,10,10);
    Druida a1 = Druida("Jojen",10,10,10);
    Feiticeiro a2 = Feiticeiro("Bloodraven",10,10,10);
    Guerreiro a3 = Guerreiro("Bronn",10,10,20);
    
    Monstro b0 = Monstro("Ratox", 2, 2, 2);        // um inimigo fraco para morrer rápido
    Monstro b1 = Monstro("Ramsey", 10, 10, 10);    // um inimigo igual ao hérois
    Monstro b2 = Monstro("Cthulhu", 25, 25, 25);   // um inimigo forte
    

    //Inicia partida com os personagens escolhidos
    std::vector <Personagem*> grupo_a = { &a0, &a1, &a2, &a3};
    std::vector <Personagem*> grupo_b = { &b0, &b1, &b2 };

    // grupo_a[3]->ataque_basico(grupo_b[2]);

    Partida partida = Partida(grupo_a, grupo_b, 2);

    partida.inicia();
    return 0;
}
 
