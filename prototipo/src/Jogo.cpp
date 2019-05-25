#include "Jogo.h"
#include "Personagem.h"
#include "Monstro.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Jogo::Jogo(){
}

bool Jogo::carrega_arquivos(){

    //carrega o arquivo contendo os herois
    std::ifstream arquivo("herois.csv");
    
    if(!arquivo.is_open()) std::cout << "Erro: falha no carregamento de arquivo";

    while(arquivo.good()){
        std::string nome,hp,max_hp,ataque,defesa;


        getline(arquivo,nome,',');
        getline(arquivo,hp,',');
        getline(arquivo,max_hp,',');
        getline(arquivo,ataque,',');
        getline(arquivo,defesa,'\n');

        Personagem novo_personagem = Personagem(nome, std::stoi(hp), std::stoi(max_hp), std::stoi(ataque), std::stoi(defesa));

        _herois.push_back(novo_personagem);
    }
    arquivo.close();

    //carrega o arquivo contendo os monstros
    arquivo.open("monstros.csv");
    
    if(!arquivo.is_open()) std::cout << "Erro: falha no carregamento de arquivo";

    while(arquivo.good()){
        std::string nome,hp,max_hp,ataque,defesa;

        getline(arquivo,nome,',');
        getline(arquivo,hp,',');
        getline(arquivo,max_hp,',');
        getline(arquivo,ataque,',');
        getline(arquivo,defesa,'\n');

        Monstro novo_personagem = Monstro(nome, std::stoi(hp), std::stoi(max_hp), std::stoi(ataque), std::stoi(defesa));

        _monstros.push_back(novo_personagem);
    }
    arquivo.close();
        
        //Arquivos carregados com sucesso
        return true;
};

Personagem Jogo::escolhe_heroi(int i){
    return _herois[i];
}

Personagem Jogo::escolhe_monstro(int i){
    return _monstros[i];
}

void Jogo::imprime_vetores(){

    //Imprime conteudo do vetor herois
    std::cout << "HEROIS:" << std::endl;
    for (unsigned int i = 0; i < _herois.size(); i++){
	    std::cout << i << " :: nome:" << _herois[i].get_nome();
        std::cout << " hp:" << _herois[i].get_hp();
        std::cout << " max_hp:" << _herois[i].get_max_hp();
        std::cout << " ataque:" << _herois[i].get_ataque();
        std::cout << " defesa:" << _herois[i].get_defesa() << std::endl;
    }
    
    //Imprime conteudo do vetor de monstros
    std::cout << std::endl << "MONSTROS" << std::endl;
    for (unsigned int i = 0; i < _monstros.size(); i++){
	    std::cout << i << " :: nome:" << _monstros[i].get_nome();
        std::cout << " hp:" << _monstros[i].get_hp();
        std::cout << " max_hp:" << _monstros[i].get_max_hp();
        std::cout << " ataque:" << _monstros[i].get_ataque();
        std::cout << " defesa:" << _monstros[i].get_defesa() << std::endl;
    }
}

