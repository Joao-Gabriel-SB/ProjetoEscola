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




//====================================================================================================================


#endif
