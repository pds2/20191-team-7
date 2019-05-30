#include "Mercenario.h"

Mercenario::Mercenario (std::string nome, int forca, int agilidade, int inteligencia):
                 Personagem (nome, forca, agilidade, inteligencia) {

    _nome_classe = "mercenário";

    modifica_atributos_secundarios();
}

void Mercenario::modifica_atributos_secundarios(){
}