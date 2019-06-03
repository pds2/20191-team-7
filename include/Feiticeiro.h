#ifndef PDS2_FEITICEIRO_H
#define PDS2_FEITICEIRO_H

#include "Personagem.h"

class Feiticeiro : public Personagem {
    private:
    public:

        //Construtor
        Feiticeiro (std::string, int, int, int);

        void modifica_atributos_secundarios();  
         
};

#endif