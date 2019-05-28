#ifndef PDS2_PARTIDA_H
#define PDS2_PARTIDA_H

#include <Personagem.h>
#include <vector>
#include <iostream>
#include <string>

class Partida {
    private:
        std::vector <Personagem> _grupo_blue;
        std::vector <Personagem> _grupo_red;
        bool _partida_terminou;
        char _grupo_que_estajogando;
    public:
        Partida(std::vector <Personagem>,std::vector <Personagem>);
        
        //inicia a partida
        void inicia();

        //confere se a partida terminou
        bool terminou();

        //cria um vetor de apontadores na ordem certa
        std::vector <Personagem*> determina_ordem();

        //controla de quem é a vez
        void turno(std::vector <Personagem*>);

        //durante a vez do personagem o jogador decide o que vai fazer
        void vez_do_personagem(Personagem, char);

        //jogador vai fazer um ataque
        void atacando(Personagem, char);

        //jogador vai usar habilidade
        void usando_habilidade(Personagem);

        //limpa a tela e imprime o estado do jogo
        void refresh_tela();

        //submenu que vai ser ultilizado para receber a escolhas do jogador
        //ele recebe um vetor contendo o texto de cada opção e retorna o numero que foi escolhido.
        int submenu_partida(std::vector <std::string>);

        //muda cor do texto para a cor correspondente ao grupo de quem esta jogando
        void cor_jogador_atual();
        
};

#endif