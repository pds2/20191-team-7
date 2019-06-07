/*#include "doctest.h"

#include "Clerigo.h"

TEST_CASE("Testando o Construtor") {
    Clerigo clerigo ("Sam", 10, 15, 20);
    std::string nome = clerigo.get_nome();
    CHECK_EQ (nome, "Sam" );
    std::string nome_classe = clerigo.get_nome_classe();
    CHECK_EQ (nome_classe, "Clerigo");

    //checa atributos principais forca, agilidade, inteligencia
    int forca = clerigo.get_forca();
    CHECK_EQ (forca, 10);
    int agilidade = clerigo.get_agilidade();
    CHECK_EQ (agilidade, 15);
    int inteligencia = clerigo.get_inteligencia();
    CHECK_EQ (inteligencia, 20);

    //checa atributos secundarios, conforme classe
    int ataque = clerigo.get_ataque();
    CHECK_EQ (ataque , 100);
    int defesa = clerigo.get_defesa();
    CHECK_EQ (defesa, 20);
    int hp = clerigo.get_hp();
    CHECK_EQ (hp, 200);
    int mp = clerigo.get_mp();
    CHECK_EQ (mp, 200); 

}

*/