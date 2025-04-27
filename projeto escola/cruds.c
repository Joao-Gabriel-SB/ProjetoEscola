#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resources.h"
#include "database.h"
#include "utils.h"


//==========================================================================================================================================================================================

int ListStudents(int amountStudents, Student* registredStudents, const int ArraySize, char key){        

        char again = '1'; 
        char sex = '0';
        char search[StrSizeMax];
        int i = 0;
        int desiredIdToFind;     
        
        Student copy[ArraySize];

        for(int j = 0; j < ArraySize; j++ )
            copy[j] = registredStudents[j];
        
        if( amountStudents == 0 ) {
            printf("\n\t\t\t\t\t%sNenhum aluno Matriculado.%s\n\n\n",yellow_F,reset);
            Pause();
            return 0;
        }
        
        switch (key){
        
            case '1': i = 0; break;

            case '3': 

                printf("Matricula do estudante:\t");
                scanf(" %d",&desiredIdToFind); 
                i = SearchInt( amountStudents, registredStudents, sizeof(Student), GetId, desiredIdToFind );

                if( i == -1 ){

                    printf("\n\t\t\t\t%sNenhum aluno encontrado com essa matricula.%s\n", yellow_F, reset); 
             
					Pause();
                    return -1;
                }

                break;

            case '5': 

                printf("Pesquisar:\t");
                scanf(" %[^\n]",search);

                amountStudents = SearchChar( registredStudents, amountStudents, copy, ArraySize, search, strlen(search));

				if( amountStudents == 0 ){

                    printf("\n\t\t\t\t%sNenhum aluno encontrado.%s\n", yellow_F, reset);
					Pause();
                    return -1;
                }

                break;


            case '6': 

                printf("\n\n\t\tOrdem Alfabetica:\n\n"); 
                CharSort( amountStudents , ArraySize, registredStudents, copy, ArraySize, 1 ); 
                break;

            case '7': 

                printf("\n\n\t\tIdade:\n\n"); 
                CharSort( amountStudents , ArraySize, registredStudents, copy, ArraySize, 0 );
                break;

            case '8': 
                
                sex = '1'; 
                printf("\t\t\tLista de alunos\n"); 
                break;

            case '9': 
                sex = '2'; 
                printf("\t\t\tLista de alunas\n"); 
                break;
        }
        

        for(; i<amountStudents && again == '1'; i++){
            
            if( sex == '0' || (sex == '1' && copy[i].sex == 'M') || (sex == '2' && copy[i].sex == 'F')){ // separa por sexo

                Spacer(75);


                printf("\n\nNome:\t\t%s\n",copy[i].name);

                printf("Nascimento:\t");
                printf("%02d/%02d/%d\n", copy[i].birthday.day, copy[i].birthday.month, copy[i].birthday.year);

                copy[i].sex == 'M' ? printf("Sexo:\t\tMasculino\n"): printf("sexo:\t\tFeminino\n");
               
                printf("Cpf:\t\t");

                for(char a = 0; a<11;a++){

                    if(a == 3 || a == 6)
                        printf(".");
                    if(a == 9)
                        printf("-");

                        printf("%c",copy[i].cpf[a]);

                    }

                printf("\nMatricula:\t%d\t\n\n",copy[i].id);
                
                if(key == '3'){
					Pause();
					return i;
				}
            }
        }
      Pause();
		return 0;
}


//==========================================================================================================================================================================================

