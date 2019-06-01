#include "Clerigo.h"

Clerigo::Clerigo(std::string nome, int forca, int agilidade, int inteligencia):
                 Personagem (nome, forca, agilidade, inteligencia){

    _nome_classe = "clerigo";

    modifica_atributos_secundarios();
}

void Clerigo::modifica_atributos_secundarios(){
}

