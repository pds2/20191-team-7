#ifndef PDS2_PARTIDA_H
#define PDS2_PARTIDA_H

#include <Personagem.h>
#include <vector>
#include <iostream>
#include <string>

class Partida {
    private:
        std::vector <Personagem> _Grupo_a;
        std::vector <Personagem> _Grupo_b;
        bool _partida_terminou;
    public:
        Partida(Personagem,Personagem,Personagem,Personagem,Personagem,Personagem);
        
        //inicia a partida
        void inicia();
        
        void turno();

        //jogador decide o que vai querer fazer em seu turno
        void escolhe_acao(Personagem);
        

        //jogador vai fazer um ataque
        void atacando(Personagem);

        //jogador vai usar habilidade
        void usando_habilidade(Personagem);

        //limpa a tela e imprime o estado do jogo
        void refresh_tela();

        //submenu que vai ser ultilizado para receber a escolhas do jogador
        int submenu_partida(std::string, std::string, std::string);
};

#endif