#ifndef cruds_h
#define cruds_h
#include "database.h"

int cadastrar_professor(professores ListaProfessores[], int *posicao, int *IncrementadorMatricula, int limite);
void listar_professor(professores ListaProfessores[], int *posicao);
int atualizar_professor(professores ListaProfessores[], int *posicao);
int excluir_professor(professores ListaProfessores[],int *posicao);
void listar_professor_nome(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao);
void listar_professor_idade(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao);
void listar_professor_sexo(professores ListaProfessores[], int *posicao);


#endif