int InsertStudent( int* amountStudents, Student* registredStudents, const int ArraySize, int* idCounter ){

        char again = '1';

            while( again == '1' ){

                if( *amountStudents == ArraySize ){
                    char tryAgain = '1';              
                    printf("Sem vagas disponiveis.");
                    StartMenu();
                      while(tryAgain != '0'){
                        AnswerField(&tryAgain);
                      }
                      return -1;
                }

				system("clear||cls");
				printf("\t\t\t%sCadastrando Aluno%s\n\n", bold, reset);
				Spacer(75);

		        printf("\nNome do aluno:\t\t\t");
		        scanf(" %[^\n]",registredStudents[*amountStudents].name);

		        //do{
		        printf("Data de Nascimento(##/##/####):\t");
		        scanf(" %d/ %d/ %d",
				    &registredStudents[*amountStudents].birthday.day, 
				    &registredStudents[*amountStudents].birthday.month, 
				    &registredStudents[*amountStudents].birthday.year);
		        //validacaoNascimento(valido, alunosCadastrados[i].nascimento.dia, alunosCadastrados[i].nascimento.mes, alunosCadastrados[i].nascimento.ano) } while (!valido);

		        printf("Sexo(M/F):\t\t\t");
		        scanf(" %c",&registredStudents[*amountStudents].sex);

		        //do{
		        printf("Cpf:\t\t\t\t");
		        scanf(" %[^\n]",registredStudents[*amountStudents].cpf);
		        //validacaocpf(valido, cpf) } while(!valido);

		        registredStudents[*amountStudents].id = *idCounter;

		        (*amountStudents)++;
		        (*idCounter)++;

		        printf("\n\n\t\t%sCadastro Realizado com sucesso!!!%s\n", yellow_F, reset);

		        printf("\n\n[1] Cadastrar Outro Aluno?\t\t[2] Listar alunos cadastrados\t\t");StartMenu();
		        Until( &again, '0', '2' );
		            
		        switch (again){
				    case '0': again = '0';
				    case '1': break;
				    case '2':
						ListStudents( *amountStudents, registredStudents, ArraySize, '1' );
						printf("[1] Cadastrar outro aluno"); StartMenu();
						Until( &again, '0', '1' );
		        }
				
            }
}

//==========================================================================================================================================================================================

int UpdateStudent( int* amountStudents, Student* registredStudents, const int ArraySize ){

		int position;
		int sucess;		

		printf("\t\t\t%sDados Atuais:%s\n", bold, reset );
		
		sucess = ListStudents( *amountStudents, registredStudents, ArraySize, '3');		

		if ( sucess != -1 ){

		printf("Novo nome:\t"); scanf(" %[^\n]",registredStudents[sucess].name);

		printf("Data de Nascimento(##/##/####):\t");
                scanf(" %d/ %d/ %d",
						&registredStudents[sucess].birthday.day, 
						&registredStudents[sucess].birthday.month, 
						&registredStudents[sucess].birthday.year);

		printf("Sexo(M/F):\t\t\t");	scanf(" %c",&registredStudents[sucess].sex);

		printf("Cpf:\t\t\t\t"); scanf(" %[^\n]",registredStudents[sucess].cpf);

		printf("%sAluno Atualizado com sucesso!!!%s", yellow_F, reset );
				
		}
		
}

//==========================================================================================================================================================================================

int DeleteStudent( int* amountStudents, Student* registredStudents, const int ArraySize ){
 
	int i, findedId = -1;
	int desiredIdToExclude;
	Student temp;

	printf("Matricula do Aluno:\t "); scanf(" %d",&desiredIdToExclude);

	for( i = 0; i < *amountStudents; i++ )
		
		if( registredStudents[i].id == desiredIdToExclude ){

			findedId = i; break;
	
		}	
	
	if ( findedId != -1 ){

		temp = registredStudents[findedId];
	
		for( i = findedId; i < *amountStudents - 1; i++ )
	
			registredStudents[i] = registredStudents[i+1];
	
		registredStudents[i] = temp;
		(*amountStudents)--;
		printf("\n\n\t\t%sAluno Excluido com sucesso!!!%s\n", yellow_F, reset );
		Spacer(70);
	}else{

		printf ("\n\t  %sNenhum aluno encontrado com essa matricula.%s\n", yellow_F, reset );
		Spacer(70);
	
	}

	Pause();
}

//==========================================================================================================================================================================================
