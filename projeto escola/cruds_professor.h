#ifndef cruds_h
#define cruds_h

#include "cruds_professor.c"

int CadastrarProfessor( professores ListaProfessores[], int limite, int* posicao, int *IncrementadorMatricula );
void ListarProfessor( professores ListaProfessores[], int posicao );
int atualizar_professor(professores ListaProfessores[], int *posicao);
int excluir_professor(professores ListaProfessores[],int *posicao);
void ListarProfessorNome(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao);
void ListarProfessorIdade(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao);
void ListarProfessorSexo(professores ListaProfessores[], int *posicao, char key);


#endif
