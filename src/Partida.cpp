#include <Partida.h>

Partida::Partida(Personagem a0,Personagem a1, Personagem a2, Personagem b0, Personagem b1, Personagem b2){
    _Grupo_a.push_back(a0);
    _Grupo_a.push_back(a1);
    _Grupo_a.push_back(a2);
    _Grupo_b.push_back(b0);
    _Grupo_b.push_back(b1);
    _Grupo_b.push_back(b2);
    _partida_terminou = false;
}

void Partida::inicia(){
    refresh_tela();

    std::cout << "Nova partida iniciada." << std::endl;  
    while (!_partida_terminou){
        turno();

        std::cout << "Partida encerrada." << std::endl;
        _partida_terminou = true;
    }

}

void Partida::turno(){
    for (unsigned int i = 0; i < _Grupo_a.size(); i++){
        std::cout << "Vez de " << _Grupo_a[i].get_nome() << ". O que fazer?" << std::endl;  

        escolhe_acao(_Grupo_a[i], 'a');
    }
        for (unsigned int i = 0; i < _Grupo_b.size(); i++){
        std::cout << "Vez de " << _Grupo_b[i].get_nome() << ". O que fazer?" << std::endl;  

        escolhe_acao(_Grupo_b[i], 'b');
    }
    return;
}

void Partida::escolhe_acao(Personagem p, char grupo_do_personagem){
    //apresenta escolhas pro jogador
    std::vector <std::string> opcoes = {"Atacar", "Usar habilidade", "Passar vez"};
    int escolha = submenu_partida(opcoes);
    if (escolha == 1){
        std::cout << p.get_nome() << " vai atacar. Quem atacar?" << std::endl;
        atacando(p, grupo_do_personagem);

    }
    if (escolha == 2){
        std::cout << p.get_nome() << " vai usar uma habilidade especial." << std::endl;
        usando_habilidade(p);

    }
    if (escolha == 3){
        std::cout << p.get_nome() << " passou a vez." << std::endl;
    }
    return;
}

void Partida::refresh_tela(){
    system("clear");
    std::cout << _Grupo_a[0].get_nome() << _Grupo_a[0].morreu() << std::endl;
    std::cout << _Grupo_a[1].get_nome() << _Grupo_a[1].morreu() << std::endl;
    std::cout << _Grupo_a[2].get_nome() << _Grupo_a[2].morreu() << std::endl;
    std::cout << std::endl << "vs" << std::endl << std::endl;    
    std::cout << _Grupo_b[0].get_nome() << _Grupo_b[0].morreu() << std::endl;
    std::cout << _Grupo_b[1].get_nome() << _Grupo_b[1].morreu() << std::endl;
    std::cout << _Grupo_b[2].get_nome() << _Grupo_b[2].morreu() << std::endl;
    std::cout << std::endl << "---------------------" << std::endl;  
}

void Partida::atacando(Personagem p, char grupo_do_personagem){
    
    std::string alvo0;
    std::string alvo1;
    std::string alvo2;
    
    //caso esteja atacando os personagens do segundo grupo
    if (grupo_do_personagem == 'b'){
        alvo0 = _Grupo_a[0].get_nome();
        alvo1 = _Grupo_a[1].get_nome();
        alvo2 = _Grupo_a[2].get_nome();

        std::vector <std::string> opcoes = {alvo0, alvo1, alvo2};
        int escolha = submenu_partida(opcoes);

    //computa o ataque e imprime o resultado
    int dano = p.ataque_basico(&_Grupo_a[escolha-1]);
    refresh_tela();
    std::cout << p.get_nome() << " causou " << std::to_string(dano) << " de dano em " << _Grupo_a[escolha-1].get_nome() << ". ";
    if (_Grupo_a[escolha-1].morreu() == " morreu"){
            std::cout << _Grupo_a[escolha-1].get_nome() << " foi morto em combate.";
        }
        std::cout << std::endl;
    }

    //caso estaja atacando o primeiro grupo
    else{
        alvo0 = _Grupo_b[0].get_nome();
        alvo1 = _Grupo_b[1].get_nome();
        alvo2 = _Grupo_b[2].get_nome();

        std::vector <std::string> opcoes = {alvo0, alvo1, alvo2};
        int escolha = submenu_partida(opcoes);

        //computa o ataque e imprime o resultado
        int dano = p.ataque_basico(&_Grupo_b[escolha-1]);
        refresh_tela();
        std::cout << p.get_nome() << " causou " << std::to_string(dano) << " de dano em " << _Grupo_b[escolha-1].get_nome() << ". ";
        if (_Grupo_b[escolha-1].morreu() == " morreu"){
            std::cout << _Grupo_b[escolha-1].get_nome() << " foi morto em combate.";
        }
        std::cout << std::endl;
    }
    return;

}

void Partida::usando_habilidade(Personagem p){
    std::vector <std::string> opcoes = {"Hadouken", "Primeiros socorros", "Mind Control"};
    int escolha = submenu_partida(opcoes);
    if (escolha == 1){
        std::cout << p.get_nome() << " usou Hadouken" << std::endl;
    }
    if (escolha == 2){
        std::cout << p.get_nome() << " usou Primeiros socorros." << std::endl;

    }
    if (escolha == 3){
        std::cout << p.get_nome() << " usou Mind Control." << std::endl;
    }
    return;

}

int Partida::submenu_partida(std::vector <std::string> opcoes){
    for (unsigned int i = 0; i < opcoes.size(); i++){
        std::cout << i+1 << ". " << opcoes[i] << std::endl;
    }
    unsigned int escolha = -1;
    std::cin >> escolha;

    if (escolha <= opcoes.size() && escolha > 0){
        refresh_tela();
        return escolha;
    }
    while (!(escolha <= opcoes.size() && escolha > 0)){
        refresh_tela();
        std::cout << "Opção inválida, tente novamente:" << std::endl;
        for (unsigned int i = 0; i < opcoes.size(); i++){
            std::cout << i+1 << ". " << opcoes[i] << std::endl;
        }
        std::cin >> escolha;
    }
    return escolha;
}
