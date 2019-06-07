#include "Druida.h"

Druida::Druida (std::string nome, int forca, int agilidade, int inteligencia):
                  Personagem (nome, forca, agilidade, inteligencia){
    
    _nome_classe = "Druida";
    _habilidade_1 = "Cura";
    _habilidade_2 = "Forma Animal";
    _habilidade_3 = "Proteção";
}
Druida::~Druida(){}

int Druida::ataque_basico(Personagem* alvo) {
    return alvo->recebe_ataque_fisico(_ataque);
}

std::string Druida::get_habilidade(int habilidade_escolhida) {
    switch (habilidade_escolhida)
    {
        case 1: return _habilidade_1; break;
        case 2: return _habilidade_2; break;
        case 3: return _habilidade_3; break;
        default: return "Habilidade inválida"; break;
    }
}

std::string Druida::usa_habilidade(int habilidade_escolhida, int segunda_escolha, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
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
