#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int valor;
    struct Elemento *prox;
} Elemento;

typedef struct Elemento* Pilha;

Pilha* criar_pilha() {
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
    if(pi != NULL) {
        *pi = NULL;
    }
    return pi;
}

int pilha_vazia(Pilha *pi) {
    if(pi == NULL) {
        printf("Lista inexistente!\n");
        return 1;
    }
    if(*pi == NULL) {
        printf("Lista Vazia!\n");
        return 1;
    }
    return 0;
}

void push(Pilha *pi, int valor) {
    if(pi == NULL) {
        printf("Lista inexistente!\n");
        return;
    }    
    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if(no == NULL) {
        printf("Erro na alocação de memória!\n");
        return;
    }    
    no->valor = valor;
    no->prox = (*pi);
    *pi = no;
}

void imprime_pilha(Pilha *pi) {
    if(pilha_vazia(pi))
        return;
    Elemento *no = *pi;
    while(no != NULL) {
        printf("%d ", no->valor);
        no = no->prox;
    }
}

void inverter_pilha(Pilha *pi) {
    Elemento *no = *pi;
    Elemento *aux = NULL;

    *pi = (*pi)->prox;
    no->prox = aux;
    while(*pi != NULL) {
        aux = no;
        no = *pi;
        *pi = (*pi)->prox;
        no->prox = aux;
    }
    *pi = no;
}

int main() {
    Pilha *primeiro = criar_pilha();

    push(primeiro, 10);
    push(primeiro, 20);
    push(primeiro, 30);
    push(primeiro, 40);

    inverter_pilha(primeiro);

    imprime_pilha(primeiro);

    return 0;
}