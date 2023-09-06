// Trabalho 1 - IMPLEX
// Antonio Thomaz e Ian Radtke

#ifndef _T1LIB_
#define _T1LIB_

// Lista duplamente encadeada sem cabeça
// permite guardar e ordenar qualquer tipo
// de dado criado pelo usuário.
struct tlista{
    void *dado;     // Dado guardado no nó da lista
    int i;          // Índice do nó
    tlista *ant;    // Ponteiro para o próximo elemento
    tlista *prox;   // Ponteiro para o elemento anterior
};

// --------Estrutura-----------

// Aloca e adiciona elemento na lista
void add(tlista **raiz, tlista **fim, void *dado);

// Troca dois elementos da lista
void troca(tlista **a, tlista**b);

// Retorna elemento com índice i
tlista *getByIndex(tlista *raiz, tlista *fim, int i, int tam);

// Retorna elemento com chave *dado
tlista *getByKey(tlista *raiz, tlista *fim, int (*compara)(void*a, void*b), void *dado, int tam);

// Inicializa o vetor com valores ordenados
void cria_ordenado(tlista **raiz, tlista **fim, int qtd);

// Inicializa o vetor com valores aleatórios
void cria_aleatorio(tlista **raiz, tlista **fim, int qtd);

// Inicializa o vetor com valores ordenados decrescentemente
void cria_inverso(tlista **raiz, tlista **fim, int qtd);

// Inicializa o vetor com valores quase ordenados
void cria_quase(tlista **raiz, tlista **fim, int qtd);

// Desaloca uma lista
void destroi(tlista **raiz);

// Copia uma lista para um vetor estático
int *copia(tlista *raiz, tlista *fim);

// Copia uma lista para outra lista
void copia(tlista **raiz, tlista **fim, tlista *src);

//---------Ordenação----------

// Algoritmos de ordenação que recebem começo e fim da lista
// e um método abstrato "compara"

void quicksort_(tlista **raiz, tlista **fim, int (*compara)(void*a, void*b));
void mergesort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b));
void insertionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b));
void selectionsort_(tlista **raiz, tlista **fim, int (*compara)(void *a, void *b));

// Algoritmos de ordenação que recebem vetor estático (int)
void heapsort_(int *vet, int N);
void countingsort_(int *v, int n);

#endif