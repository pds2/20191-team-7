#ifndef PDS2_GUERREIRO_H
#define PDS2_GUERREIRO_H

#include "Personagem.h"

class Guerreiro : public Personagem {
    private:
    public:

        //Construtor
        Guerreiro (std::string, int, int, int);

        void modifica_atributos_secundarios();
};

#endif