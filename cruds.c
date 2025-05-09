#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resources.h"
#include "database.h"
#include "utils.h"
#include "cruds_professor.h"

//==========================================================================================================================================================================================

int ListStudents(int amountStudents, Student* registredStudents, const int ArraySize, char key){        

        char again = '1'; 
        char sex = '0';
        char search[StrSizeMax];
        int i = 0;
        int desiredIdToFind;     
        int qtdLocal=0;

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

				case '4':

					 for(int j = 0; j < amountStudents; j++ ){

						if( registredStudents[j].qtdDisciplinas < 3 ){

            			copy[j] = registredStudents[j];
							qtdLocal++;

						}
					 }
					 
					 amountStudents = qtdLocal;
					 printf("\n\namount %d\n",amountStudents);
					 if ( amountStudents == 0 ){

							printf("\n%sNão existem estudantes cadastrados em menos de 3 disciplinas.%s\n",yellow_F,reset);
							Pause();
							return -1;
					 }

					 printf("\tAlunos matriculados em menos de 3 disciplinas:\n");

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
					
                printf("\nMatricula:\t%d\t",copy[i].id);

					printf("\nDisciplinas:\t");
					for(int j = 0; j<copy[i].qtdDisciplinas; j++)
					 	printf("%s, ",copy[i].disciplinasCadastrado[j] );

               putchar('\n');

						
                if(key == '3'){
						Pause();
						return i;
					 }

            }
        }
      Pause();
		return 0;
}

//======================================================================================================================================


int ListarPessoas( int amountStudents, Student* registredStudents, professores* ListaProfessores, int posicao, int ArraySize ){

   char search[StrSizeMax];
	printf("Pesquisar:\t");
	scanf(" %[^\n]",search);

	Student copyStd[ArraySize];
	professores copyProf[ArraySize];

	amountStudents = SearchChar( registredStudents, amountStudents, copyStd, ArraySize, search, strlen(search));


	if( amountStudents != 0 ) ListStudents( amountStudents, copyStd, MaxStudent, '1' );

	posicao = SearchCharProf( ListaProfessores, posicao, copyProf, ArraySize, search, strlen(search) );

	if( posicao != 0 ) ListarProfessor( copyProf, posicao );

	if( amountStudents == 0 && posicao == 0){

		printf("\n\t\t\t\t%sNinguém foi encontrado.%s\n", yellow_F, reset);
		Pause();
		return -1;

	}

}

//==========================================================================================================================================


int InsertStudent( int* amountStudents, Student* registredStudents, const int ArraySize, int* idCounter ){

	int verificador_sexo = 1;
	int cpf_valido = 1;
	int data_valido = 1;
        char again = '1';
	int cancelar;

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

		        do{

		        printf("Data de Nascimento(##/##/####):\t");
		        scanf(" %d/ %d/ %d",
				    &registredStudents[*amountStudents].birthday.day, 
				    &registredStudents[*amountStudents].birthday.month, 
				    &registredStudents[*amountStudents].birthday.year);

		        data_valido = validador_data(registredStudents[*amountStudents].birthday.day,registredStudents[*amountStudents].birthday.month,registredStudents[*amountStudents].birthday.year);


      			if (data_valido == 0)
      			{

        		printf("Data de Nascimento digitada está INVÁLIDA. Tente novamente.\n");

      			}

    			}while(data_valido == 0);

		        printf("Sexo(M/F):\t\t\t");
		        
		        while (verificador_sexo) {

        			scanf(" %c",&registredStudents[*amountStudents].sex);


        			if (registredStudents[*amountStudents].sex == 'm' || registredStudents[*amountStudents].sex == 'M' ||
            				registredStudents[*amountStudents].sex == 'f' || registredStudents[*amountStudents].sex == 'F') {

            				break;

        			} else {

            				printf("Entrada inválida, tente novamente.\nSexo (M/F): ");
					limpar_buffer();
        			}
    			}
		        

		        do{
				printf("Cpf:\t\t\t\t");
				scanf(" %[^\n]",registredStudents[*amountStudents].cpf);
				
				cpf_valido = validador_cpf(registredStudents[*amountStudents].cpf);

		      		if(cpf_valido == 0)
		      		{

					printf("CPF Inválido, tente novamente!.\n");

		      		}  

		    	}while(cpf_valido == 0);

			cancelar = Confirmar();
			if ( cancelar == -1 ) {Pause();return -1;}				

		        registredStudents[*amountStudents].id = *idCounter;

		        (*amountStudents)++;
		        (*idCounter)++;

		        printf("\n\n\t\t%sCadastro Realizado com sucesso!!!%s\n", yellow_F, reset);

		        printf("\n\n[1] Cadastrar Outro Aluno?\t\t[2] Listar alunos cadastrados\n");StartMenu();

		        Until( &again, '0', '2' );
		            
		        switch (again){
				    case '0': again = '0';
				    case '1': break;
				    case '2':
						ListStudents( *amountStudents, registredStudents, ArraySize, '1' );

						printf("\n\n[1] Cadastrar outro aluno\t"); StartMenu();

						Until( &again, '0', '1' );
		        }
				
            }
}

//==========================================================================================================================================================================================

int UpdateStudent( int* amountStudents, Student* registredStudents, const int ArraySize ){

		int position;
		int sucess;		

		if(*amountStudents == 0){

			printf("\n\t\t\t%sNenhum aluno matriculado.%s\n\n\n",yellow_F,reset);
			Pause();
			return -1;

	   }


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

	Pause();

}

//==========================================================================================================================================================================================

int DeleteStudent( int* amountStudents, Student* registredStudents, const int ArraySize ){

 	int cancelar;
	int i; 
	int findedId = -1;
	int desiredIdToExclude;
	Student temp;

	if(*amountStudents == 0){

			printf("\n\t\t\t%sNenhum aluno matriculado.%s\n\n\n",yellow_F,reset);
			Pause();
			return -1;

	}

	ListStudents( *amountStudents, registredStudents, ArraySize, '1' ); 

	printf("\n\nMatricula do Aluno:\t "); scanf(" %d",&desiredIdToExclude);

	for( i = 0; i < *amountStudents; i++ )
		
		if( registredStudents[i].id == desiredIdToExclude ){

			findedId = i; break;
	
		}	
	
	if ( findedId != -1 ){
		
		cancelar = Confirmar();
		if ( cancelar == -1 ) {Pause();return -1;}	
		
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

void aniversarianteDoMes( int amountStudents, Student* registredStudents, professores* ListaProfessores, int posicao, int ArraySize ){

	int mes;
	int qtdLocalStd = 0;
	int qtdLocalProf = 0;
	Student copyStd[ArraySize];
	professores copyProf[ArraySize];

	printf("Aniversario no mes:\t");
	scanf(" %d",&mes);

	for( int i = 0; i < amountStudents; i++ ){
		if( registredStudents[i].birthday.month == mes ){
			copyStd[i] = registredStudents[i];
			qtdLocalStd++;
		}
	}

	for( int i = 0; i < posicao; i++ ){
		if( ListaProfessores[i].nascimento.mes == mes ){
			copyProf[i] = ListaProfessores[i];
			qtdLocalProf++;
		}
	}

	if ( qtdLocalStd != 0 ) ListStudents( qtdLocalStd, copyStd, ArraySize, '1');
	if ( qtdLocalProf != 0 ) ListarProfessor( copyProf, qtdLocalProf );
	if ( qtdLocalStd == 0 && qtdLocalProf == 0 ) {printf("\n\n\t\t%sNinguém faz aniversário nesse mês.%s",yellow_F,reset); Pause();}
}


