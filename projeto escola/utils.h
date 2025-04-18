#ifndef UTILS_H
#define UTILS_H

#include "utils.c"

void Pause();
void AnswerField(char *a);
void Until( char* a, char lowerest, char biggest );
void StartMenu();
void Spacer(int tamanhoDaBarra);
int GetMatricula(void* element);
int SearchInt( int tamanhoDoVetor, void* Nomevetor, size_t tipoDoElemento, int ( *funcGet )( void* ), int valorDesejado );
void CharSort( int amountStudants, const int tamVetor1, Student* vetor, Student* vetOrdenado, const int tamVetor2, int selector );
int SearchCharSearchChar( Student* vetor, const int tamVetor1, Student* vetOrdenado, const int tamVetor2, char* strDesejada );
int CompareBirthDay( Student a, Student b );
#endif
