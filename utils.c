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

void ToLower( char* copyVetIn, char* vetIn, int tamVetIn ){

	for( int i = 0; i < tamVetIn; i++ )
		copyVetIn[i] = vetIn[i];

	for (int i = 0; i < tamVetIn; i++){
		
			if( copyVetIn[i] >= 'A' && copyVetIn[i] <= 'Z' )
				copyVetIn[i] = copyVetIn[i] + 32;

	}
}
//=====================================================================================================================================================================================================

int GetId(void* element){
    
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

        if( funcGet( campoStructDesejado ) == valorDesejado )

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

void CharSort( int amountStudents, const int tamVetIn, Student* vetIn, Student* vetOut, const int tamVetOut, int selector ){

     int i, j, smaller;
     Student temp;
    
     if ( selector == 1 ){
	
				Student copyVetOut[tamVetIn];
				for( int i = 0; i < tamVetIn; i++ )
					ToLower( copyVetOut[i].name, vetOut[i].name, tamVetIn );

            for( i = 0; i < amountStudents; i++)
            	vetOut[i] = vetIn[i];

            for( i = 0; i < amountStudents; i++ ){

                smaller = i;
                      
                for( j = i+1; j < amountStudents; j++ ){

                    if( strcmp( copyVetOut[smaller].name, copyVetOut[j].name ) > 0 ){

                    smaller = j;
        
                    }            
                }
            
            temp = vetOut[smaller];
            vetOut[smaller] = vetOut[i];
            vetOut[i] = temp;    
            }   

    }else{

            for( i = 0; i < amountStudents; i++)
                vetOut[i] = vetIn[i];


            for( i = 0; i < amountStudents; i++ ){

                smaller = i;
                  
                for( j = i+1; j < amountStudents; j++ ){

                    if( CompareBirthDay( vetOut[smaller], vetOut[j] ) > 0 ){

                        smaller = j;
    
                    }            
                }
        
            temp = vetOut[smaller];
            vetOut[smaller] = vetOut[i];
            vetOut[i] = temp;    

            }
    }
}

//=====================================================================================================================================================================================================

int SearchChar( Student* vetIn, const int tamVetIn, Student* vetOut, const int tamVetOut, char* strDesejada, int tamStrDesejada ){

   int amountStudentsLocal = 0;

	Student copyVetIn[tamVetIn];
	for( int i = 0; i < tamVetIn; i++ )
		ToLower( copyVetIn[i].name, vetIn[i].name, tamVetIn );

		ToLower( strDesejada, strDesejada, tamStrDesejada );
    
    for( int i = 0; i < tamVetIn; i++ ){


        if( strncmp( copyVetIn[i].name, strDesejada, tamStrDesejada ) == 0 ) {   

            vetOut[amountStudentsLocal] = vetIn[i];
            amountStudentsLocal++;
            
        }
       
    }

    return amountStudentsLocal;

}

//=====================================================================================================================================================================================================

int authenticateCpf(){

	printf("Em breve...");

}

//=====================================================================================================================================================================================================

int authenticateBarthday(){

	printf("Em breve...");

}

//=====================================================================================================================================================================================================
