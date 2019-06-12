#include "Monstro.h"

Monstro::Monstro(std::string nome, int forca, int agilidade, int inteligencia):
                 Personagem (nome, forca, agilidade, inteligencia) {

    modifica_atributos_secundarios();
}
Monstro::~Monstro(){}

void Monstro::modifica_atributos_secundarios(){

}

std::string Monstro::usa_habilidade(int habilidade_escolhida, int segunda_escolha, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
    std::string msg = "";
    switch (habilidade_escolhida)
    {
        case 1:
            msg = "Usou " + _habilidade_1;
            break;
        case 2:
            msg = "Usou " + _habilidade_2;
            break;
        case 3:
            msg = "Usou " + _habilidade_3;
            break;
        default:
            msg = "Habilidade inválida";
            break;
    }

    return msg;
}
