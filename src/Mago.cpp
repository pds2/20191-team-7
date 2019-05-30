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
    _defesa = 0; //teste de dano  (_forca * BONUS__DEFESA;)
    _hp = 1000* _forca * MODIFICADOR_HP;//HP teste dano
    _mp = _inteligencia  * MODIFICADOR_INT_MP;
}