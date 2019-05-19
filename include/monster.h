#include <string>

#ifndef PDS2_MONSTER_H
#define PDS2_MONSTER_H

class Monster {
    private:
        int _HP;
        int _MP;
        //int _XP;
        int _ATK;
        int _DEF;
        std::string _Name;

    public:
        Monster(int HP, int MP, int ATK, int DEF, std::string Name);
        bool MonsterAlive();
        int BaseAtk(int atkType);
        int BaseDef(int atkType);
        std::string GetName();
        int GetHP();
        void SetHP(int HP);
};

#endif

