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
    CHECK_EQ (hp, 275);
    int mp = guerreiro.get_mp();
    CHECK_EQ (mp, 200); 
}

TEST_CASE ("Teste: habilidade 'Primeiro Socorros'"){
    //a habilidade cura 25% do HP maximo do personagem
    std::vector<Personagem*> teste;
    Guerreiro guerreiro ("Jon", 10, 10, 10); //HP do heroi = 200
    teste = {&guerreiro};
    int hp = guerreiro.get_hp();
    CHECK( hp == 200);

    //usar 'Primeiros Socorros com HP cheio, nao deve fazer nada
    guerreiro.usa_habilidade(1, 1, teste, teste);
    hp = guerreiro.get_hp();
    CHECK(hp == 200);
    
    //HP == 100, apos cura HP == 150
    guerreiro.diminui_hp(100);
    guerreiro.usa_habilidade(1, 1, teste, teste);
    hp = guerreiro.get_hp();
    CHECK ( hp == 150);

}

TEST_CASE ("Teste: habilidade 'Execução'"){
    std::vector<Personagem*> herois;
    Guerreiro paladino ("Jon", 10, 10, 10);
    herois = {&paladino};

    std::vector<Personagem*> vilao;
    Guerreiro doMal ("Dark", 10, 10, 10);//HP == 200
    vilao = {&doMal};
    bool vivo = doMal.get_vivo(); 

    //TESTA SE A HABILIDADE NAO EH EXECUTADA (HP = 100%) E SE NAO MATA O INIMIGO 
    std::string retorno = paladino.usa_habilidade(2, 1, herois, vilao);
    CHECK (retorno == "Ainda não é possivel executar este inimgo.");
    CHECK(vivo == true);
    
    //TESTA SE EXECUTA HABILIDADE (HP >= 25%)
    doMal.diminui_hp(150);
    retorno = paladino.usa_habilidade(2, 1, herois, vilao);
    CHECK (retorno == "Ainda não é possivel executar este inimgo.");
    CHECK(vivo == true);
    
    //TESTA SE EXECUTA HABILIDADE COM HP < 25% E MATA O INIMIGO
    doMal.diminui_hp(1); //HP == 49 (24,5% de HP)
    retorno = paladino.usa_habilidade(2, 1, herois, vilao);
    CHECK (retorno == "Dark foi executado. Jon gastou toda sua energia ao fazer isso.");
    vivo = doMal.get_vivo();
    CHECK(vivo == false);
}   

TEST_CASE ("Teste: habilidade 'Fúria de Batalha'"){
    
}