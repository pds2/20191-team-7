# Projeto: Jogo RPG
## Instruções para compilação do projeto
Para executar o projeto basta usar o makefile que já esta incluso.
```
make run
```

## Definição do Projeto
Jogo RPG com batalhas em turnos inspirado em D&D onde o jogador escolhe seu grupo de heróis e parte em aventuras, vencendo diferentes inimigos, evoluindo os personagens e colecionando recompensas.

## User Stories
### Como um jogador de RPG, eu quero poder escolher heróis para enfrentar as batalhas do jogo.

##### Critérios de aceitação
- Fornecer diferentes personagens jogáveis com atributos diferenciados.
- Fornecer diferentes classes de heróis (mago, guerreiro...).
- Criar grupo de batalha com mais de um personagem.

### Como um jogador de RPG, eu quero ter o controle das ações do meu personagem para ter o controle de como a luta irá se desenrolar

##### Critérios de aceitação
- Implementar sistema de batalhas por turno
- Fornecer diferentes ataques para cada herói

### Como um jogador de RPG, eu quero diferentes tipos de inimigos para dar mais variedade às lutas

##### Critérios de aceitação
- Fornecer diferentes personagens não jogáveis com atributos diferenciados para serem enfrentados.
- Fornecer diferentes classes de vilôes (orcs, undead...)
- Implementar diferentes níveis de vilôes.

### Como jogador de RPG, eu quero evoluir de nível após as batalhas para tornar meus heróis mais fortes e enfrentar desafios maiores

##### Critérios de aceitação
- Implementar sistema de níveis com aumento de atributos conforme a progressão do nível.
- Implementar aumento de XP para os heróis após batalhas vencidas.
- Fornecer atributos desbloqueáveis conforme nível atingido.

### Como jogador de RPG, eu quero ter acesso a informações sobre os meus heróis para definir minha estratégia antes de cada batalha

##### Critérios de aceitação
- Exibir tela de detalhes informando o nível e atributos do herói.

### Como jogador de RPG, eu quero a presença de um elemento de randomicidade para tornar as batalhas mais imprevisíveis

##### Critérios de aceitação
- Implementar fator sorte nos ataques e defesas dos personagens
- Implementar condições externas que influenciam nos atributos dos heróis e vilôes (terreno, clima...)

