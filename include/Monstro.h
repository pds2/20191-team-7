#ifndef PDS2_MONSTER_H
#define PDS2_MONSTER_H

#include <string>
#include "Personagem.h"

//no momento não tem nada de diferente da classe personagem
class Monstro : public Personagem {
    private:
    public:
        Monstro(std::string, int, int, int);

        void modifica_atributos_secundarios();
};
#endif
