#include "Guerreiro.h"


#define BONUS_FORCA_ATAQUE 35;
#define BONUS_FORCA_DEFESA 5;
#define BONUS_FORCA_HP 5;

#define MODIFICADOR_INT_MP 2;


Guerreiro::Guerreiro (std::string nome, int forca, int agilidade, int inteligencia):
                         Personagem (nome, forca, agilidade, inteligencia){
    _nome = nome;
    _forca = forca;
    _agilidade = agilidade;
    _inteligencia = inteligencia;
}

void Guerreiro::modifica_atributos_secundarios () {
    _ataque *= BONUS_FORCA_ATAQUE;
    _defesa *= BONUS_FORCA_DEFESA;
    _hp *= BONUS_FORCA_HP;
    _mp *= MODIFICADOR_INT_MP;

}
