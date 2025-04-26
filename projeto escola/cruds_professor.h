#ifndef cruds_h
#define cruds_h

#include "cruds_professor.c"

int CadastrarProfessor( professores ListaProfessores[], int limite, int* posicao, int *IncrementadorMatricula );
void ListarProfessor( professores ListaProfessores[], int *posicao );
int atualizar_professor(professores ListaProfessores[], int *posicao);
int excluir_professor(professores ListaProfessores[],int *posicao);
void listar_professor_nome(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao);
void listar_professor_idade(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao);
void listar_professor_sexo(professores ListaProfessores[], int *posicao);


#endif
