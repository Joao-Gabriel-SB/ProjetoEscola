#include <stdio.h>
#include "resources.h"
#include <string.h>
#include "database.h"

void Pause(){
    
    char Buffer;

    while ((Buffer = getchar()) != '\n' && Buffer != EOF);
    
}

void AnswerField(char *a){
    
	printf("\nR: ");
	scanf(" %c",a);
	putchar('\n');
}

//=====================================================================================================================================================================================================

void Until( char* a, char lowerest, char biggest ){

    do{

    AnswerField(a);

        if( ( *a < lowerest || *a > biggest ) ){

            printf("%sOpção invalida, tente novamente!%s", yellow_F, reset );
            Pause();

        }
    
    }while( *a < lowerest || *a > biggest );

} 

//=====================================================================================================================================================================================================
void StartMenu(){
	printf("\n\x1B[1;33m[0] Menu inicial\t%s",reset);
}

//=====================================================================================================================================================================================================

void Spacer(int tamanhoDaBarra){

    for(int x = 0; x < tamanhoDaBarra; x++)//divisões
    printf("-");    
    putchar('\n');
}

//=====================================================================================================================================================================================================

int GetMatricula(void* element){
    
        return (( Student* )element)-> id; 

}

//=====================================================================================================================================================================================================


/*Busca por numeros inteiros em um vetor de estrutura, é uma função generica então é complicada de entender. Basicamente: vc precisa criar uma função int getalgumaCoisa no seguinte formato:

 int getMatricula(void* elemento){
    
        return (( NomeQueVoceDeuPraSuaStruct* )elemento)-> CampoDaStructQueVcQuerProcurar; 

  }

E passar ela como 4º parametro. 
size_t tipoDoElemento é basicamente o tamanho da estrutura que vc está passando. quando for chamar a função use sizeof( NomeDaSuaStruct ),
*/
int SearchInt( int tamanhoDoVetor, void* Nomevetor, size_t tipoDoElemento, int ( *funcGet )( void* ), int valorDesejado ){  
        
    int i, index = -1;

    for( i=0; i<tamanhoDoVetor; i++ ){

        void* campoStructDesejado = ( char* )Nomevetor + ( i * tipoDoElemento ); 

        if( funcGet( campoStructDesejado ) == valorDesejado)

            index = i;
            
    }
    
    return index;
        
}

//=====================================================================================================================================================================================================

int CompareBirthDay( Student a, Student b ){

    int oldest;

    if( a.birthday.year < b.birthday.year ) oldest = 1;
    if( a.birthday.year > b.birthday.year ) oldest = -1;
    if( a.birthday.year == b.birthday.year ){
    
        if( a.birthday.month < b.birthday.month ) oldest = 1;
        if( a.birthday.month > b.birthday.month ) oldest = -1;
        if( a.birthday.month == b.birthday.month ){

            if( a.birthday.day < b.birthday.day ) oldest = 1;
            if( a.birthday.day > b.birthday.day ) oldest = -1;
            if( a.birthday.day == b.birthday.day ) oldest = 1;            

        }

    }
        
    return oldest;    
    
}


//=====================================================================================================================================================================================================
   
void CharSort( int amountStudants, const int tamVetor1, Student* vetor, Student* vetOrdenado, const int tamVetor2, int selector ){

     int i, j, smaller;
     Student temp;
    
     if ( selector == 1 ){
    
            for( i = 0; i < amountStudants; i++)
            vetOrdenado[i] = vetor[i];

            for( i = 0; i < amountStudants; i++ ){

                smaller = i;
                      
                for( j = i+1; j < amountStudants; j++ ){

                    if( strcmp( vetOrdenado[smaller].name, vetOrdenado[j].name ) > 0 ){

                    smaller = j;
        
                    }            
                }
            
            temp = vetOrdenado[smaller];
            vetOrdenado[smaller] = vetOrdenado[i];
            vetOrdenado[i] = temp;    
            }   

    }else{

            for( i = 0; i < amountStudants; i++)
                vetOrdenado[i] = vetor[i];


            for( i = 0; i < amountStudants; i++ ){

                smaller = i;
                  
                for( j = i+1; j < amountStudants; j++ ){

                    if( CompareBirthDay( vetOrdenado[smaller], vetOrdenado[j] ) > 0 ){

                        smaller = j;
    
                    }            
                }
        
            temp = vetOrdenado[smaller];
            vetOrdenado[smaller] = vetOrdenado[i];
            vetOrdenado[i] = temp;    

            
            }
    }
}

//=====================================================================================================================================================================================================

int SearchChar( Student* vetor, const int tamVetor1, Student* vetOrdenado, const int tamVetor2, char* strDesejada, int tamVetor3 ){

    int amountStudantsLocal = 0;
    
    for( int i = 0; i < tamVetor1; i++ ){


        if( strncmp( vetor[i].name, strDesejada, tamVetor3 ) == 0 ) {   

            vetOrdenado[amountStudantsLocal] = vetor[i];
            amountStudantsLocal++;
            
        }
       
    }

    return amountStudantsLocal;

}

//=====================================================================================================================================================================================================



//=====================================================================================================================================================================================================
