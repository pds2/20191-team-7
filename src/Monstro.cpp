#include <Monstro.h>

Monstro::Monstro(std::string nome, int forca, int agilidade, int inteligencia):
                 Personagem (nome, forca, agilidade, inteligencia) {
 
    //teste do modificador ao criar o player
    modifica_atributos_secundarios();
}

void Monstro::modifica_atributos_secundarios(){
    _ataque = _agilidade * 10;
    _defesa = _forca * 1;
    _hp = _forca * 1000;
    _mp = _inteligencia * 10;

}