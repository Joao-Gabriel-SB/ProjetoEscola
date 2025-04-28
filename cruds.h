#ifndef CRUDS_H
#define CRUDS_H

#include "cruds.c"

int ListStudents( int amountStudents, Student* registredStudents, const int ArraySize, char key);
int ListarPessoas( int amountStudents, Student* registredStudents, professores* ListaProfessores, int posicao, int ArraySize );
int InsertStudent( int* amountStudents, Student* registredStudents, const int ArraySize, int* idCounter  );
int UpdateStudent( int* amountStudents, Student* registredStudents, const int ArraySize );
int DeleteStudent( int* amountStudents, Student* registredStudents, const int ArraySize );

#endif
