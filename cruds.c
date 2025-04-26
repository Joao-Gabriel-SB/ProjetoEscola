#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cruds.h"
#include "utils.h"

int cadastrar_professor(professores ListaProfessores[], int *posicao, int *IncrementadorMatricula, int limite) {
    int verificador_sexo = 1,cpf_valido = 0,data_valido = 0;;
    if (*posicao >= limite) {
        printf("PET CHEIO.\n\n");
        return 0;
    }
    // Gera a matrícula
    ListaProfessores[*posicao].matricula = *IncrementadorMatricula + 1;
    *IncrementadorMatricula = ListaProfessores[*posicao].matricula;
    ListaProfessores[*posicao].ativo = 1;
    printf("Número de Matrícula: %d\n", ListaProfessores[*posicao].matricula);
    limpar_buffer();

    printf("Nome do Professor: ");
    fgets(ListaProfessores[*posicao].nome, sizeof(ListaProfessores[*posicao].nome), stdin);
    // Validação do sexo
    printf("Sexo (M/F): ");
    while (verificador_sexo) {
        scanf(" %c", &ListaProfessores[*posicao].sexo);
        limpar_buffer();
        if (ListaProfessores[*posicao].sexo == 'm' || ListaProfessores[*posicao].sexo == 'M' ||
            ListaProfessores[*posicao].sexo == 'f' || ListaProfessores[*posicao].sexo == 'F') {
            verificador_sexo = 0;
        } else {
            printf("Entrada inválida, tente novamente.\nSexo (M/F): ");
        }
    }
    // Data de nascimento
    do{
      printf("Data de Nascimento (dd/mm/aaaa): ");
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



    // CPF
    do{
      printf("CPF: ");
      fgets(ListaProfessores[*posicao].cpf, sizeof(ListaProfessores[*posicao].cpf), stdin);
      limpar_buffer();
      cpf_valido = validador_cpf(ListaProfessores[*posicao].cpf);
      if (cpf_valido == 0)
      {
        printf("CPF Inválido, tente novamente!.\n");
      }  
    }while(cpf_valido == 0);

    // Atualiza posição
    (*posicao)++;

    return 1;
}

void listar_professor(professores ListaProfessores[], int *posicao){
    //Listando todos os professores cadastrados no sistema
    int i;
        for(i=0;i < *posicao;i++)
        {
          printf("%d >>>>>>>>>>",i+1);
          printf("\nMatrícula: %d\nNome: %sSexo: %c\nData de Nascimento: %d/%d/%d \nCPF: %s\n\n",ListaProfessores[i].matricula,ListaProfessores[i].nome,ListaProfessores[i].sexo,ListaProfessores[i].nascimento.dia,ListaProfessores[i].nascimento.mes,ListaProfessores[i].nascimento.ano,ListaProfessores[i].cpf);
        }
}

int atualizar_professor(professores ListaProfessores[], int *posicao){
    int sair_atualizar,opcao_atualizar,i;
    int ValueMatricula,verificador_sexo,VerificadorMatricula,cpf_valido = 0,data_valido = 0;
    printf("Informe o número de matrícula: ");
    scanf("%d",&VerificadorMatricula);
    ValueMatricula = 0;
    sair_atualizar = 1;

    for(i=0; i <= *posicao;i++) // verifica se o número de matrícula digitado tem cadastro no sistema.
        {
          if(ListaProfessores[i].matricula == VerificadorMatricula)
          {
            ValueMatricula = 1;
            break;
          }
        }
    if(ValueMatricula == 0)
      {
        printf("Número de Matrícula Inválido.\n");
      }
    if(ValueMatricula == 1)
      {
        while (sair_atualizar!=5)
            {  
                printf("O que deseja atualizar? 1 - Nome ----------- 2 - Sexo ----------- 3 - Data Nascimento ----------- 4 - CPF ----------- 5 - Voltar para o Menu");
                scanf("%d",&opcao_atualizar);
                fflush(stdin);
                limpar_buffer();

        switch (opcao_atualizar){
            case 1:

                printf("Nome do Professor: ");
                fgets(ListaProfessores[i].nome,sizeof(ListaProfessores[i].nome),stdin);
            break;

            case 2:
               printf("Sexo (M/F): ");
               verificador_sexo = 1;
               while (verificador_sexo == 1)
                {
                  scanf(" %c",&ListaProfessores[i].sexo);
                  limpar_buffer();
                  //verifica se a entrada está correta, solicitando que o usuário informe novamente o sexo caso esse esteja inválido.
                  if (ListaProfessores[i].sexo == 'm' || ListaProfessores[i].sexo == 'M' || ListaProfessores[i].sexo == 'f' || ListaProfessores[i].sexo == 'F')
                    {
                        verificador_sexo = 0;
                    }
                   else
                    {
                       printf("Entrada inválida, tente novamente.\n");
                       printf("Sexo (M/F): ");
                       verificador_sexo = 1;
                    }
                }
            break;

            case 3:
                // Data de nascimento
                do{
                  printf("Data de Nascimento (dd/mm/aaaa): ");
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

            case 4:        
                // CPF
                do{
                  printf("CPF: ");
                  fgets(ListaProfessores[*posicao].cpf, sizeof(ListaProfessores[*posicao].cpf), stdin);
                  limpar_buffer();
                  cpf_valido = validador_cpf(ListaProfessores[*posicao].cpf);
                  if (cpf_valido == 0)
                  {
                    printf("CPF Inválido, tente novamente!.\n");
                  }  
                }while(cpf_valido == 0);           
            break;

            case 5:
                sair_atualizar = 5;
            break;                              

            default:
                printf("Opção Inválida.\n");
            break;
                }
            }
        } 
}

int excluir_professor(professores ListaProfessores[],int *posicao){
    int achou = 0;
    int ValueMatricula,VerificadorMatricula,i,j;
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
}

void listar_professor_nome(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao){
    int i,j;
    int comparador;
    for(i=0;i < *posicao; i++)
        {
            CopiaProfessores[i] = ListaProfessores[i]; 
        }

    // iniciando o processo de comparação dos nomes p/ verificar o menor e colocar em ordem
    for(i=0;i < *posicao;i++)
        {
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
            printf("%d >>>>>>>>>>",i+1);
            printf("\nMatrícula: %d\nNome: %sSexo: %c\nData de Nascimento: %d/%d/%d\nCPF: %s\n\n\n",CopiaProfessores[i].matricula,CopiaProfessores[i].nome,CopiaProfessores[i].sexo,CopiaProfessores[i].nascimento.dia,CopiaProfessores[i].nascimento.mes,CopiaProfessores[i].nascimento.ano,CopiaProfessores[i].cpf);
        }
}

void listar_professor_idade(professores ListaProfessores[],professores CopiaProfessores[],professores aux_struct, int *posicao){
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

        for (j = i - 1; j >= 0 && CopiaProfessores[j].nascimento.total > aux_struct.nascimento.total; j--)
          {
            CopiaProfessores[j+1] = CopiaProfessores[j];

          }
        CopiaProfessores[j+1] = aux_struct;
      }

    //Listando todos os professores cadastrados no sistema ordenados por idade
    for(i=0;i < *posicao;i++)
      {
        printf("%d >>>>>>>>>>",i+1);
        printf("\nMatrícula: %d\nNome: %sSexo: %c\nData de Nascimento: %d/%d/%d\nCPF: %s\n\n\n",CopiaProfessores[i].matricula,CopiaProfessores[i].nome,CopiaProfessores[i].sexo,CopiaProfessores[i].nascimento.dia,CopiaProfessores[i].nascimento.mes,CopiaProfessores[i].nascimento.ano,CopiaProfessores[i].cpf);
      }
}

void listar_professor_sexo(professores ListaProfessores[], int *posicao){
    //Listando os professores por Sexo
    int i;
    printf("Professores do Sexo FEMININO >>>>>>>>>>");
    for(i=0;i < *posicao;i++)
      {
        if (ListaProfessores[i].sexo == 'F' || ListaProfessores[i].sexo == 'f')
          {
            printf("\nMatrícula: %d\nNome: %s\nData de Nascimento: %d/%d/%d\nCPF: %s\n\n\n",ListaProfessores[i].matricula,ListaProfessores[i].nome,ListaProfessores[i].nascimento.dia,ListaProfessores[i].nascimento.mes,ListaProfessores[i].nascimento.ano,ListaProfessores[i].cpf);
          }
      }
        printf("Professores do Sexo MASCULINO >>>>>>>>>>");
        for(i=0;i < *posicao;i++)
        {
            if (ListaProfessores[i].sexo == 'M' || ListaProfessores[i].sexo == 'm')
            {
              printf("\nMatrícula: %d\nNome: %sData de Nascimento: %d/%d/%d\nCPF: %s\n\n\n",ListaProfessores[i].matricula,ListaProfessores[i].nome,ListaProfessores[i].nascimento.dia,ListaProfessores[i].nascimento.mes,ListaProfessores[i].nascimento.ano,ListaProfessores[i].cpf);
           }
       }
}
