#include <stdio.h>
#include "resources.h"

void campoResposta(short int *a){
	printf("\nR: ");
	scanf("%hd",&*a);
	putchar('\n');
}

void Clear(){
        puts("\x1B[2J");
        puts("\x1B[H");
}

void menuIniciar(){
	printf("\n\x1B[1;33mMenu inicial\t(0)%s",reset);
}

void listarAlunos(short int a){
	switch (a){
		case 1: printf("vou listar todos os alunos");break;
		case 2:	printf("Sexo(1)\tNome(2)\tIdade(3)");
			campoResposta(&a);
			switch(a){
			case 1: printf("Ordenando por sexo...");break;
			case 2: printf("Ordenando por nome...");break;
			case 3: printf("Ordenando por Idade...");break;
			}
			break;
		case 3:printf("vou listar todos os alunos");break;
		case 0:printf("vou listar todos os alunos");break;
	}
}
