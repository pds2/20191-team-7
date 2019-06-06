#include "doctest.h"

#include "Experiencia.h"

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

TEST_CASE ("Teste: subir de level e atualizar _xp_para_prox_level"){
    Experiencia experiencia;
    int xp_ganha = 100; // valor suficiente para proximo level
    experiencia.adiciona_xp(xp_ganha);
    int level = experiencia.get_level_atual();
    CHECK (level == 2);
    int xp_para_prox_level = experiencia.get_xp_prox_level();
    CHECK (xp_para_prox_level == 225); //testa se atualiza o xp necessario para subir level: 100+100*1.25 
}