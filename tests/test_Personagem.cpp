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