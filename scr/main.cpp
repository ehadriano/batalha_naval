#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "../include/utilitarios.hpp"
#include "../include/jogador.hpp"
#include "../include/inimigo.hpp"
#include "../include/menu.hpp"

using namespace std;

int main() {
    // Configura a cor do console
    system("color 90");

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Instancia os objetos necessários
    inimigo a;
    jogador b;
    menu a1;

    // Oculta o cursor do console
    ocultarCursor();

    // Exibe a tela inicial e limpa o console
    a1.TELA_INICIAL();
    system("cls");

    // Exibe o objetivo do jogo e limpa o console
    a1.OBJETIVO();
    system("cls");

    // Inicializa as variáveis de controle do jogo
    int q1 = 2; // Coordenada x do cursor do jogador
    int w1 = 3; // Coordenada y do cursor do jogador
    int q2 = 2; // Coordenada x do cursor do navio
    int w2 = 28; // Coordenada y do cursor do navio
    int Nave1 = 1, Nave = 1; // Controle de seleção de navios
    int cam = 0; // Orientação do navio (0 para vertical, 1 para horizontal)
    int p1, p2, p3 = 0, p4, p5 = 1;
    int x1, y1, x2, y2, x3, y3, x4, y4; // Coordenadas dos navios
    int c1, c2, c3, c4; // Orientações dos navios
    int op; // Opção de menu
    bool gameover = true; // Flag para controle do loop principal do jogo

    // Exibe o tabuleiro do inimigo
    gotoxy(0, 0);
    a.printarTabuleiro();
    gotoxy(0, 25);
    a.printarTabuleiro();
    a1.INSTRUCOES();

    // Loop principal do jogo
    while(gameover == true)
    {
		
        if(Nave1 == 2) Nave = 2;
        if(Nave1 == 3) Nave = 3;
        if(Nave1 == 4) Nave = 4;
        if(Nave1 == 5) Nave = 5;
        if(Nave1 == 6) Nave = 6;
        if(Nave1 == 7) Nave = 7;

        // Verificação de vitória do jogador
        if(a.retornarVidaJO() == 11)
        {
            system("cls");
            gotoxy(10,10);cout<<"VOCE GANHOU!";
            gotoxy(10,12);cout<<"DESEJA JOGAR NOVAMENTE?";
            gotoxy(10,14);cout<<"1. sim  / 2. nao";
            cin>>op;
            switch(op)
            {
                case 1: return main();
                break;
                
                case 2: gameover=false;
                break;
            }
        }

        // Verificação de derrota do jogador
        if(a.retornarVidaIN() == 11)
        {
            system("cls");
            gotoxy(10,10);cout<<"VOCE PERDEU!";
            gotoxy(10,12);cout<<"DESEJA JOGAR NOVAMENTE?";
            gotoxy(10,14);cout<<"1. sim  / 2. nao";
            cin>>op;
            switch(op)
            {
                case 1: return main();
                break;
                
                case 2: gameover=false;
                break;
            }
        }

        if(p5 == 1)
        {
            if(p1 == 1)
            {
                b.printarCARRIER_Permanente(x1, y1, c1);
            }
            if(p2 == 2)
            {
                b.pintarTANKER_Permanente(x2, y2, c2);
            }
            if(p3 == 3)
            {
                b.printarDESTROYER_Permanente(x3, y3, c3);
            }
            if(p4 == 4)
            {
                b.printarSUBMARINE_Permanente(x4, y4, c4);
            }
        }

        if(kbhit())
        {
            char tecla = getch();
            if(tecla == 'c')
            {
                if(cam == 0)
                {
                    if(Nave == 1) b.apagarCARRIER(q2,w2,cam);
                    if(Nave == 2) b.apagarTANKER(q2,w2,cam);
                    if(Nave == 3) b.apagarDESTROYER(q2,w2,cam);
                    if(Nave == 4) b.apagarSUBMARINE(q2,w2,cam);
                    cam = 1;
                    q2 = 2;
                    w2 = 28;
                }
                else
                {
                    if(Nave == 1) b.apagarCARRIER(q2,w2,cam);
                    if(Nave == 2) b.apagarTANKER(q2,w2,cam);
                    if(Nave == 3) b.apagarDESTROYER(q2,w2,cam);
                    if(Nave == 4) b.apagarSUBMARINE(q2,w2,cam);
                    cam = 0;
                    q2 = 2;
                    w2 = 28;
                }
            }
            if(tecla == 'x' && Nave<5)
            {
                if(Nave == 1)
                {
                    q2 = 2;
                    w2 = 28;
                    p1 = 1;
                    Nave1 = 2;
                    x1=b.capturaX();
                    y1=b.capturaY();
                    c1=cam;
                }
                if(Nave == 2)
                {
                    q2 = 2;
                    w2 = 28;
                    p2 = 2;
                    Nave1 = 3;
                    x2=b.capturaX();
                    y2=b.capturaY();
                    c2=cam;
                }
                if(Nave == 3)
                {
                    q2 = 2;
                    w2 = 28;
                    p3 = 3;
                    Nave1 = 4;
                    x3=b.capturaX();
                    y3=b.capturaY();
                    c3=cam;
                }
                if(Nave == 4)
                {
                    q2 = 2;
                    w2 = 28;
                    p4 = 4;
                    Nave1 = 5;
                    x4=b.capturaX();
                    y4=b.capturaY();
                    c4=cam;
                }
            }
            if(tecla == 'z')
            {
                a.disparo(q1,w1);
                Nave1=7;
            }
        }

        if(Nave == 1)
        {
            b.moverCARRIER(q2,w2,cam);
        }
        if(Nave == 2)
        {
            b.moverTANKER(q2,w2,cam);
        }
        if(Nave == 3)
        {
            b.moverDESTROYER(q2,w2,cam);
        }
        if(Nave == 4)
        {
            b.moverSUBMARINE(q2,w2,cam);
        }
        if(Nave == 5)
        {
            a.printarNavios();
            p5 = 2;
            Nave1 = 6;
        }
        if(Nave == 6)
        {
            a.mover(q1,w1);
            gotoxy(0,25);
            a.printarTabuleiroJO();
        }
        if(Nave == 7)
        {
            b.IAgeneral();
            gotoxy(0,25);
            a.printarTabuleiroJO();
            Sleep(30);
            Nave1=6;
        }

        Sleep(20);
    }

    return 0;
}
