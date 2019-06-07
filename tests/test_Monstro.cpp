#include "doctest.h"

#include "Monstro.h"

TEST_CASE("Testando o Construtor") {
    Monstro Monstro ("Clegane", 10, 15, 20);
    std::string nome = Monstro.get_nome();
    CHECK_EQ (nome, "Clegane" );
    std::string nome_classe = Monstro.get_nome_classe();
//    CHECK_EQ (nome_classe, "mercenário");   DECIDIR SER IRA TER CLASSE DE MONSTRO SOMENTE COMO STRING


    //checa atributos principais forca, agilidade, inteligencia
    int forca = Monstro.get_forca();
    CHECK_EQ (forca, 10);
    int agilidade = Monstro.get_agilidade();
    CHECK_EQ (agilidade, 15);
    int inteligencia = Monstro.get_inteligencia();
    CHECK_EQ (inteligencia, 20);

    //checa atributos secundarios, conforme classe
    int ataque = Monstro.get_ataque();
    CHECK_EQ (ataque , 100);
    int defesa = Monstro.get_defesa();
    CHECK_EQ (defesa, 20);
    int hp = Monstro.get_hp();
    CHECK_EQ (hp, 200);
    int mp = Monstro.get_mp();
    CHECK_EQ (mp, 200); 
}