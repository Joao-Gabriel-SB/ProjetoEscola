#ifndef utils_h
#define utils_h
#include "database.h"

int menu();
void limpar_buffer();
int validador_cpf (char cpf_validation[]);
int validador_data (int dia, int mes, int ano);

#endif