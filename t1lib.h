#ifndef _T1LIB_
#define _T1LIB_

struct tlista{
    void *dado; // Dado guardado no nó da lista
    int i;      // Índice do nó;
    tlista *ant;
    tlista *prox;
};

// --------Estrutura-----------
void add(tlista **raiz, tlista **fim, void *dado);
void troca(tlista **a, tlista**b);
tlista *getByIndex(tlista *raiz, tlista *fim, int i, int tam);
tlista *getByKey(tlista *raiz, tlista *fim, int (*compara)(void*a, void*b), void *dado, int tam);
void cria_ordenado(tlista **raiz, tlista **fim, int qtd);
void cria_aleatorio(tlista **raiz, tlista **fim, int qtd);
void cria_inverso(tlista **raiz, tlista **fim, int qtd);
void cria_quase(tlista **raiz, tlista **fim, int qtd);


//---------Ordenação----------
void quicksort_(int p, int r, tlista **raiz, tlista **fim, int tam, int (*compara)(void*a, void*b));
void mergesort_();
void heapsort_();
void completionsort_();
void insertionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b));
void selectionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b));

#endif