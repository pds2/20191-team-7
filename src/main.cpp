#include <iostream>
#include "Personagem.h"
#include "Jogo.h"
#include "Partida.h"

int main() {
    /* Esta parte de carregar do arquivo estava dando pau no linux, vou concertar
    //inicia o jogo
    Jogo jogo = Jogo();
    jogo.carrega_arquivos();

    //imprime o conteudo que foi carregado
    jogo.imprime_vetores();

    //Escolhe quem vai participar da partida
    Personagem a0 = jogo.escolhe_heroi(0);
    Personagem a1 = jogo.escolhe_heroi(1);
    Personagem a2 = jogo.escolhe_heroi(2);
    Personagem b0 = jogo.escolhe_monstro(0);
    Personagem b1 = jogo.escolhe_monstro(1);
    Personagem b2 = jogo.escolhe_monstro(2);
    */
    Personagem a0 = Personagem("Guerreiro",1,10,10,true); //a partir de agora o construtor tera o status booleano true para inicar o personagem como vivo.
    Personagem a1 = Personagem("Clerigo",14,8,8,true);
    Personagem a2 = Personagem("Mago",8,8,14,true);
    Personagem b0 = Personagem("Goblin",2,2,2,true);
    Personagem b1 = Personagem("Orc",8,8,8,true);
    Personagem b2 = Personagem("Troll",20,20,500,true);


    //Inicia partida com os personagens escolhidos
    Partida partida = Partida(a0, a1, a2, b0, b1, b2);

    partida.inicia();
    return 0;
}

