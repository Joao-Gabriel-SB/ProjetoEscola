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
int dia;
int mes;
int ano;
int total;
}struct_nasc_ord_idade;

typedef struct{
int dia;
int mes;
int ano;
}struct_nasc_ord_nome;

typedef struct{
int matricula;
char nome[50];
char sexo;
struct_nascimento nascimento;
char cpf[12];  
int ativo;
}professores;

typedef struct{
int matricula_ordenado;
char nome_ordenado[50];
char sexo_ordenado;
struct_nasc_ord_nome nascimento_ordenado;
char cpf_ordenado[12];
}professores_ordenados_nome;

typedef struct{
int matricula_idade;
char nome_idade[50];
char sexo_idade;
struct_nasc_ord_idade nascimento_idade;
char cpf_idade[12];
}professores_ordenados_idade;



void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
  professores ListaProfessores[TAM];
  professores_ordenados_nome ordenado_nome[TAM];
  professores_ordenados_idade ordenado_idade[TAM];
  int verificador_sexo,verificador_data, teste_dia,teste_mes,teste_ano,teste_cpf,verificador_cpf;
  int IncrementadorMatricula = 2020;
  int sair,opcao,i,j,comparador,ValueMatricula,achou,opcao_atualizar,sair_atualizar,VerificadorMatricula,aux_int,key;
  int posicao = 0;
  int key_dia,key_mes,key_ano,key_matricula;
  char key_sexo;
  char key_nome[50];
  char key_cpf[12];
  char aux[50],aux_char;
  sair = 1;
  sair_atualizar = 1;
  
  
  while (sair!=0)
    {
      printf("Cadastro - 1 >>>>>>>>>  Sair - 0 >>>>>>>>>>>> Listar - 2 >>>>>>>>>>>> Atualizar - 3 >>>>>>>>>>>>>>>>> Excluir - 4 >>>>>>>>>>>>>>>>> Listar por Nome - 5");
      scanf("%d",&opcao);
      switch (opcao)
        {
          case 1:
                if (posicao < TAM)
                  {
                          //gera automaticamente a matrícula como chave primária do código.
                          printf("Número de Matrícula: ");
                          ListaProfessores[posicao].matricula = IncrementadorMatricula + 1;
                          IncrementadorMatricula = ListaProfessores[posicao].matricula;
                          ListaProfessores[posicao].ativo = 1;
                          printf("%d\n",ListaProfessores[posicao].matricula);

                          getchar(); //Consome o '\n' deixado no buffer
                          printf("Nome do Professor: ");
                          fgets(ListaProfessores[posicao].nome,sizeof(ListaProfessores[posicao].nome),stdin);
      
                          printf("Sexo (M/F): ");
                          verificador_sexo = 1;
                          while (verificador_sexo == 1)
                            {
                              scanf(" %c",&ListaProfessores[posicao].sexo);
                              limpar_buffer();
                              //verifica se a entrada está correta, solicitando que o usuário informe novamente o sexo caso esse esteja inválido.
                              if (ListaProfessores[posicao].sexo == 'm' || ListaProfessores[posicao].sexo == 'M' || ListaProfessores[posicao].sexo == 'f' ||       ListaProfessores[posicao].sexo == 'F')
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
      
                          printf("Data de Nascimento (dd/mm/aaaa): ");
                          scanf(" %d/ %d/ %d",&ListaProfessores[posicao].nascimento.dia,&ListaProfessores[posicao].nascimento.mes,&ListaProfessores[posicao].nascimento.ano);
                          limpar_buffer();
                          
                          
                          
      
                          printf("CPF: ");                       
                          fgets(ListaProfessores[posicao].cpf, sizeof(ListaProfessores[posicao].cpf), stdin);  
                          limpar_buffer();
                          posicao ++;
                          
      
                    }   
                  else
                  {
                    printf("PET CHEIO.\n\n");
                  }
                  break;
          
            case 0:
                sair = 0;
                break;
          
            case 2:
                //Listando todos os professores cadastrados no sistema
                for(i=0;i < posicao;i++)
                {
                  printf("%d >>>>>>>>>>",i+1);
                  printf("\nMatrícula: %d\nNome: %sSexo: %c\nData de Nascimento: %d/%d/%d \nCPF: %s\n\n",ListaProfessores[i].matricula,ListaProfessores[i].nome,ListaProfessores[i].sexo,ListaProfessores[i].nascimento.dia,ListaProfessores[i].nascimento.mes,ListaProfessores[i].nascimento.ano,ListaProfessores[i].cpf);
                }
              break;

          case 3:
              printf("Informe o número de matrícula: ");
              scanf("%d",&VerificadorMatricula);
              ValueMatricula = 0;
              sair_atualizar = 1;

              for(i=0; i <= posicao;i++) // verifica se o número de matrícula digitado tem cadastro no sistema.
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
                            {
                              limpar_buffer();
                              printf("Nome do Professor: ");
                              fgets(ListaProfessores[i].nome,sizeof(ListaProfessores[i].nome),stdin);
                              break;
                            }
                          case 2:
                            {
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
                            }
                          case 3:
                            {
                              printf("Data de Nascimento (dd/mm/aaaa): ");
                              scanf(" %d/ %d/ %d",&ListaProfessores[i].nascimento.dia,&ListaProfessores[i].nascimento.mes,&ListaProfessores[i].nascimento.ano);
                              limpar_buffer();                          
                              break;
                              // pendente colocar validações;
                            }
                          case 4:
                            {
                              printf("CPF: ");
                              fgets(ListaProfessores[i].cpf, sizeof(ListaProfessores[i].cpf), stdin);
                              limpar_buffer();
                              break;
                            }
                          case 5:
                            {
                              sair_atualizar = 5;
                              break;                              
                            }
                          default:
                            {
                              printf("Opção Inválida.\n");
                              
                            }           
                        }
                      }
                } 
              
            break;

          case 4:

            int achou = 0;
            
            printf("Informe o número de matrícula: ");
            scanf("%d",&VerificadorMatricula);
            ValueMatricula = 0;
            
            for(i=0; i <= posicao;i++) // exclusao lógica (inativando usuário)
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
                  for (j = i;j < posicao - 1;j++)
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
                  posicao --;
                  achou = 1;
                }
              
            if (achou == 1)
              printf("Professor excluído com sucesso.\n");
            else
              printf("Matrícula inexistente.\n");
            break;

          case 5:
            for(i=0;i < posicao; i++)
              {
                 strcpy(ordenado_nome[i].nome_ordenado,ListaProfessores[i].nome);
              
                 ordenado_nome[i].nascimento_ordenado.dia = ListaProfessores[i].nascimento.dia;
                 ordenado_nome[i].nascimento_ordenado.mes = ListaProfessores[i].nascimento.mes;
                 ordenado_nome[i].nascimento_ordenado.ano = ListaProfessores[i].nascimento.ano;
                
                 strcpy(ordenado_nome[i].cpf_ordenado,ListaProfessores[i].cpf);
                 ordenado_nome[i].matricula_ordenado = ListaProfessores[i].matricula;
                 ordenado_nome[i].sexo_ordenado = ListaProfessores[i].sexo;
              }

            // iniciando o processo de comparação dos nomes p/ verificar o menor e colocar em ordem
              for(i=0;i < posicao;i++)
              {
                for(j=i + 1;j < posicao;j++)
                  {
                       comparador = strcmp(ordenado_nome[i].nome_ordenado,ordenado_nome[j].nome_ordenado);
                        if (comparador > 0)
                       {
                            strcpy(aux,ordenado_nome[i].nome_ordenado);
                            strcpy(ordenado_nome[i].nome_ordenado,ordenado_nome[j].nome_ordenado);
                            strcpy(ordenado_nome[j].nome_ordenado,aux);

                            aux_int = ordenado_nome[i].nascimento_ordenado.dia;
                            ordenado_nome[i].nascimento_ordenado.dia = ordenado_nome[j].nascimento_ordenado.dia;
                            ordenado_nome[j].nascimento_ordenado.dia = aux_int;

                            aux_int = ordenado_nome[i].nascimento_ordenado.mes;
                            ordenado_nome[i].nascimento_ordenado.mes = ordenado_nome[j].nascimento_ordenado.mes;
                            ordenado_nome[j].nascimento_ordenado.mes = aux_int;

                            aux_int = ordenado_nome[i].nascimento_ordenado.ano;
                            ordenado_nome[i].nascimento_ordenado.ano = ordenado_nome[j].nascimento_ordenado.ano;
                            ordenado_nome[j].nascimento_ordenado.ano = aux_int;

                            strcpy(aux,ordenado_nome[i].cpf_ordenado);
                            strcpy(ordenado_nome[i].cpf_ordenado,ordenado_nome[j].cpf_ordenado);
                            strcpy(ordenado_nome[j].cpf_ordenado,aux);

                            
                            aux_int = ordenado_nome[i].matricula_ordenado;
                            ordenado_nome[i].matricula_ordenado = ordenado_nome[j].matricula_ordenado;
                            ordenado_nome[j].matricula_ordenado = aux_int;

                            aux_char = ordenado_nome[i].sexo_ordenado; 
                            ordenado_nome[i].sexo_ordenado = ordenado_nome[j].sexo_ordenado;
                            ordenado_nome[j].sexo_ordenado = aux_char;
                       }
                  }
              }
                //Listando todos os professores cadastrados no sistema ordenados por nome
                for(i=0;i < posicao;i++)
                {
                  printf("%d >>>>>>>>>>",i+1);
                  printf("\nMatrícula: %d\nNome: %sSexo: %c\nData de Nascimento: %d/%d/%d\nCPF: %s\n\n\n",ordenado_nome[i].matricula_ordenado,ordenado_nome[i].nome_ordenado,ordenado_nome[i].sexo_ordenado,ordenado_nome[i].nascimento_ordenado.dia,ordenado_nome[i].nascimento_ordenado.mes,ordenado_nome[i].nascimento_ordenado.ano,ordenado_nome[i].cpf_ordenado);
                }
              
          break;



          case 6: 
              // ORDENAÇÃO POR IDADE
                // copiando a struct principal para struct que será ordenada por idade
                for(i=0;i < posicao; i++)
                  {
                     strcpy(ordenado_idade[i].nome_idade,ListaProfessores[i].nome);

                     ordenado_idade[i].nascimento_idade.dia = ListaProfessores[i].nascimento.dia;
                     ordenado_idade[i].nascimento_idade.mes = ListaProfessores[i].nascimento.mes;
                     ordenado_idade[i].nascimento_idade.ano = ListaProfessores[i].nascimento.ano;

                     strcpy(ordenado_idade[i].cpf_idade,ListaProfessores[i].cpf);
                     ordenado_idade[i].matricula_idade = ListaProfessores[i].matricula;
                     ordenado_idade[i].sexo_idade = ListaProfessores[i].sexo;
                  }

                //fazendo a contagem da idade de cada professor cadastrado para posteriormente realizar a ordenação
                for(i=0;i <= posicao;i++)
                  {
                    ordenado_idade[i].nascimento_idade.total = ordenado_idade[i].nascimento_idade.ano*10000 + ordenado_idade[i].nascimento_idade.mes*100 + ordenado_idade[i].nascimento_idade.dia;
                  }

                //utilizando o insertion sort para ordenação

                for(i=1 ; i< posicao;i++)
                  {
                    key = ordenado_idade[i].nascimento_idade.total;
                    key_dia = ordenado_idade[i].nascimento_idade.dia; 
                    key_mes = ordenado_idade[i].nascimento_idade.mes;
                    key_ano = ordenado_idade[i].nascimento_idade.ano;
                    key_matricula = ordenado_idade[i].matricula_idade;
                    key_sexo = ordenado_idade[i].sexo_idade;
                    strcpy(key_cpf,ordenado_idade[i].cpf_idade);
                    strcpy(key_nome,ordenado_idade[i].nome_idade);
                    
                    for (j = i - 1; j >= 0 && ordenado_idade[j].nascimento_idade.total > key; j--)
                      {
                        ordenado_idade[j+1].nascimento_idade.total = ordenado_idade[j].nascimento_idade.total;
                        ordenado_idade[j+1].nascimento_idade.dia = ordenado_idade[j].nascimento_idade.dia;
                        ordenado_idade[j+1].nascimento_idade.mes = ordenado_idade[j].nascimento_idade.mes;
                        ordenado_idade[j+1].nascimento_idade.ano = ordenado_idade[j].nascimento_idade.ano;
                        ordenado_idade[j+1].matricula_idade = ordenado_idade[j].matricula_idade;
                        ordenado_idade[j+1].sexo_idade = ordenado_idade[j].sexo_idade;
                        strcpy(ordenado_idade[j+1].cpf_idade,ordenado_idade[j].cpf_idade);
                        strcpy(ordenado_idade[j+1].nome_idade,ordenado_idade[j].nome_idade);
                      }
                    ordenado_idade[j+1].nascimento_idade.total = key;
                  }

                //Listando todos os professores cadastrados no sistema ordenados por idade
                for(i=0;i < posicao;i++)
                  {
                    printf("%d >>>>>>>>>>",i+1);
                    printf("\nMatrícula: %d\nNome: %sSexo: %c\nData de Nascimento: %d/%d/%d\nCPF: %s\n\n\n",ordenado_idade[i].matricula_idade,ordenado_idade[i].nome_idade,ordenado_idade[i].sexo_idade,ordenado_idade[i].nascimento_idade.dia,ordenado_idade[i].nascimento_idade.mes,ordenado_idade[i].nascimento_idade.ano,ordenado_idade[i].cpf_idade);
                  }
              break;
          
            default:
              {
              printf("Opção inválida.\n");
              break;
              }
          }
            }
      
    
}

  
       
      

// O que falta no código: 1 - Validar todos os campos necessários, ou seja, evitar que o usuário pule algum dos itens do cadastro sem digitar nada; 2 - Validar que o CPF foi digitado corretamente; 3 - Validar que a data de nascimento ao menos está correta de acordo com o calendário (lembrar do ano bissexto);