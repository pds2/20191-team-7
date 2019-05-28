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

    //estado do personagem
    _vivo = true;
}

char Personagem::get_grupo(){
    return _grupo;
}

void Personagem::set_grupo(char grupo){
    _grupo = grupo;
    return;
}

std::string Personagem::get_nome(){
    return _nome;
}

int Personagem::get_hp(){
    return _hp;
}

int Personagem::get_mp(){
    return _mp;
}

int Personagem::get_agilidade(){
    return _agilidade;
}

bool Personagem::get_vivo(){
    return _vivo;
}

void Personagem::imprime(){
    std::cout << _nome << " >>";    
    std::cout << " forca:" << _forca;
    std::cout << " agilidade:" << _agilidade;
    std::cout << " inteligencia:" << _inteligencia;
    std::cout << std::endl;
    std::cout << " ataque:" << _ataque;
    std::cout << " defesa:" << _defesa;
    std::cout << " mp:" << _mp;
    std::cout << " hp:" << _hp;
    std::cout << std::endl;
}

int Personagem::ataque_basico(Personagem* alvo){
    return alvo->recebe_ataque_fisico(_ataque);
}

int Personagem::recebe_ataque_fisico(int ataque){
    if ((ataque - _defesa) > 0){
        _hp -= (ataque - _defesa);
        if (_hp <= 0){
            _vivo = false;
        }    
        return ataque - _defesa;
    }
    else return 0; 
}

std::string Personagem::morreu(){
    if(_vivo){
        return " hp= " + std::to_string(_hp);
    }
    else {
        _vivo = false;
        return " morreu";
    }
}
