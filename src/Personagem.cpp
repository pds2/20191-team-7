#include "Personagem.h"

#include <string>
#include <iostream>

//METODOS PARA TESTES
void Personagem::set_vivo_morto(bool status){
    _vivo = status;
}

void Personagem::diminui_hp(int redutor){
    _hp -= redutor;
}

void Personagem::set_agilidade(int agilidade){
    _agilidade = agilidade;
}
//FIM METODOS PARA TESTES

Personagem::Personagem(std::string nome, int forca, int agilidade, int inteligencia) {
     //atributos principais
    _nome = nome;
    _forca = forca;
    _agilidade = agilidade;
    _inteligencia = inteligencia;
    Experiencia _xp;
    
    //calcula os atributos secundarios a partir dos principais
    _ataque = 10 * forca;
    _defesa = 2 * forca; //maximo de 60
    if (_defesa > 60){
        _defesa = 60;
    }
    _mp = 10 * inteligencia;
    _hp = 10 * forca + 5 * _agilidade + 5 * _inteligencia;
    _max_hp = _hp;
    _max_mp = _mp;

    //estado do personagem
    _vivo = true;
    _perdeu_vez = false;

    //habilidades
    _habilidade_1 = "Habilidade 1";
    _habilidade_2 = "Habilidade 2";
    _habilidade_3 = "Habilidade 3";
}
Personagem::~Personagem(){}

char Personagem::get_grupo(){
    return _grupo;
}


void Personagem::set_grupo(char grupo){
    _grupo = grupo;
    return;
}

int Personagem::get_level(){
    return _xp.get_level_atual();
}

std::string Personagem::get_nome(){
    return _nome;
}


int Personagem::get_forca(){
    return _forca;
}

int Personagem::get_agilidade(){
    return _agilidade;
}

int Personagem::get_inteligencia(){
    return _inteligencia;
}

int Personagem::get_hp(){
    return _hp;
}

int Personagem::get_max_hp(){
    return _max_hp;
}

int Personagem::get_max_mp(){
    return _max_mp;
}

int Personagem::get_mp(){
    return _mp;
}

int Personagem::get_ataque(){
    return _ataque;
}

int Personagem::get_defesa(){
    return _defesa;
}

bool Personagem::get_vivo(){
    return _vivo;
}

bool Personagem::get_perdeu_vez(){
    return _perdeu_vez;
}

void Personagem::set_perdeu_vez(bool status){
    _perdeu_vez = status;
}

void Personagem::set_mp(int mp) {
    _mp = mp;
}
void Personagem::set_hp(int hp) {
    _hp = hp;
}
void Personagem::set_atributos_lvl_up(){
    //_xp.sobe_de_level();
    _forca = round(_forca * MULTIP_LEVEL_UP);
    _agilidade =round (_agilidade * MULTIP_LEVEL_UP);
    _inteligencia = round (_inteligencia * MULTIP_LEVEL_UP);
    set_atributos_secundarios_lvl_up(_forca, _agilidade, _inteligencia);
}

void Personagem::set_atributos_secundarios_lvl_up(int forca, int agilidade, int inteligencia){
    _ataque = 10 * forca;
    _defesa = 2 * forca; //maximo de 60
    if (_defesa > 60){
        _defesa = 60;
    }
    _mp = 10 * inteligencia;
    _hp = 10 * forca + 5 * _agilidade + 5 * _inteligencia;
    _max_hp = _hp;
    _max_mp = _mp;

}

void Personagem::set_experiencia_adquirida(int exp){
    int level = _xp.get_level_atual();
    _xp.adiciona_xp(exp);
    while (level < _xp.get_level_atual()){
        set_atributos_lvl_up();
        level++;
    }
}

int Personagem::calcula_xp_monstro(Personagem* monstro){
    if (monstro->get_nome_classe() == "Monstro"){
        int experiencia = monstro->get_agilidade() + monstro->get_forca() + monstro->get_inteligencia();
        return experiencia;
    }
    return 0;
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

std::string Personagem::get_habilidade(int habilidade_escolhida) {
    switch (habilidade_escolhida)
    {
        case 1: return _habilidade_1; break;
        case 2: return _habilidade_2; break;
        case 3: return _habilidade_3; break;
        default: return "Habilidade inválida"; break;
    }
}

std::string Personagem::usa_habilidade(int habilidade_escolhida, int segunda_escolha, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
    switch (habilidade_escolhida)
    {
        case 1: 
            std::cout << "Usou " << _habilidade_1 << std::endl;
            break;
        case 2: 
            std::cout << "Usou " << _habilidade_2 << std::endl;
            break;
        case 3: 
            std::cout << "Usou " << _habilidade_3 << std::endl;
            break;
        default: 
            std::cout << "Habilidade inválida" << std::endl;
            break;
    }
    return "";
}

int Personagem::recebe_ataque_fisico(int ataque){
    //numero aleatório entre 0 e 100
    int random;
    random = rand() % 100 + 1;
    //se menor que agilidade o ataque erra
    if (random <= _agilidade){
        std::cout << _nome + " conseguiu se esquivar. ";
        return 0;
    }
    else{
        //defesa reduz o ataque
        int resultado = ataque * (100-_defesa)/100;
        _hp -= resultado;
        if (_hp <= 0){
            _vivo = false;
        }    
        return resultado;
    }
}

int Personagem::recebe_ataque_magia(int ataque){
    _hp -= ataque;
    if (_hp <= 0){
        _vivo = false;
    }
    return ataque;
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

std::string Personagem::get_nome_classe(){
    return _nome_classe;
}