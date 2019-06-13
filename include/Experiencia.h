#ifndef PSS2_EXPERIENCIA_H
#define PSS2_EXPERIENCIA_H

#include <math.h>


#define MULTIP_LEVEL_UP 1.30
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

        int _level; //nivel atual do personagem
        int _xp_para_prox_level;//xp  necessaria para subir de level
        int _xp_necessaria;


        
    
    public: 
        
        Experiencia();
        ~Experiencia();
        int get_xp();
        int get_level_atual();
        //retorna xp necessario para subir de level (valor de xp por level)
        int get_xp_prox_level();

        //xp q fata pra subir de level
        int get_xp_necessaria();

        //calcula xp com base nos stats do monstro derrotado
        int calcula_xp_monstro();

        //adiciona xp, se subir de level, chama sobe_level e atualiza _xp_para_prox_level
        void adiciona_xp(int xp);
        
    
        void sobe_de_level();




};

#endif