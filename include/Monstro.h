#ifndef PDS2_MONSTER_H
#define PDS2_MONSTER_H

#include <string>
#include "Personagem.h"

//no momento não tem nada de diferente da classe personagem
class Monstro : public Personagem {
    private:
        int _exp_do_monstro;
    public:
        Monstro(std::string, int, int, int);
        ~Monstro();
        
//        void modifica_atributos_secundarios();
        std::string usa_habilidade(int, int, std::vector<Personagem*>, std::vector<Personagem*>) override;

};
#endif
