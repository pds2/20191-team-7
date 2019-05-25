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

        escolhe_acao(_Grupo_a[i]);
    }
        for (unsigned int i = 0; i < _Grupo_b.size(); i++){
        std::cout << "Vez de " << _Grupo_b[i].get_nome() << ". O que fazer?" << std::endl;  

        escolhe_acao(_Grupo_b[i]);
    }
    return;
}

void Partida::escolhe_acao(Personagem p){
    //apresenta escolhas pro jogador
    int escolha = submenu_partida("Atacar", "Usar habilidade", "Passar vez");
    if (escolha == 1){
        std::cout << p.get_nome() << " vai atacar. Como atacar?" << std::endl;
        atacando(p);

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
    std::cout << _Grupo_a[0].get_nome() << " hp=" << _Grupo_a[0].get_hp() << std::endl;
    std::cout << _Grupo_a[1].get_nome() << " hp=" << _Grupo_a[1].get_hp() << std::endl;
    std::cout << _Grupo_a[2].get_nome() << " hp=" << _Grupo_a[2].get_hp() << std::endl;
    std::cout << std::endl << "vs" << std::endl;    
    std::cout << _Grupo_b[0].get_nome() << " hp=" << _Grupo_b[0].get_hp() << std::endl;
    std::cout << _Grupo_b[1].get_nome() << " hp=" << _Grupo_b[1].get_hp() << std::endl;
    std::cout << _Grupo_b[2].get_nome() << " hp=" << _Grupo_b[2].get_hp() << std::endl;
    std::cout << std::endl << "---------------------" << std::endl;  
}

void Partida::atacando(Personagem p){
    int escolha = submenu_partida("Ataque basico", "Ataque especial", "Ataque de área");
    if (escolha == 1){
        std::cout << p.get_nome() << " tentou um Ataque basico" << std::endl;
    }
    if (escolha == 2){
        std::cout << p.get_nome() << " Ataque especial." << std::endl;

    }
    if (escolha == 3){
        std::cout << p.get_nome() << " Ataque de área." << std::endl;
    }
    return;

}

void Partida::usando_habilidade(Personagem p){
    int escolha = submenu_partida("Hadouken", "Primeiros socorros", "Mind Control");
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

int Partida::submenu_partida(std::string opcao_1, std::string opcao_2, std::string opcao_3){
    std::cout << "1." << opcao_1 << std::endl;
    std::cout << "2." << opcao_2 << std::endl;
    std::cout << "3." << opcao_3 << std::endl;

    int escolha = 0;
    std::cin >> escolha;
    if (escolha == 1 || escolha == 2 || escolha == 3){
        refresh_tela();
        return escolha;
    }
    while (!(escolha == 1 || escolha == 2 || escolha == 3)){
        refresh_tela();
        std::cout << "Opção inválida, tente novamente:" << std::endl;
        std::cout << "1." << opcao_1 << std::endl;
        std::cout << "2." << opcao_2 << std::endl;
        std::cout << "3." << opcao_3 << std::endl;
        std::cin >> escolha;
    }
    refresh_tela();
    return escolha;
}