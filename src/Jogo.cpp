/*

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
        std::string nome,forca,agilidade,inteligencia;

        getline(arquivo,nome,',');
        getline(arquivo,forca,',');
        getline(arquivo,agilidade,',');
        getline(arquivo,inteligencia,'\n');

        Personagem novo_personagem = Personagem(nome, std::stoi(forca), std::stoi(agilidade), std::stoi(inteligencia));

        _herois.push_back(novo_personagem);
    }
    arquivo.close();

    //carrega o arquivo contendo os monstros
    arquivo.open("monstros.csv");
    
    if(!arquivo.is_open()) std::cout << "Erro: falha no carregamento de arquivo";

    while(arquivo.good()){
        std::string nome,forca,agilidade,inteligencia;

        getline(arquivo,nome,',');
        getline(arquivo,forca,',');
        getline(arquivo,agilidade,',');
        getline(arquivo,inteligencia,'\n');

        Monstro novo_personagem = Monstro(nome, std::stoi(forca), std::stoi(agilidade), std::stoi(inteligencia));

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
        _herois[i].imprime();
    }
    
    //Imprime conteudo do vetor de monstros
    std::cout << std::endl << "MONSTROS:" << std::endl;
    for (unsigned int i = 0; i < _monstros.size(); i++){
        _monstros[i].imprime();	    
    }
}
*/