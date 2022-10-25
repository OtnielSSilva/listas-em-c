#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    int valor;
    struct Elemento *next;
} Elemento;

typedef Elemento* Lista;

Lista* criar_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;    
}

void libera_lista(Lista *li) {
    if(li != NULL) {
        Elemento *no;
        while((*li) != NULL) {
            no = *li;
            *li = (*li)->next;
            free(no);
        }
        free(li);
    }
}

void insercao(Lista *li, int valor)
{
    if(li == NULL)
        return;
    
    Elemento *no = *li;;
    
    Elemento *no_novo = (Elemento *)malloc(sizeof(Elemento));
    if(no_novo == NULL)
        return;
    no_novo->valor = valor;
    no_novo->next = NULL;
    
    if(no) {
        while(no->next != NULL)
            no = no->next;
        no->next = no_novo;    
    } else {
        *li = no_novo;
    } 
}

void imprimir_lista(Lista *li) {
    if(li == NULL) {
        printf("Lista nao existe!\n");
        return;
    }
    if(*li == NULL) {
        printf("Lista esta vazia!\n");
        return;
    }
    Elemento *no = *li;
    while(no != NULL) {
        printf("%d ", no->valor);
        no = no->next;
    }
}

Lista* copiar_lista(Lista *l) {
    if(l == NULL) { // testa se o ponteiro existe
        return NULL;
    }
    
    Lista *copia = criar_lista(); // inicializa ponteiro 
    
    if(*l == NULL) { // testa se a lista está vazia
        return copia;
    }
    
    Elemento *copia_elemento = (Elemento*)malloc(sizeof(Elemento)); // criar um novo Elemento
    if(copia_elemento == NULL) {
        printf("Erro ao alocar memoria!\n");
        return copia;
    }

    *copia = copia_elemento; // aponta o cabeça de lista para o novo elemento
    
    // ponteiros para acessar os Elementos das listas
    Elemento *no = *l;
    Elemento *no_copia = *copia;

    no_copia->valor = no->valor;
    while(no->next != NULL) {
        copia_elemento = (Elemento*)malloc(sizeof(Elemento)); 
        no_copia->next = copia_elemento;
        no_copia = no_copia->next;
        no = no->next;
        no_copia->valor = no->valor;
    }
    no_copia->next = NULL;

    return copia;
}

int igual(Lista *l1, Lista *l2) {
    // Considerar ou não? 
    if(l1 == NULL && l2 == NULL) {
        printf("Ambos ponteiros inexistentes!\n");
        return 1;
    } else if(l1 == NULL || l2 == NULL) {
        printf("Erro, ponteiro inexistente encontrado!\n");
        return 0;
    }
    // Considerar ou não?
    if(*l1 == NULL && *l2 == NULL) { 
        printf("Ambas as listas estão vazias!\n");
        return 1;
    } else if(*l1 == NULL || *l2 == NULL) {
        printf("Erro, lista vazia encontrada!\n");
        return 0;
    }

    Elemento *no_l1 = *l1;
    Elemento *no_l2 = *l2;

    while(no_l1 && no_l2) {
        if(no_l1->valor != no_l2->valor) {
            printf("Lista desiguais!\n");
            return 0;
        }
        no_l1 = no_l1->next;
        no_l2 = no_l2->next;
    }
    printf("Listas iguais!\n");
    return 1;
}

void inverter_lista(Lista *li) {
    if(li == NULL) {
        printf("Lista nao existe!\n");
        return;
    }
    if(*li == NULL) {
        printf("Lista esta vazia!\n");
        return;
    }
    
    Elemento *no;
    Elemento *aux = NULL;

    no = *li;
    *li = (*li)->next;
    no->next = aux;
    while(*li) {
        aux = no;
        no = *li;
        *li = (*li)->next;
        no->next = aux;
    }
    (*li) = no;
}

int main()
{
    Lista *primeira = criar_lista();

    insercao(primeira, 10);
    insercao(primeira, 20);
    insercao(primeira, 30);
    insercao(primeira, 40);
    
    inverter_lista(primeira);

    imprimir_lista(primeira);
    
    return 0;
}