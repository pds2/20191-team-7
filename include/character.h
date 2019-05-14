#include <string>

#ifndef PDS2_CHARACTER_H
#define PDS2_CHARACTER_H

class Character {
    private:
        int _HP;
        int _MP;
        int _XP;
        int _ATK;
        int _DEF;
        std::string _Name;

    public:
        Character(int HP, int MP, int XP, int ATK, int DEF, std::string Name);
        bool CharacterAlive();
        int BaseAtk(int atkType);
        int BaseDef(int atkType);
};

#endif