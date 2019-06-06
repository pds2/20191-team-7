#include "doctest.h"

#include "Experiencia.h"
#include "Monstro.h"

TEST_CASE("Teste: construtor"){
    Experiencia experiencia;

    //testa se o heroi inicia level 1,  ZERO de xp e 100 de xp para proximo level
    int level = experiencia.get_level_atual();
    CHECK (level == 1);
    int xp = experiencia.get_xp();
    CHECK_EQ (xp, 0);
    int xp_prox_level = experiencia.get_xp_prox_level();
    CHECK_EQ (xp_prox_level, XP_PROX_LEVEL); //XP_PROX_LEVEL == 100 
}

TEST_CASE ("Teste: adquirir experiencia"){
    //adiciona 50 de xp
    Experiencia experiencia;
    int xp_ganha = 50;
    experiencia.adiciona_xp(xp_ganha);
    int xp_atual = experiencia.get_xp();
    CHECK (xp_atual == 50);
    
}

TEST_CASE ("Teste: subir de level, atualizar _xp_para_prox_level, xp q falta pra subir de lvl"){
    Experiencia experiencia;
    int xp_ganha = 100; // valor suficiente para proximo level
    experiencia.adiciona_xp(xp_ganha);
    int level = experiencia.get_level_atual();
    CHECK (level == 2);
    int xp_para_prox_level = experiencia.get_xp_prox_level();
    CHECK (xp_para_prox_level == 125); // atualiza o xp necessario para subir level: 100*1.25 
    experiencia.adiciona_xp(xp_ganha);
    int xp_necessaria_pra_subir = experiencia.get_xp_necessaria();
    //checa se mantem level atual = 2, xp total ganha 200 e faltam 25 pra subir de level
    CHECK (xp_necessaria_pra_subir == 25); //para subir do lvl2 pro 3 precisa ganhar 125 de xp, logo faltam 25.
    int xp_total = experiencia.get_xp();
    level = experiencia.get_level_atual();
    CHECK (xp_total == 200);
    CHECK (level == 2);
    
}

TEST_CASE("Teste: subir varios levels de uma vez"){
    Experiencia exp;
    int xp_ganha = 1125; //equivalente a 6 levels (heroi vai do lvl 1 para o lvl 7) 
    exp.adiciona_xp(xp_ganha);
    int level = exp.get_level_atual();
    CHECK (level == 7);
}   

TEST_CASE ("Teste: calculo de xp gerado por monstros diferentes"){
    Experiencia experiencia;
    Monstro b1 = Monstro("Ramsey",10,10,10); //um inimigo igual ao hérois
    int xp_do_monstro = experiencia.calcula_xp_monstro(b1);
    CHECK (xp_do_monstro == 30); // xp = 10+10+10

    Monstro b2 ("Bolton", 20, 20, 20);
    xp_do_monstro = experiencia.calcula_xp_monstro(b2);
    CHECK (xp_do_monstro == 60); //xp = 20+20+20

}