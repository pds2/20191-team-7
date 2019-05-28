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
    _grupo_blue = grupo_a;
    _grupo_red = grupo_b;
    _partida_terminou = false;
}

void Partida::inicia(){
    refresh_tela();

    std::cout << RESETCOLOR << "Nova partida iniciada." << std::endl;
    cor_jogador_atual();

    //cria um vetor de apontadores para personagens e ordena o mesmo por agilidade
    std::vector <Personagem*> ordem = determina_ordem();    

    while (!_partida_terminou){

        //inicia um turno
        turno(ordem);

        //confere se a partida terminou
        _partida_terminou = terminou();
    }
    std::cout << RESETCOLOR;
    std::cout << "Partida encerrada." << std::endl;

}

std::vector <Personagem*> Partida::determina_ordem(){
    std::vector <Personagem*> ordem;
    for (unsigned int i = 0; i < _grupo_blue.size(); i++){
        _grupo_blue[i].set_grupo('b');
        ordem.push_back(&_grupo_blue[i]);
    }
    for (unsigned int i = 0; i < _grupo_red.size(); i++){
        _grupo_red[i].set_grupo('r');
        ordem.push_back(&_grupo_red[i]);
    }

    //TODO:nescessario ordenar esse vetor pela quantidade de agilidade dos Personagens para o qual ele aponta
    std::sort(ordem.begin(), ordem.end(), compara_agilidade);

    return ordem;
}

void Partida::turno(std::vector <Personagem*> ordem){

    for (unsigned int i = 0; i < ordem.size(); i++){
        _partida_terminou = terminou();
        if (_partida_terminou){
            return;
        }

        //imprime o texto de cada grupo com cor diferente
        if(ordem[i]->get_grupo() == 'b'){
            std::cout << BLUE;
            _grupo_que_estajogando = 'b';
        }
        else{
            std::cout << RED;
            _grupo_que_estajogando = 'r';      
        }

        //

        //permite que esse jogador escolha suas ações no turno
        std::cout << "Vez de " << ordem[i]->get_nome() << ". O que fazer?" << std::endl;  
        vez_do_personagem(*ordem[i], ordem[i]->get_grupo());
    }
    return;
}

void Partida::vez_do_personagem(Personagem p, char grupo_do_personagem){
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

//TODO: esta função esta repetindo o codigo, da pra melhorar
void Partida::atacando(Personagem p, char grupo_do_personagem){
    
    std::string alvo0;
    std::string alvo1;
    std::string alvo2;
    
    //caso esteja atacando os personagens do segundo grupo
    if (grupo_do_personagem == 'r'){
        std::vector <std::string> opcoes = {};
        for (unsigned int i = 0; i < _grupo_blue.size(); i++){
            opcoes.push_back(_grupo_blue[i].get_nome());
        }
        int escolha = submenu_partida(opcoes);

    //computa o ataque e imprime o resultado
    int dano = p.ataque_basico(&_grupo_blue[escolha-1]);
    refresh_tela();
    std::cout << p.get_nome() << " causou " << std::to_string(dano) << " de dano em " << _grupo_blue[escolha-1].get_nome() << ". ";
    if (_grupo_blue[escolha-1].morreu() == " morreu"){
            std::cout << _grupo_blue[escolha-1].get_nome() << " foi morto em combate.";
        }
        std::cout << std::endl;
    }

    //caso estaja atacando o primeiro grupo
    else{
        std::vector <std::string> opcoes = {};
        for (unsigned int i = 0; i < _grupo_red.size(); i++){
            opcoes.push_back(_grupo_red[i].get_nome());
        }

        int escolha = submenu_partida(opcoes);

        //computa o ataque e imprime o resultado
        int dano = p.ataque_basico(&_grupo_red[escolha-1]);
        refresh_tela();
        std::cout << p.get_nome() << " causou " << std::to_string(dano) << " de dano em " << _grupo_red[escolha-1].get_nome() << ". ";
        if (_grupo_red[escolha-1].morreu() == " morreu"){
            std::cout << _grupo_red[escolha-1].get_nome() << " foi morto em combate.";
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
    refresh_tela();
    return escolha;
}

bool Partida::terminou(){
    bool terminou_blue = true;
    bool terminou_red = true;

    for (unsigned int i = 0; i < _grupo_blue.size(); i++){
        if (_grupo_blue[i].get_vivo()){
            terminou_blue = false;
        }
    }
    for (unsigned int i = 0; i < _grupo_red.size(); i++){
        if (_grupo_red[i].get_vivo()){
            terminou_red = false;
        }
    }
    //se terminou para um dos dois grupos terminou para os dois
    return (terminou_red || terminou_blue);
}

void Partida::refresh_tela(){
    system("clear");
    std::cout << RESETCOLOR;
    for (unsigned int i = 0; i < _grupo_blue.size(); i++){
        std::cout << _grupo_blue[i].get_nome() << _grupo_blue[i].morreu() << std::endl;
    }
    std::cout << std::endl << "vs" << std::endl << std::endl;    
     for (unsigned int i = 0; i < _grupo_red.size(); i++){
        std::cout << _grupo_red[i].get_nome() << _grupo_red[i].morreu() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    cor_jogador_atual();
}

void Partida::cor_jogador_atual(){
    if (_grupo_que_estajogando == 'b'){
        std::cout << BLUE;
    }
    else std::cout << RED;
}
