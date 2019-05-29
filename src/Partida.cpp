#include "Partida.h"
#include <algorithm>
#include <cmath>
#include "time.h"

// Cores usadas
#define RESETCOLOR   "\033[0m"
#define BOLDGREEN    "\033[1m\033[32m"
#define BOLDBLUE     "\033[1m\033[34m"
#define BOLDMAGENTA  "\033[1m\033[35m"
#define BOLDRED      "\033[1m\033[31m"

// Cores ainda não usadas (deletar no final)
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

// Funcao auxiliar  para compara agilidade entre ponteiros de personagens
bool compara_agilidade(Personagem* a, Personagem* b){
    return (a->get_agilidade() > b->get_agilidade());
}

Partida::Partida(std::vector <Personagem> grupo_a, std::vector <Personagem> grupo_b, int modo_de_jogo){
    _grupo_blue = grupo_a;
    _grupo_red = grupo_b;
    _partida_terminou = false;
    _modo_de_jogo = modo_de_jogo;
}

void Partida::inicia(){
    refresh_tela();
    std::cout << "Nova partida iniciada." << std::endl;
    std::cout << "Aperte Enter para continuar..." << std::endl;
    std::getchar();
    refresh_tela();

    // Cnicializa random seed para geração de números aleatórios
    srand(time(NULL));

    // Cria um vetor de apontadores para personagens e ordena o mesmo por agilidade
    std::vector <Personagem*> ordem = determina_ordem();

    // Chama um novo turno até a partida terminar
    while (!_partida_terminou){
        //inicia um turno
        turno(ordem);
    }
    std::cout << "Partida encerrada." << std::endl;
}

std::vector <Personagem*> Partida::determina_ordem(){
    // Unifica os dois grupos da partida em um vetor de apontadores para personagens
    std::vector <Personagem*> ordem;
    for (unsigned int i = 0; i < _grupo_blue.size(); i++) {
        _grupo_blue[i].set_grupo('b');
        ordem.push_back(&_grupo_blue[i]);
    }
    for (unsigned int i = 0; i < _grupo_red.size(); i++) {
        _grupo_red[i].set_grupo('r');
        ordem.push_back(&_grupo_red[i]);
    }

    // Ordena esse vetor por agilidade dos personagens
    std::sort(ordem.begin(), ordem.end(), compara_agilidade);

    // Retorna o vetor ordenado
    return ordem;
}

void Partida::turno(std::vector <Personagem*> ordem) {
    for (unsigned int i = 0; i < ordem.size(); i++) {

        // Confere se a partida já terminou antes da vez do personagem
        _partida_terminou = terminou();
        if (_partida_terminou) {
            return;
        }

        // Chama a função que permite o personagem agir no turno
        if (ordem[i]->get_vivo()) {
            // Caso controlado pela a CPU
            if (_modo_de_jogo == 2 && ordem[i]->get_grupo() == 'r') {
                vez_da_cpu(*ordem[i]);
            }
            // Caso seja controlado por um jogador
            else {
                std::cout << "Vez de " << ordem[i]->get_nome() << ". O que fazer?" << std::endl;
                vez_do_personagem(*ordem[i]);
            }
        }
    }
    return;
}

