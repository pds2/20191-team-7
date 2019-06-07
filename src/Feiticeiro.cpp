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
            if (segunda_escolha == 0){
                return "Faltou segunda opcao";
            }
            msg = this->habilidade_2(segunda_escolha, grupo_inimigo);
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
    // Verifica se possui MP suficiente para habilidade
    if (_mp >= CUSTO_HABILIDADE_1) {
        std::string msg = this->_nome + " conjurou uma bola de fogo sobre os adversários\n";
        int dano = 0;
        _mp -= CUSTO_HABILIDADE_1;
        for(Personagem* p : grupo_inimigo) {
            if (p->get_vivo()) {
                dano = p->recebe_ataque_magia(DANO_BOLA_DE_FOGO);
                msg += p->get_nome() + " sofreu " + std::to_string(dano) + " de dano.\n";
                if (!p->get_vivo()) {
                    msg += p->get_nome() + " foi derrotado.\n";
                }
            }
        }

        return msg;
    }
    return "Energia insuficiente para usar esta habilidade. " + _nome + " desperdiçou sua vez.";
}

std::string Feiticeiro::habilidade_2(int segunda_escolha, std::vector<Personagem*> grupo_inimigo) {
    if (grupo_inimigo[segunda_escolha-1]->get_vivo()) {
        if (_mp >= CUSTO_HABILIDADE_2) {
            int hp_inimigo = grupo_inimigo[segunda_escolha-1]->get_hp();
            int mp_inimigo = grupo_inimigo[segunda_escolha-1]->get_mp();
            int hp_drena = hp_inimigo * FATOR_DRENAR;
            int mp_drena = mp_inimigo * FATOR_DRENAR;

            std::string msg = this->_nome + " usou drenar energia em " + grupo_inimigo[segunda_escolha-1]->get_nome() + ".\n";
            msg += "Foi absorvido " + std::to_string(hp_drena) + " de HP e " + std::to_string(mp_drena) + " de MP\n";
            
            // Adiciona valores ao feiticeiro
            if (_hp + hp_drena < _max_hp) {
                _hp += hp_drena;
            } else {
                _hp = _max_mp;
            }

            if (_mp + mp_drena < _max_mp) {
                _mp += mp_drena;
            } else {
                _mp = _max_mp;
            }

            // Remove valores do inimigo
            grupo_inimigo[segunda_escolha-1]->set_hp(hp_inimigo - hp_drena);
            grupo_inimigo[segunda_escolha-1]->set_mp(mp_inimigo - mp_drena);

            return msg;
        }
        return "Energia insuficiente para usar esta habilidade. " + _nome + " desperdiçou sua vez.";
    } 
    return grupo_inimigo[segunda_escolha-1]->get_nome() + " já está morto! " + _nome + " desperdiçou sua vez.";   
}