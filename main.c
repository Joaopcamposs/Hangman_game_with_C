#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblio.h"
#include <time.h>
#include <string.h>


int main (){
  int opc;
  int i, contador, n, nchar, e1, e2, e3, e4, e5, certo;
  char frase[100], resposta[100], tentativa, dica[200];

  do{
    system("cls");
    puts("___________   \n|         |   \n|        _|_\n|         O   Jogo de Forca \n|        /|\\    \n|        / \\ \n| \n| \n| \n");
    menu();
    scanf("%i", &opc);

    if(opc != 0){
      if (opc == 1){
        int num;
        num = ramdom();

        if(num == 0){
          strcpy(frase,"fluor");
          strcpy(dica,"Elemento mais eletronegativo");
        }
        if(num == 1){
          strcpy(frase,"atomo");
          strcpy(dica,"Menor elemento da molecula");
        }
        if(num == 2){
          strcpy(frase,"cesio");
          strcpy(dica,"Elemento com maior raio atomico");
        }
        if(num == 3){
          strcpy(frase,"hidrogenio");
          strcpy(dica,"Elemento sem familia");
        }
        if(num == 4){
          strcpy(frase,"chumbo");
          strcpy(dica,"Elemento capaz de isolar radiacao");
        }
        if(num == 5){
          strcpy(frase,"tungstenio");
          strcpy(dica,"Metal com maior temperatura de fusao");
        }
        if(num == 6){
          strcpy(frase,"alcool");
          strcpy(dica,"Funcao organica na qual o etanol pertence");
        }
        if(num == 7){
          strcpy(frase,"sublimacao");
          strcpy(dica,"Passagem direta do estado solido para o gasoso");
        }
        if(num == 8){
          strcpy(frase,"Elemento com maior massa atomica");
          strcpy(dica,"ununoctio");
        }
        if(num == 9){
          strcpy(frase,"prata");
          strcpy(dica,"Metal com maior condutividade eletrica");
        }
      }

      if (opc == 2){
        puts("\nComo jogar: a primeira pessoa digita uma palavra ou frase e a segunda tenta advinhar o que foi digitado.\n");
        printf("\nDigite a palavra ou a frase desejada: ");
        fflush(stdin);
        gets(frase);
        printf("\nDigite a dica: ");
        gets(dica);
      }

      certo = 0;
      nchar=0;
      n = 0;
      i=0;
      contador = 0;
      e1 = ' ';
      e2 = ' ';
      e3 = ' ';
      e4 = ' ';
      e5 = ' ';

      system("CLS");

      for(i = 0; i < 100; i++){
        resposta[i]='_';
      }

      while(contador < 6){
        n=0;
        certo=0;
        switch(contador){
          case 0: printf("___________   \n|         |   \n|        _|_\n|          \n|        \ \n|         \n| \n| \n| \n\n");
            break;
          case 1: printf("___________   \n|         |   \n|        _|_\n|         O    \n|         \n|       \n| \n| \n| \n\n");
            break;
          case 2: printf("___________   \n|         |   \n|        _|_\n|         O    \n|         |    \n|         \n| \n| \n| \n\n");
            break;
          case 3: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|    \n|         \n| \n| \n| \n\n");
            break;
          case 4: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|         \n| \n| \n| \n\n");
            break;
          case 5: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        /  \n| \n| \n| \n\n");
            break;
        }
        
        for(i=0; i < 100; i++){
          if(frase[i]=='\0'){
            nchar = i;
            break;
          }
          else{
            if(frase[i]==' '){
              resposta[i]=' ';
              printf("%c", resposta[i]);
            }
            else{
              if(frase[i]==tentativa){
                resposta[i]=frase[i];
              }
            }
          }
          printf("%c ", resposta[i]);
        }
        printf("\n\n%c %c %c %c %c\n", e1, e2, e3, e4, e5);
  
        switch(contador){
          case 0: puts("\n\nVoce pode errar 5 vezes");
            break;
          case 1: puts("\n\nVoce pode errar 4 vezes");
            break;
          case 2: puts("\n\nVoce pode errar 3 vezes");
            break;
          case 3: puts("\n\nVoce pode errar 2 vezes");
            break;
          case 4: puts("\n\nVoce pode errar apenas mais uma vez");
            break;
          case 5: puts("\n\nUltima chance!!!");
        }
  
        for(i = 0; i <= nchar; i++){
          if(tentativa!=' '){
            if(resposta[i]!='_'){
              certo++;
              if(certo==nchar){
                contador=7;
                break;
              }
            }
          }
        }

        if(certo!=nchar){
          printf("\nDica: %s", dica);
          printf("\n\nDigite uma letra: ");
          fflush(stdin);
          scanf("%c", &tentativa);
          tentativa = tolower(tentativa);
        }

        for(i = 0; i < nchar; i++){
          if(tentativa!=frase[i]){
            n++;
            if(n==nchar){
              contador++;
              if(contador==1){
                e1 = tentativa;
              }
              if(contador==2){
                e2 = tentativa;
              }
              if(contador==3){
                e3 = tentativa;
              }
              if(contador==4){
                e4 = tentativa;
              }
              if(contador==5){
                e5 = tentativa;
              }
            }
          }
        }
        system("cls");
      }

      if(contador==6){
        printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        / \\ \n| \n| \n| \n\n");
        for(i = 0; i < nchar; i++){
          if(resposta[i]==frase[i]){
            printf("%c ", resposta[i]);
          }
          else{
            printf("(%c) ", frase[i]);
          }
        }

        printf("\n\n%c %c %c %c %c %c\n", e1, e2, e3, e4, e5, tentativa);
        printf("\n\n\nVoce Perdeu! FIM.\n");
        system("PAUSE");
      }

      if(contador==7){
        system("cls");
        printf("Parabens!! Voce Venceu!!\n");
        printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        \\O/\n|         | \n|        / \\\n\n");
        tentativa='_';
        system("PAUSE");
      }
    }     
  } while(opc!=0);
  
  return 0;
}
