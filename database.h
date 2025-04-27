#ifndef DATABASE_H
#define DATABASE_H
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

#endif
