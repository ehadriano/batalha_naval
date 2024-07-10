TP - PDS2 - Grupo 8: Batalha Naval
Integrantes: Eduardo H Adriano, Pedro Bicalho de Sousa, Júlia Menezes, Gabriela Teixeira Santos

Apresentação do Problema: Quem nunca passou por momentos de tédio, onde não se tem nada para fazer? Nessas horas, não tem nada melhor que um joguinho simples para passar o tempo.

Visão Geral da Solução: Visando entretenimento, desenvolveu-se um jogo de Batalha Naval para dois jogadores. Os tabuleiros serão posicionados de forma aleatória, cada jogador terá seu turno, podendo digitar uma coordenada e saber as consequências de sua jogada. Quando todos os navios de um jogador estiverem afundados, um vencedor deve ser declarado. 

Estrutura Geral do Projeto (Sujeito a Eventuais Mudanças): 
batalha_naval/ 
├── src/ │ 
       ├── main.cpp 
       ├── tabuleiro.cpp 
       ├── tabuleiro.h  
       ├── jogo.cpp 
       ├── jogo.h 
       ├── jogador.cpp 
       ├── jogador.h 
├── include/
       ├── tabuleiro.h  
       ├── jogo.h 
       ├── jogador.h 
├── tests/ 
       ├── test_main.cpp 
       ├── test_board.cpp 
       ├── test_game.cpp 
       ├── test_player.cpp 
├── docs/   
       ├── README.md
       ├── manual.pdf 
       ├── design.md 
├── CMakeLists.txt 
└── Makefile

Instruções de Instalação:
Passo 1: Instalar Ferramentas Básicas
1- Instalar um compilador C++, no caso do LINUX, pode ser instalado pelo comando “sudo apt-get install g++”.
2- Instalar o CMake, no caso do LINUX, “sudo apt-get install cmake”.
3- Instalar um editor de texto.

Passo 2: Clonar o Repositório
1- Abrir uma Prompt de Comando
2- Instalar o git usando, no caso do LINUX, “sudo apt-get install git”.
3-Clonar o repositório usando:
git clone https://github.com/ehdriano/batalha_naval.git
cd batalha_naval

Passo 3: Configurar o CMake
1- Crie um arquivo “CmakeLists.txt” na raiz do projeto.

Passo 4: Compilar o projeto
1- Crie um Diretório de Construção usando:
mkdir build
cd build
2- Gere os arquivos de construção e compile o projeto usando:
cmake ..
3- Compile o projeto usando:
cmake --build .

Passo 5: Executar o Projeto
1-Após compilado, execute o projeto usando:
./BatalhaNaval
2-Instalar extensões como:
C/C++
CMake Tools
3-Configurar a Construção criando um arquivo .vscode/tasks.json.
4-Configura o Debug criando um arquivo .vscode/launch.json.

Instruções de Uso: (O jogo irá te guiar durante a partida)

Principais dificuldades: Se provou extremamente complicado organizar a estrutura geral do projeto e as instruções de instalação, dito isso, recorrer a monitoria em estágios mais avançados deve se mostrar necessário.

User Stories - Batalha Naval Multiplayer
Descrição: Como usuário, desejo conseguir jogar uma partida do clássico jogo de batalha naval, com mais uma pessoa.
Critérios de Aceitação:
- O código posicionará automaticamente e de forma aleatória, tanto o meu tabuleiro, quanto do meu adversário.
- Posso realizar jogadas, digitando duas coordenadas válidas.
- Posso saber se minha jogada é uma coordenada válida.
- Posso saber se minha jogada acertou ou errou um alvo.
- Posso saber o vencedor da partida

