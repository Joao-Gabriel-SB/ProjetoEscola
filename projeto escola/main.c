#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM_DISCIPLINAS 5
#define MAX_ALUNOS_DISCIPLINA 20

int string_vazia(char *str) {
  while (*str != '\0') {
      if (!isspace((unsigned char)*str)) {
          return 0;
      }
      str++;
  }
  return 1;
}

typedef struct{
  char nome[50];
  char codigo[50];
  int semestre;
  char professor[50];
  int ativo;
  char alunos[MAX_ALUNOS_DISCIPLINA][50];
  int qtd_alunos;
} disciplina;

disciplina lista_disciplinas[TAM_DISCIPLINAS];

int main(){

  int sair=0, opcao;
  int qtd_disciplina=0;
  int achou = 0;
  

  printf("                  Projeto Escola\n\n");

  while(!sair){
    printf("[1] Aluno");
    printf("  [2] Professor");
    printf("  [3] Disciplina");
    printf("  [0] Sair\n\n");

    scanf("%d",&opcao);


    switch(opcao){
      case 0:
        sair=1;
        break;
      
      case 1:
        printf("                  Interface Aluno\n\n");      
        break;
      
      case 2:
        printf("                  Interface Professor\n\n");
        break;
      
      case 3:
        printf("                                        Interface Disciplina\n\n");
        int sair_disciplina=0;
        int opcao_disciplina;
        while(!sair_disciplina){
          printf("[0] Voltar");
          printf("  [1] Cadastrar Disciplina");
          printf("  [2] Listar Disciplinas");
          printf("  [3] Atualizar Disciplina");
          printf("  [4] Excluir Disciplina\n\n");
          scanf("%d",&opcao_disciplina);
          while ((getchar()) != '\n');
        

          switch(opcao_disciplina){
            case 0:
              sair_disciplina=1;
              break;
            
            case 1:
              printf("                                        Cadastro de Disciplina\n\n"); 
              if (qtd_disciplina == TAM_DISCIPLINAS)
                printf("A quantidade máxima de disciplinas foi atingida\n");   
              else{
                printf("Digite o nome da disciplina: ");
                fgets(lista_disciplinas[qtd_disciplina].nome, sizeof(lista_disciplinas[qtd_disciplina].nome), stdin);
                lista_disciplinas[qtd_disciplina].nome[strcspn(lista_disciplinas[qtd_disciplina].nome, "\n")] = '\0';


                printf("Digite o código da disciplina: ");
                fgets(lista_disciplinas[qtd_disciplina].codigo, sizeof(lista_disciplinas[qtd_disciplina].codigo), stdin);
                lista_disciplinas[qtd_disciplina].codigo[strcspn(lista_disciplinas[qtd_disciplina].codigo, "\n")] = '\0';
                for (int i = 0; lista_disciplinas[qtd_disciplina].codigo[i] != '\0'; i++) {
                    lista_disciplinas[qtd_disciplina].codigo[i] = toupper(lista_disciplinas[qtd_disciplina].codigo[i]);
                }

                printf("Digite o semestre da disciplina: ");
                scanf("%d", &lista_disciplinas[qtd_disciplina].semestre);
                while ((getchar()) != '\n');
                
                printf("Digite o professor da disciplina: ");
                fgets(lista_disciplinas[qtd_disciplina].professor, sizeof(lista_disciplinas[qtd_disciplina].professor), stdin);
                lista_disciplinas[qtd_disciplina].professor[strcspn(lista_disciplinas[qtd_disciplina].professor, "\n")] = '\0';

                lista_disciplinas[qtd_disciplina].ativo = 1;
                
                qtd_disciplina++;
                printf("Disciplina cadastrada com sucesso\n\n");
                
              }
              
              break;
            
            case 2:
              printf("                                        Lista de Disciplinas\n\n");
              if(qtd_disciplina==0)
                printf("Lista Vazia\n");
              else
                for (int i = 0; i < qtd_disciplina;i++){
                  if(lista_disciplinas[i].ativo)
                  printf("%d - %s\n",i+1,lista_disciplinas[i].nome);
                }
              printf("\n");
              break;
            
            case 3:
              printf("                                        Atualizacao de disciplina\n\n");
              if(qtd_disciplina==0){
                printf("Não há disciplinas para atualizar\n\n");
                break;
              }
              
              printf("Digite o código da disciplina que deseja atualizar: ");
              char atualizar[50];
              
              fgets(atualizar, sizeof(atualizar), stdin);
              atualizar[strcspn(atualizar, "\n")] = '\0';
              
              if (string_vazia(atualizar)) {
                  printf("Código de disciplinas inválido\n\n");
                  break;
              }
              
              for (int i = 0; atualizar[i] != '\0'; i++) {
                  atualizar[i] = toupper(atualizar[i]);
              }
              
              achou = 0;
              for(int i = 0; i < qtd_disciplina; i++){
                if (strcmp(atualizar, lista_disciplinas[i].codigo) == 0 && lista_disciplinas[i].ativo){
                  printf("Digite o novo nome da disciplina: ");
                  fgets(lista_disciplinas[i].nome, sizeof(lista_disciplinas[i].nome), stdin);
                  lista_disciplinas[i].nome[strcspn(lista_disciplinas[i].nome, "\n")] = '\0';

                  printf("Digite o novo código da disciplina: ");
                  fgets(lista_disciplinas[i].codigo, sizeof(lista_disciplinas[i].codigo), stdin);
                  lista_disciplinas[i].codigo[strcspn(lista_disciplinas[i].codigo, "\n")] = '\0';
                  for (int i = 0; lista_disciplinas[i].codigo[i] != '\0'; i++) {
                      lista_disciplinas[i].codigo[i] = toupper(lista_disciplinas[i].codigo[i]);
                  }

                  printf("Digite o novo semestre da disciplina: ");
                  scanf("%d", &lista_disciplinas[i].semestre);
                  while ((getchar()) != '\n');

                  printf("Digite o novo professor da disciplina: ");
                  fgets(lista_disciplinas[i].professor, sizeof(lista_disciplinas[i].professor), stdin);
                  lista_disciplinas[i].professor[strcspn(lista_disciplinas[i].professor, "\n")] = '\0';
                  achou = 1;
                  
                  }
                  
                  
                }
            
              if(achou==1)
                printf("Disciplina atualizada com sucesso\n\n");
              else
                printf("Disciplina não encontrada\n\n");
              
              break;
            
            case 4:
              printf("                                        Exclusao de disciplina\n\n");
              if(qtd_disciplina==0){
                printf("Não há disciplinas para excluir\n\n");
                break;
              }
              
              printf("Digite o código da disciplina que deseja excluir: ");
                char excluir[50];
                fgets(excluir, sizeof(excluir), stdin);
                excluir[strcspn(excluir, "\n")] = '\0';

                if (string_vazia(excluir)) {
                    printf("Código de disciplina inválido\n\n");
                    break;
                }
              
                achou = 0;
                for (int i = 0; excluir[i] != '\0'; i++){
                    excluir[i] = toupper(excluir[i]);
                }

                for(int i = 0; i < qtd_disciplina; i++){
                  if (strcmp(excluir, lista_disciplinas[i].codigo) == 0){
                    lista_disciplinas[i].ativo = 0;
                    for(int j = i;j < qtd_disciplina - 1; j++){
                      strcpy(lista_disciplinas[j].nome, lista_disciplinas[j+1].nome);
                      strcpy(lista_disciplinas[j].codigo, lista_disciplinas[j+1].codigo);
                      lista_disciplinas[j].semestre = lista_disciplinas[j+1].semestre;
                      strcpy(lista_disciplinas[j].professor, lista_disciplinas[j+1].professor);
                      lista_disciplinas[j].ativo = lista_disciplinas[j+1].ativo;
                    }
                    
                    qtd_disciplina--;
                    achou = 1;
                  }
                }
                if(achou)
                  printf("Disciplina excluida com sucesso\n\n");
                else
                  printf("Disciplina não encontrada\n\n");
              break;

            case 5:
              printf("                                        Inclusão de Aluno\n\n");
              if (qtd_disciplina == 0) {
                printf("Não há disciplinas cadastradas.\n\n");
                break;
              }

              printf("Digite o código da disciplina para incluir o aluno: ");
              char cod_incluir[50];
              fgets(cod_incluir, sizeof(cod_incluir), stdin);
              cod_incluir[strcspn(cod_incluir, "\n")] = '\0';

              for (int i = 0; cod_incluir[i] != '\0'; i++) {
                cod_incluir[i] = toupper(cod_incluir[i]);
              }

              achou = 0;
              for (int i = 0; i < qtd_disciplina; i++) {
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
              break;

            case 6:
              printf("                                        Exclusão de Aluno\n\n");
              if (qtd_disciplina == 0) {
                printf("Não há disciplinas cadastradas.\n\n");
                break;
              }

              printf("Digite o código da disciplina: ");
              char cod_excluir[50];
              fgets(cod_excluir, sizeof(cod_excluir), stdin);
              cod_excluir[strcspn(cod_excluir, "\n")] = '\0';

              for (int i = 0; cod_excluir[i] != '\0'; i++) {
                cod_excluir[i] = toupper(cod_excluir[i]);
              }

              achou = 0;
              for (int i = 0; i < qtd_disciplina; i++) {
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
              break;

            
            default:
              printf("                                        Opcao indisponivel\n\n");
            break;
          }
        }
        
        break;
      
      default:
        printf("                  Opcao indisponivel\n");
        break;
    }
  }	

}
