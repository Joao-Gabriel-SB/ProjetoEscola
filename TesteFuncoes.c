#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

typedef struct{
int dia;
int mes;
int ano;
}struct_nascimento;

typedef struct{
int matricula;
char nome[50];
char sexo;
struct_nascimento nascimento;
char cpf[12];  
int ativo;
}professores;

int menu(){ // FUNÇÃO PARA PRINTAR O MENU PRINCIPAL DE ESCOLHA
  int opcao;
  printf("Cadastro - 1 >>>>>>>>>  Sair - 0 >>>>>>>>>>>> Listar - 2 >>>>>>>>>>>> Atualizar - 3 >>>>>>>>>>>>>>>>> Excluir - 4 >>>>>>>>>>>>>>>>> Listar por Nome - 5");
  scanf("%d",&opcao);
  return opcao;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int cadastrar_professor(professores ListaProfessores[], int *posicao, int *IncrementadorMatricula, int limite) {
    int verificador_sexo = 1;
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
    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", 
        &ListaProfessores[*posicao].nascimento.dia, 
        &ListaProfessores[*posicao].nascimento.mes, 
        &ListaProfessores[*posicao].nascimento.ano);
    limpar_buffer();

    // CPF
    printf("CPF: ");
    fgets(ListaProfessores[*posicao].cpf, sizeof(ListaProfessores[*posicao].cpf), stdin);
    limpar_buffer();

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
    int ValueMatricula,verificador_sexo,VerificadorMatricula;
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
                printf("Data de Nascimento (dd/mm/aaaa): ");
                scanf(" %d/ %d/ %d",&ListaProfessores[i].nascimento.dia,&ListaProfessores[i].nascimento.mes,&ListaProfessores[i].nascimento.ano);
                limpar_buffer();                          
            break;
            // pendente colocar validações;
                    
            case 4:        
                printf("CPF: ");
                fgets(ListaProfessores[i].cpf, sizeof(ListaProfessores[i].cpf), stdin);
                limpar_buffer();
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

int main() {
  
  professores ListaProfessores[TAM];
  int posicao = 0;
  int IncrementadorMatricula = 2020;
  int opcao,sair = 1;
   // testar o limite sem declarar aqui, somente dentro da função cadastro

  
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

          
      }
      
    }

  
}
