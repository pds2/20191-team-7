#ifndef PDS2_LADRAO_H
#define PDS2_LADRAO_H

#include "Personagem.h"

class Ladrao : public Personagem {
    public:
        //Construtor
        Ladrao (std::string, int, int, int);

        // calcula atributos secundarios (ataque, defesa, HP, MP), 
        //com base nos bonus das classes
        void modifica_atributos_secundarios();

};

#endif