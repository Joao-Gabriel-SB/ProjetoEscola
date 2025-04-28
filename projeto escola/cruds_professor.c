#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"


void ListarProfessor( professores ListaProfessores[], int posicao ){

   int i;
	
	if( posicao == 0 ) {

      printf("\n\t\t\t\t\t%sNenhum professor cadastrado.%s\n\n\n",yellow_F,reset);
 
      i = posicao + 1; 

   }

        for( i=0; i < posicao; i++ ){

			Spacer(75);
			
			printf("\n\nNome:\t\t%s\n",ListaProfessores[i].nome);

			printf("Nascimento:\t%02d/%02d/%d\n",ListaProfessores[i].nascimento.dia,ListaProfessores[i].nascimento.mes,ListaProfessores[i].nascimento.ano );

			ListaProfessores[i].sexo == 'M' ? printf("Sexo:\t\tMasculino\n") : printf("sexo:\t\tFeminino\n");

			printf("Cpf:\t\t");

         	for(char a = 0; a<11;a++){

            	if(a == 3 || a == 6)
               	printf(".");
                  if(a == 9)

                  	printf("-");

                     printf("%c",ListaProfessores[i].cpf[a]);

         	}

			printf("\nMatricula:\t%d\t\n\n",ListaProfessores[i].matricula );
         
        }

	Pause();

}

//===================================================================================================================================================================

int CadastrarProfessor( professores ListaProfessores[], int limite, int* posicao, int *IncrementadorMatricula ) {

    int verificador_sexo = 1;
	 int cpf_valido = 1;
	 int data_valido = 1;
	 char sair = '1';
	  

    // Gera a matrícula
	while ( sair == '1' ){
	
	if ( *posicao >= limite ) {
 
		  char erro = '1';
        printf("Sem vagas disponiveis.");
		  StartMenu();	

		  while( erro != '0' ){
        		AnswerField(&erro);
        }
        return 0;
	}

	verificador_sexo = 1;

    ListaProfessores[*posicao].matricula = *IncrementadorMatricula + 1;

    *IncrementadorMatricula = ListaProfessores[*posicao].matricula;

    ListaProfessores[*posicao].ativo = 1;

	system("clear||cls");
	printf("\t\t\t%sCadastrando professor%s\n\n", bold, reset);
	Spacer(75);



    printf("Número de Matrícula:\t\t%d\n", ListaProfessores[*posicao].matricula);


    printf("Nome do Professor:\t\t");
	 scanf(" %[^\n]",ListaProfessores[*posicao].nome );

    // Validação do sexo
    printf("Sexo (M/F):\t\t\t");

    while (verificador_sexo) {

        scanf(" %c", &ListaProfessores[*posicao].sexo);


        if (ListaProfessores[*posicao].sexo == 'm' || ListaProfessores[*posicao].sexo == 'M' ||
            ListaProfessores[*posicao].sexo == 'f' || ListaProfessores[*posicao].sexo == 'F') {

            verificador_sexo = 0;

        } else {

            printf("Entrada inválida, tente novamente.\nSexo (M/F): ");
				limpar_buffer();
        }
    }
    // Data de nascimento
    do{
      printf("Nascimento (dd/mm/aaaa):\t");
      scanf(" %d/ %d/ %d", 
      &ListaProfessores[*posicao].nascimento.dia, 
      &ListaProfessores[*posicao].nascimento.mes, 
      &ListaProfessores[*posicao].nascimento.ano);

      //data_valido = validador_data(ListaProfessores[*posicao].nascimento.dia,ListaProfessores[*posicao].nascimento.mes,ListaProfessores[*posicao].nascimento.ano);


      if (data_valido == 0)
      {

        printf("Data de Nascimento digitada está INVÁLIDA. Tente novamente.\n");

      }

    }while(data_valido == 0);



    // CPF
    do{
      printf("CPF:\t\t\t\t");

      scanf(" %[^\n]",ListaProfessores[*posicao].cpf );
		ListaProfessores[ *posicao ].cpf[ strcspn ( ListaProfessores[ *posicao ].cpf, "\n" ) ] = '\0'; 
      

      //cpf_valido = validador_cpf(ListaProfessores[*posicao].cpf);

      if(cpf_valido == 0)
      {

        printf("CPF Inválido, tente novamente!.\n");

      }  

    }while(cpf_valido == 0);

    // Atualiza posição
    (*posicao)++;

	 printf("\n\n\t\t%sCadastro Realizado com sucesso!!!%s\n", yellow_F, reset);

	 printf("\n\n[1] Cadastrar Outro Professor?\t\t[2] Listar Professores cadastrados\t\t\n");StartMenu();

	 	Until( &sair, '0', '2' );
		            
			switch (sair){

				case '0': sair = '0';
				case '1': break;
			   case '2':
					ListarProfessor( ListaProfessores, *posicao );
					printf("[1] Cadastrar outro professor"); StartMenu();
					Until( &sair, '0', '1' );
		   }
	}
}

