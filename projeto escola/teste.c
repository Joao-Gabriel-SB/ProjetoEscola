#include <stdio.h>
#include <string.h>

#define tamMax 5
#define MaxAlunos 5
typedef struct{
  char nome[tamMax];    
}cadAluno;

int main(){

  cadAluno alunoCadastrado[tamMax],menor;
  int maior, i, j, a, b, c, d,x;
  char copia[tamMax];
  
  strcpy( menor.nome, alunoCadastrado[0].nome);
  
  for(x=0;x<'z';x++){
    for(i=0; i<MaxAlunos; i++){
      for(j=i+1){
        if( menor > alunoCadastrado[j+1].nome[x]){
          strcpy( menor, alunosCadastrado[j+1].nome);        
        }
      }
      strcpy(copia[i], menor);
    }
  }
  
  for(i=0; i<MaxAlunos; i++){
    printf("%s",alunoCadastrado[i].nome);
  }
  
}
