#ifndef PDS2_DRUIDA_H
#define PDS2_DRUIDA_H

#include "Personagem.h"
#include <iostream>

#define CUSTO_HABILIDADE_1_DRUIDA 30
#define CUSTO_HABILIDADE_2_DRUIDA 30
#define CUSTO_HABILIDADE_3_DRUIDA 60
#define INCREMENTO_ATAQUE_DRUIDA 60 
#define FATOR_CURA_DRUIDA 0.70
#define FATOR_REVITALIZACAO_DRUIDA 0.50

class Druida : public Personagem{
    private:
    public:
        //Construtor
        Druida (std::string, int, int, int);
        ~Druida();

        int ataque_basico(Personagem*) override;
        std::string get_habilidade(int) override;
        std::string usa_habilidade(int, int, std::vector<Personagem*>, std::vector<Personagem*>) override;
        std::string habilidade_1(int, std::vector<Personagem*>);
        std::string habilidade_2(int, std::vector<Personagem*>);       
        std::string habilidade_3(int, std::vector<Personagem*>);
};

#endif