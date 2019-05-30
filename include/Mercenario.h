#ifndef PDS2_MERCENARIO_H
#define PDS2_MERCENARIO_H

#include "Personagem.h"

class Mercenario : public Personagem {
    private:
    public:

        //Construtor
        Mercenario (std::string, int, int, int);

        void modifica_atributos_secundarios();
};

#endif