#ifndef DISCIPLINAS_H
#define DISCIPLINAS_H

#define TAM_DISCIPLINAS 5
#define MAX_ALUNOS_DISCIPLINA 20

typedef struct{
    char nome[50];
    char codigo[50];
    int semestre;
    char professor[50];
    int ativo;
    char alunos[MAX_ALUNOS_DISCIPLINA][50];
    int qtd_alunos;
  } disciplina;
  
extern disciplina lista_disciplinas[TAM_DISCIPLINAS];

int string_vazia(char *str);
void cadastrar_disciplina(int *qtd_disciplina);
void listar_disciplina(int *qtd_disciplina);
void atualizar_disciplina(int *qtd_disciplina);
void excluir_disciplina(int *qtd_disciplina);
void incluir_aluno_disciplina(int *qtd_disciplina);
void excluir_aluno_disciplina(int *qtd_disciplina);


#endif
