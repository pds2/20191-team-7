#ifndef PDS2_JOGO_H
#define PDS2_JOGO_H

#include <vector>
#include "Personagem.h"
#include "Monstro.h"

class Jogo {
    private:
        std::vector <Personagem> _herois;
        std::vector <Monstro> _monstros;
    public:
        Jogo();
        ~Jogo();
        bool carrega_arquivos();
        void imprime_vetores();
};

#endif
