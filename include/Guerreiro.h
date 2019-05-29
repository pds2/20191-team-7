#ifndef PDS2_GUERREIRO_H
#define PDS2_GUERREIRO_H

#include "Personagem.h"
#include <string>

class Guerreiro : public Personagem {
    private:

    public:
        //CONSTRUTOR

        Guerreiro (std::string, int, int, int);

        void modifica_atributos_secundarios();
        



        

};
#endif