#ifndef PDS2_FEITICEIRO_H
#define PDS2_FEITICEIRO_H

#include "Personagem.h"
#include <iostream>

class Feiticeiro : public Personagem {
    private:
    public:
        //Construtor
        Feiticeiro (std::string, int, int, int);
        ~Feiticeiro();

        int ataque_basico(Personagem*) override;
        std::string get_habilidade(int) override;
        std::string usa_habilidade(int, int, std::vector<Personagem*>, std::vector<Personagem*>) override;
};

#endif