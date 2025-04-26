#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utils.h"
#include "resources.h"
#include "cruds.h"
#include "database.h"

int main(int argc,char *argv[]){

   setlocale(LC_ALL,"Portuguese");

    
   char sair=0,key;
          
	system("clear||cls");

	printf("%s\n\t\tSeja bem vindo ao sistema de cadastro da escola!\t\t\n%s",bold,resetBold);Spacer(75);

	do{
	   printf("\n\t\t\t\t%sMENU INICIAL\n\n",bold); Spacer(75);
        
      printf("[1] Menu cadastro\t\t");
      printf("[2] Menu aluno\t\t");
      printf("[3] Menu Professor\t\n");
      printf("[4] Menu disciplina\t\t");
      printf("[5] Pesquisar\t\t");
      printf("%s[0] Sair\t%s", yellow_F, reset);
		AnswerField(&key);
		system("clear||cls");

      if( key == '0' ) break;        

			switch (key){

		   	case '1':

			   	printf("\t\t\t%sMENU CADASTRO%s\n\n",bold,reset); Spacer(70);
			   	printf("[1] Cadastrar\t\t");
            	printf("[2] Atualizar\t\t");
            	printf("[3] Excluir\t\t");
            	StartMenu();
            	Until( &key, '0', '3' );
                
               	switch(key){

			        		case '1': 

                     	printf("[4] Aluno\t\t");
                     	printf("[5] Professor\t\t");
                     	printf("[6] Disciplina\t");
			            	Until( &key, '4', '6' );

                        	switch(key){

			                  	case '4': InsertStudent( &amountStudents, registredStudents, MaxStudent, &idCounter ); break;
                           	case '5':/*AQUI VAI A FUNÇÃO DE CADASTRO DE PROFESSORES DE ENZO */ break;
                           	case '6':/*AQUI VAI A FUNÇÃO DE CADASTRO DE PROFESSORES DE NETO */ break;
			                  }                               
                            
                    break;

                    case '2':/*AQUI VAI A FUNÇÃO DE Atualização */ 

								UpdateStudent( &amountStudents, registredStudents, MaxStudent );
                			Pause();

                        break;  
    
                    case '3':/*AQUI VAI A FUNÇÃO DE Exclusão*/ 

 						  		DeleteStudent( &amountStudents, registredStudents, MaxStudent);

	
								Pause(); 
                        break;

               	} 
			    
		   	break;

		    	case '2':

            	do{ 

			      	printf("\t\t\t\t\t\t%sMENU ALUNOS%s\n\n",bold,reset);Spacer(120);
			         printf("[1] Listar todos os alunos\t\t");
                  printf("[2] Listar alunos ordenados por...\t\t");
                  printf("[3] Buscar aluno por matricula");
                  StartMenu();	
                    
                  Until( &key, '0', '3' );        
                    
                  if( key == '2' ){
                        
                  	printf("[5] Sexo...\t[6] Nome\t[7] Idade");
                     Until( &key, '5', '7' );

                     switch(key){

                     	case '5': printf("\n[8] Homem\t\t [9] Mulher"); Until( &key, '8', '9' ); break;
                        case '6': break;
                        case '7': break;   

                     }
                    
                  }
                    
                  if( key != '0') ListStudents( amountStudents, registredStudents, MaxStudent, key);
                   
                  Pause();
                	system("clear||cls");
                	}while( key != '0' );
        			    
		    	break;

		    	case '3':

			   	printf("\t\t%sMENU PROFESSORES%s\n\n",bold,reset);
			    	printf("[1] Listar professores\t");
               printf("[2] Em Breve...");
			    	StartMenu();
               AnswerField(&key);
			    
			   break;

		    	case '4':

			   	printf("\t\t%sMENU DISCIPLINAS%s\n\n",bold,reset);
			   	printf("[1] Listar disciplinas\t");
               printf("[2] Em Breve...");
			    	StartMenu();
               AnswerField(&key);

			   break;

            case '5':
             
            	ListStudents( amountStudents, registredStudents, MaxStudent, key);               
               Pause();
               break;                

			}

        	key = '1';
	    	system("clear||cls");
        
	}while(key != '0');

}
