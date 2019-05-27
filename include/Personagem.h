#ifndef PDS2_PERSONAGEM_H
#define PDS2_PERSONAGEM_H

#include <string>

class Personagem {
    protected:
        //nome do personagem
        std::string _nome;

        //atributos principais:
        //determina dano do ataque basico e defesa
        int _forca;

        //determina chance de ataque critico, esquiva e ordem da rodada
        int _agilidade;

        //determina quantidade de mp
        int _inteligencia;

        //atributos derivados
        int _ataque;
        int _defesa;
        int _hp;
        int _mp;

        //estado do personagem
        bool _vivo;

    public:
        Personagem();
        Personagem(std::string,int, int, int);
        Personagem(std::string,int, int, int, bool); // esse construtor adiciona o estatus vivo em todos os personagens e monstros no comeco do combate.

        std::string get_nome();
        int get_ataque();
        int get_defesa();

        int get_hp();
        void set_hp(int);
        bool get_status(); // esse metodo retorna true se o personagem ta vivo e false se ele ta morto

        //imprime atributos do personagem
        void imprime();


        //ataque basico contra outro personagem
        int ataque_basico(Personagem*);

        //recebe um ataque fisico
        int recebe_ataque_fisico(int);

        //confere se o personagem já morreu
        //bool morreu(); Esse metodo nao eh mais necessario

};

#endif
