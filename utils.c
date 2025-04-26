#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"


int menu(){ // FUNÇÃO PARA PRINTAR O MENU PRINCIPAL DE ESCOLHA
  int opcao;
  printf("Cadastro - 1 >>>>>>>>>  Sair - 0 >>>>>>>>>>>> Listar - 2 >>>>>>>>>>>> Atualizar - 3 >>>>>>>>>>>>>>>>> Excluir - 4 >>>>>>>>>>>>>>>>> Listar por Nome - 5 >>>>>>>>>>>>>>>>> Listar por Idade - 6 >>>>>>>>>>>>>>>>> Listar por Sexo - 7 ");
  scanf("%d",&opcao);
  return opcao;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validador_cpf (char cpf_validation[]){
  int numeros[11],soma = 0 ,i,j,digito1,digito2;

  j=0;
  // Tirar caracteres não numéricos e validar tamanho
  for(i=0; i < strlen(cpf_validation);i++) // strlen é uma função que retorna o tamanho da string, excluindo o caractere nulo
    {
      if(isdigit(cpf_validation[i]))
      {
        numeros[j] = cpf_validation[i] - '0'; //transforma o caracrtere em número
        j++;
      }
    }

  if(j!=11)
  {
    return 0;
  }

  //verificar se todos os números são iguais
  int todos_iguais = 1;
  for(i=0;i < 11; i++)
    {
      if(numeros[0] != numeros[i])
      {
        todos_iguais = 0;
        break;
      }
    }

  if (todos_iguais == 1)
  {
    return 0;
  }

  //Calculando o primeiro dígito verificador
  for (i=0;i < 9;i++)
    {
      soma = soma + numeros[i] * (10 - i);
    }

  digito1 = soma%11;
  if (digito1 < 2)
    digito1 = 0;
  else 
    digito1 = 11 - digito1;

  //Calculando o segundo dígito verificador
  soma =0;
  for (i=0;i < 9;i++)
    {
      soma = soma + numeros[i] * (11 - i);
    }
  soma = soma + (digito1*2);

  digito2 = soma%11;
  if (digito2 < 2)
    digito2 = 0;
  else 
    digito2 = 11 - digito2;

  //Validar dígitos
  if (digito1 == numeros[9] && digito2 == numeros[10])
    return 1;
  else
    return 0;
}

int validador_data (int dia, int mes, int ano)
{
   // Verifica ano válido
      if (ano < 1900 || ano > 2100)
          return 0;

      // Verifica mês válido
      if (mes < 1 || mes > 12)
          return 0;

      // Verifica dia válido para cada mês
      if (dia < 1)
          return 0;

      // Meses com 31 dias
      if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
          if (dia > 31)
              return 0;
      }
      // Meses com 30 dias
      else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
          if (dia > 30)
              return 0;
      }
      // Fevereiro
      else if (mes == 2) {
          // Verifica se é ano bissexto
          int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));

          if (bissexto) {
              if (dia > 29)
                  return 0;
          } else {
              if (dia > 28)
                  return 0;
          }
      }

      return 1; // Data válida
  }