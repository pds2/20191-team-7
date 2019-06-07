#ifndef PDS2_GUERREIRO_H
#define PDS2_GUERREIRO_H

#include "Personagem.h"
#include <iostream>

#define FATOR_CURA 0.25
#define PONTO_DE_EXECUCAO 0.25
#define CUSTO_HABILIDADE_3 15

class Guerreiro : public Personagem {
    private:
    public:
        //Construtor
        Guerreiro (std::string, int, int, int);
        ~Guerreiro();

        int ataque_basico(Personagem*) override;
        std::string get_habilidade(int) override;
        std::string usa_habilidade(int, int, std::vector<Personagem*>, std::vector<Personagem*>) override;
        std::string habilidade_1();
        std::string habilidade_2(int, std::vector<Personagem*>);
        std::string habilidade_3(int, std::vector<Personagem*>);

};

#endif