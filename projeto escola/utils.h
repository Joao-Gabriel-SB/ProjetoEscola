#ifndef UTILS_H
#define UTILS_H

#include "utils.c"

void Pause();
void AnswerField(char *a);
void Until( char* a, char lowerest, char biggest );
void StartMenu();
void Spacer(int tamanhoDaBarra);
int GetId(void* element);
int SearchInt( int tamanhoDoVetor, void* Nomevetor, size_t tipoDoElemento, int ( *funcGet )( void* ), int valorDesejado );
void CharSort( int amountStudents, const int tamVetor1, Student* vetor, Student* vetOrdenado, const int tamVetor2, int selector );
int SearchChar( Student* vetIn, const int tamVetIn, Student* vetOut, const int tamVetOut, char* strDesejada, int tamstrDesejada );
int CompareBirthDay( Student a, Student b );

// ENZO===================================================================================================================================

int menu();
void limpar_buffer();
int validador_cpf (char cpf_validation[]);
int validador_data (int dia, int mes, int ano);


#endif 
