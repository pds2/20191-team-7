#include "Druida.h"

Druida::Druida (std::string nome, int forca, int agilidade, int inteligencia):
                  Personagem (nome, forca, agilidade, inteligencia){
    
    _nome_classe = "druida";
    
    modifica_atributos_secundarios();
}

void Druida::modifica_atributos_secundarios () {
    //Guerreiros ganham um bônus no seus atque básico
}