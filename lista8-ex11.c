#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
    int *A;
    int tamanho;
    int quantidade;
} Lista;

void criar_lista(Lista *li, int tamanho) {
    if(li == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return;
    }
    li->tamanho = tamanho;
    li->A = (int *)malloc(li->tamanho * sizeof(int));
    li->quantidade = 0;
}

void preencher_lista(Lista *li) {
    for(int i = 0; i < li->tamanho; i++) {
        li->A[i] = rand() % 100;
        li->quantidade++;
    }
}

void imprimir_lista(Lista li) {
    if(li.quantidade != 0) {
        for(int i = 0; i < li.tamanho; i++) {
            printf("%d ", li.A[i]);
        }
        printf("\n");
    }
}

int quantidade_elementos_lista(Lista li) {
    return li.quantidade;
}

int maior_elemento_lista(Lista li) {
    int maior = 0;
    for(int i = 1; i < li.quantidade; i++) {
        if(li.A[i] > li.A[maior]) {
            maior = i;
        }
    }
    return maior;
}

int menor_elemento_lista(Lista li) {
    int menor = 0;
    for(int i = 1; i < li.quantidade; i++) {
        if(li.A[i] < li.A[menor]) {
            menor = i;
        }
    }
    return menor;
}

int primeiro_elemento_lista(Lista li) {
    return 0;
}

int ultimo_elemento_lista(Lista li) {
    return li.tamanho-1;
}

void operacao_lista(Lista li) {
    printf("\n");
    printf("Quantidade de elementos: %d\n", quantidade_elementos_lista(li));
    printf("Maior elemento: indice: %d, elemento: %d\n", maior_elemento_lista(li), li.A[maior_elemento_lista(li)]);
    printf("Menor elemento: indice: %d, elemento: %d\n", menor_elemento_lista(li), li.A[menor_elemento_lista(li)]);
    printf("Primeiro da lista: %d\n", li.A[primeiro_elemento_lista(li)]);
    printf("Ultimo da lista: %d\n", li.A[ultimo_elemento_lista(li)]);
}

int main() {
    Lista li;
    
    criar_lista(&li, TAM);
    preencher_lista(&li);
    imprimir_lista(li);
    operacao_lista(li);

    return 0;
}