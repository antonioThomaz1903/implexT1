#include<stdio.h>
#include<stdlib.h>
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
        if(compara(p1->dado, dado)){
            return p1;
        }
        if(compara(p2->dado, dado)){
            return p2;
        }
    }
}


void troca(tlista **a, tlista**b){
    void *aux;
    aux = (*a)->dado;
    (*a)->dado = (*b)->dado;
    (*b)->dado = aux; 
}

void *cria_ordenado(tlista **raiz, tlista **fim, int qtd){
    int *aux;
    for(int i=1; i<=qtd; i++){
        aux = (int*)calloc(1, sizeof(int));
        *aux = i;
        add(raiz, fim, aux);
    }
}

void *cria_inverso(tlista **raiz, tlista **fim, int qtd){
    int *aux;
    for(int i=qtd; i>0; i--){
        aux = (int*)calloc(1, sizeof(int));
        *aux = i;
        add(raiz, fim, aux);
    }
}
