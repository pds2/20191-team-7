#include "Personagem.h"
#include <string>
#include <iostream>

Personagem::Personagem(std::string nome, int forca, int agilidade, int inteligencia) {
    //atributos principais
    _nome = nome;
    _forca = forca;
    _agilidade = agilidade;
    _inteligencia = inteligencia;

    //calcula os atributos secundarios a partir dos principais
    _ataque = 10 * forca;
    _defesa = 2 * forca;
    _mp = 10 * inteligencia;
    _hp = 30 * forca;
}

std::string Personagem::get_nome(){
    return _nome;
}

int Personagem::get_hp(){
    return _hp;
}

void Personagem::imprime(){
    std::cout << _nome << " >>";    
    std::cout << " forca:" << _forca;
    std::cout << " agilidade:" << _agilidade;
    std::cout << " inteligencia:" << _inteligencia;
    std::cout << std::endl;
}