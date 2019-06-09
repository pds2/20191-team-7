#include "Guerreiro.h"

Guerreiro::Guerreiro (std::string nome, int forca, int agilidade, int inteligencia):
                         Personagem (nome, forca, agilidade, inteligencia){
    _max_mp = 100;
    _nome_classe = "Guerreiro";
    _habilidade_1 = "Primeiros Socorros - recupera 25% do HP";
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

std::string Guerreiro::usa_habilidade(int habilidade_escolhida, int segunda_escolha, std::vector<Personagem*> grupo_aliado, std::vector<Personagem*> grupo_inimigo) {
    std::string msg = "";
    switch (habilidade_escolhida)
    {
        case 1: {
            msg = this->habilidade_1();
            break;
        }
        case 2: { 
            if (segunda_escolha == 0){
                return "Escolher inimigo";
            }
            msg = this->habilidade_2(segunda_escolha, grupo_inimigo);
            break;
        }
        case 3: {
            if (segunda_escolha == 0){
                return "Escolher inimigo";
            }
            msg = this->habilidade_3(segunda_escolha, grupo_inimigo);
            break;
        }
        default:  {
            msg = "Habilidade inválida";
            break;
        }
    }

    return msg;
}

std::string Guerreiro::habilidade_1(){
    //testa se tem energia suficiente usar esta habilidade
    if (_mp >= CUSTO_HABILIDADE_1){
            int recupera_hp = _max_hp * FATOR_CURA;
            if (_hp + recupera_hp >= _max_hp){
                recupera_hp = (_max_hp - _hp);
            }
            _hp += recupera_hp;
            return _nome + " usou " + _habilidade_1 + " e conseguiu recuperar " + std::to_string(recupera_hp) + " de HP.";
    }
    return "Energia insuficiente para usar esta habilidade. " + _nome + " desperdiçou sua vez.";
}

std::string Guerreiro::habilidade_2(int segunda_escolha, std::vector<Personagem*> grupo_inimigo){
    //testa se inimigo esta vivo
    if(grupo_inimigo[segunda_escolha-1]->get_vivo() == true){
        //testa se é possivel executar o inimigo
        if(grupo_inimigo[segunda_escolha-1]->get_hp() < (grupo_inimigo[segunda_escolha-1]->get_max_hp() * PONTO_DE_EXECUCAO)){
            _mp = 0;
            grupo_inimigo[segunda_escolha-1]->set_vivo_morto(false);
            return  grupo_inimigo[segunda_escolha-1]->get_nome() + " foi executado. " + _nome + " gastou toda sua energia ao fazer isso.";
        } 
    return "Ainda não é possivel executar este inimgo.";
    }    
    else return "Habilidade só pode ser usada em um inimigo que ainda esta vivo. " + _nome + " não conseguiu fazer nada.";

}

std::string Guerreiro::habilidade_3(int segunda_escolha, std::vector<Personagem*> grupo_inimigo){
    std::string menssagem = "";

    //testa se inimigo esta vivo
    if(grupo_inimigo[segunda_escolha-1]->get_vivo() == true){
        
        //testa so o personagem tem energia e HP suficientes
        if(_hp > _ataque && _mp >= (CUSTO_HABILIDADE_3)){

            grupo_inimigo[segunda_escolha-1]->diminui_hp(2 * _ataque);
            _hp -= _ataque;
            _mp -= CUSTO_HABILIDADE_3;
            std::string menssagem;

            //confere se o inimigo foi morto pelo ataque
            if(grupo_inimigo[segunda_escolha-1]->get_hp() <= 0){
                grupo_inimigo[segunda_escolha-1]->set_vivo_morto(false);
                menssagem = grupo_inimigo[segunda_escolha-1]->get_nome() + " foi morto.";
            }
            return grupo_inimigo[segunda_escolha-1]->get_nome() + " sofreu " + std::to_string(2 * _ataque) + " de dano. " + menssagem;
            
        }
        else return "HP insuficiente para realizar este ataque. " + _nome + " não conseguiu fazer nada.";
    }
    else return "Habilidade só pode ser usada em um inimigo que ainda esta vivo. " + _nome + " não conseguiu fazer nada.";
}