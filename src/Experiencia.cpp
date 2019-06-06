#include "Experiencia.h"

Experiencia::Experiencia (){
    this->_level = 1;
    this->_xp_total = 0;
    this->_xp_para_prox_level = XP_PROX_LEVEL;
  //  this->_xp_por_level = XP_PROX_LEVEL;

}

int Experiencia::get_xp(){
    return this->_xp_total;
}
int Experiencia::get_level_atual(){
    return this->_level;
}
int Experiencia::get_xp_prox_level(){
    return this->_xp_para_prox_level;
}

void Experiencia::sobe_de_level(){
    this->_level += 1;
}
void Experiencia::adiciona_xp(int xp){
    if(this->_xp_total + xp >= XP_PROX_LEVEL){
        sobe_de_level();
        this->_xp_para_prox_level = (this->_xp_para_prox_level) + (this->_xp_para_prox_level)*(XP_MULTIPLICADOR);
    }
    this->_xp_total += xp;
}

