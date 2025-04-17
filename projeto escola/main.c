#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utils.h"
#include "resources.h"
#include "CadastroAluno.h"

int main(int argc,char *argv[]){

	setlocale(LC_ALL,"Portuguese");
    
    int matriculaBusca, teste;
	char sair=0,key;
	CadAlunos alunosCadastrados[MaxAlunos], copia[MaxAlunos];
    short int qtdAlunos = 0;
      
	Clear();
	printf("%s\n\tSeja bem vindo ao sistema de cadastro da escola!\t\t\n %s",bold,resetBold);

	do{
		printf("\n\t\t\t%sMENU INICIAL\n\n\t\t Oque você deseja fazer?%s\n\n[1] Menu cadastro\t\t[2] Menu aluno\t\t[3] Menu Professor\t\n[4] Menu disciplina\t\t%s[0] Sair\t%s",bold,reset,yellow_F,reset);
		campoResposta(&key);
		Clear();

		switch (key){

		case '1':
			printf("\t\t%sMENU CADASTRO%s\n\n",bold,reset);
			printf("\t%sO que você deseja cadastrar:%s\n[1] Aluno\t\t[2] Professor\t\t[3] Disciplina\t",bold,reset);
			menuIniciar();  
			campoResposta(&key);
                        switch(key){
			      case '1': InserirAluno(&qtdAlunos,alunosCadastrados,MaxAlunos);break;
			    }
			key = '1';
			break;
		case '2':
			printf("\t\t\t%sMENU ALUNOS%s\n\n",bold,reset);
			printf("[1] Listar todos os alunos\t\t[2] Listar alunos ordenados por...\t\t[3] Buscar aluno por matricula");
			menuIniciar();	campoResposta(&key);
                        switch(key){
                            case '1': ListarAlunos( &qtdAlunos, alunosCadastrados, MaxAlunos, key);getchar();break;
                            case '2': AlunosMaisOpcoes(&key); ListarAlunos( &qtdAlunos, alunosCadastrados, MaxAlunos, key); getchar(); break;
                            case '3': ListarAlunos( &qtdAlunos, alunosCadastrados, MaxAlunos, key);getchar(); break;
                        }
			key = '1';
			break;
		case '3':
			printf("\t\t%sMENU PROFESSORES%s\n\n",bold,reset);
			printf("[1] Listar professores\t");
			menuIniciar();campoResposta(&key);

			key = '1';
			break;
		case '4':
			printf("\t\t%sMENU DISCIPLINAS%s\n\n",bold,reset);
			printf("[1] Listar disciplinas\t");
			menuIniciar();campoResposta(&key);

			key = '1';
			break;
		}
	Clear();
	}while(key != '0');

}
