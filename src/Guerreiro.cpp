#include "Guerreiro.h"

Guerreiro::Guerreiro (std::string nome, int forca, int agilidade, int inteligencia):
                         Personagem (nome, forca, agilidade, inteligencia){

    _nome_classe = "Guerreiro";
    _habilidade_1 = "Primeiros Socorros";
    _habilidade_2 = "Execução";
    _habilidade_3 = "Fúria de Batalha";
}
Guerreiro::~Guerreiro(){}

int Guerreiro::ataque_basico(Personagem* alvo) {
    return alvo->recebe_ataque_fisico(_ataque);
}

std::string Guerreiro::get_habilidade(int habilidade_escolhida) {
    switch (habilidade_escolhida)
    {
        case 1: return _habilidade_1; break;
        case 2: return _habilidade_2; break;
        case 3: return _habilidade_3; break;
        default: return "Habilidade inválida"; break;
    }
}

std::string Guerreiro::usa_habilidade(int habilidade_escolhida, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
    std::string msg = "";
    switch (habilidade_escolhida)
    {
        case 1: {
            int recupera_hp = _hp * FATOR_CURA;
            if (_hp + recupera_hp > _max_hp) {
                recupera_hp -= ((_hp + recupera_hp) - _max_hp);
            }
            _hp += recupera_hp;
            msg = "Usou " + _habilidade_1 + "\n" + _nome + " recuperou " + std::to_string(recupera_hp) + " de HP.";
            break;
        }
        case 2: { 
            msg = "Usou " + _habilidade_2;
            break;
        }
        case 3: {
            msg = "Usou " + _habilidade_3;
            break;
        }
        default:  {
            msg = "Habilidade inválida";
            break;
        }
    }

    return msg;
}