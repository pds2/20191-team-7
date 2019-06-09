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

    //TESTA SE EXECUTA HABILIDADE COM HP == 0 (INIMIGO MORTO)
    retorno = paladino.usa_habilidade(2, 1, herois, vilao);
    CHECK (retorno == "Habilidade só pode ser usada em um inimigo que ainda esta vivo. Jon não conseguiu fazer nada.");
}   

TEST_CASE ("Teste: habilidade 'Fúria de Batalha'"){
    std::vector<Personagem*> herois;
    Guerreiro paladino ("Jon", 10, 10, 10);//Dano == 100, HP == 150
    herois = {&paladino};

    std::vector<Personagem*> vilao;
    Guerreiro doMal ("Dark", 10, 0, 30);//HP == 250
    vilao = {&doMal};
    int hp_vilao;

    //TESTA SE HABILIDADE DOBRA O DANO
    paladino.usa_habilidade(3, 1, herois, vilao);//hp do paladino passa a ser 50
    hp_vilao = doMal.get_hp();
    CHECK (hp_vilao == 50);

    //TESTA SE EXECUTA HABILIDADE COM MENOS HP QUE O NECESSARIO (HP>dano);
    //HP MENOR QUE DANO
    std::string hp_insuficiente = paladino.usa_habilidade(3, 1, herois, vilao);
    CHECK ( hp_insuficiente == "HP insuficiente para realizar este ataque. Jon não conseguiu fazer nada.");
    //HP IGUAL AO DANO
    paladino.set_hp(100); 
    hp_insuficiente = paladino.usa_habilidade(3, 1, herois, vilao);
    CHECK ( hp_insuficiente == "HP insuficiente para realizar este ataque. Jon não conseguiu fazer nada.");
    

    //TESTA SE HABILIDADE MATA INIMIGO
    paladino.set_hp(150);
    paladino.usa_habilidade(3, 1, herois, vilao);
    bool vivo = doMal.get_vivo();
    CHECK (vivo == false);

    //TESTA SE HABILIDADE EH ATIVADA CONTRA INIMIGO MORTO
    paladino.set_hp(150);
    std::string inimigo_morto = paladino.usa_habilidade(3, 1, herois, vilao);
    CHECK (inimigo_morto == "Habilidade só pode ser usada em um inimigo que ainda esta vivo. Jon não conseguiu fazer nada.");
}