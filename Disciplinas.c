#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "database.h"
#include "cruds.h"


int string_vazia(char *str) {
    while (*str != '\0') {
        if (!isspace((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
  }

  void listar_disciplina(int *qtd_disciplina){

    setlocale(LC_ALL,"Portuguese");
  
    if(*qtd_disciplina==0)
        printf("\n\t\t\t\t\t%sNenhuma Disciplina Cadastrada.%s\n\n\n",red_F,reset);
    else{
        printf("\t\t\tLISTA DE DISCIPLINAS\n\n");
        for (int i = 0; i < *qtd_disciplina;i++){
            if(lista_disciplinas[i].ativo){
            	printf("Nome:\t\t %s\n",lista_disciplinas[i].nome);
                printf("Codigo:\t\t %s\n",lista_disciplinas[i].codigo);
                printf("Semestre:\t %d\n",lista_disciplinas[i].semestre);
                printf("Professor:\t %s\n",lista_disciplinas[i].professor);
                Spacer(30);
            }   
        }
    }
    Pause();
    printf("\n");
    StartMenu();
}

int cadastrar_disciplina( int *qtd_disciplina, professores ListaProfessores[], professores CopiaProfessores[],professores aux_struct){
    int cancelar;
    int returnMatricula;
    int flag;
    char sair ='1';
    setlocale(LC_ALL,"Portuguese");

    system("clear||cls");
    while ( sair == '1' ){
    printf("\t\t\t\t\tCADASTRO DISCIPLINA\n\n");

    Spacer(105);

    if (*qtd_disciplina == TAM_DISCIPLINAS){

                printf("\nA quantidade máxima de disciplinas foi atingida\n");   
    }
              	 else{

                printf("\nDigite o nome da disciplina: \t\t");
                scanf(" %[^\n]",lista_disciplinas[*qtd_disciplina].nome);
                printf("Digite o código da disciplina: \t\t");
                scanf(" %[^\n]",lista_disciplinas[*qtd_disciplina].codigo);
                for (int i = 0; lista_disciplinas[*qtd_disciplina].codigo[i] != '\0'; i++) {
                    lista_disciplinas[*qtd_disciplina].codigo[i] = toupper(lista_disciplinas[*qtd_disciplina].codigo[i]);
                }

                printf("Digite o semestre da disciplina: \t");
                scanf("%d", &lista_disciplinas[*qtd_disciplina].semestre);
                
                ListarProfessorNome( ListaProfessores, CopiaProfessores, aux_struct, posicao );
  
                returnMatricula = BuscarPorMatriculaProf(ListaProfessores, posicao);
	 	
                if (returnMatricula == 0){

                ListaProfessores[*qtd_disciplina].ProfessoresDisciplina[*qtd_disciplina] = lista_disciplinas[*qtd_disciplina];
                strcpy(lista_disciplinas[*qtd_disciplina].professor, ListaProfessores[*qtd_disciplina].nome);

		cancelar = Confirmar();
        if ( cancelar == -1 ) {Pause();return -1;}
                lista_disciplinas[*qtd_disciplina].ativo = 1;
                (*qtd_disciplina)++;
                printf("\n\t\t\t\t%sCadastro Finalizado!!!%s\n", yellow_F, reset);

                }
                else{

                    memset(&lista_disciplinas[*qtd_disciplina], 0, sizeof(disciplina)); // limpa os dados
                    Pause();
                    return -1;
                }

                printf("\n\n[1] Cadastrar outra disciplina\t\t[2] Listar disciplinas cadastradas\t\t\n");StartMenu();

                Until( &sair, '0', '2' );
		            
			switch (sair){

				case '0': sair = '0';
				case '1': break;
			    case '2':
                    listar_disciplina(qtd_disciplina);
					printf("[1] Cadastrar outra disciplina\t");
					Until( &sair, '0', '1' );

                
                    
            }
        }
    }

}


int atualizar_disciplina( int *qtd_disciplina, professores ListaProfessores[], professores CopiaProfessores[], professores aux_struct ){

    int returnMatricula;
    printf("                                        ATUALIZACÃO DE DISCIPLINA\n\n");
    int achou = 0;

    if(*qtd_disciplina==0){
        printf("\n\n\t\t\t\t\t%sNão há disciplinas para atualizar.%s\n", red_F, reset);
        return -1;
    }
    Spacer(60);
    printf("Digite o código da disciplina que deseja atualizar: ");
    char atualizar[50];
    
    scanf(" %[^\n]",atualizar);
    
    if (string_vazia(atualizar)) {
        printf("\n\n\t\t\t\t\t%sCódigo de disciplina inválido%s\n", red_F, reset);
        return -1;

    }
    
    for (int i = 0; atualizar[i] != '\0'; i++) {
        atualizar[i] = toupper(atualizar[i]);
    }
    
    achou = 0;
    for(int i = 0; i < *qtd_disciplina; i++){

        if (strcmp(atualizar, lista_disciplinas[i].codigo) == 0 && lista_disciplinas[i].ativo){
            printf("Digite o novo nome da disciplina: ");

            scanf(" %[^\n]",lista_disciplinas[i].nome);

            printf("Digite o novo código da disciplina: ");
            scanf(" %[^\n]",lista_disciplinas[i].codigo);
            for (int i = 0; lista_disciplinas[i].codigo[i] != '\0'; i++) {
                lista_disciplinas[i].codigo[i] = toupper(lista_disciplinas[i].codigo[i]);
            }

            printf("Digite o novo semestre da disciplina: ");
            scanf("%d", &lista_disciplinas[i].semestre);
            while ((getchar()) != '\n');


            ListarProfessorNome(ListaProfessores, CopiaProfessores,aux_struct, posicao); 
            
            returnMatricula = BuscarPorMatriculaProf(ListaProfessores, posicao);
                if (returnMatricula == 0)
                {
                ListaProfessores[i].ProfessoresDisciplina[i] = lista_disciplinas[i];
                strcpy(lista_disciplinas[i].professor, ListaProfessores[*qtd_disciplina].nome);

                lista_disciplinas[i].ativo = 1;
                Pause();
                return 0;
                }
                else{

                    break;
                    Pause();
                    return -1;
                }
                }

              Pause(); 
        }
        if(achou==1 && returnMatricula == 0)
        {
            printf("\n\n\t\t\t\t%sDisciplina atualizada com sucesso!!!%s\n", yellow_F, reset);
            Pause();
        }
            
        else
        {
            if(achou == 0)
            {
                printf("\n\n\t\t\t\t%sDisciplina não encontrada.%s\n", red_F, reset);
                Pause();
            }    
        }
            
            return 0;
            Pause();
            
}
  
int excluir_disciplina(int *qtd_disciplina){
    int cancelar;
    printf("                                        EXCLUSÃO DE DISCIPLINA\n\n");
    Spacer(105);
    int achou=0;
    if(*qtd_disciplina==0){

        printf("\n\n\t\t\t\t%sNão há disciplinas para excluir.%s\n", red_F, reset);
        Pause();
        return -1;

    }
    
    printf("\nDigite o código da disciplina que deseja excluir: ");
    char excluir[50];
    scanf(" %[^\n]",excluir);

    if (string_vazia(excluir)) {
        printf("\n\n\t\t\t\t\t%sCódigo de disciplina inválido%s\n", red_F, reset);

        return -1;

    }
    
    achou = 0;
    for (int i = 0; excluir[i] != '\0'; i++){
        excluir[i] = toupper(excluir[i]);
    }
	cancelar = Confirmar();
    if ( cancelar == -1 ) {Pause();return -1;}
        
    for(int i = 0; i < *qtd_disciplina; i++){
        if (strcmp(excluir, lista_disciplinas[i].codigo) == 0){
        lista_disciplinas[i].ativo = 0;
        	for(int j = i;j < *qtd_disciplina - 1; j++){
		        strcpy(lista_disciplinas[j].nome, lista_disciplinas[j+1].nome);
		        strcpy(lista_disciplinas[j].codigo, lista_disciplinas[j+1].codigo);
		        lista_disciplinas[j].semestre = lista_disciplinas[j+1].semestre;
		        strcpy(lista_disciplinas[j].professor, lista_disciplinas[j+1].professor);
		        lista_disciplinas[j].ativo = lista_disciplinas[j+1].ativo;
        	}
        
        (*qtd_disciplina)--;
        achou = 1;
        }
    }
    if(achou)

        printf("\n\n\t\t\t\t\t%sExclusão realizada com sucesso!!!%s\n", yellow_F, reset);

    else{
        printf("\n\n\t\t\t\t%sDisciplina não encontrada.%s\n", red_F, reset);
    }
        Pause();

}

int incluir_aluno_disciplina( int *qtd_disciplina, int amountStudents, Student* registredStudents ){

	 int cancelar;
	 int auxMatricula;
	 int indexAluno;
	 int indexDisciplina;
	 int achou=0;
     int erro;

    if ( *qtd_disciplina == 0 ) {
        printf("\n\t\t\t\t\t%sNenhuma disciplina cadastrada.%s\n\n\n",yellow_F,reset);
		Pause();
        return -1;

    }

	 erro = ListStudents( amountStudents, registredStudents, MaxStudent, '1' );

	 if ( erro == -1 ) return -1;

	 printf("\n\t\t\tInclusão de aluno em disciplina\n\n");
     Spacer(50);


	 printf("\n\nMatricula do estudante:\t");
	 scanf(" %d", &auxMatricula);

	 indexAluno = SearchInt( amountStudents, registredStudents, sizeof(Student), GetId, auxMatricula );

	 if( indexAluno == -1 ) {

		 printf("\n\t\t\t\t%sNenhum aluno encontrado com essa matricula.%s\n", yellow_F, reset); 
		          
		 Pause();
		 return -1;

	 }
	 
	 printf("\n\nNome:\t\t%s",registredStudents[indexAluno].name);
	 printf("\nNascimento:\t%02d/%02d/%d", registredStudents[indexAluno].birthday.day, registredStudents[indexAluno].birthday.month, registredStudents[indexAluno].birthday.year);
	 registredStudents[indexAluno].sex == 'M' ? printf("\nSexo:\t\tMasculino\n"): printf("\nsexo:\t\tFeminino\n");
    printf("Cpf:\t\t");

                for(char a = 0; a<11;a++){

                    if(a == 3 || a == 6)
                        printf(".");
                    if(a == 9)
                        printf("-");

                        printf("%c",registredStudents[indexAluno].cpf[a]);

                    }

    printf("\nMatricula:\t%d\t\n\n",registredStudents[indexAluno].id);

    printf("\nDigite o código da disciplina que deseja incluir o aluno: ");


    char cod_incluir[50];
    scanf(" %[^\n]",cod_incluir);

    for (int i = 0; cod_incluir[i] != '\0'; i++) {
        cod_incluir[i] = toupper(cod_incluir[i]);
    }



    for (int i = 0; i < *qtd_disciplina; i++) {

        if (strcmp(lista_disciplinas[i].codigo, cod_incluir) == 0 && lista_disciplinas[i].ativo) {

            achou = 1;

            if (lista_disciplinas[i].qtd_alunos >= MAX_ALUNOS_DISCIPLINA) {

                printf("A disciplina já possui o número máximo de alunos.\n\n");
                break;
            }

		  indexDisciplina = i;
				
        }
    }

    if (!achou){
 
      printf("\n\t\t\t\t%sDisciplina não encontrada.%s\n", yellow_F, reset);
		Pause();
      return -1;

    }
    
    	cancelar = Confirmar();
        if ( cancelar == -1 ) {Pause();return -1;}
        
		lista_disciplinas[ indexDisciplina ].alunos[ lista_disciplinas[indexDisciplina].qtd_alunos ] = registredStudents[indexAluno];	 	 
		strcpy( registredStudents[ indexAluno ].disciplinasCadastrado[ registredStudents[indexAluno].qtdDisciplinas ] , lista_disciplinas[ indexDisciplina ].codigo );

				     
		printf("Aluno %s agora está matriculado em %d disciplina(s)\n",
		registredStudents[indexAluno].name,
		registredStudents[indexAluno].qtdDisciplinas+1);


		registredStudents[indexAluno].qtdDisciplinas++;
		lista_disciplinas[indexDisciplina].qtd_alunos++;


      printf("\n\t\t%sAluno incluído com sucesso.%s\n\n", yellow_F, reset);

      StartMenu();

}


void listar_alunos_disciplina( int *qtd_disciplina){

    char cod_add_aluno[50];

    setlocale(LC_ALL,"Portuguese");

    printf("Digite o código da disciplina:\t");
    scanf(" %[^\n]", cod_add_aluno);
    for (int i = 0; cod_add_aluno[i] != '\0'; i++) {
        cod_add_aluno[i] = toupper(cod_add_aluno[i]);
    }

    for(int i=0; i < *qtd_disciplina; i++){  
        if (strcmp(cod_add_aluno, lista_disciplinas[i].codigo) == 0 && lista_disciplinas[i].ativo){

            if (lista_disciplinas[i].qtd_alunos == 0) {
                printf("\n\n\t\t\t\t%sNão há alunos nesta disciplina.%s\n", red_F, reset);
                Pause();
                return;
            }
            
            printf("\n\n\t\t\t\tAlunos matriculados na disciplina - %s\n\n", lista_disciplinas[i].nome);

            for(int j = 0 ; j<lista_disciplinas[i].qtd_alunos; j++){
                printf("%d - %s\n", j+1,lista_disciplinas[i].alunos[j].name);                  
            }
        }
        printf("\n");
        StartMenu();    
    }

    Pause();
}


int excluir_aluno_disciplina(int *qtd_disciplina, Student* registredStudents) {

	int cancelar;

    if (*qtd_disciplina == 0) {
        printf("\n\n\t\t\t\t%sNão há disciplinas cadastradas.%s\n", red_F, reset);
        Pause();
        return -1;
    }
    printf("\t\t\tEXCLUSÃO DE ALUNO\n\n");
    printf("Digite o código da disciplina: ");

    char cod_exc_aluno[50];
    scanf(" %[^\n]", cod_exc_aluno);
    
    // Deixa o código da disciplina em maiúsculas
    for (int i = 0; cod_exc_aluno[i] != '\0'; i++) {
        cod_exc_aluno[i] = toupper(cod_exc_aluno[i]);
    }

    int achou = 0;

    for (int i = 0; i < *qtd_disciplina; i++) {
        if (strcmp(lista_disciplinas[i].codigo, cod_exc_aluno) == 0 && lista_disciplinas[i].ativo) {
            achou = 1;

            if (lista_disciplinas[i].qtd_alunos == 0) {
                printf("\n\n\t\t\t\t\t%sNão há alunos nesta disciplina%s\n", red_F, reset);
                Pause();
                return -1;
            }
            Spacer(30);
            printf("Alunos matriculados nesta disciplina:\n\n");
            Spacer(30);
            for (int j = 0; j < lista_disciplinas[i].qtd_alunos; j++) {
                printf("%d - %s\n", j + 1, lista_disciplinas[i].alunos[j].name);
            }

            printf("\nDigite o número do aluno a ser excluído: ");
            int indice;
            scanf("%d", &indice);
            indice--;
            

            if (indice < 0 || indice >= lista_disciplinas[i].qtd_alunos) {
                printf("Índice inválido.\n\n");
                Pause();
                return -1;
            }
            
    cancelar = Confirmar();
    if ( cancelar == -1 ) {Pause(); return -1;}

            // Remove o aluno deslocando os elementos para a esquerda
            for (int j = indice; j < lista_disciplinas[i].qtd_alunos - 1; j++) {
                lista_disciplinas[i].alunos[j] = lista_disciplinas[i].alunos[j + 1];
            }
            
            for (int j = indice; j < registredStudents[i].qtdDisciplinas - 1; j++) {
                strcpy( registredStudents[i].disciplinasCadastrado[j] , registredStudents[i].disciplinasCadastrado[j + 1]);
            }

            lista_disciplinas[i].qtd_alunos--;
            registredStudents[i].qtdDisciplinas--;
            printf("\n\t\t\t\t%sAluno removido com sucesso!!%s\n", yellow_F, reset);
            return -1;
        }
    }

    if (!achou) {
        printf("Disciplina não encontrada.\n\n");
        Pause();
    }
}

void ListarDisciplinasLotadas(disciplina lista_disciplinas[],int MaxDisciplina){
    int i,j;
    j = 0;
    for (i=0; i < MaxDisciplina; i++)
    {
        if(lista_disciplinas[i].qtd_alunos > 40)
        {
            printf("\n\tDisciplina: %s\n",lista_disciplinas[i].nome);
            printf("Código: %s\n",lista_disciplinas[i].codigo);
            printf("Professor da Disciplina: %s\n\n",lista_disciplinas[i].professor);
            Pause(); 
            j = 1;
        }
    }

    if (j == 0)
    {
        printf("Não existem disciplinas que possuem mais de 40 alunos matriculados.\n");
    }
    Pause();
}

