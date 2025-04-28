#include "database.h"
#include "resources.h"
#include "utils.h"
#include "cruds.h"
#include "cruds_professor.h"
#include "Disciplinas.h"


int main(){

   setlocale(LC_ALL,"Portuguese");

   int opcao, sair = 1;
   char key;
          
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
		Until(&key, '0', '5');
		system("clear||cls");

      if( key == '0' ) break;        

			switch (key){

		   	case '1':

			   	printf("\t\t\t%sMENU CADASTRO%s\n\n",bold,reset); Spacer(70);
			   	printf("[1] Cadastrar\t\t");
            	printf("[2] Atualizar\t\t");
            	printf("[3] Excluir\n");
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
                           	case '5': CadastrarProfessor( ListaProfessores, MaxProfessor ,&posicao, &IncrementadorMatricula ); break;
                           	case '6': cadastrar_disciplina(&qtd_disciplina, amountStudents, registredStudents); Pause(); break;
			                  }                               
                            
                    break;

                    case '2':/*AQUI VAI A FUNÇÃO DE Atualização */ 

								printf("[1] Aluno\t\t");
								printf("[2] Professor\t\t");
								printf("[3] Disciplina\t");
								Until( &key, '1', '3' );

							  	switch (key){

								case '1': UpdateStudent( &amountStudents, registredStudents, MaxStudent ); Pause(); break;

								case '2': AtualizarProfessor( ListaProfessores,&posicao); Pause(); break;
								
								case '3': atualizar_disciplina(&qtd_disciplina); Pause(); break;
							  }
    
								break;

                    case '3':/*AQUI VAI A FUNÇÃO DE Exclusão*/ 

								printf("[1] Aluno\t\t");
								printf("[2] Professor\t\t");
								printf("[3] Disciplina\t");
								Until( &key, '1', '3' );

								switch (key){

									case '1': DeleteStudent( &amountStudents, registredStudents, MaxStudent); Pause(); break;

									case '2': ExcluirProfessor( ListaProfessores, &posicao ); Pause(); break;

									case '3': excluir_disciplina(&qtd_disciplina); Pause(); break;
								}

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

					do{					

						printf("\t\t%sMENU PROFESSORES%s\n\n",bold,reset);
					 	printf("[1] Listar todos os professores\t");
		            printf("[2] Listar alunos ordenados por...");
						printf("[3] Buscar aluno por matricula");
					 	StartMenu();
		            Until( &key, '0', '3' );
					 
						if( key == '1' ) ListarProfessor( ListaProfessores, posicao );						

						if( key == '2' ){
		                     
		               printf("[5] Sexo...\t[6] Nome\t[7] Idade");
		               Until( &key, '5', '7' );

		               switch(key){

		               case '5': printf("\n[8] Homem\t\t [9] Mulher"); Until( &key, '8', '9' ); ListarProfessorSexo( ListaProfessores, &posicao, key); break;
		               case '6': ListarProfessorNome( ListaProfessores, CopiaProfessores, aux_struct, &posicao ); break;
		               case '7': ListarProfessorIdade( ListaProfessores, CopiaProfessores, aux_struct, &posicao ); break;   

		               }
		                 
		             }
		                 
		             //if( key != '0') ListStudents( amountStudents, registredStudents, MaxStudent, key);
		                
		             Pause();
		             system("clear||cls");

                	}while( key != '0' );					


				
			   break;

		    	case '4':

			   	printf("\t\t\t\t\t%sMENU DISCIPLINAS%s\n\n",bold,reset);
				Spacer(105);
			   	printf("\n[1] Listar disciplinas\t\t");
               	printf("[2] Incluir Aluno na Disciplina\t\t");
				printf("[3] Excluir Aluno da Disciplina\n");
			    	StartMenu();
               Until(&key, '0', '3');

			   switch(key){

					case '1': listar_disciplina(&qtd_disciplina); Pause(); break;
					case '2': incluir_aluno_disciplina(&qtd_disciplina, amountStudents, registredStudents); Pause(); break;


			   }

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
