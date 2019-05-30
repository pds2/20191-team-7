#include "Mago.h"

#define BONUS__ATAQUE 5;
#define BONUS__DEFESA 2;
#define MODIFICADOR_HP 2;

#define MODIFICADOR_INT_MP 30;

Mago::Mago (std::string nome, int forca, int agilidade, int inteligencia):
            Personagem (nome, forca, agilidade, inteligencia){

    //teste do modificador ao criar o player
    modifica_atributos_secundarios();
}

void Mago::modifica_atributos_secundarios(){
    _ataque = _forca * BONUS__ATAQUE;
    _defesa = _forca * BONUS__DEFESA;
    _hp = _forca * MODIFICADOR_HP;
    _mp = _inteligencia  * MODIFICADOR_INT_MP;
}