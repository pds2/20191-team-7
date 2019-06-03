#include "doctest.h"

#include "Guerreiro.h"

TEST_CASE("Testando o Construtor") {
    Guerreiro guerreiro ("Jaime", 10, 15, 20);
    std::string nome = guerreiro.get_nome();
    CHECK_EQ (nome, "Jaime" );
    std::string nome_classe = guerreiro.get_nome_classe();
    CHECK_EQ (nome_classe, "guerreiro");


    //checa atributos principais forca, agilidade, inteligencia
    int forca = guerreiro.get_forca();
    CHECK_EQ (forca, 10);
    int agilidade = guerreiro.get_agilidade();
    CHECK_EQ (agilidade, 15);
    int inteligencia = guerreiro.get_inteligencia();
    CHECK_EQ (inteligencia, 20);

    //checa atributos secundarios, conforme classe
    int ataque = guerreiro.get_ataque();
    CHECK_EQ (ataque , 100);
    int defesa = guerreiro.get_defesa();
    CHECK_EQ (defesa, 20);
    int hp = guerreiro.get_hp();
    CHECK_EQ (hp, 200);
    int mp = guerreiro.get_mp();
    CHECK_EQ (mp, 200); 
}