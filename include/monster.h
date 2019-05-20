#include <string>

#ifndef PDS2_MONSTER_H
#define PDS2_MONSTER_H

#include "character.h"

class Monster : public Character {
    private:
        std::string _Categoria;
    public:
        Monster(int HP, int MP, int ATK, int DEF, std::string Name, std::string Categoria);
        virtual int BaseAtk(int atkType) override;
        virtual int BaseDef(int defType) override;
};

#endif

