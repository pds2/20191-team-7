#include <Monstro.h>

Monstro::Monstro(std::string nome, int forca, int agilidade, int inteligencia):
                 Personagem (nome, forca, agilidade, inteligencia) {
                     
    modifica_atributos_secundarios();
}

void Monstro::modifica_atributos_secundarios(){

}