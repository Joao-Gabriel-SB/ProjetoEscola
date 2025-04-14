#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define MaxAlunos 2
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
        int cpf;
        int matricula;
    }CadAlunos;


    int main(int argc,char *argv[]){

        CadAlunos alunosCadastrados[MaxAlunos];
        short int qtdAlunos=0;
        char continuarCadastrando == '1';

            for(char i=0, continuarCadastrando == '1'; continuarCadastrando == '1' && i<MaxAlunos; i++){
                if(qtdAlunos > MaxAlunos){
                    printf("Sem vagas disponiveis.");
                    return 0;
                }

                printf("\nNome do aluno:\t\t\t");
                scanf(" %[^\n]",&alunosCadastrados[qtdAlunos].nome);

                //do{
                printf("Data de Nascimento(##/##/####):\t");
                scanf(" %d/%d/%d",&alunosCadastrados[qtdAlunos].nascimento.dia, &alunosCadastrados[qtdAlunos].nascimento.mes, &alunosCadastrados[qtdAlunos].nascimento.ano);
                //validacaoNascimento(valido, alunosCadastrados[i].nascimento.dia, alunosCadastrados[i].nascimento.mes, alunosCadastrados[i].nascimento.ano) } while (!valido);

                printf("Sexo(M/F):\t\t\t");
                scanf(" %c",&alunosCadastrados[qtdAlunos].sexo);

                //do{
                printf("Cpf:\t\t\t\t");
                scanf(" %d",&alunosCadastrados[qtdAlunos].cpf);
                //validacaocpf(valido, cpf) } while(!valido);

                alunosCadastrados[qtdAlunos].matricula = 2025000 + qtdAlunos;

                qtdAlunos++;

                printf("Cadastro realizado com sucesso!!");

                printf("\n\n[1] Cadastrar Outro Aluno?\t\t[2] Listar alunosCadastrados\t\t[0] Menu inicial");
                campoResposta(&continuarCadastrando);

                    switch (continuarCadastrando){
                        case '0': return 0;
                        case '1': break;
                        case '2': printf("Listando alunos cadastrados..."); return 0;
                    }
            }



            //função listar em prototipo
            putchar('\n');
            for(char i=0; i<MaxAlunos; i++){
                for(char x = 0; x<100;x++)
                    printf("-");

                printf("\n\nNome:\t\t%s\n",alunosCadastrados[i].nome);

                printf("Nascimento:\t");
                printf("%d/%d/%d\n",alunosCadastrados[i].nascimento.dia, alunosCadastrados[i].nascimento.mes, alunosCadastrados[i].nascimento.ano);

                alunosCadastrados[i].sexo == 'M' ? printf("Sexo:\t\tMasculino\n"): printf("sexo:\t\tFeminino\n");

                printf("Cpf:\t\t%d\n",alunosCadastrados[i].cpf);

                printf("Matricula:\t%d\t\n\n",alunosCadastrados[i].matricula);
            }
}
