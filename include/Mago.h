#ifndef PDS2_MAGO_H
#define PDS2_MAGO_H

#include "Personagem.h"

class Mago : public Personagem {
    private:

    public:
    
        //CONSTRUTOR
        Mago (std::string, int, int, int);

        // calcula atributos secundarios (ataque, defesa, HP, MP), 
        //com base nos bonus das classes
        void modifica_atributos_secundarios();
 


};

#endif