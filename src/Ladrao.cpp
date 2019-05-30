#include "Ladrao.h"

#define BONUS_ATAQUE 15;
#define BONUS_DEFESA 5;
#define BONUS_HP 4;
#define MODIFICADOR_MP 3;

Ladrao::Ladrao (std::string nome, int forca, int agilidade, int inteligencia):
                 Personagem (nome, forca, agilidade, inteligencia) {
 
    //teste do modificador ao criar o player
    modifica_atributos_secundarios();
}

void Ladrao::modifica_atributos_secundarios(){
    _ataque = _agilidade * BONUS_ATAQUE;
    _defesa = 0; //teste de dano  ( _forca * BONUS_DEFESA;)
    _hp = 1000* _forca * BONUS_HP;
    _mp = _inteligencia * MODIFICADOR_MP;

}