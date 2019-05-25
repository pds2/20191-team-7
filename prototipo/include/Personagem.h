#ifndef PDS2_PERSONAGEM_H
#define PDS2_PERSONAGEM_H

#include <string>

class Personagem {
    protected:
        //nome do personagem
        std::string _nome;
    
        //pondos de vida do personagem
        int _hp;

        //maximo de hp que o personagem pode ter
        int _max_hp;

        //determina a força dos ataques
        int _ataque;

        //pontos de defesa, reduzem o dano de ataques fisicos
        int _defesa;

    public:
        Personagem();
        Personagem(std::string,int, int, int, int);

        std::string get_nome();
        int get_hp();
        int get_max_hp();
        int get_ataque();
        int get_defesa();

        void set_hp(int);
};

#endif