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

    //DANO EM AREA
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

    //EXECUTA MAGIA COM MP == 25 (custo da habilidade)
    feiticeiro.set_mp(25);
    feiticeiro.usa_habilidade(1, 1, heroi, viloes);
    hp1 = inimigo1.get_hp();
    hp2 = inimigo2.get_hp();
    hp3 = inimigo3.get_hp();
    CHECK (hp1 == 120);
    CHECK (hp2 == 120);
    CHECK (hp3 == 120);

    //NAO EXECUTA MAGIA COM MP < 25
    feiticeiro.set_mp(24);
    std::string sem_mp = feiticeiro.usa_habilidade(1, 1, heroi, viloes);
    CHECK (sem_mp == "Energia insuficiente para usar esta habilidade. Tyrell desperdiçou sua vez.");
    
    //DANO EM AREA APENAS NOS INIMIGOS VIVOS
    feiticeiro.set_mp(100);
    inimigo1.set_vivo_morto(false);//inimigo1 _vivo == false, _hp == 120;
    feiticeiro.usa_habilidade(1, 1, heroi, viloes);
    hp1 = inimigo1.get_hp();
    hp2 = inimigo2.get_hp();
    hp3 = inimigo3.get_hp();
    CHECK (hp1 == 120);
    CHECK (hp2 == 80);
    CHECK (hp3 == 80);

    
}

TEST_CASE ("Teste: habilidade 'Drenar Energia"){
    // fator drena 20% do HP e MP inimigo, custo da habilidade = 30 MP
    Feiticeiro feiticeiro("Tyrell", 10, 10, 10);// HP == 200, MP == 100 
    std::vector<Personagem*> heroi;
    heroi.push_back(&feiticeiro);
    feiticeiro.set_hp(100);
    feiticeiro.set_mp(50);

    Feiticeiro inimigo ("Artur", 10, 10, 10); // HP == 200, MP == 100
    std::vector<Personagem*>vilao;
    vilao.push_back(&inimigo);

    //TESTA SE RECUPERA HP E MP DO HEROI E INFLIGE DANO AO INIMIGO
    feiticeiro.usa_habilidade(2, 1, heroi, vilao);//suga 40 de HP e 20 de MP
    int hp_feiticeiro, mp_feiticeiro, hp_inimigo, mp_inimigo;
    hp_feiticeiro = feiticeiro.get_hp();
    CHECK(hp_feiticeiro == 140);
    mp_feiticeiro = feiticeiro.get_mp();
    CHECK(mp_feiticeiro == 50);
    hp_inimigo = inimigo.get_hp();
    CHECK(hp_inimigo == 160);
    mp_inimigo = inimigo.get_mp();
    CHECK(mp_inimigo == 80); 

 




}
