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
void destroi(tlista **raiz);
int *copia(tlista *raiz, tlista *fim);
void copia(tlista **raiz, tlista **fim, tlista *src);

//---------Ordenação----------
void quicksort_(tlista **raiz, tlista **fim, int (*compara)(void*a, void*b));
void mergesort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b));
void countingsort_(int *v, int n);
void insertionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b));
void selectionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b));
void heapsort_(int *vet, int N);

#endif