#include "monster.h"

int Monster::BaseAtk(int atkType){
    return Character::_ATK;
}

int Monster::BaseDef(int atkType){
    return Character::_DEF;
}

Monster::Monster(int HP, int MP, int ATK, int DEF, std::string Name, std::string Categoria) 
    : Character(HP, MP, ATK, DEF, Name), _Categoria(Categoria) {}