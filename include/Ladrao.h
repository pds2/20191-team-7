#ifndef PDS2_LADRAO_H
#define PDS2_LADRAO_H

#include "Personagem.h"

class Ladrao : public Personagem {
    private:
    public:

        //Construtor
        Ladrao(std::string, int, int, int);

        void modifica_atributos_secundarios();
        
};

#endif

