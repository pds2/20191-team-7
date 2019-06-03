#ifndef PDS2_DRUIDA_H
#define PDS2_DRUIDA_H

#include "Personagem.h"

class Druida : public Personagem{
    private:
    public:
    
        //Construtor
        Druida (std::string, int, int, int);

        void modifica_atributos_secundarios();

};

#endif