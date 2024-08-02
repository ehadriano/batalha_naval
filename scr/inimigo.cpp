void inimigo::desenharMapaen(){
    for(int i = 0; i < 22; i++){
        cout << endl;
        for(int j = 0; j < 22; j++){
            cout << en[i][j];
        }
    }
}
void inimigo::printar(peca &P, int r){
    if(r == 1){
       for(int i=0; i<4; i++){ //Controla o número de casas que um navio pode ocupar
            coord c = P.posicao(i);
            en[c.y][c.x] = P.d; // Marca a posição do navio com o caractere que representa o tipo do navio
    }
    }
    else{
        for(int i=0; i<4; i++){ //Controla o número de casas que um navio pode ocupar
            coord c = P.posicao(i);
            en[c.y][c.x] = P.D; // Marca a posição do navio com o caractere que representa o tipo do navio
        }
    }
}
void inimigo::apagar(peca &P){
    for(int i=0; i<4; i++){
        coord c = P.posicao(i);
        en[c.y][c.x] = ' '; // Substitui a posição do navio por um espaço em branco
    }
}
void inimigo::mover(peca &P, int &r){
    if (kbhit()) {
        peca copia = P;
        char tecla = getch();

        // Processa a entrada do usuário para mover a peça
        if(tecla == 'a') P.original.x -=2;
        if(tecla == 'd') P.original.x +=2;
        if(tecla == 'w') P.original.y -=2;
        if(tecla == 's') P.original.y +=2;

        inimigo::apagar(copia);
        inimigo::printar(P,1);
        }
}