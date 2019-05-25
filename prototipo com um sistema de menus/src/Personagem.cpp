#include "Personagem.h"
#include <string>

Personagem::Personagem(std::string nome, int hp, int max_hp, int ataque, int defesa) {
    _nome = nome;
    _hp = hp;
    _max_hp = max_hp;
    _ataque = ataque;
    _defesa = defesa;
}

std::string Personagem::get_nome(){
    return _nome;
}

int Personagem::get_hp(){
    return _hp;
}

int Personagem::get_max_hp(){
    return _max_hp;
}

int Personagem::get_ataque(){
    return _ataque;
}

int Personagem::get_defesa(){
    return _defesa;
}