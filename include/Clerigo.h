#ifndef PDS2_CLERIGO_H
#define PDS2_CLERIGO_H

#include "Personagem.h"

class Clerigo : public Personagem {
    private:
    public:

        //Construtor
        Clerigo(std::string, int, int, int);

        void modifica_atributos_secundarios();
};

#endif

