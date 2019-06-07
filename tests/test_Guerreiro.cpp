#include "doctest.h"

#include "Guerreiro.h"

TEST_CASE("Testando o Construtor") {
    Guerreiro guerreiro ("Jaime", 10, 15, 20);
    std::string nome = guerreiro.get_nome();
    CHECK_EQ (nome, "Jaime" );
    std::string nome_classe = guerreiro.get_nome_classe();
    CHECK_EQ (nome_classe, "Guerreiro");


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

TEST_CASE ("Teste: habilidade 'Primeiro Socorros'"){
    //a habilidade cura 25% do HP
    std::vector<Personagem*> teste;
    Guerreiro guerreiro ("Jon", 10, 10, 10); //HP do heroi = 200
    teste = {&guerreiro};
    int hp = guerreiro.get_hp();
    CHECK( hp == 200);

    //usar 'Primeiros Socorros com HP cheio, nao deve fazer nada
    guerreiro.usa_habilidade(1, teste, teste);
    hp = guerreiro.get_hp();
    CHECK(hp == 200);
    
    //HP == 100, apos cura HP == 125
    guerreiro.diminui_hp(100);
    guerreiro.usa_habilidade(1, teste, teste);
    hp = guerreiro.get_hp();
    CHECK ( hp == 125);

}

TEST_CASE ("Teste: habilidade 'Execução'"){

}

TEST_CASE ("Teste: habilidade 'Fúria de Batalha'"){
    
}