void Partida::vez_do_personagem(Personagem p){
    std::vector <std::string> opcoes = {"Atacar", "Usar habilidade", "Passar vez"};
    int escolha = submenu_partida(opcoes);
    if (escolha == 1){
        std::cout << p.get_nome() << " vai atacar. Quem atacar?" << std::endl;
        if (p.get_grupo()=='b'){
            atacando(p, _grupo_red);
        }
        else atacando(p, _grupo_blue);

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

void Partida::atacando(Personagem p, std::vector <Personagem> &grupo_inimigo) {
    // Caso esteja atacando os personagens do segundo grupo
    std::vector <std::string> opcoes = {};
    for (unsigned int i = 0; i < grupo_inimigo.size(); i++){
        opcoes.push_back(grupo_inimigo[i].get_nome());
    }
    int escolha = submenu_partida(opcoes);

    // Computa o ataque e imprime o resultado
    while(!grupo_inimigo[escolha-1].get_vivo()){
        std::cout << p.get_nome() << "Esse inimigo ja esta morto, ataque outro!" << std::endl;
        escolha = submenu_partida(opcoes);
    }

        int dano = p.ataque_basico(&grupo_inimigo[escolha-1]);
        refresh_tela();
        std::cout << p.get_nome() << " causou " << std::to_string(dano) << " de dano em " << grupo_inimigo[escolha-1].get_nome() << ". ";

        // Informa caso o personagem tenha morrido
        if (!(grupo_inimigo[escolha-1].get_vivo())){
            std::cout << grupo_inimigo[escolha-1].get_nome() << " foi morto em combate.";
        }


    std::cout << std::endl;
    return;
}

// Ataque da CPU
void Partida::atacando(Personagem atacante, std::vector <Personagem> &grupo_inimigo, int inimigo_atacado) {
    int dano = atacante.ataque_basico(&grupo_inimigo[inimigo_atacado]);

    std::cout << atacante.get_nome() << " atacou e causou " << std::to_string(dano) << " de dano em " << grupo_inimigo[inimigo_atacado].get_nome() << ". ";

    //informa caso o personagem tenha morrido
    if (!(grupo_inimigo[inimigo_atacado].get_vivo())){
        std::cout << grupo_inimigo[inimigo_atacado].get_nome() << " foi morto em combate.";
    }

    std::cout << std::endl;
    std::cout << "Aperte Enter para continuar..." << std::endl;
    std::getchar();
    refresh_tela();
    return;
}


// TODO: não implementada, as escolhas não fazem nada
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
    std::string buffer;
    unsigned int escolha = -1;
    char c;

    // Imprime na tela as opções
    for (unsigned int i = 0; i < opcoes.size(); i++) {
        std::cout << i+1 << ". " << opcoes[i] << std::endl;
    }

    // Recebe a entrada do jogador
    std::getline (std::cin,buffer);
    if (!buffer.empty()){
        c = buffer.at(0);
        escolha = atoi(&c);
    }

     // Se o jogador fez uma escolha valida retorna o resultado
    if (escolha <= opcoes.size() && escolha > 0) {
        refresh_tela();
        return escolha;
    }

    // Em caso de escolha inválida, repete as opções
    while (!(escolha <= opcoes.size() && escolha > 0)) {
        refresh_tela();
        std::cout << "Opção inválida, tente novamente:" << std::endl;
        for (unsigned int i = 0; i < opcoes.size(); i++) {
            std::cout << i+1 << ". " << opcoes[i] << std::endl;
        }

        // Recebe a entrada do jogador.
        std::getline (std::cin,buffer);
        if (!buffer.empty()){
            c = buffer.at(0);
            escolha = atoi(&c);
        }
    }
    refresh_tela();
    return escolha;
}

bool Partida::terminou() {
    bool terminou_blue = true;
    bool terminou_red = true;

    // Confere se tem alguem vivo no primeiro grupo
    for (unsigned int i = 0; i < _grupo_blue.size(); i++) {
        if (_grupo_blue[i].get_vivo()) {
            terminou_blue = false;
        }
    }

    // Confere se tem alguem vivo no segundo grupo
    for (unsigned int i = 0; i < _grupo_red.size(); i++) {
        if (_grupo_red[i].get_vivo()){
            terminou_red = false;
        }
    }

    // Informa se um time perdeu
    if(terminou_blue) {
        std::cout << "O time azul foi derrotado!" << std::endl;
    }
    if(terminou_red) {
        std::cout << "O time vermelho foi derrotado!" << std::endl;
    }

    // Se terminou para um dos dois grupos terminou a partida
    return (terminou_red || terminou_blue);
}

void Partida::refresh_tela(){
    // Limpa a tela
    system("clear");

    // Imprime na tela os jogadores da partida dividios em dois times
    for (unsigned int i = 0; i < _grupo_blue.size(); i++) {
        std::cout << BOLDBLUE << _grupo_blue[i].get_nome() << " " << RESETCOLOR;
        if (_grupo_blue[i].get_vivo()) {
            std::cout << " hp:" << BOLDGREEN << _grupo_blue[i].get_hp();
            reseta_cor();
            std::cout << "  mp:" << BOLDMAGENTA << _grupo_blue[i].get_mp();
            reseta_cor();
        }
        else std::cout << "morreu";
        std::cout << std::endl;
    }
    std::cout << std::endl << "vs" << std::endl << std::endl;
     for (unsigned int i = 0; i < _grupo_red.size(); i++) {
        std::cout << BOLDRED << _grupo_red[i].get_nome() << " " << RESETCOLOR;
        if (_grupo_red[i].get_vivo()) {
            std::cout << " hp:" << BOLDGREEN <<_grupo_red[i].get_hp();
            reseta_cor();
            std::cout << "  mp:" << BOLDMAGENTA <<_grupo_red[i].get_mp();
            reseta_cor();
        }
        else std::cout << "morreu";
        std::cout << std::endl;
    }
    std::cout << "-------------------" << std::endl;
}

void Partida::cor_jogador_atual() {
    if (_grupo_que_estajogando == 'b'){
        std::cout << BOLDBLUE;
    }
    else std::cout << BOLDRED;
}

void Partida::reseta_cor() {
    std::cout << RESETCOLOR;
}

void Partida::vez_da_cpu(Personagem p) {
    bool inimigo_vivo = false;
    int inimigo_atacado;

    //gra numero aleatório entre 1 e 100
    int random;
    random = rand() % 100 + 1;

    // Determina ação da CPU
    // 10% de chance de passar a vez
    if (random < 10) {
        std::cout << "CPU controlando " << p.get_nome() << " ficou confusa e passou a vez..." << std::endl;
        std::cout << "Aperte Enter para continuar..." << std::endl;
        std::getchar();
        refresh_tela();
    }
    // 20% de chance de usar habilidade especial
    else if(random > 80) {
        std::cout << "CPU controlando " << p.get_nome() << " usou habilidade." << std::endl;
        std::cout << "Aperte Enter para continuar..." << std::endl;
        std::getchar();
        refresh_tela();
    // 70% de chance de ataque normal
    } else {
        std::cout << "CPU controlando " << p.get_nome() << " decidiu atacar." << std::endl;


        // Seleciona um inimigo vivo para atacar
        while (!inimigo_vivo) {
            // Gera número aleatório entre 1 e 100
            random = rand() % 100 + 1;
            // Determina qual inimigo atacar com chances iguais entre cada uma das opções do grupo
            inimigo_atacado = std::floor(random*_grupo_blue.size() / 100);
            inimigo_vivo = _grupo_blue[inimigo_atacado].get_vivo();
        }

        atacando(p, _grupo_blue, inimigo_atacado);
    }
}