//=============================================================================================================================


int ExcluirProfessor(professores ListaProfessores[],int *posicao){
    int achou = 0;
    int ValueMatricula,VerificadorMatricula,i,j;

	 if(*posicao == 0){

			printf("\n\t\t\t%sNenhum professor cadastrado.%s\n\n\n",yellow_F,reset);
			Pause();
			return -1;

	}

    printf("Informe o número de matrícula: ");
    scanf("%d",&VerificadorMatricula);
    ValueMatricula = 0;

	
    for(i=0; i <= *posicao;i++) // exclusao lógica (inativando usuário)
      {
        if(ListaProfessores[i].matricula == VerificadorMatricula)
          {
            ValueMatricula = 1;
            ListaProfessores[i].ativo = -1;
            break;
          }
        }
        if(ValueMatricula == 0)
        {
        	printf("Número de Matrícula Inválido.\n");
		  	Pause();
		  	return -1;
        }
        if(ValueMatricula == 1)
        {
          for (j = i;j < *posicao - 1;j++)
            {
              ListaProfessores[j].matricula =  ListaProfessores[j+1].matricula;
              strcpy(ListaProfessores[j].nome, ListaProfessores[j+1].nome);
              ListaProfessores[j].sexo = ListaProfessores[j+1].sexo;
              ListaProfessores[j].nascimento.dia = ListaProfessores[j+1].nascimento.dia;
              ListaProfessores[j].nascimento.mes = ListaProfessores[j+1].nascimento.mes;
              ListaProfessores[j].nascimento.ano = ListaProfessores[j+1].nascimento.ano;
              strcpy(ListaProfessores[j].cpf, ListaProfessores[j+1].cpf);
              ListaProfessores[j].ativo = ListaProfessores[j+1].ativo;
            }
            (*posicao)--;
          achou = 1;
        }

    if (achou == 1)
      printf("Professor excluído com sucesso.\n");
    else
      printf("Matrícula inexistente.\n");

  	 Pause();
}




void ListarProfessorNome(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao){

    int i,j;
    int comparador;

    for(i=0;i < *posicao; i++)
        {
            CopiaProfessores[i] = ListaProfessores[i]; 
        }

    // iniciando o processo de comparação dos nomes p/ verificar o menor e colocar em ordem
    for( i=0;i < *posicao;i++ ){
            for(j=i + 1;j < *posicao;j++)
              {
                comparador = strcmp(CopiaProfessores[i].nome,CopiaProfessores[j].nome);
                if (comparador > 0)
                {
                    aux_struct = CopiaProfessores[i];
                    CopiaProfessores[i] = CopiaProfessores[j];
                    CopiaProfessores[j] = aux_struct;
                }
              }
          }
        //Listando todos os professores cadastrados no sistema ordenados por nome
        for(i=0;i < *posicao;i++)
        {

				Spacer(75);
				
				printf("\n\nNome:\t\t%s\n",CopiaProfessores[i].nome);

				printf("Nascimento:\t%02d/%02d/%d\n",CopiaProfessores[i].nascimento.dia, CopiaProfessores[i].nascimento.mes, CopiaProfessores[i].nascimento.ano );

				ListaProfessores[i].sexo == 'M' ? printf("Sexo:\t\tMasculino\n") : printf("sexo:\t\tFeminino\n");

				printf("Cpf:\t\t");

		      	for(char a = 0; a<11;a++){

		         	if(a == 3 || a == 6)
		            	printf(".");
		               if(a == 9)

		               	printf("-");

		                  printf("%c",CopiaProfessores[i].cpf[a]);

		      	}

				printf("\nMatricula:\t%d\t\n\n",CopiaProfessores[i].matricula );

        }
	Pause();
}





