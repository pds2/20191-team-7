#include <Partida.h>
#include <algorithm>

#define RESETCOLOR "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

//funcao auxiliar  para compara agilidade entre ponteiros de personagens
bool compara_agilidade(Personagem* a, Personagem* b){
    return (a->get_agilidade() > b->get_agilidade());
} 

Partida::Partida(std::vector <Personagem> grupo_a, std::vector <Personagem> grupo_b){
    _Grupo_a = grupo_a;
    _Grupo_b = grupo_b;
    _partida_terminou = false;
}

void Partida::inicia(){
    refresh_tela();
    std::cout << "Nova partida iniciada." << std::endl; 

    //cria um vetor de apontadores na ordem certa
    std::vector <Personagem*> ordem = determina_ordem();    

    while (!_partida_terminou){
        turno(ordem);

        std::cout << "Partida encerrada." << std::endl;
        _partida_terminou = true;
    }

}

std::vector <Personagem*> Partida::determina_ordem(){
    std::vector <Personagem*> ordem;
    for (unsigned int i = 0; i < _Grupo_a.size(); i++){
        _Grupo_a[i].set_grupo('a');
        ordem.push_back(&_Grupo_a[i]);
    }
    for (unsigned int i = 0; i < _Grupo_b.size(); i++){
        _Grupo_b[i].set_grupo('b');
        ordem.push_back(&_Grupo_b[i]);
    }

    //TODO:nescessario ordenar esse vetor pela quantidade de agilidade dos Personagens para o qual ele aponta
    std::sort(ordem.begin(), ordem.end(), compara_agilidade);

    return ordem;
}

void Partida::turno(std::vector <Personagem*> ordem){

    for (unsigned int i = 0; i < ordem.size(); i++){

        //imprime o texto de cada grupo com cor diferente
        if(ordem[i]->get_grupo() == 'a'){
            std::cout << BLUE;
            _grupo_que_estajogando = 'a';
        }
        else{
            std::cout << RED;
            _grupo_que_estajogando = 'b';      
        }

        //

        //permite que esse jogador escolha suas ações no turno
        std::cout << "Vez de " << ordem[i]->get_nome() << ". O que fazer?" << std::endl;  
        escolhe_acao(*ordem[i], ordem[i]->get_grupo());
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

void Partida::atacando(Personagem p, char grupo_do_personagem){
    
    std::string alvo0;
    std::string alvo1;
    std::string alvo2;
    
    //caso esteja atacando os personagens do segundo grupo
    if (grupo_do_personagem == 'b'){
        std::vector <std::string> opcoes = {};
        for (unsigned int i = 0; i < _Grupo_a.size(); i++){
            opcoes.push_back(_Grupo_a[i].get_nome());
        }
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
        std::vector <std::string> opcoes = {};
        for (unsigned int i = 0; i < _Grupo_b.size(); i++){
            opcoes.push_back(_Grupo_b[i].get_nome());
        }

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

void Partida::refresh_tela(){
    system("clear");
    std::cout << RESETCOLOR;
    for (unsigned int i = 0; i < _Grupo_a.size(); i++){
        std::cout << _Grupo_a[i].get_nome() << _Grupo_a[i].morreu() << std::endl;
    }
    std::cout << std::endl << "vs" << std::endl << std::endl;    
     for (unsigned int i = 0; i < _Grupo_b.size(); i++){
        std::cout << _Grupo_b[i].get_nome() << _Grupo_b[i].morreu() << std::endl;
    }
    std::cout << std::endl << "---------------------" << std::endl;
    if (_grupo_que_estajogando == 'a'){
        std::cout << BLUE;
    }
    else std::cout << RED;
}

