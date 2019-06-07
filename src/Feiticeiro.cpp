#include "Feiticeiro.h"

Feiticeiro::Feiticeiro (std::string nome, int forca, int agilidade, int inteligencia):
            Personagem (nome, forca, agilidade, inteligencia){

    _nome_classe = "Feiticeiro";
    _habilidade_1 = "Bola de Fogo";
    _habilidade_2 = "Drenar Energia";
    _habilidade_3 = "Curandeiro";
}
Feiticeiro::~Feiticeiro(){}

int Feiticeiro::ataque_basico(Personagem* alvo) {
    return alvo->recebe_ataque_fisico(_ataque);
}

std::string Feiticeiro::get_habilidade(int habilidade_escolhida) {
    switch (habilidade_escolhida)
    {
        case 1: return _habilidade_1; break;
        case 2: return _habilidade_2; break;
        case 3: return _habilidade_3; break;
        default: return "Habilidade inválida"; break;
    }
}

std::string Feiticeiro::usa_habilidade(int habilidade_escolhida, int segunda_escolha, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
    std::string msg = "";
    switch (habilidade_escolhida)
    {
        case 1: 
            msg = this->habilidade_1(grupo_inimigo);
            break;
        case 2: 
            msg = "Usou " + _habilidade_2;
            break;
        case 3: 
            msg = "Usou " + _habilidade_3;
            break;
        default: 
            msg = "Habilidade inválida";
            break;
    }

    return msg;
}

std::string Feiticeiro::habilidade_1(std::vector<Personagem*> grupo_inimigo) {
    std::string msg = this->_nome + " conjurou uma bola de fogo sobre os adversários\n";
    int dano = 0;
    // Verifica se possui MP suficiente para habilidade
    if (_mp >= CUSTO_HABILIDADE_1){
        _mp -= CUSTO_HABILIDADE_1;
        for(Personagem* p : grupo_inimigo) {
            dano = p->recebe_ataque_magia(DANO_BOLA_DE_FOGO);
            msg += p->get_nome() + " sofreu " + std::to_string(dano) + " de dano.\n";
            if (!p->get_vivo()) {
                msg += p->get_nome() + " foi derrotado.\n";
            }
        }

        return msg;
    }
    return "Energia insuficiente para usar esta habilidade. " + _nome + " desperdiçou sua vez.";
}