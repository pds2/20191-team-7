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

Personagem::Personagem(std::string nome, int forca, int agilidade, int inteligencia, bool status){

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
    _vivo = status;


}

std::string Personagem::get_nome(){
    return _nome;
}

int Personagem::get_hp(){
    return _hp;
}

bool Personagem::get_status(){
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
        if (_hp < 0){
            _vivo = false;
        }
        return ataque - _defesa;
    }
    else return 0;
}

/* Esse metodo nao eh mais necessario.
bool Personagem::morreu(){
    return get_status();
}
*/
