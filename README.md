TP - PDS2 - Grupo 8: Batalha Naval
Integrantes: Eduardo H Adriano, Pedro Bicalho de Sousa, Júlia Menezes, Gabriela Teixeira Santos

**Apresentação do Problema: Quem nunca passou por momentos de tédio, onde não se tem nada para fazer? Nessas horas, não tem nada melhor que um joguinho simples para passar o tempo.

**Visão Geral da Solução: Visando entretenimento, desenvolveu-se um jogo de Batalha Naval. O tabuleiro do jogador poderá ser montado de forma arbitrária.

======================================================================================================================================================================================

**Estrutura Geral do Projeto: 
batalha_naval/ 
├── bin
│   └── main.exe
├── Documentação
│   └── Doxyfile
│   └── html
│   └── latex
├── img
│   └── ship.ico
├── include
│   ├── config.hpp
│   ├── inimigo.hpp
│   ├── jogador.hpp
│   ├── matrizes.hpp
│   ├── menu.hpp
│   └── utilitarios.hpp
├── obj
│   ├── inimigo.o
│   ├── jogador.o
│   ├── main.o
│   ├── matrizes.o
│   ├── menu.o
│   └── utilitarios.o
├── scr
│   ├── inimigo.cpp
│   ├── jogador.cpp
│   ├── main.cpp
│   ├── matrizes.cpp
│   ├── menu.cpp
│   └── utilitarios.cpp
├── scripts
│   └── create_shortcut.bat
├── Batalha_Naval.lnk
├── Makefile
└── README.md

======================================================================================================================================================================================

**Instruções de Instalação:
Esse código foi escrito para funcionar no sistema Windows. Siga os passos abaixo para configurar e executar o projeto corretamente.

MinGW: Certifique-se de ter o MinGW (Minimalist GNU for Windows) instalado. Você pode baixá-lo aqui: https://sourceforge.net/projects/mingw/
Git: Certifique-se de ter o Git instalado. Você pode baixá-lo aqui: https://git-scm.com/downloads

Passo 1: Clone o repositório
git clone https://github.com/ehadriano/batalha_naval.git
cd batalha_naval

Passo 2: Instale o MinGW
Baixe e instale o MinGW. Certifique-se de selecionar o "mingw32-gcc-g++" no menu de seleção de pacotes.

Passo 3: Configure o PATH
Adicione o caminho do MinGW ao seu PATH do sistema. O caminho é algo como "C:\MinGW\bin"
       Para adicionar ao PATH:
              Abra o Painel de Controle
              Vá em Sistema e Segurança > Sistema > Configurações avançadas do sistema
              Clique em "Variáveis de Ambiente"
              Em "Variáveis do sistema", encontre a variável Path e edite-a
              Adicione o caminho do MinGW (por exemplo, C:\MinGW\bin)

Passo 4: Compile o código
Navegue até o diretório do projeto clonado e compile o código usando "mingw32-make"

Passo 5: Execute o programa
Após a compilação bem-sucedida, você pode executar o programa usando ".\bin\main.exe"

======================================================================================================================================================================================

**Instruções de Uso: 
-Execute "Batalha_Naval".
-Espere o jogo carregar e aperte a tecla 'Espaço'.

======================================================================================================================================================================================

**Principais dificuldades: A ideia inicial, era ser um jogo Multiplayer, porém se provou complicado fazer a manutenção de dois jogadores. Para que o jogo pudesse ser jogado,
elaboramos um IA simples, para competir com o jogador

======================================================================================================================================================================================

**User Stories - Batalha Naval Multiplayer
Descrição: Como usuário, desejo conseguir jogar uma partida do clássico jogo de batalha naval.
Critérios de Aceitação:
- Quero poder posicionar meus navios onde eu desejar
- Posso realizar jogadas, selecionando coordenadas no tabuleiro do inimigo.
- Posso mover minha peça pelo tabuleiro.
- Posso rotacionar minha peça pelo tabuleiro.
- Posso saber se minha jogada acertou ou errou um alvo.

======================================================================================================================================================================================

