#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}no;

typedef struct lista{
    no *inicio;
}Lista;

void inicializar(Lista *lista){
    (*lista).inicio = NULL;
}

void adicionarNo(Lista *lista, int valorNum){
    no *novo;
    novo = malloc(sizeof(no));
    (*novo).valor = valorNum;
    (*novo).prox= NULL;

    if((*lista).inicio == NULL){
        (*lista).inicio = novo;
    }
    else{
        no *aux;
        aux = (*lista).inicio;
        while((*aux).prox != NULL){
            aux = (*aux).prox;
        }
        (*aux).prox = novo;
    }
}

void printLista(Lista * lista){
    no *atual;
    atual = (*lista).inicio;
    while(atual != NULL){
        printf("%d ",(*atual).valor);
        atual = (*atual).prox;
    }
}

int main(){
    Lista listinhaDeTeste;
    inicializar(&listinhaDeTeste);
    adicionarNo(&listinhaDeTeste,5);
    adicionarNo(&listinhaDeTeste,7);
    adicionarNo(&listinhaDeTeste,4);
    printLista(&listinhaDeTeste);
}