Classes/Funções a serem usadas (Cartões CRC): Possíveis atributos necessários para funcionamento (sujeito a mudanças), Responsabilidade (Função) de cada classe e como elas Colaboram umas com as outras.
1º Classe “Tabuleiro”: Inicia o tabuleiro do jogo, representado por uma Matriz 10x10, onde serão armazenados os estados das células (água, navios, navios afundados).
Atributos: 
“vector<vector<char>> grade”: inicia o tabuleiro
“Tamanho_do_Tabuleiro” * “Tamanho_do_Tabuleiro”: define a área do tabuleiro
“Agua”: preenche o tabuleiro
Colabora com:
-”void PrintTabuleiro” para exibir o tabuleiro.
-”bool ColocarNavio” para posicionar os navios no tabuleiro.
-”bool FazerJogada” para registrar ataque no tabuleiro.
-”bool FimDeJogo” para verificar se todos os navios foram afundados.

2º Função “void PrintTabuleiro”: Imprime o tabuleiro no console
Parâmetros: 
“const Tabuleiro& tabuleiro”
Colabora com:
-“Tabuleiro” pois recebe o tabuleiro para imprimir

3° Função “bool ColocarNavio”: coloca um navio no tabuleiro, em uma posição aleatória.
Parâmetros: 
“Tabuleiro& tabuleiro”: Onde o navio será colocado.
“char Tipo_do_Navio”: Define o tipo de navio a ser colocado (S, D, T, ou C)
“Int Tamanho_do_Navio”: Define o tamanho do navio.
“unsigned int seed”: Garante que os navios sejam posicionados aleatoriamente
Colabora com:
-“Tabuleiro” para modificar o estado do tabuleiro com os navios adicionados

4º Função “void ColocarNavios”: coloca todos os navios no tabuleiro, usando a função 3
Parâmetros: 
“Tabuleiro& tabuleiro”
“Int seed”
Colabora com:
-“Tabuleiro” para modificar o estado do tabuleiro com os navios adicionados.
-”bool ColocarNavio” para colocar cada navio individualmente.

5º Função “bool FazerJogada”: Realiza um movimento no tabuleiro, marcando um erro ou acerto.
Parâmetros:
“Tabuleiro& tabuleiro”
“Int x”: coordenada X
“Int y”: coordenada Y
Colabora com:
-“Tabuleiro” para modificar o estado do tabuleiro com o resultado do ataque.

6º Função “bool FimDeJogo”: Verifica se um dos jogadores teve todos os navios afundados.
Parâmetros:
“const Tabuleiro& tabuleiro”
Colabora com:
-“Tabuleiro” para verificar o tabuleiro e a presença de navios.

7º Função “void Turno”: Gerencia a vez de um jogador, incluindo a entrada de um par de coordenadas e a realização de uma jogada.
Parâmetros:
“Tabuleiro& meuTabuleiro” : Tabuleiro do jogador atual
“Tabuleiro& oponenteTabuleiro”: Tabuleiro do oponente, onde será feita a jogada
“Int NumeroJogador”
“Int NumeroRodada”
Colabora com:
-“Tabuleiro” para ler e modificar o tabuleiro dos jogadores.
-“bool FazerJogada” para realizar o ataque.
-“void PrintTabuleiro” para exibir o estado atual dos tabuleiros.

8º Função “int Main”: Função principal, onde a magia acontece. Aqui serão inicializados os tabuleiros, os navios serão colocados, os turnos serão gerenciados e o vencedor determinado.
Colabora com:
-“Tabuleiro” para criar os tabuleiros dos jogadores.
-“void ColocarNavios” para posicionar os navios nos tabuleiros.
-“void Turno” para gerenciar os turnos dos jogadores.
-“bool FimDeJogo” para verificar um vencedor.

Variáveis Globais:
const int TAMANHO_DO_TABULEIRO = 10;
const char AGUA = '~'; 
const char SUBMARINE = 'S'; (4 desse tipo, ocupando 4 casa cada)
const char DESTROYER = 'D'; (3 desse tipo, ocupando 3 casas cada)
const char TANKER = 'T'; (2 desse tipo, ocupando 4 casas cada)
const char CARRIER = 'C'; (1 desse tipo, ocupando 5 casas cada)
const char ACERTO = 'X';
const char ERRO = ' ';
