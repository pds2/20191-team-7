#include <string>

#ifndef PDS2_CHARACTER_H
#define PDS2_CHARACTER_H

class Character {
    protected:
        int _HP;
        int _MP;
        int _ATK;
        int _DEF;
        std::string _Name;

    public:
        Character(int HP, int MP, int ATK, int DEF, std::string Name);
        bool CharacterAlive();
        int GetHP();
        void SetHP(int HP);
        std::string GetName();
        virtual int BaseAtk(int atkType);
        virtual int BaseDef(int atkType);
        
};

#endif