void ListarProfessorIdade(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao){
    // ORDENAÇÃO POR IDADE
    // copiando a struct principal para struct que será ordenada por idade
    int i,j;
    for(i=0;i < *posicao; i++)
        {
            CopiaProfessores[i] = ListaProfessores[i]; 
        }

    //fazendo a contagem da idade de cada professor cadastrado para posteriormente realizar a ordenação
    for(i=0;i <= *posicao;i++)
      {
        CopiaProfessores[i].nascimento.total = CopiaProfessores[i].nascimento.ano*10000 + CopiaProfessores[i].nascimento.mes*100 + CopiaProfessores[i].nascimento.dia;
      }

    //utilizando o insertion sort para ordenação

    for(i=1 ; i < *posicao;i++)
      {
        aux_struct = CopiaProfessores[i];

        for (j = i - 1; j >= 0 && CopiaProfessores[j].nascimento.total < aux_struct.nascimento.total; j--)
          {
            CopiaProfessores[j+1] = CopiaProfessores[j];

          }
        CopiaProfessores[j+1] = aux_struct;
      }

    //Listando todos os professores cadastrados no sistema ordenados por idade
    for(i=0;i < *posicao;i++){
        
				Spacer(75);
				
				printf("\n\nNome:\t\t%s\n",CopiaProfessores[i].nome);

				printf("Nascimento:\t%02d/%02d/%d\n",CopiaProfessores[i].nascimento.dia, CopiaProfessores[i].nascimento.mes, CopiaProfessores[i].nascimento.ano );

				ListaProfessores[i].sexo == 'M' ? printf("Sexo:\t\tMasculino\n") : printf("sexo:\t\tFeminino\n");

				printf("Cpf:\t\t");

		      	for(char a = 0; a<11;a++){

		         	if(a == 3 || a == 6)
		            	printf(".");
		               if(a == 9)

		               	printf("-");

		                  printf("%c",CopiaProfessores[i].cpf[a]);

		      	}

				printf("\nMatricula:\t%d\t\n\n",CopiaProfessores[i].matricula );
        
	}
	Pause();
}




void ListarProfessorSexo(professores ListaProfessores[], int *posicao, char key){
    //Listando os professores por Sexo

	int i;
	
	char sexo = key == '8' ? 'M' : 'F';

	sexo == 'F' ? printf("\t\t\tLista Professoras\n") : printf("\t\t\tLista Professores\n");

		for(i=0;i < *posicao;i++){

			if ( ListaProfessores[i].sexo == sexo || ListaProfessores[i].sexo == sexo + 32 ){

				Spacer(75);

		   	printf("\n\nNome:\t\t%s\n",ListaProfessores[i].nome);

				printf("Nascimento:\t%02d/%02d/%d\n",ListaProfessores[i].nascimento.dia,ListaProfessores[i].nascimento.mes,ListaProfessores[i].nascimento.ano );

				ListaProfessores[i].sexo == 'M' ? printf("Sexo:\t\tMasculino\n") : printf("sexo:\t\tFeminino\n");

				printf("Cpf:\t\t");

		      	for(char a = 0; a<11;a++){

		         	if(a == 3 || a == 6)
		            	printf(".");
		               if(a == 9)

		               	printf("-");

		                  printf("%c",ListaProfessores[i].cpf[a]);

		      	}

				printf("\nMatricula:\t%d\t\n\n",ListaProfessores[i].matricula );
		       
			}
		}
	
	Pause();
}

//==================================================================================================================================================================

int SearchCharProf( professores* vetIn, const int tamVetIn, professores* vetOut, const int tamVetOut, char* strDesejada, int tamStrDesejada ){

   int qtdProfessoresLocal = 0;

	professores copyVetIn[tamVetIn];
	for( int i = 0; i < tamVetIn; i++ )
		ToLower( copyVetIn[i].nome, vetIn[i].nome, tamVetIn );

		ToLower( strDesejada, strDesejada, tamStrDesejada );
    
    for( int i = 0; i < tamVetIn; i++ ){


        if( strncmp( copyVetIn[i].nome, strDesejada, tamStrDesejada ) == 0 ) {   

            vetOut[qtdProfessoresLocal] = vetIn[i];
            qtdProfessoresLocal++;
            
        }
       
    }

    return qtdProfessoresLocal;

}

//==================================================================================================================================================================

