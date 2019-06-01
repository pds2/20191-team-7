#include "Ladrao.h"

Ladrao::Ladrao(std::string nome, int forca, int agilidade, int inteligencia):
               Personagem (nome, forca, agilidade, inteligencia){

    _nome_classe = "ladrao";

    modifica_atributos_secundarios();
}

void Ladrao::modifica_atributos_secundarios(){
}

