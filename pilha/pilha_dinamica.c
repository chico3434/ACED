#include <stdio.h>
#include <stdlib.h>

struct ptr{
  int valor;
  struct ptr *prox;
};

struct pilha {
  struct ptr *topo;
};

struct pilha * inicializar(){
  struct pilha *p = (struct pilha *)malloc(sizeof(struct pilha));
  p->topo = (struct ptr *)NULL;
  return p;
}

void consultar (struct pilha *p){
  if (p -> topo == (struct ptr *) NULL)
    printf("\nPilha Vazia.");
  else
    printf("\n Topo: %d", p->topo->valor);
}

void empilhar(struct pilha *p){
    struct ptr *aux = (struct ptr *)malloc(sizeof(struct ptr));
    printf("Digite o valor: ");
    scanf("%d", &aux->valor);
    aux->prox=p->topo;
    p->topo=aux;
}

int desempilhar (struct pilha *p){
  struct ptr *aux = p->topo;
  int valor =0;
  valor = aux->valor;
  p->topo = p->topo->prox;
  aux->prox = (struct ptr *)NULL;
  free(aux);
  aux = (struct ptr*)NULL;
  return valor;
}

void mostrar(struct pilha *p){
  struct ptr *aux = p->topo;
  if(aux == (struct ptr *)NULL)
    printf("\nLista vazia!\n");
  else
    while(aux!=NULL){
      printf("\n| %d |\n", aux->valor);
      aux = aux->prox;
    }
  aux = (struct ptr *)NULL;
}

int main(){
  struct pilha *p;
  p = inicializar();
  mostrar(p);
  for(int i = 0; i <= 5; i++){
    empilhar(p);
    mostrar(p);
  }
  consultar(p);
  printf("\n Valor desempilhado: %d", desempilhar(p));
  consultar(p);
  mostrar(p);
  return 0;
}