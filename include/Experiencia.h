#ifndef PSS2_EXPERIENCIA_H
#define PSS2_EXPERIENCIA_H

#include <math.h>
#include "Personagem.h"

#define XP_MULTIPLICADOR 1.25
#define XP_PROX_LEVEL 100 //valor da xp necessaria pro level 1 ir para level 2 
                          //valor apenas ilustrativo, a ser decidido.

/* na classe experiencia precisamos controlar
nivel do personagem 
xp atual
xp que falta pra subir de nivel


*/
class Experiencia {
    private:
        
        int _xp_total;
        double _xp_por_level; //atributo utilizado para realizar calculos xp

        int _level; //nivel atual do personagem
        int _xp_para_prox_level;
        

        
    
    public: 
        
        Experiencia();
        int get_xp();
        int get_level_atual();
        int get_xp_prox_level();
        int get_calcula_xp_monstro(Personagem* monstro);

        void adiciona_xp(int xp);
        
        void sobe_de_level();



};

#endif