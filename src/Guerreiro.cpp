#include "Guerreiro.h"

Guerreiro::Guerreiro (std::string nome, int forca, int agilidade, int inteligencia):
                         Personagem (nome, forca, agilidade, inteligencia){

    _nome_classe = "guerreiro";
    
    modifica_atributos_secundarios();
}

void Guerreiro::modifica_atributos_secundarios () {
}
