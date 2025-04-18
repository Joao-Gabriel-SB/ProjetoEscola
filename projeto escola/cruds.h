#ifndef CRUDS_H
#define CRUDS_H

#include "cruds.c"

int ListStudents(int amountStudants, Student* registredStudants, const int ArraySize, char key);
int InsertStudent( int* amountStudants, Student* registredStudants, const int ArraySize );

#endif
