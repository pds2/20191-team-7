#include "doctest.h"

#include "Mercenario.h"

TEST_CASE("Testando o Construtor") {
    Mercenario mercenario ("Clegane", 10, 15, 20);
    std::string nome = mercenario.get_nome();
    CHECK_EQ (nome, "Clegane" );
    std::string nome_classe = mercenario.get_nome_classe();
    CHECK_EQ (nome_classe, "mercenário");


    //checa atributos principais forca, agilidade, inteligencia
    int forca = mercenario.get_forca();
    CHECK_EQ (forca, 10);
    int agilidade = mercenario.get_agilidade();
    CHECK_EQ (agilidade, 15);
    int inteligencia = mercenario.get_inteligencia();
    CHECK_EQ (inteligencia, 20);

    //checa atributos secundarios, conforme classe
    int ataque = mercenario.get_ataque();
    CHECK_EQ (ataque , 100);
    int defesa = mercenario.get_defesa();
    CHECK_EQ (defesa, 20);
    int hp = mercenario.get_hp();
    CHECK_EQ (hp, 200);
    int mp = mercenario.get_mp();
    CHECK_EQ (mp, 200); 
}