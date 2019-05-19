#include "monster.h"

Monster::Monster(int HP, int MP, int ATK, int DEF, std::string Name) {
    _HP = HP;
    _MP = MP;
    _ATK = ATK;
    _DEF = DEF;
    _Name = Name;
}

bool Monster::MonsterAlive() {
    if (_HP > 0) {
        return true;
    } else {
        return false;
    }
}

int Monster::BaseAtk(int atkType){
    return _ATK;
}

int Monster::BaseDef(int atkType){
    return _DEF;
}

std::string Monster::GetName() {
    return _Name;
}

int Monster::GetHP() {
    return _HP;
}

void Monster::SetHP(int HP) {
    _HP = HP;
}

