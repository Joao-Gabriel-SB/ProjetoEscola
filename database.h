#ifndef database_h
#define database_h
#include <stdio.h>
#include <stdlib.h>

#define TAM 3

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

#endif