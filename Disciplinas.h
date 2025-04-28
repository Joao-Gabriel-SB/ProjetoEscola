#ifndef DISCIPLINAS_H
#define DISCIPLINAS_H

#include "Disciplinas.c"

int string_vazia(char *str);
void cadastrar_disciplina( int *qtd_disciplina, professores ListaProfessores[], professores CopiaProfessores[],professores aux_struct);
void listar_disciplina(int *qtd_disciplina);
void atualizar_disciplina(int *qtd_disciplina);
void excluir_disciplina(int *qtd_disciplina);
void incluir_aluno_disciplina( int *qtd_disciplina, int amountStudents, Student* registredStudents );
//void excluir_aluno_disciplina(int *qtd_disciplina);

#endif
