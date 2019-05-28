#include <iostream>
#include <Personagem.h>
#include <Jogo.h>
#include <Partida.h>

int main() {
    /* Tirei a parte de carregar arquivos por enquanto, vai ter que ser refeita já que deu problema no Linux
    */
    Personagem a0 = Personagem("Jon Snow",10,10,10);
    Personagem a1 = Personagem("Jorah Mormont",14,8,8);
    Personagem a2 = Personagem("Daenerys",8,8,14);
    Personagem b0 = Personagem("Rato",2,2,2);
    Personagem b1 = Personagem("Orc",8,8,8);
    Personagem b2 = Personagem("Cthulhu",20,20,500);


    //Inicia partida com os personagens escolhidos
    Partida partida = Partida(a0, a1, a2, b0, b1, b2);

    partida.inicia();
    return 0;
}
 
