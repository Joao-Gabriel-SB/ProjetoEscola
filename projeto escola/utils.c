#include <stdio.h>
#include "resources.h"

void campoResposta(char *a){
	printf("\nR: ");
	scanf(" %c",&*a);
	putchar('\n');
}

void Clear(){
        puts("\x1B[2J");
        puts("\x1B[H");
}

void menuIniciar(){
	printf("\n\x1B[1;33mMenu inicial\t(0)%s",reset);
}

void AlunosMaisOpcoes(char *a){
  
    printf("Sexo(1)\tNome(2)\tIdade(3)");
    campoResposta(&*a);
    switch(*a){
      case '1': printf("\n[7] Homem\t\t [8] Mulher"); campoResposta(&*a); break;
      case '2': printf("Ordenando por nome...");break;
      case '3': printf("Ordenando por Idade...");break;
      }
}

