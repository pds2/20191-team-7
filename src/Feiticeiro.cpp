#include "Feiticeiro.h"

Feiticeiro::Feiticeiro (std::string nome, int forca, int agilidade, int inteligencia):
            Personagem (nome, forca, agilidade, inteligencia){

    _nome_classe = "Feiticeiro";
    _habilidade_1 = "Drenar Energia";
    _habilidade_2 = "Bola de Fogo";
    _habilidade_3 = "Esfera de Proteção";
}
Feiticeiro::~Feiticeiro(){}

int Feiticeiro::ataque_basico(Personagem* alvo) {
    return alvo->recebe_ataque_fisico(_ataque);
}

std::string Feiticeiro::get_habilidade(int habilidade_escolhida) {
    switch (habilidade_escolhida)
    {
        case 1: return _habilidade_1; break;
        case 2: return _habilidade_2; break;
        case 3: return _habilidade_3; break;
        default: return "Habilidade inválida"; break;
    }
}

std::string Feiticeiro::usa_habilidade(int habilidade_escolhida, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
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
