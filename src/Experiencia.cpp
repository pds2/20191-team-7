#include "Experiencia.h"

Experiencia::Experiencia (){
    this->_level = 1;
    this->_xp_total = 0;
    this->_xp_para_prox_level = XP_PROX_LEVEL;
    this->_xp_necessaria = XP_PROX_LEVEL;
}
Experiencia::~Experiencia(){}

int Experiencia::get_xp(){
    return this->_xp_total;
}
int Experiencia::get_level_atual(){
    return this->_level;
}
int Experiencia::get_xp_prox_level(){
    return this->_xp_para_prox_level;
}

int Experiencia::get_xp_necessaria(){
    return this->_xp_necessaria;
}

void Experiencia::sobe_de_level(){
    this->_level += 1;
}
void Experiencia::adiciona_xp(int xp){
    //entra no if caso o personagem ganhe xp suficiente para subir level
    //TeSTE
    int xp_aux = xp;
    while(this->_xp_necessaria - xp_aux <= 0){
        sobe_de_level();
        xp_aux -= this->_xp_necessaria;
        this->_xp_para_prox_level *=XP_MULTIPLICADOR;
        this->_xp_necessaria = this->_xp_para_prox_level;
        //this->_xp_para_prox_level = (this->_xp_para_prox_level) + (this->_xp_para_prox_level)*(XP_MULTIPLICADOR);//atualiza xp necessaria para proximo level
        }
        this->_xp_necessaria -= xp_aux;
 
 
 /*   if(this->_xp_total + xp >= XP_PROX_LEVEL){
        sobe_de_level();
        this->_xp_para_prox_level = (this->_xp_para_prox_level) + (this->_xp_para_prox_level)*(XP_MULTIPLICADOR);//atualiza xp necessaria para proximo level
    }*/
    this->_xp_total += xp;
}
//xp gerada pelo monstro = forca + inteligencia + agilidade

//A FAZER --- CALCULAR XP DO MONSTRO
/*
int Experiencia::calcula_xp_monstro(Monstro monstro){
    int xp_monstro = (monstro.get_forca() + monstro.get_inteligencia() + monstro.get_agilidade());
    return xp_monstro;
}
*/

//CALCULAR ATRIBUTOS EH RESPONSABILIDADE DE QUEM?
/*
void Experiencia::modifica_atributos_por_level(Personagem* heroi, int level){
    for (int i = 0; i < level; i++){
        heroi->set_atributos_lvl_up();
    }
    
*/  


