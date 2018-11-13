#include <stdio.h>
#include <stdlib.h>

struct pilha{
  int *vetor;
  int topo;
  int max;
};

struct pilha * init(int tamanho){
  struct pilha *p=(struct pilha *) malloc(sizeof(struct pilha));
  p->vetor = (int *)malloc(tamanho * sizeof(int));
  p->topo = -1;
  p->max = tamanho-1;
  return p;
}

void consulta(struct pilha *p){
  if(p->topo == -1){
    printf("Pilha vazia");
  } else {
    printf("Topo = %d\n", p->vetor[p->topo]);
  }
}

void mostrar(struct pilha *p){
  if(p->topo>=0){
    for(int i = 0; i <= p->topo; i++){
      printf("%d ", p->vetor[i]);
    }
    printf("\n");
  }
}

int getValor(){
  int num;
  printf("Digite o número a ser empilhado: ");
  scanf("%d", &num);
  return num;
}


int empilha(struct pilha *p){
  if(p->topo != p->max){
    int valor = getValor();
    p->topo++;
    p->vetor[p->topo] = valor;
    return 1;
  } else {
    printf("Pilha cheia\n");
    return 0;
  }
}

int desempilha(struct pilha *p){
  if(p->topo>=0){
    p->vetor[p->topo] =(int *)NULL;
    p->topo--;
    return 1;
  } else {
    printf("Pilha vazia\n");
    return 0;
  }
}

int main(int argc, char const *argv[]){
  printf("Digite o tamanho: ");
  int tam;
  scanf("%d", &tam);
  struct pilha *p = init(tam);
  while(empilha(p)){
    mostrar(p);
  }
  while(desempilha(p)){
    mostrar(p);
  }
  return 0;
}
