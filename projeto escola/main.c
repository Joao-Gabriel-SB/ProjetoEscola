#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utils.h"
#include "resources.h"

int main(int argc,char *argv[]){

	setlocale(LC_ALL,"Portuguese");

	short int sair=1,key;

	Clear();
	printf("%s\n\t\tSeja bem vindo ao sistema de cadastro da escola!\t\t\n %s",bold,resetBold);

	do{
		printf("\n\t\t\t\t %sMENU INICIAL\n\n\t\t\t   Oque você deseja fazer?%s\n\n[1] Menu cadastro\t\t[2] Menu aluno\t\t[3] Menu Professor\t\n[4] Menu disciplina\t\t%s[0] Sair\t%s",bold,reset,yellow_F,reset);
		campoResposta(&key); if(key == 0) sair=0;
		system("clear||cls");

		switch (key){

		case 1:
			printf("\t\t\t%sMENU CADASTRO%s\n\n",bold,reset);
			printf("[1] Cadastrar\t\t[2] Atualizar\t\t[3] Excluir");
			campoResposta(&key);

				switch(key){

					case 1:
						printf("\t\t%sO que você deseja cadastrar:%s\n[1] Aluno\t\t[2] Professor\t\t[3] Disciplina\t",bold,reset);
						menuIniciar();
						campoResposta(&key);
						break;
					case 2:
						printf("\t\t%sO que você deseja cadastrar:%s\n[1] Aluno\t\t[2] Professor\t\t[3] Disciplina\t",bold,reset);
						menuIniciar();
						campoResposta(&key);
						break;
					case 3;
						printf("\t\t%sO que você deseja cadastrar:%s\n[1] Aluno\t\t[2] Professor\t\t[3] Disciplina\t",bold,reset);
						menuIniciar();
						campoResposta(&key);
						break;
				}
			break;
		case 2:
			printf("\t\t\t%sMENU ALUNOS%s\n\n",bold,reset);
			printf("[1] Listar todos os alunos\t\t[2] Listar alunos ordenados por...");
			menuIniciar();	campoResposta(&key);	listarAlunos(key);
			break;
		case 3:
			printf("\t\t%sMENU PROFESSORES%s\n\n",bold,reset);
			printf("[1] Listar professores\t");
			menuIniciar();campoResposta(&key);
			break;
		case 4:
			printf("\t\t%sMENU DISCIPLINAS%s\n\n",bold,reset);
			printf("[1] Listar disciplinas\t");
			menuIniciar();campoResposta(&key);
			break;
		}
	system("clear||cls");
	}while(sair != 0);
}
