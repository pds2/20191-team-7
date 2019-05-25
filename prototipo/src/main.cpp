#include <iostream>
#include <Personagem.h>
#include <Jogo.h>
#include <Partida.h>

int main() {
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

    std::cout << std::endl << a0.get_nome() << ", " << a1.get_nome() << ", " << a2.get_nome() << std::endl;
    std::cout << b0.get_nome() << ", " << b1.get_nome() << ", " << b2.get_nome() << std::endl << std::endl;

    //Inicia partida com os personagens escolhidos
    Partida partida = Partida(a0, a1, a2, b0, b1, b2);

    partida.inicia();

}