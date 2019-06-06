#ifndef PDS2_CLERIGO_H
#define PDS2_CLERIGO_H

#include "Personagem.h"
#include <iostream>

class Clerigo : public Personagem {
    private:
    public:
        //Construtor
        Clerigo(std::string, int, int, int);
        ~Clerigo();
        
        int ataque_basico(Personagem*) override;
        std::string get_habilidade(int) override;
        void usa_habilidade(int, std::vector<Personagem*>, std::vector<Personagem*>) override;
};

#endif

