#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include <string.h>

#define MaxAlunos 3
#define TamMax 100

  typedef struct{
            int dia;
            int mes;
            int ano;
  }StructNasc;

  typedef struct {
        char nome[TamMax];
        StructNasc nascimento;
        char sexo;
        char cpf[12];
        int matricula;
  }CadAlunos;
    

    void ListarAlunos(short int * qtdAlunos, CadAlunos alunosCadastrados[MaxAlunos],int){
    
        char continuar = '1';
        
        for(char i=0; i<*qtdAlunos; i++){

            for(char x = 0; x<100;x++)//divisões
                printf("-");

            printf("\n\nNome:\t\t%s\n",alunosCadastrados[i].nome);

            printf("Nascimento:\t");
            printf("%02d/%02d/%d\n",alunosCadastrados[i].nascimento.dia, alunosCadastrados[i].nascimento.mes, alunosCadastrados[i].nascimento.ano);

            alunosCadastrados[i].sexo == 'M' ? printf("Sexo:\t\tMasculino\n"): printf("sexo:\t\tFeminino\n");
            //094 32 676 501
            printf("Cpf:\t\t");
            for(char a = 0; a<11;a++){

                if(a == 3 || a == 6)
                    printf(".");
                if(a == 9)
                    printf("-");

                    printf("%c",alunosCadastrados[i].cpf[a]);
            }
            printf("\n");

            printf("Matricula:\t%d\t\n\n",alunosCadastrados[i].matricula);
        }
        getchar();
    }


    int InserirAluno(short int *qtdAlunos,CadAlunos alunosCadastrados[MaxAlunos],int){
        *qtdAlunos = 0;
        char continuarCadastrando = '1';

            while(continuarCadastrando == '1'){

                if(*qtdAlunos == MaxAlunos){
                    char continuar = '1';              
                    printf("Sem vagas disponiveis.");
                    menuIniciar();
                      while(continuar != '0'){
                        campoResposta(&continuar);
                      }
                      return 0;
                }

                printf("\nNome do aluno:\t\t\t");
                scanf(" %[^\n]",alunosCadastrados[*qtdAlunos].nome);

                //do{
                printf("Data de Nascimento(##/##/####):\t");
                scanf(" %d/ %d/ %d",&alunosCadastrados[*qtdAlunos].nascimento.dia, &alunosCadastrados[*qtdAlunos].nascimento.mes, &alunosCadastrados[*qtdAlunos].nascimento.ano);
                //validacaoNascimento(valido, alunosCadastrados[i].nascimento.dia, alunosCadastrados[i].nascimento.mes, alunosCadastrados[i].nascimento.ano) } while (!valido);

                printf("Sexo(M/F):\t\t\t");
                scanf(" %c",&alunosCadastrados[*qtdAlunos].sexo);

                //do{
                printf("Cpf:\t\t\t\t");
                scanf(" %[^\n]",alunosCadastrados[*qtdAlunos].cpf);
                //validacaocpf(valido, cpf) } while(!valido);

                alunosCadastrados[*qtdAlunos].matricula = 2025000 + *qtdAlunos;

                (*qtdAlunos)++;
              
                printf("\n\n[1] Cadastrar Outro Aluno?\t\t[2] Listar alunosCadastrados\t\t");menuIniciar();
                campoResposta(&continuarCadastrando);

                    switch (continuarCadastrando){
                        case '0': return 0;
                        case '1': break;
                        case '2':
                        ListarAlunos(&*qtdAlunos,alunosCadastrados,MaxAlunos);
                        printf("[1] Cadastrar outro aluno");menuIniciar();
                        campoResposta(&continuarCadastrando);
                    }
            }
    }

  /*
  for(i=0; i<MaxAlunos; i++)
    for(j=i+1; j<MaxAlunos; j++){
      if(menor > copia[j]){
        menor = copia[j];
      }
  copia[i] = menor;
  }
  */

