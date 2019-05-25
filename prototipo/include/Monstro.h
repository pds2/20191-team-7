#ifndef PDS2_MONSTER_H
#define PDS2_MONSTER_H

#include <string>
#include "Personagem.h"

class Monstro : public Personagem {
    private:
    public:
        Monstro(std::string nome,int hp, int hp_max, int ataque, int defesa) : Personagem(nome,hp,hp_max,ataque,defesa){
            
        }
};

#endif
