#include "doctest.h"

#include "Feiticeiro.h"

TEST_CASE("Testando o Construtor") {
    Feiticeiro feiticeiro ("Tyrell", 10, 15, 20);
    std::string nome = feiticeiro.get_nome();
    CHECK_EQ (nome, "Tyrell" );
    std::string nome_classe = feiticeiro.get_nome_classe();
    CHECK_EQ (nome_classe, "feiticeiro");


    //checa atributos principais forca, agilidade, inteligencia
    int forca = feiticeiro.get_forca();
    CHECK_EQ (forca, 10);
    int agilidade = feiticeiro.get_agilidade();
    CHECK_EQ (agilidade, 15);
    int inteligencia = feiticeiro.get_inteligencia();
    CHECK_EQ (inteligencia, 20);

    //checa atributos secundarios, conforme classe
    int ataque = feiticeiro.get_ataque();
    CHECK_EQ (ataque , 100);
    int defesa = feiticeiro.get_defesa();
    CHECK_EQ (defesa, 20);
    int hp = feiticeiro.get_hp();
    CHECK_EQ (hp, 200);
    int mp = feiticeiro.get_mp();
    CHECK_EQ (mp, 200); 
}