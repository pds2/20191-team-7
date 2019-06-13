#include "doctest.h"

#include "Partida.h"



TEST_CASE("Teste: 'esquiva' e 'defesa diminui dano'"){
    Personagem p("Zezinho", 30, 0, 10); // defesa == 60;
    int esquiva;
    int dano_reduzido_defesa;

    //testa dano com reducao da defesa
    dano_reduzido_defesa = p.recebe_ataque_fisico(100);
    CHECK (dano_reduzido_defesa == 40);

    p.set_agilidade(1000);
    esquiva = p.recebe_ataque_fisico(100);
    CHECK (esquiva == 0);
}

TEST_CASE ("Teste: recebe ataque magico (ignora defesa)"){
    Personagem p("Zezinho", 30, 0, 10); // defesa == 60, HP == 350;
    p.recebe_ataque_magia(100);
    int hp = p.get_hp();
    CHECK (hp == 250);
}

TEST_CASE ("Teste: subir de level e atualizacao de atributos"){
    Personagem p("Zezinho", 10, 10, 10); // maxHP=200; maxMP = 100; ataque = 100; defesa = 20; 
    p.set_atributos_lvl_up();
    int level_personagem = p.get_level();;
    CHECK (level_personagem == 2);
    int agilidade, forca, inteligencia, ataque, defesa, maxhp, maxmp;

    agilidade = p.get_agilidade();
    CHECK(agilidade == 13);

    forca  = p.get_forca();
    CHECK(forca == 13);
    inteligencia = p.get_inteligencia();
    CHECK(inteligencia == 13);
    ataque = p.get_ataque();
    CHECK(ataque == 130);
    defesa = p.get_defesa();
    CHECK(defesa == 26);
    maxmp = p.get_max_mp();
    CHECK(maxmp == 130);
    maxhp = p.get_max_hp();
    CHECK(maxhp == 260);


    
    
}