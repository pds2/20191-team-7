#include <iostream>
#include <Personagem.h>
#include "Guerreiro.h"
#include <Jogo.h>
#include <Partida.h>

int main() {
    /* Tirei a parte de carregar arquivos por enquanto, vai ter que ser refeita já que deu problema no Linux
    */
    Guerreiro a0 = Guerreiro("Jon Snow",100,10,10);
    Personagem a1 = Personagem("Jorah Mormont",140,8,8);
    Personagem a2 = Personagem("Daenerys",8,8,14);
    Personagem a3 = Personagem("Tyrion",10,10,20);
    Personagem b0 = Personagem("Rato",2,2,2);
    Personagem b1 = Personagem("Orc",8,8,8);
    Personagem b2 = Personagem("Cthulhu",20,20,500);


    //Inicia partida com os personagens escolhidos
    std::vector <Personagem> grupo_a = {a0, a1, a2, a3};
    std::vector <Personagem> grupo_b = {b0, b1, b2};
    Partida partida = Partida(grupo_a, grupo_b, 2);

    partida.inicia();
    return 0;
}
 
