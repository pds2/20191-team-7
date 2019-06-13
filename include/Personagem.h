#ifndef PDS2_PERSONAGEM_H
#define PDS2_PERSONAGEM_H

#include "Experiencia.h"

#include <string>
#include <vector>

class Personagem {
    protected:
        //nome do personagem
        std::string _nome;

        //nome da classe do personagem
        std::string _nome_classe;

        Experiencia _xp;    
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
        int _max_hp;
        int _max_mp;

        //estado do personagem
        bool _vivo;
        bool _perdeu_vez;

        //grupo ao qual ele pertence
        char _grupo;

        std::string _habilidade_1;
        std::string _habilidade_2;
        std::string _habilidade_3;

    public:
        Personagem(std::string,int, int, int);
        ~Personagem();

        std::string get_nome();
        virtual std::string get_nome_classe();

        int calcula_xp_monstro(Personagem*);
        int get_forca();
        int get_agilidade();
        int get_inteligencia();
        int get_ataque();
        int get_defesa();
        char get_grupo();
        bool get_vivo();
        bool get_perdeu_vez();
        int get_hp();
        int get_max_hp();
        int get_mp();
        int get_max_mp();
        int get_level();
        void set_hp(int);
        void set_mp(int);
        void set_grupo(char);
        void set_perdeu_vez(bool);

        //METODOS UTILIZADOS PARA TESTE 
        void diminui_hp(int);
        void set_vivo_morto(bool);
        void set_agilidade(int);
        
        void set_experiencia_adquirida(int);
        void set_atributos_lvl_up();
        void set_atributos_secundarios_lvl_up(int, int, int);

/*
        void set_forca_upgrade();
        void set_inteligencia_upgrade();
        void set_agilidade_upgrade(int);
        void set_ataque_upgrade(int);
        void set_defesa_upgrade(int);
        void set_maxhp_upgrade(int);
        void set_maxmp_upgrade(int);
*/
        //FIM METODOS DE TESTE

        //imprime atributos do personagem
        void imprime();

        //ataque basico contra outro personagem
        virtual int ataque_basico(Personagem*);

        // Recupera habilidade
        virtual std::string get_habilidade(int);
        // Usa habilidade
        virtual std::string usa_habilidade(int, int, std::vector<Personagem*>, std::vector<Personagem*>);

        //recebe um ataque fisico
        int recebe_ataque_fisico(int);

        //recebe ataque de magia
        int recebe_ataque_magia(int);

        //confere se o personagem já morreu
        std::string morreu();
};

#endif