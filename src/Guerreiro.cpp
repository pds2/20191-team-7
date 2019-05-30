#include "Guerreiro.h"


#define BONUS_FORCA_ATAQUE 35;
#define BONUS_FORCA_DEFESA 5;
#define BONUS_FORCA_HP 5;

#define MODIFICADOR_INT_MP 2;


Guerreiro::Guerreiro (std::string nome, int forca, int agilidade, int inteligencia):
                         Personagem (nome, forca, agilidade, inteligencia){
 
    //teste do modificador ao criar o player
    modifica_atributos_secundarios();
}

void Guerreiro::modifica_atributos_secundarios () {
    _ataque = _forca * BONUS_FORCA_ATAQUE;
    _defesa = _forca * BONUS_FORCA_DEFESA;
    _hp = _forca * BONUS_FORCA_HP;
    _mp = _inteligencia * MODIFICADOR_INT_MP;

}
