#include "Feiticeiro.h"

Feiticeiro::Feiticeiro (std::string nome, int forca, int agilidade, int inteligencia):
            Personagem (nome, forca, agilidade, inteligencia){

    _nome_classe = "feiticeiro";

    modifica_atributos_secundarios();
}

void Feiticeiro::modifica_atributos_secundarios(){
    //
}
