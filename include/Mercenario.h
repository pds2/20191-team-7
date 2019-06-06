#ifndef PDS2_MERCENARIO_H
#define PDS2_MERCENARIO_H

#include "Personagem.h"
#include <iostream>

class Mercenario : public Personagem {
    private:
    public:
        //Construtor
        Mercenario (std::string, int, int, int);
        ~Mercenario();

        int ataque_basico(Personagem*) override;
        std::string get_habilidade(int) override;
        void usa_habilidade(int, std::vector<Personagem*>, std::vector<Personagem*>) override;
};

#endif