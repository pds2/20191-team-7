#ifndef PDS2_LADRAO_H
#define PDS2_LADRAO_H

#include "Personagem.h"
#include <iostream>

class Ladrao : public Personagem {
    private:
    public:
        //Construtor
        Ladrao(std::string, int, int, int);
        
        int ataque_basico(Personagem*) override;
        std::string get_habilidade(int) override;
        void usa_habilidade(int, std::vector<Personagem*>, std::vector<Personagem*>) override;    
};

#endif

