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

TEST_CASE ("Teste: habilidade 'Cura'"){ //habilidade recupera 70% do maximo
    Druida tester ("Bran", 10, 10, 10); //HP == 200
    std::vector<Personagem*> heroi = {&tester};
    Druida druid("Dark", 10, 10, 10);
    std::vector<Personagem*> heroi2;
    heroi2.push_back(&druid);

    //TESTA SE NAO RECUPERA VIDA COM HP == 100% E TEXTO CORRETO
    int hp_atual = tester.get_hp();
    std::string nao_cura = tester.habilidade_1(1, heroi);
    CHECK (nao_cura == "Bran usou Cura - e conseguiu aumentar em 0 o HP de Bran");
    CHECK (hp_atual == 200);

    //TESTA SE RECUPERA HP ATE O HP MAXIMO E TEXTO CORRETO
    tester.set_hp(199);
    nao_cura = tester.habilidade_1(1, heroi);
    hp_atual = tester.get_hp();
    CHECK(hp_atual == 200);
    CHECK(nao_cura == "Bran usou Cura e conseguiu aumentar em 1 o HP de Bran");

    //TESTA SE EXECUTA HABILIDADE EM PERSONAGEM MORTO
    druid.set_vivo_morto(false);
    nao_cura = tester.habilidade_1(1, heroi2);
    CHECK(nao_cura == "Dark está morto e não pode ser curado");

    //TESTA SE EXECUTA HABILIDADE SEM MP SUFICIENTE
    tester.set_mp(29);
    nao_cura = tester.habilidade_1(1, heroi2);
    CHECK (nao_cura == "Energia insuficiente para usar esta habilidade. Bran desperdiçou sua vez.");

}

TEST_CASE("Teste: habilidade 'Forma Animal' "){
    Druida tester ("Bran", 10, 10, 10); //HP == 200; ATAQUE == 100
    std::vector<Personagem*> heroi = {&tester};
    Druida inimigo("Dark", 10, 10, 10);// HP == 200
    std::vector<Personagem*> vilao;
    vilao.push_back(&inimigo);

    //TESTE SE HABILIDADE INCREMENTA O ATAQUE EM 60 E IMPRIME TEXTO CORRETO
    std::string ataque = tester.habilidade_2(1, vilao);
    int hp_vilao = inimigo.get_hp();
    CHECK (hp_vilao == 40);
    CHECK (ataque == "Bran se transformou em um urso e atacou Dark causando 160 de dano. ");

    //TESTE SE EXECUTA HABILIDADE SEM MP SUFICIENTE
    tester.set_mp(29);
    ataque = tester.habilidade_2(1, vilao);
    CHECK (ataque == "MP insuficiente para realizar este ataque. Bran não conseguiu fazer nada.");

    //TESTE SE HABILIDADE MATA INIMIGO
    tester.set_mp(100);
    inimigo.set_hp(1);
    ataque = tester.habilidade_2(1, vilao);
    bool inimigo_vivo = inimigo.get_vivo();
    CHECK (inimigo_vivo == false);
    CHECK (ataque == "Bran se transformou em um urso e atacou Dark causando 160 de dano. Dark foi morto.");

    //TESTE SE HABILIDADE EH EXECUTADA EM INIMIGO MORTO
    ataque = tester.habilidade_2(1, vilao);
    CHECK (ataque == "Habilidade só pode ser usada em um inimigo que ainda esta vivo. Bran não conseguiu fazer nada.");
}

TEST_CASE("Teste: habilidade 'Revitaliza' "){
    Druida tester ("Bran", 10, 10, 10); //HP == 200, 100 MP
    Druida amigo("Dark", 10, 10, 10);// HP == 200, 100 MP

    std::vector<Personagem*> herois = {&tester, &amigo};
    amigo.set_mp(0);

    //TESTA SE RECUPERA MP DE ALIADO
    std::string recupera_mp = tester.habilidade_3(2,herois);
    int mp_aliado = amigo.get_mp();
    CHECK (mp_aliado == 50);
    CHECK (recupera_mp == "Bran usou Revitaliza e conseguiu regenerar 50 do MP/EP de Dark");

    //TESTA SE UTILIZA EM SI MESMO
    tester.set_mp(100);
    tester.habilidade_3(1, herois);
    int mp = tester.get_mp();
    CHECK (mp == 100);

    //TESTA SE EXECUTA EM ALIADO MORTO
    amigo.set_vivo_morto(false);
    recupera_mp = tester.habilidade_3(2, herois);
    CHECK (recupera_mp == "Dark está morto e não pode ser revitalizado");

    //TESTA SE NAO EXECUTA HABILIDADE SEM MP SUFICIENTE E TEXTO CORRETO
    tester.set_mp(49);
    recupera_mp = tester.habilidade_3(1, herois);
    CHECK (recupera_mp == "MP insuficiente para usar esta habilidade. Bran desperdiçou sua vez.");
}
