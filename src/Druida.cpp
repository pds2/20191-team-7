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

void Druida::usa_habilidade(int habilidade_escolhida, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
    switch (habilidade_escolhida)
    {
        case 1: 
            std::cout << "Usou " << _habilidade_1 << std::endl;
            break;
        case 2: 
            std::cout << "Usou " << _habilidade_2 << std::endl;
            break;
        case 3: 
            std::cout << "Usou " << _habilidade_3 << std::endl;
            break;
        default: 
            std::cout << "Habilidade inválida" << std::endl;
            break;
    }
}   
