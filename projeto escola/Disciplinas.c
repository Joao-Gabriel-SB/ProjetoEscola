#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "database.h"

int string_vazia(char *str) {
    while (*str != '\0') {
        if (!isspace((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
  }



void cadastrar_disciplina (int *qtd_disciplina){

    setlocale(LC_ALL,"Portuguese");

    printf("\t\t\t\t\tCADASTRO DISCIPLINA\n\n");
    Spacer(105);
    if (*qtd_disciplina == TAM_DISCIPLINAS)
                printf("\nA quantidade máxima de disciplinas foi atingida\n");   
              else{
                printf("\nDigite o nome da disciplina: \t\t");
                scanf(" %[^\n]",lista_disciplinas[*qtd_disciplina].nome);

                printf("Digite o código da disciplina: \t");
                scanf(" %[^\n]",lista_disciplinas[*qtd_disciplina].codigo);
                for (int i = 0; lista_disciplinas[*qtd_disciplina].codigo[i] != '\0'; i++) {
                    lista_disciplinas[*qtd_disciplina].codigo[i] = toupper(lista_disciplinas[*qtd_disciplina].codigo[i]);
                }

                printf("Digite o semestre da disciplina: \t");
                scanf("%d", &lista_disciplinas[*qtd_disciplina].semestre);
                while ((getchar()) != '\n');
                
                printf("Digite o professor da disciplina: \t");
                scanf(" %[^\n]",lista_disciplinas[*qtd_disciplina].professor);

                lista_disciplinas[*qtd_disciplina].ativo = 1;
                
                (*qtd_disciplina)++;
                printf("\n\n\t\t\t\t%sCadastro Realizado com sucesso!!!%s\n", yellow_F, reset);
                
              }
              
              Pause(); 

}

void listar_disciplina(int *qtd_disciplina){

    setlocale(LC_ALL,"Portuguese");
  
    if(*qtd_disciplina==0)
        printf("\n\t\t\t\t\t%sNenhuma Disciplina Cadastrada.%s\n\n\n",red_F,reset);
    else{
        printf("\t\t\tLista de Disciplinas\n\n");
        for (int i = 0; i < *qtd_disciplina;i++){
            if(lista_disciplinas[i].ativo)
            printf("%d - %s\n",i+1,lista_disciplinas[i].nome);
        }
        printf("\n");
    }
    Pause();
}

void atualizar_disciplina(int *qtd_disciplina){
    printf("                                        ATUALIZACÃO DE DISCIPLINA\n\n");
    int achou = 0;
    if(*qtd_disciplina==0){
        printf("\n\n\t\t\t\t\t%sNão há disciplinas para atualizar.%s\n", red_F, reset);
        return;
    }
    
    printf("Digite o código da disciplina que deseja atualizar: ");
    char atualizar[50];
    
    scanf(" %[^\n]",atualizar);
    
    if (string_vazia(atualizar)) {
        printf("\n\n\t\t\t\t\t%sCódigo de disciplina inválido%s\n", red_F, reset);
        return;
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

            printf("Digite o novo professor da disciplina: ");
            scanf(" %[^\n]",lista_disciplinas[i].professor);
        
        }
        
        
      }
  
      
    if(achou==1)
        printf("\n\n\t\t\t\t%sDisciplina atualizada com sucesso!!!%s\n", yellow_F, reset);
    else
        printf("\n\n\t\t\t\t%sDisciplina não encontrada.%s\n", red_F, reset);

}

void excluir_disciplina(int *qtd_disciplina){
    printf("                                        EXCLUSÃO DE DISCIPLINA\n\n");
    Spacer(105);
    int achou=0;
    if(*qtd_disciplina==0){
        printf("\n\n\t\t\t\t\t%sNão há disciplinas para excluir.%s\n", red_F, reset);
        Pause();
        return;
    }
    
    printf("\nDigite o código da disciplina que deseja excluir: ");
    char excluir[50];
    scanf(" %[^\n]",excluir);

    if (string_vazia(excluir)) {
        printf("\n\n\t\t\t\t\t%sCódigo de disciplina inválido%s\n", red_F, reset);
        return;
    }
    
    achou = 0;
    for (int i = 0; excluir[i] != '\0'; i++){
        excluir[i] = toupper(excluir[i]);
    }

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
        printf("\n\n\t\t\t\t%sExclusão realizada com sucesso!!!%s\n", yellow_F, reset);
    else{
        printf("\n\n\t\t\t\t%sDisciplina não encontrada.%s\n", red_F, reset);
    }
        Pause();

}

void incluir_aluno_disciplina(int *qtd_disciplina){
    printf("                                        Inclusão de Aluno\n\n");
    int achou=0;
    if (*qtd_disciplina == 0) {
        printf("Não há disciplinas cadastradas.\n\n");
        return;
    }

    printf("Digite o código da disciplina para incluir o aluno: ");
    char cod_incluir[50];
    scanf(" %[^\n]",cod_incluir);

    for (int i = 0; cod_incluir[i] != '\0'; i++) {
        cod_incluir[i] = toupper(cod_incluir[i]);
    }

    achou = 0;
    for (int i = 0; i < *qtd_disciplina; i++) {
        if (strcmp(lista_disciplinas[i].codigo, cod_incluir) == 0 && lista_disciplinas[i].ativo) {
            achou = 1;
            if (lista_disciplinas[i].qtd_alunos >= MAX_ALUNOS_DISCIPLINA) {
                printf("A disciplina já possui o número máximo de alunos.\n\n");
                break;
            }
            printf("Digite o nome do aluno: ");
            fgets(lista_disciplinas[i].alunos[lista_disciplinas[i].qtd_alunos], 50, stdin);
            lista_disciplinas[i].alunos[lista_disciplinas[i].qtd_alunos][strcspn(lista_disciplinas[i].alunos[lista_disciplinas[i].qtd_alunos], "\n")] = '\0';
            lista_disciplinas[i].qtd_alunos++;
            printf("Aluno incluído com sucesso.\n\n");
            break;
        }
    }

    if (!achou)
        printf("Disciplina não encontrada.\n\n");

        Pause();
}

void excluir_aluno_disciplina(int *qtd_disciplina){
    printf("                                        Exclusão de Aluno\n\n");
    int achou=0;
    if (*qtd_disciplina == 0) {
      printf("Não há disciplinas cadastradas.\n\n");
      return;
    }

    printf("Digite o código da disciplina: ");
    char cod_excluir[50];
    fgets(cod_excluir, sizeof(cod_excluir), stdin);
    cod_excluir[strcspn(cod_excluir, "\n")] = '\0';

    for (int i = 0; cod_excluir[i] != '\0'; i++) {
      cod_excluir[i] = toupper(cod_excluir[i]);
    }

    achou = 0;
    for (int i = 0; i < *qtd_disciplina; i++) {
        if (strcmp(lista_disciplinas[i].codigo, cod_excluir) == 0 && lista_disciplinas[i].ativo) {
            achou = 1;
            if (lista_disciplinas[i].qtd_alunos == 0) {
            printf("Não há alunos nessa disciplina.\n\n");
            break;
            }

            printf("Alunos matriculados:\n");
            for (int j = 0; j < lista_disciplinas[i].qtd_alunos; j++) {
            printf("[%d] %s\n", j + 1, lista_disciplinas[i].alunos[j]);
            }

            printf("Digite o número do aluno a ser excluído: ");
            int indice;
            scanf("%d", &indice);
            while ((getchar()) != '\n');

            if (indice < 1 || indice > lista_disciplinas[i].qtd_alunos) {
                printf("Índice inválido.\n\n");
                break;
            }

            for (int j = indice - 1; j < lista_disciplinas[i].qtd_alunos - 1; j++) {
            strcpy(lista_disciplinas[i].alunos[j], lista_disciplinas[i].alunos[j + 1]);
            }

            lista_disciplinas[i].qtd_alunos--;
            printf("Aluno removido com sucesso.\n\n");
            break;
        }
    }

    if (!achou)
      printf("Disciplina não encontrada.\n\n");
}