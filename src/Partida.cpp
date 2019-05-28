#include <Partida.h>
#include <algorithm>
#include <cmath>

//Cores usadas
#define RESETCOLOR   "\033[0m"
#define BOLDGREEN    "\033[1m\033[32m" 
#define BOLDBLUE     "\033[1m\033[34m"
#define BOLDMAGENTA  "\033[1m\033[35m"
#define BOLDRED      "\033[1m\033[31m"

//cores ainda não usadas (deletar no final)
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

//funcao auxiliar  para compara agilidade entre ponteiros de personagens
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

    // Inicializa random seed para geração de números aleatórios
    srand (time(NULL));

    //cria um vetor de apontadores para personagens e ordena o mesmo por agilidade
    std::vector <Personagem*> ordem = determina_ordem();    

    //chama um novo turno até a partida terminar
    while (!_partida_terminou){
        //inicia um turno
        turno(ordem);
    }
    std::cout << "Partida encerrada." << std::endl;
}

std::vector <Personagem*> Partida::determina_ordem(){
    // Unifica os dois grupos em um vetor de apontadores para personagens
    std::vector <Personagem*> ordem;
    for (unsigned int i = 0; i < _grupo_blue.size(); i++) {
        _grupo_blue[i].set_grupo('b');
        ordem.push_back(&_grupo_blue[i]);
    }
    for (unsigned int i = 0; i < _grupo_red.size(); i++) {
        _grupo_red[i].set_grupo('r');
        ordem.push_back(&_grupo_red[i]);
    }

    //ordena esse vetor por agilidade dos personagens
    std::sort(ordem.begin(), ordem.end(), compara_agilidade);

    return ordem;
}

void Partida::turno(std::vector <Personagem*> ordem) {
    for (unsigned int i = 0; i < ordem.size(); i++) {
        _partida_terminou = terminou();
        if (_partida_terminou) {
            return;
        }

        // Permite que esse jogador escolha suas ações no turno
        if (ordem[i]->get_vivo()) {
            if (_modo_de_jogo == 2 && ordem[i]->get_grupo() == 'r') {
                vez_da_cpu(*ordem[i]);
            }
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
    if (!grupo_inimigo[escolha-1].get_vivo()){
        std::cout << p.get_nome() << " perdeu a vez atacando um inimigo que já estava morto";
    }
    else{
        int dano = p.ataque_basico(&grupo_inimigo[escolha-1]);
        refresh_tela();
        std::cout << p.get_nome() << " causou " << std::to_string(dano) << " de dano em " << grupo_inimigo[escolha-1].get_nome() << ". ";

        // Informa caso o personagem tenha morrido
        if (!(grupo_inimigo[escolha-1].get_vivo())){
            std::cout << grupo_inimigo[escolha-1].get_nome() << " foi morto em combate.";
        }
    }

    std::cout << std::endl;
    return;
}

// Ataque da CPU
void Partida::atacando(Personagem atacante, std::vector <Personagem> &grupo_inimigo, int inimigo_atacado) {
    int dano = atacante.ataque_basico(&grupo_inimigo[inimigo_atacado]);
    
    refresh_tela();
    std::cout << atacante.get_nome() << " causou " << std::to_string(dano) << " de dano em " << grupo_inimigo[inimigo_atacado].get_nome() << ". ";

    // Informa caso o personagem tenha morrido
    if (!(grupo_inimigo[inimigo_atacado].get_vivo())){
        std::cout << grupo_inimigo[inimigo_atacado].get_nome() << " foi morto em combate.";
    }

    std::cout << std::endl;
    std::cout << "Digite qualquer tecla para iniciar o próximo turno." << std::endl;
    std::getchar();

    return;
}


//TODO: não implementada, as escolhas não fazem nada
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
    // Imprime na tela as opções
    for (unsigned int i = 0; i < opcoes.size(); i++) {
        std::cout << i+1 << ". " << opcoes[i] << std::endl;
    }
    unsigned int escolha = -1;
    std::cin >> escolha;

    // Se o jogador fez uma escolha valida retorna o resultado
    if (escolha <= opcoes.size() && escolha > 0) {
        refresh_tela();
        return escolha;
    }

    // Em caso de escolha inválida, repete as opções até ser feita um escolha valida
    while (!(escolha <= opcoes.size() && escolha > 0)) {
        refresh_tela();
        std::cout << "Opção inválida, tente novamente:" << std::endl;
        for (unsigned int i = 0; i < opcoes.size(); i++) {
            std::cout << i+1 << ". " << opcoes[i] << std::endl;
        }
        std::cin >> escolha;
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

    // Informa que time perdeu
    if(terminou_blue) {
        std::cout << "O time azul foi derrotado!" << std::endl;
    }
    if(terminou_red) {
        std::cout << "O time vermelho foi derrotado!" << std::endl; 
    }

    // Se terminou para um dos dois grupos terminou para os dois
    return (terminou_red || terminou_blue);
}

void Partida::refresh_tela(){
    // Limpa a tela e reseta a cor do terminal
    system("clear");

    // Imprime na tela os times da partida
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

    //volta a cor do texto para a do time de quem esta jogando
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

    // Gera numero aleatório entre 1 e 100
    int random;
    random = rand() % 100 + 1;

    // Determina ação da CPU
    // 10% de chance de passar a vez
    if (random < 10) {
        std::cout << "CPU passa a vez" << std::endl;
    }
    // 20% de chance de usar habilidade especial
    if (random > 80) {
        std::cout << "CPU usa habilidade" << std::endl;
    // 70% de chance de ataque normal
    } else {
        std::cout << "CPU ataca" << std::endl;

        // Seleciona um inimigo vivo para atacar
        while (!inimigo_vivo) {
            // Gera número aleatório entre 1 e 100
            random = rand() % 100 + 1;
            // Determina qual inimigo atacar com chances iguais entre cada uma das opções do grupo
            inimigo_atacado = std::floor(random*_grupo_blue.size() / 100);
            inimigo_vivo = _grupo_blue[inimigo_atacado].get_vivo();
            std::cout << "Numero random: " << inimigo_atacado << std::endl;
        }

        atacando(p, _grupo_blue, inimigo_atacado);
    }

    // std::cout << "CPU muito burra não conseguiu fazer nada... " << p.get_nome() << " perdeu a vez." << std::endl;
}
