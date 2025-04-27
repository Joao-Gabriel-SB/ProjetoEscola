#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Alunos==============================================================================================================

#define MaxStudent 3
#define StrSizeMax 100

typedef struct{
        int day;
        int month;
        int year;
}StructBirth;

typedef struct {
        char         name[StrSizeMax];
        StructBirth  birthday;
        char         sex;
        char         cpf[12];
        int          id;
}Student;

Student registredStudents[MaxStudent]; 
//Student copy[MaxStudent];
int amountStudents;
int idCounter = 202521001;



// Professores ====================================================================================================================

#define MaxProfessor 3

typedef struct{
int dia;
int mes;
int ano;
int total;
}struct_nascimento;

typedef struct{
int matricula;
char nome[50];
char sexo;
struct_nascimento nascimento;
char cpf[12];  
int ativo;
}professores;

professores ListaProfessores[MaxProfessor], CopiaProfessores[MaxProfessor], aux_struct;
int posicao = 0;
int IncrementadorMatricula = 202542000;

// Disciplinas =====================================================================================================================

#define TAM_DISCIPLINAS 5
#define MAX_ALUNOS_DISCIPLINA 20


typedef struct{
    char nome[StrSizeMax];
    char codigo[StrSizeMax];
    int semestre;
    char professor[StrSizeMax];
    int ativo;
    char alunos[MAX_ALUNOS_DISCIPLINA][StrSizeMax];
    int qtd_alunos;
  } disciplina;
  
extern disciplina lista_disciplinas[TAM_DISCIPLINAS];

disciplina lista_disciplinas[TAM_DISCIPLINAS];

int qtd_disciplina=0;

#endif
