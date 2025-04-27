#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "resources.h"
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

	char freeBuffer[StrSizeMax];
   *a =  lowerest - 1;	

	do{

		printf("\nR: ");
		scanf(" %[^\n]",freeBuffer);
		putchar('\n');
		
		if( strlen (freeBuffer) > 1 ){

			printf("%sOpção invalida, tente novamente!%s\n\n", yellow_F, reset );
			continue;

		}else{

			*a = freeBuffer[0];

		}

		     if( ( *a < lowerest || *a > biggest ) ){

		         printf("%sOpção invalida, tente novamente!%s\n\n", yellow_F, reset );
		         
		     }
		 
    }while( *a < lowerest || *a > biggest );

} 

//=====================================================================================================================================================================================================
void StartMenu(){
	printf("\x1B[1;33m[0] Menu inicial\t%s",reset);
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

// Enzo =====================================================================================================================================================================================================


int menu(){ // FUNÇÃO PARA PRINTAR O MENU PRINCIPAL DE ESCOLHA
  int opcao;
  printf("Cadastro - 1 >>>>>>>>>  Sair - 0 >>>>>>>>>>>> Listar - 2 >>>>>>>>>>>> Atualizar - 3 >>>>>>>>>>>>>>>>> Excluir - 4 >>>>>>>>>>>>>>>>> Listar por Nome - 5 >>>>>>>>>>>>>>>>> Listar por Idade - 6 >>>>>>>>>>>>>>>>> Listar por Sexo - 7 ");
  scanf("%d",&opcao);
  return opcao;
}



void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



int validador_cpf (char cpf_validation[]){
  int numeros[11],soma = 0 ,i,j,digito1,digito2;

  j=0;
  // Tirar caracteres não numéricos e validar tamanho
  for(i=0; i < strlen(cpf_validation);i++) // strlen é uma função que retorna o tamanho da string, excluindo o caractere nulo
    {
      if(isdigit(cpf_validation[i]))
      {
        numeros[j] = cpf_validation[i] - '0'; //transforma o caracrtere em número
        j++;
      }
    }

  if(j!=11)
  {
    return 0;
  }

  //verificar se todos os números são iguais
  int todos_iguais = 1;
  for(i=0;i < 11; i++)
    {
      if(numeros[0] != numeros[i])
      {
        todos_iguais = 0;
        break;
      }
    }

  if (todos_iguais == 1)
  {
    return 0;
  }

  //Calculando o primeiro dígito verificador
  for (i=0;i < 9;i++)
    {
      soma = soma + numeros[i] * (10 - i);
    }

  digito1 = soma%11;
  if (digito1 < 2)
    digito1 = 0;
  else 
    digito1 = 11 - digito1;

  //Calculando o segundo dígito verificador
  soma =0;
  for (i=0;i < 9;i++)
    {
      soma = soma + numeros[i] * (11 - i);
    }
  soma = soma + (digito1*2);

  digito2 = soma%11;
  if (digito2 < 2)
    digito2 = 0;
  else 
    digito2 = 11 - digito2;

  //Validar dígitos
  if (digito1 == numeros[9] && digito2 == numeros[10])
    return 1;
  else
    return 0;
}

int validador_data (int dia, int mes, int ano)
{
   // Verifica ano válido
      if (ano < 1900 || ano > 2100)
          return 0;

      // Verifica mês válido
      if (mes < 1 || mes > 12)
          return 0;

      // Verifica dia válido para cada mês
      if (dia < 1)
          return 0;

      // Meses com 31 dias
      if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
          if (dia > 31)
              return 0;
      }
      // Meses com 30 dias
      else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
          if (dia > 30)
              return 0;
      }
      // Fevereiro
      else if (mes == 2) {
          // Verifica se é ano bissexto
          int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));

          if (bissexto) {
              if (dia > 29)
                  return 0;
          } else {
              if (dia > 28)
                  return 0;
          }
      }

      return 1; // Data válida
  }

