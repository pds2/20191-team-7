#include "monster.h"

int Monster::BaseAtk(int atkType, std::string Local){
    if (Local == _Categoria) {
        return Character::_ATK * _Bonus;
    } else {
        return Character::_ATK;
    }
}

int Monster::BaseDef(int atkType, std::string Local){
    if (Local == _Categoria) {
        return Character::_DEF * _Bonus;
    } else {
        return Character::_DEF;
    }
}

Monster::Monster(int HP, int MP, int ATK, int DEF, std::string Name, std::string Categoria, float Bonus) 
    : Character(HP, MP, ATK, DEF, Name), _Categoria(Categoria), _Bonus(Bonus) {}