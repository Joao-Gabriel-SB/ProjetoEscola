#ifndef DISCIPLINAS_H
#define DISCIPLINAS_H

#include "Disciplinas.c"

int string_vazia(char *str);
int cadastrar_disciplina( int *qtd_disciplina, professores ListaProfessores[], professores CopiaProfessores[],professores aux_struct);
void listar_disciplina(int *qtd_disciplina);
int atualizar_disciplina(int *qtd_disciplina,professores ListaProfessores[], professores CopiaProfessores[],professores aux_struct);
int excluir_disciplina(int *qtd_disciplina);
int incluir_aluno_disciplina( int *qtd_disciplina, int amountStudents, Student* registredStudents );
int excluir_aluno_disciplina(int *qtd_disciplina, Student* registredStudents);
void listar_alunos_disciplina( int *qtd_disciplina);

#endif