int BuscarPorMatriculaProf( professores ListaProfessores[], int posicao ){

  int achou = 0;
  int ValueMatricula,VerificadorMatricula,i;
  printf("Informe o número de matrícula: ");
  scanf("%d",&VerificadorMatricula);
  ValueMatricula = 0;

  for(i=0; i <= posicao;i++) // exclusao lógica (inativando usuário)
      {
        if(ListaProfessores[i].matricula == VerificadorMatricula)
          {
            ValueMatricula = 1;
            break;
          }
        }
  if(ValueMatricula == 1)
  {
    Spacer(75);
			
			printf("\n\nNome:\t\t%s\n",ListaProfessores[i].nome);

			printf("Nascimento:\t%02d/%02d/%d\n",ListaProfessores[i].nascimento.dia,ListaProfessores[i].nascimento.mes,ListaProfessores[i].nascimento.ano );

			ListaProfessores[i].sexo == 'M' ? printf("Sexo:\t\tMasculino\n") : printf("sexo:\t\tFeminino\n");

			printf("Cpf:\t\t");

         	for(char a = 0; a<11;a++){

            	if(a == 3 || a == 6)
               	printf(".");
                  if(a == 9)

                  	printf("-");

                    printf("%c",ListaProfessores[i].cpf[a]);

         	}

			printf("\nMatricula:\t%d\t\n\n",ListaProfessores[i].matricula );
         return i;
   }
   else
   {
    printf("Não existe professor cadastrado com a matrícula digitada.\n");
	 return -1;
   }
	Pause();
  }


//========================================================================================================================================================


int AtualizarProfessor(professores ListaProfessores[], int *posicao){

    int sair_atualizar = 1;
	 int i;
    int ValueMatricula = 0;
    int verificador_sexo;
 	 int VerificadorMatricula;
	 int cpf_valido = 0;
	 int data_valido = 0;
	 char opcao_atualizar;

    if(*posicao == 0){

		printf("\n\t\t\t%sNenhum professor cadastrado.%s\n\n\n",yellow_F,reset);
   	Pause();
   	return -1;

	 }

	 ListarProfessor( ListaProfessores, *posicao );

    i = BuscarPorMatriculaProf( ListaProfessores, *posicao );

    if( i != -1 ){

        while ( opcao_atualizar != '0' ){

					Spacer(75); putchar('\n');
					printf("\t\t\tAtualizar o campo:\n");
					Spacer(75); putchar('\n');

					printf("[1] Nome\t\t");
					printf("[2] Sexo\t\t");
					printf("[3] Nascimento\n");
					printf("[4] CPF\t\t\t");
					StartMenu();
               Until(&opcao_atualizar, '0', '4');
               

        switch (opcao_atualizar){

            case '1':

                printf("Novo Nome: ");
					 scanf(" %[^\n]",ListaProfessores[i].nome );
                
            break;

            case '2':

               printf("Novo Sexo (M/F): ");
               verificador_sexo = 1;

               while (verificador_sexo == 1){

                  scanf(" %c",&ListaProfessores[i].sexo);
                  limpar_buffer();
                  //verifica se a entrada está correta, solicitando que o usuário informe novamente o sexo caso esse esteja inválido.
                  if (ListaProfessores[i].sexo == 'm' || ListaProfessores[i].sexo == 'M' || ListaProfessores[i].sexo == 'f' || ListaProfessores[i].sexo == 'F'){

                        verificador_sexo = 0;

                  }else{

                       printf("Entrada inválida, tente novamente.\n");
                       printf("Sexo (M/F): ");
                       verificador_sexo = 1;
                  }
             }
            break;

            case '3':
                // Data de nascimento
                do{
                  printf("Nova Data de Nascimento (dd/mm/aaaa): ");
                  scanf("%d/%d/%d", 
                  &ListaProfessores[*posicao].nascimento.dia, 
                  &ListaProfessores[*posicao].nascimento.mes, 
                  &ListaProfessores[*posicao].nascimento.ano);
                  data_valido = validador_data(ListaProfessores[*posicao].nascimento.dia,ListaProfessores[*posicao].nascimento.mes,ListaProfessores[*posicao].nascimento.ano);
                  limpar_buffer();
                  if (data_valido == 0)
                  {
                    printf("Data de Nascimento digitada está INVÁLIDA. Tente novamente.\n");
                  }
                }while(data_valido == 0);
            break;

            case '4':        
                // CPF
                do{
                  printf("Novo CPF: ");
                  scanf(" %s[^\n]",ListaProfessores[*posicao].cpf);
                  limpar_buffer();
                  cpf_valido = validador_cpf(ListaProfessores[*posicao].cpf);
                  if (cpf_valido == 0)
                  {
                    printf("CPF Inválido, tente novamente!.\n");
                  }  
                }while(cpf_valido == 0);           
            break;                            

        }
			printf("\t\t\t%sAtualizado com sucesso!!!%s\n\n", yellow_F, reset);
			printf("[1] Atualizar outro campo\t\t");
			StartMenu();
			Until( &opcao_atualizar, '0', '1' );
		}
	} 
}







