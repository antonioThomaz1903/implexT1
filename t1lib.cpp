#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include"t1lib.h"

// Adiciona um elemento na lista
void add(tlista **raiz, tlista **fim, void *dado){ 
    tlista *novo = (tlista*)calloc(1, sizeof(tlista)); //aloca
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = NULL;
    novo->i = 0;
    if(*raiz == NULL){ // Lista vazia
        *raiz = novo;
        *fim = novo;
    }
    else{ // Lista não vazia
        (*fim)->prox = novo;
        novo->ant = *fim;
        novo->i = (*fim)->i + 1;
        (*fim) = novo;
    }
}

// Encontra um elemento que possui um índice i
tlista *getByIndex(tlista *raiz, tlista *fim, int i, int tam){
    int aux;
    tlista *p;
    if(i == tam-1){ // Ultimo elemento
        return fim;
    }
    else if(i <= tam/2){ // Primeira metade da lista
        aux = 0;
        p = raiz;
        for(;aux < i; aux++){
            p = p->prox;
        }
    }
    else{ // Segunda metade da lista
        aux = tam;
        p = fim;
        for(;aux > i; aux--){
            p = p->ant;
        }
    }
}

// Retorna um elemento por comparação de um dado variado
tlista *getByKey(tlista *raiz, tlista *fim, int (*compara)(void*a, void*b), void *dado, int tam){
    tlista *p1, *p2;
    for(p1 = raiz, p2 = fim; p1!=p2; p1 = p1->prox, p2 = p2->ant){
        if(compara(p1->dado, dado)==0){
            return p1;
        }
        if(compara(p2->dado, dado)==0){
            return p2;
        }
    }
}

// Troca dois elementos da lista
void troca(tlista **a, tlista**b){
    void *aux;
    aux = (*a)->dado;
    (*a)->dado = (*b)->dado;
    (*b)->dado = aux; 
}

// Inicializa a lista como um vetor ordenado
void cria_ordenado(tlista **raiz, tlista **fim, int qtd){
    int *aux;
    for(int i=1; i<=qtd; i++){
        aux = (int*)calloc(1, sizeof(int));
        *aux = i;
        add(raiz, fim, aux);
    }
}

// Inicializa a lista como um vetor invertido
void cria_inverso(tlista **raiz, tlista **fim, int qtd){
    int *aux;
    for(int i=qtd; i>0; i--){
        aux = (int*)calloc(1, sizeof(int));
        *aux = i;
        add(raiz, fim, aux);
    }
}

// Inicializa a lista como um vetor aleatório
void cria_aleatorio(tlista **raiz, tlista **fim, int qtd){
    srand(time(NULL));
    int *aux;
    for(int i=0; i < qtd; i++){
        aux = (int*)calloc(1, sizeof(int));
        *aux = rand() %qtd + 1;
        add(raiz, fim, aux);
    }
}

// Inicializa a lista como um vetor quase ordenado
void cria_quase(tlista **raiz, tlista **fim, int qtd){
    int dezp = qtd/10;
    int cont = 0;
    int *aux;
    srand(time(NULL));
    for(int i=0 ;i<qtd; i++){
        aux = (int*)calloc(1, sizeof(int));
        *aux = rand() % qtd + 1;
        if(cont < dezp){
            add(raiz, fim, aux);
            cont++;
        }
        else{
            *aux = i;
        }
    }
}

// Método auxiliar do quicksort
int separa(int p, int r, tlista **raiz, tlista **fim, int tam, int (*compara)(void *a, void *b)){
    tlista *x, *a, *b;
    int i, j;
    x = getByIndex(*raiz, *fim, p, tam);
    i = p - 1;
    j = r + 1;
    while (1) {
        do {
        j--;
        a = getByIndex(*raiz, *fim, j, tam);
        } while (compara(a->dado, x->dado) < 0);
        do {
        i++;
        b = getByIndex(*raiz, *fim, i, tam);
        } while (compara(b->dado, x->dado) > 0);
        if (i < j)
            troca(&a, &b);
        else
            return j;
    }
}

// Quicksort
// p=0, r = tam-1
void quicksort_(int p, int r, tlista **raiz, tlista **fim, int tam, int (*compara)(void *a, void *b)){
    int q;
    if (p < r) {
        q = separa(p, r, raiz, fim, tam, compara);
        quicksort_(p, q, raiz, fim, tam, compara);
        quicksort_(q+1, r, raiz, fim, tam, compara);
    }
}

//InsertionSort
void insertionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    int i, j, tam;
    tlista *x, *y, *p, *q;
    x = *raiz;
    tam = (*fim)->i+1;

    for (p = *raiz; p!=NULL; p=p->prox){
        for (q = (*raiz)->ant; q!=NULL && compara(x->dado, x->ant->dado) == 1; q->ant->dado){
            troca(&x, &x->ant);
            x = x->ant;
        }
        x = p;
    }
}

//SelectionSort
void selectionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    int i, j, tam;
    tlista *x, *p, *q;
    x = *raiz;//menor valor
    tam = (*fim)->i+1;

    for (p = *raiz; p!=NULL; p=p->prox){
        for (q = *raiz; q!=NULL; q=q->prox){
            if (compara(q->dado, q->ant->dado) == 1){
                x = getByIndex(*raiz, *fim, q->i, tam);
            }
        }
        troca(&p, &x);
        q = p;
        x = p;
    }
}