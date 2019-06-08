#include "doctest.h"

#include "Druida.h"


TEST_CASE("Testando o Construtor") {
    Druida druida ("Bran", 10, 15, 20);
    std::string nome = druida.get_nome();
    CHECK_EQ (nome, "Bran" );
    std::string nome_classe = druida.get_nome_classe();
    CHECK_EQ (nome_classe, "Druida");


    //checa atributos principais forca, agilidade, inteligencia
    int forca = druida.get_forca();
    CHECK_EQ (forca, 10);
    int agilidade = druida.get_agilidade();
    CHECK_EQ (agilidade, 15);
    int inteligencia = druida.get_inteligencia();
    CHECK_EQ (inteligencia, 20);

    //checa atributos secundarios, conforme classe
    int ataque = druida.get_ataque();
    CHECK_EQ (ataque , 100);
    int defesa = druida.get_defesa();
    CHECK_EQ (defesa, 20);
    int hp = druida.get_hp();
    CHECK_EQ (hp, 275);
    int mp = druida.get_mp();
    CHECK_EQ (mp, 200); 
}