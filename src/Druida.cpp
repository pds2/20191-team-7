#include "Druida.h"

Druida::Druida (std::string nome, int forca, int agilidade, int inteligencia):
                  Personagem (nome, forca, agilidade, inteligencia){

    _nome_classe = "Druida";
    _habilidade_1 = "Cura - permite curar um aliado";
    _habilidade_2 = "Forma Animal - ataca um inimigo em forma de urso";
    _habilidade_3 = "Revitaliza - permite revitalizar EP/MP de um aliado ";
}
Druida::~Druida(){}

int Druida::ataque_basico(Personagem* alvo) {

    // O ataque_total eh 1d20 + a forca
    int ataque_total;
    ataque_total = _ataque + (rand() % 20 + 1);
    std::cout << "O ataque foi de: " << ataque_total << " " << std::endl;
    return alvo->recebe_ataque_fisico(ataque_total);
}

std::string Druida::get_habilidade(int habilidade_escolhida) {
    switch (habilidade_escolhida)
    {
        case 1: return _habilidade_1; break;
        case 2: return _habilidade_2; break;
        case 3: return _habilidade_3; break;
        default: return "Habilidade inválida"; break;
    }
}

std::string Druida::usa_habilidade(int habilidade_escolhida, int segunda_escolha, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
    std::string msg = "";
    switch (habilidade_escolhida)
    {
        case 1:
            if (segunda_escolha == 0){
                return "Escolher aliado";
            }
            msg = this->habilidade_1(segunda_escolha, grupo_aliado);
            break;
        case 2:
            if (segunda_escolha == 0){
                return "Escolher inimigo";
            }
            msg = this->habilidade_2(segunda_escolha, grupo_inimigo);
            break;
        case 3:
            if (segunda_escolha == 0){
                return "Escolher aliado";
            }
            msg = this->habilidade_3(segunda_escolha, grupo_aliado);
            break;
        default:
            msg = "Habilidade inválida";
            break;
    }

    return msg;
}

std::string Druida::habilidade_1(int segunda_escolha, std::vector<Personagem*> grupo_aliado){
    --segunda_escolha;
    // Testa se possui MP suficiente para usar habilidade
    if (_mp >= CUSTO_HABILIDADE_1_DRUIDA){
        // Verifica se personagem está vivo
        if (grupo_aliado[segunda_escolha]->get_vivo()) {
            int recupera_hp = grupo_aliado[segunda_escolha]->get_max_hp() * FATOR_CURA_DRUIDA;

            if (grupo_aliado[segunda_escolha]->get_hp() + recupera_hp >= grupo_aliado[segunda_escolha]->get_max_hp()){
                recupera_hp = (grupo_aliado[segunda_escolha]->get_max_hp() - grupo_aliado[segunda_escolha]->get_hp());
            }
            grupo_aliado[segunda_escolha]->set_hp(recupera_hp + grupo_aliado[segunda_escolha]->get_hp());

            return _nome + " usou " + _habilidade_1 + " e conseguiu aumentar em "
                + std::to_string(recupera_hp) + " o HP de " + grupo_aliado[segunda_escolha]->get_nome();
        }
        return grupo_aliado[segunda_escolha]->get_nome() + " está morto e não pode ser curado";
    }
    return "Energia insuficiente para usar esta habilidade. " + _nome + " desperdiçou sua vez.";
}

std::string Druida::habilidade_2(int segunda_escolha, std::vector<Personagem*> grupo_inimigo){
    --segunda_escolha;
    //testa se inimigo esta vivo
    if(grupo_inimigo[segunda_escolha]->get_vivo() == true){

        //testa so o personagem tem mp suficientes
        if(_mp >= (CUSTO_HABILIDADE_2_DRUIDA)){

            grupo_inimigo[segunda_escolha]->diminui_hp(INCREMENTO_ATAQUE_DRUIDA + _ataque);
            _mp -= CUSTO_HABILIDADE_2_DRUIDA;
            std::string menssagem;

            //confere se o inimigo foi morto pelo ataque
            if(grupo_inimigo[segunda_escolha]->get_hp() <= 0){
                grupo_inimigo[segunda_escolha]->set_vivo_morto(false);
                menssagem = grupo_inimigo[segunda_escolha]->get_nome() + " foi morto.";
            }
            return _nome + " se transformou em um urso e atacou " + grupo_inimigo[segunda_escolha]->get_nome()
            + " causando " + std::to_string(INCREMENTO_ATAQUE_DRUIDA + _ataque) + " de dano. " + menssagem;

        }
        else return "MP insuficiente para realizar este ataque. " + _nome + " não conseguiu fazer nada.";
    }
    else return "Habilidade só pode ser usada em um inimigo que ainda esta vivo. " + _nome + " não conseguiu fazer nada.";
}

std::string Druida::habilidade_3(int segunda_escolha, std::vector<Personagem*> grupo_aliado){
    --segunda_escolha;
    //testa de possui MP suficiente para usar esta
    if (_mp >= CUSTO_HABILIDADE_3_DRUIDA){
        if (grupo_aliado[segunda_escolha]->get_vivo()) {
            int recupera_mp = grupo_aliado[segunda_escolha]->get_max_mp() * FATOR_REVITALIZACAO_DRUIDA;

            if (grupo_aliado[segunda_escolha]->get_mp() + recupera_mp >= grupo_aliado[segunda_escolha]->get_max_mp()){
                recupera_mp = (grupo_aliado[segunda_escolha]->get_max_mp() - grupo_aliado[segunda_escolha]->get_mp());
            }

            grupo_aliado[segunda_escolha]->set_mp(recupera_mp + grupo_aliado[segunda_escolha]->get_mp());

            return _nome + " usou " + _habilidade_1 + " e conseguiu regenerar "
                + std::to_string(recupera_mp) + " do MP/EP de " + grupo_aliado[segunda_escolha]->get_nome();
        }
        return grupo_aliado[segunda_escolha]->get_nome() + " está morto e não pode ser revitalizado";
    }
    return "MP insuficiente para usar esta habilidade. " + _nome + " desperdiçou sua vez.";

}
