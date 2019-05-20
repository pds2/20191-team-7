#include <string>

#ifndef PDS2_MONSTER_H
#define PDS2_MONSTER_H

#include "character.h"

class Monster : public Character {
    private:
        std::string _Categoria;
        float _Bonus;
    public:
        Monster(int HP, int MP, int ATK, int DEF, std::string Name, std::string Categoria, float Bonus);
        int BaseAtk(int atkType, std::string Local);
        int BaseDef(int defType, std::string Local);
};

#endif

