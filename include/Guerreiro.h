#ifndef PDS2_GUERREIRO_H
#define PDS2_GUERREIRO_H

#include "Personagem.h"
#include <iostream>

class Guerreiro : public Personagem {
    private:
    public:
        //Construtor
        Guerreiro (std::string, int, int, int);

        int ataque_basico(Personagem*) override;
        std::string get_habilidade(int) override;
        void usa_habilidade(int, std::vector<Personagem*>, std::vector<Personagem*>) override;
};

#endif