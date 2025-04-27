#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Disciplinas.h"

#define TAM_DISCIPLINAS 5
#define MAX_ALUNOS_DISCIPLINA 20


int main(){

  int sair=0, opcao;
  int qtd_disciplina=0;
 

  
  while(!sair){
    printf("                  Projeto Escola\n\n");
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
                cadastrar_disciplina(&qtd_disciplina);
              break;
            
            case 2:
                listar_disciplina(&qtd_disciplina);
                break;
            
            case 3:
                atualizar_disciplina(&qtd_disciplina);
                break;

            case 4:
                excluir_disciplina(&qtd_disciplina);
                break;

            case 5:
                incluir_aluno_disciplina(&qtd_disciplina);
                break;

            case 6:
                excluir_aluno_disciplina(&qtd_disciplina);
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