#ifndef PDS2_FEITICEIRO_H
#define PDS2_FEITICEIRO_H

#include "Personagem.h"
#include <iostream>

#define CUSTO_HABILIDADE_FT_1 5
#define CUSTO_HABILIDADE_FT_2 4
#define CUSTO_HABILIDADE_FT_3 6

#define DANO_BOLA_DE_FOGO 20
#define FATOR_DRENAR 0.20
#define FATOR_F_CURA 0.30
#define DANO_RAIO_PARALIZANTE 30


class Feiticeiro : public Personagem {
    private:
    public:
        //Construtor
        Feiticeiro (std::string, int, int, int);
        ~Feiticeiro();

        int ataque_basico(Personagem*) override;
        std::string get_habilidade(int) override;
        std::string usa_habilidade(int, int, std::vector<Personagem*>, std::vector<Personagem*>) override;
        std::string habilidade_1(std::vector<Personagem*>);
        std::string habilidade_2(int, std::vector<Personagem*>);
        std::string habilidade_3(int, std::vector<Personagem*>);
};

#endif
