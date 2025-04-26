#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "cruds.h"
#include "database.h"


int main(){
   professores ListaProfessores[TAM],CopiaProfessores[TAM],aux_struct;
    int posicao = 0;
    int IncrementadorMatricula = 2020;
    int opcao,sair = 1;

  
    while(sair!=0)
      {
        opcao = menu();

        switch(opcao){
          case 0:
            sair = 0;
            break;

          case 1:
              cadastrar_professor(ListaProfessores, &posicao, &IncrementadorMatricula, TAM);
            break;

          case 2:
            listar_professor(ListaProfessores,&posicao);
          break;

          case 3:
             atualizar_professor(ListaProfessores,&posicao);     
          break;

          case 4:
              excluir_professor(ListaProfessores,&posicao);
          break;

          case 5:
              listar_professor_nome(ListaProfessores,CopiaProfessores,aux_struct,&posicao);
          break;

          case 6:
               listar_professor_idade(ListaProfessores,CopiaProfessores,aux_struct,&posicao); 
          break;

          case 7:
            listar_professor_sexo(ListaProfessores,&posicao);
          break;

          default:
            printf("Opção Inválida.\n");
          break;
          
        }

      }


  }

  