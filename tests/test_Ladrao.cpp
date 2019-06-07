/*#include "doctest.h"

#include "Ladrao.h"

TEST_CASE("Testando o Construtor") {
    Ladrao ladrao ("Davos", 10, 15, 20);
    std::string nome = ladrao.get_nome();
    CHECK_EQ (nome, "Davos" );
    std::string nome_classe = ladrao.get_nome_classe();
    CHECK_EQ (nome_classe, "ladrao");


    //checa atributos principais forca, agilidade, inteligencia
    int forca = ladrao.get_forca();
    CHECK_EQ (forca, 10);
    int agilidade = ladrao.get_agilidade();
    CHECK_EQ (agilidade, 15);
    int inteligencia = ladrao.get_inteligencia();
    CHECK_EQ (inteligencia, 20);

    //checa atributos secundarios, conforme classe
    int ataque = ladrao.get_ataque();
    CHECK_EQ (ataque , 100);
    int defesa = ladrao.get_defesa();
    CHECK_EQ (defesa, 20);
    int hp = ladrao.get_hp();
    CHECK_EQ (hp, 200);
    int mp = ladrao.get_mp();
    CHECK_EQ (mp, 200); 
}*/