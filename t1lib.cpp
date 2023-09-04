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
    if(i <= tam/2){ // Primeira metade da lista
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
    return p;
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

int *copia(tlista *raiz, tlista *fim){
    tlista *p;
    int *vetor = (int*)calloc(fim->i+1, sizeof(int));
    int i=0;
    for(p = raiz; p!=NULL; p=p->prox){
        vetor[i] = *(int*)p->dado;
        i++;
    }
    return vetor;
}

void copia(tlista **raiz, tlista **fim, tlista *src){
    for(tlista *p = src; p!=NULL; p=p->prox){
        int aux = *(int*)p->dado;
        add(raiz, fim, &aux);
    }
}

// Troca dois elementos da lista
void troca(tlista **a, tlista**b){
    void *aux;
    aux = (*a)->dado;
    (*a)->dado = (*b)->dado;
    (*b)->dado = aux; 
}

void troca(int *a, int *b){
    int aux;
    aux = *b;
    *a = *b;
    *b = aux;
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
        if(cont < dezp){
            *aux = qtd - i;
            cont++;
        }
        else{
            *aux = i;
        }
        add(raiz, fim, aux);
    }
}

void destroi(tlista **raiz){
    if(*raiz == NULL){
        return;
    }
    destroi(&(*raiz)->prox);
    free(*raiz);
    *raiz = NULL;
}

// Método auxiliar do quicksort
tlista *separa(tlista *p, tlista *r, tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    tlista *x, *i, *j;
    int aux = 0;
    x = p; i = p; j = r;
    while (1) {
        if(aux){
            j = j->ant;
            i = i->prox;
        }
        while (compara(j->dado, x->dado) < 0){
            j = j->ant;
        }
        while (compara(i->dado, x->dado) > 0){
            i = i->prox;
        }
        if (i->i < j->i){
            troca(&i, &j);
            aux = 1;
        }
        else
            return j;
    }
}

// Quicksort
void quicksort(tlista *p, tlista *r, tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    tlista *q;
    if (p->i < r->i) {
        q = separa(p, r, raiz, fim, compara);
        quicksort(p, q, raiz, fim, compara);
        quicksort(q->prox, r, raiz, fim, compara);
    }
}

void quicksort_(tlista **raiz, tlista **fim, int (*compara)(void*a, void*b)){
    tlista *a, *b;
    a = *raiz; b = *fim;
    quicksort(a, b, raiz, fim, compara);
}

//InsertionSort
void insertionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    tlista *p, *q, *aux;
    for (p = *raiz; p!=NULL; p=p->prox){
        aux = p;
        for (q = p->ant; q!=NULL && compara(aux->dado, q->dado) == 1; q = q->ant){
            troca(&q, &aux);
            aux = aux->ant;
        }
    }
}

//SelectionSort
void selectionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    tlista *x, *p, *q;

    for (p = *raiz; p!=NULL; p=p->prox){
        x = p;
        for (q = p->prox; q!=NULL; q=q->prox){
            if (compara(q->dado, x->dado) == 1){
                x = q;
            }
        }
        troca(&p, &x);
    }
}

void countingsort_(int *v, int n){
  int i, j, k;
  int w[n];
  for (i=0; i<n; i++)
    w[i]=0;
  for (i=0; i<n; i++)
    w[v[i]]++;
  for (i=0, j=0; j<n; j++)
    for (k=w[j]; k>0; k--)
      v[i++]=j;
}

void intercala(tlista *p, tlista *q, tlista *r, tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    tlista *i, *j, *k, *wi = NULL, *wf = NULL;
    i = p; j = q;
    while(i->i < q->i && j->i < r->i) {
        if(compara(i->dado, j->dado) == 1){
            add(&wi, &wf, i->dado); i = i->prox;
        }
        else{
            add(&wi, &wf, j->dado); j = j->prox;
        }
    }
    while(i->i < q->i) {
        add(&wi, &wf, i->dado); i = i->prox;
    }
    
    while(j->i < r->i) {
        add(&wi, &wf, j->dado); j = j->prox;
    }

    for(i = p, k = wi; i->i < r->i; i=i->prox, k = k->prox){
        i->dado = k->dado;
    }

}

void mergesort(tlista *p, tlista *r, tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    tlista *q;
    if(p->i < r->i -1){
        for(q = p; q->i < (p->i + r->i) / 2; q = q->prox);
        mergesort(p, q, raiz, fim, compara);
        mergesort(q, r, raiz, fim, compara);
        intercala(p, q, r, raiz, fim, compara);
    }
}

void mergesort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b)){
    tlista *a, *b;
    int aux = 0;
    add(raiz, fim, &aux);
    a = *raiz;
    b = *fim;
    mergesort(a, b, raiz, fim, compara);
    a = b;
    b = b->ant;
    free(a);
    b->prox = NULL;
}

void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f){
            if(vet[j] < vet[j + 1]){
                j = j + 1;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux;
}

void heapsort_(int *vet, int N){
    int i, aux;
    for(i=(N - 1)/2; i >= 0; i--){
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--){
        aux = vet[0];
        vet [0] = vet [i];
        vet [i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}
 


 