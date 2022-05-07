#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblio.h"
#include <time.h>
#include <string.h>

void menu(){
    printf("\n0.Sair");
    printf("\n1.Jogador unico (questoes de quimica)");
    printf("\n2.Jogar com duas pessoas");
    printf("\nEscolha: ");
};

int ramdom(){
    int num;
    srand((unsigned)time(NULL));
    num = rand()%10;
    return num;
};