**Classes/Funções a serem usadas (Cartões CRC):
1) Cartão CRC para jogador:
-Responsabilidades:
       Retornar a vida atual do jogador (retornarVidaJO).
       Imprimir o tabuleiro do jogador (printarTabuleiroJO).
       Capturar a coordenada X (capturaX).
       Capturar a coordenada Y (capturaY).
       Obter uma coordenada aleatória (obter).
       Manipular o navio CARRIER:
              Printar (printarCARRIER)
              Apagar (apagarCARRIER)
              Mover (moverCARRIER)
              Printar permanentemente (printarCARRIER_Permanente)
       Manipular o navio TANKER:
              Printar (printarTANKER)
              Apagar (apagarTANKER)
              Mover (moverTANKER)
              Printar permanentemente (printarTANKER_Permanente)
       Manipular o navio DESTROYER:
              Printar (printarDESTROYER)
              Apagar (apagarDESTROYER)
              Mover (moverDESTROYER)
              Printar permanentemente (printarDESTROYER_Permanente)
       Manipular o navio SUBMARINE:
              Printar (printarSUBMARINE)
              Apagar (apagarSUBMARINE)
              Mover (moverSUBMARINE)
              Printar permanentemente (printarSUBMARINE_Permanente)
       Converter coordenadas da matriz para coordenadas do tabuleiro (converterMatriz).
       Converter coordenadas do tabuleiro para coordenadas da matriz (converterTabuleiro).
       IA:
              Obter coordenadas para jogada automática (IAobter).
              Gerar jogadas (IAgeneral).
              Definir dificuldade da IA (IAdificuldade).
              Verificar a jogada da IA (IAverificar).

-Colaborações:
       Interage com a classe Tabuleiro para atualizar e imprimir o tabuleiro.
       Interage com as funções de utilitários (gotoxy, ocultarCursor).

2) Cartão CRC para menu:
-Responsabilidades:
       Exibir a tela inicial do jogo (TELA_INICIAL).
       Exibir as instruções do jogo (INSTRUCOES).
       Exibir o objetivo do jogo (OBJETIVO).

-Colaborações:
       Interage com a interface do usuário para mostrar as diferentes telas do menu.

3) Cartão CRC para utilitarios:
-Responsabilidades:
       Posicionar o cursor na coordenada (x, y) no console (gotoxy).
       Ocultar o cursor no console (ocultarCursor).

-Colaborações:
       Utilizado pelas classes Jogador e Menu para manipulação do cursor e da interface do console.

4) Cartão CRC para matrizes:
-Responsabilidades:
       Armazenar o estado do tabuleiro principal (MA).
       Armazenar o estado do tabuleiro do jogador (JO).
       Armazenar o estado do tabuleiro do inimigo (en).

-Colaborações:
       Utilizado pelas classes Jogador, Tabuleiro, e possivelmente outras classes relacionadas ao jogo para:
              Atualizar o estado dos tabuleiros durante o jogo.
              Verificar o estado atual do jogo (por exemplo, se um navio foi atingido).
              Renderizar a visualização do tabuleiro para o jogador e o inimigo.

5) Cartão CRC para inimigo:
-Responsabilidades:
       Gerenciar a vida do inimigo:
              Retornar a vida atual do inimigo (retornarVidaIN).
       Imprimir o tabuleiro do inimigo:
              Imprimir o tabuleiro do inimigo (printarTabuleiro).
              Imprimir o tabuleiro interno do inimigo (printarTabuleiroIN).
       Manipular a posição e estado de disparo:
              Imprimir a posição (printar).
              Apagar a posição (apagar).
              Mover a posição (mover).
       Obter coordenadas e direção:
              Obter coordenada X (obterX).
              Obter coordenada Y (obterY).
              Obter direção (obterC).
       Imprimir navios do inimigo:
              Imprimir todos os navios do inimigo (printarNavios).
              Imprimir navios específicos (printarCARRIER, printarTANKER, printarDESTROYER, printarSUBMARINE).
       Registrar disparo:
              Registrar disparo (disparo).
-Colaborações:
       Herda e colabora com a classe Jogador para reutilizar métodos e funcionalidades comuns aos jogadores.
       Interage com a matriz global en para atualizar o estado do tabuleiro do inimigo.
       Utiliza funções de utilitários para manipulação do cursor e interface do console.

6) Cartão CRC para config:
-Responsabilidades:
       Definir constantes para teclas de direção do teclado:
              Definir constante para a tecla de seta para a esquerda (ESQUERDA).
              Definir constante para a tecla de seta para a direita (DIREITA).
              Definir constante para a tecla de seta para cima (CIMA).
              Definir constante para a tecla de seta para baixo (BAIXO).
-Colaborações:
       Utilizado por diversas classes e funções no jogo de batalha naval para interpretar e responder às entradas do usuário via teclado.

======================================================================================================================================================================================

**Referência da imagem ship.ico: https://www.flaticon.com/free-icon/boat_3322490?term=ship&page=1&position=5&origin=search&related_id=3322490
