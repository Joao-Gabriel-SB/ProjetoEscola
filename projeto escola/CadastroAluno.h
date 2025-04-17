#ifndef CADASTROALUNO_H
#define CADASTROALUNO_H

#include "CadastroAluno.c"

int InserirAluno(short int *qtdAlunos, CadAlunos* alunosCadastrados, int n);
void ListarAlunos(short int * qtdAlunos, CadAlunos* alunosCadastrados, int n, char key);
int BuscaInt(int n, CadAlunos* vet, int elemento);

#endif
