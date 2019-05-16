#include "character.h"

Character::Character(int HP, int MP, int XP, int ATK, int DEF, std::string Name) {
    _HP = HP;
    _MP = MP;
    _XP = XP;
    _ATK = ATK;
    _DEF = DEF;
    _Name = Name;
}

bool Character::CharacterAlive() {
    if (_HP > 0) {
        return true;
    } else {
        return false;
    }
}

int Character::BaseAtk(int atkType){
    return _ATK;
}

int Character::BaseDef(int atkType){
    return _DEF;
}

std::string Character::GetName() {
    return _Name;
}

int Character::GetHP() {
    return _HP;
}

void Character::SetHP(int HP) {
    _HP = HP;
}