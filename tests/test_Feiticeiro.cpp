#include "doctest.h"

#include "Feiticeiro.h"

TEST_CASE("Testando o Construtor") {
    Feiticeiro feiticeiro ("Tyrell", 10, 15, 20);
    std::string nome = feiticeiro.get_nome();
    CHECK_EQ (nome, "Tyrell" );
    std::string nome_classe = feiticeiro.get_nome_classe();
    CHECK_EQ (nome_classe, "Feiticeiro");


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
    CHECK_EQ (hp, 275);
    int mp = feiticeiro.get_mp();
    CHECK_EQ (mp, 200); 
}

TEST_CASE ("Teste: habilidade 'Bola de Fogo'  (ataque em area)"){
    Feiticeiro feiticeiro("Tyrell", 10, 15, 20);
    std::vector<Personagem*> heroi;
    heroi.push_back(&feiticeiro);
    //Inimigos HP = 200
    Feiticeiro inimigo1 ("Artur", 10, 10, 10);
    Feiticeiro inimigo2 ("Breno", 10, 10, 10);
    Feiticeiro inimigo3 ("Douglas", 10, 10, 10);
    std::vector<Personagem*>viloes;
    viloes = {&inimigo1, &inimigo2, &inimigo3};
    //Dano em area = 40;
    feiticeiro.usa_habilidade(1, 1, heroi, viloes);
    int hp1, hp2, hp3;
    hp1 = inimigo1.get_hp();
    hp2 = inimigo2.get_hp();
    hp3 = inimigo3.get_hp();
    CHECK (hp1 == 160);
    CHECK (hp2 == 160);
    CHECK (hp3 == 160);

    
}