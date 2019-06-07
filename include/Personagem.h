#ifndef PDS2_PERSONAGEM_H
#define PDS2_PERSONAGEM_H

#include <string>
#include <vector>

class Personagem {
    protected:
        //nome do personagem
        std::string _nome;

        //nome da classe do personagem
        std::string _nome_classe;

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

        int get_forca();
        int get_agilidade();
        int get_inteligencia();
        int get_ataque();
        int get_defesa();
        char get_grupo();
        bool get_vivo();
        int get_hp();
        int get_mp();

        void set_hp(int);
        void set_grupo(char);

        //METODOS UTILIZADOS PARA TESTE 
        void diminui_hp(int);
        void set_vivo_morto(bool);
        //FIM METODOS DE TESTE

        //imprime atributos do personagem
        void imprime();

        //ataque basico contra outro personagem
        virtual int ataque_basico(Personagem*);

        // Recupera habilidade
        virtual std::string get_habilidade(int);
        // Usa habilidade
        virtual void usa_habilidade(int, std::vector<Personagem*>, std::vector<Personagem*>);

        //recebe um ataque fisico
        int recebe_ataque_fisico(int);

        //confere se o personagem já morreu
        std::string morreu();
};

#endif