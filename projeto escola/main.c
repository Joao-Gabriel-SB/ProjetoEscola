#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utils.h"
#include "resources.h"

int main(int argc,char *argv[]){

	setlocale(LC_ALL,"Portuguese");

	char sair=0,key;

	Clear();
	printf("%s\n\tSeja bem vindo ao sistema de cadastro da escola!\t\t\n %s",bold,resetBold);

	do{
		printf("\n\t\t\t%sMENU INICIAL\n\n\t\t Oque você deseja fazer?%s\n\nMenu cadastro\t(1)\tMenu aluno\t(2)\tMenu Professor\t(3)\nMenu disciplina\t(4)\t%sSair\t(0)%s",bold,reset,yellow_F,reset);
		campoResposta(&key);
		Clear();

		switch (key){

		case '1':
			printf("\t\t%sMENU CADASTRO%s\n\n",bold,reset);
			printf("\t%sO que você deseja cadastrar:%s\nAluno\t(1)\tProfessor\t(2)\tDisciplina\t(3)",bold,reset);
			menuIniciar();
			campoResposta(&key);

			key = '1';
			break;
		case '2':
			printf("\t\t\t%sMENU ALUNOS%s\n\n",bold,reset);
			printf("Listar todos os alunos\t(1)\tListar alunos ordenados por...(2)");
			menuIniciar();	campoResposta(&key);	listarAlunos(key);

			key = '1';
			break;
		case '3':
			printf("\t\t%sMENU PROFESSORES%s\n\n",bold,reset);
			printf("Listar professores\t(1)");
			menuIniciar();campoResposta(&key);

			key = '1';
			break;
		case '4':
			printf("\t\t%sMENU DISCIPLINAS%s\n\n",bold,reset);
			printf("Listar disciplinas\t(2)");
			menuIniciar();campoResposta(&key);

			key = '1';
			break;
		}
	Clear();
	}while(key != '0');

}
