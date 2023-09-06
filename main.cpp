// Trabalho 1 - IMPLEX
// Antonio Thomaz e Ian Radtke

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<chrono>
#include"t1lib.h"

using namespace std;
using namespace chrono;

// Imprime lista no terminal
void imprime(tlista *raiz){
    tlista *p;
    for(p = raiz; p!=NULL; p=p->prox){
        printf("%d ", *(int*)p->dado);
    }
    printf("\n");
}

// Imprime vetor no terminal
void imprime(int *v, int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", v[i]);
    }
}

// Compara dois elementos da lista
int compara(void*a, void*b){
    if(*(int*)a == *(int*)b){
        return 0;
    }
    if(*(int*)a > *(int*)b){
        return -1;
    }
    return 1;
}

// Calcula e imprime o tempo para vetor ordenado
void teste_ordenado(FILE *arq, int i, int f, int s){

    fprintf(arq, "[[ORDERED]]\n");
    fprintf(arq, "%6s\t%12s\t%12s\t%12s\t%12s\t%12s\t%12s\n", "n", "Selection", "Insertion", "Merge", "Quick", "Heap", "Counting");
    fprintf(arq, "----------------------------------------------------------------------------------------------------\n");
    tlista *raiz = NULL, *fim = NULL;
    int *v;
    steady_clock::time_point t1, t2;
    duration<double> delta; // duration_cast<duration<double>>();
    for(; i<=f; i+=s){
        fprintf(arq, "%6d\t", i);
        cria_ordenado(&raiz, &fim, i);
        t1 = steady_clock::now();
        selectionsort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        
        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_ordenado(&raiz, &fim, i);
        t1 = steady_clock::now();
        insertionsort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_ordenado(&raiz, &fim, i);
        t1 = steady_clock::now();
        mergesort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_ordenado(&raiz, &fim, i);
        t1 = steady_clock::now();
        quicksort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_ordenado(&raiz, &fim, i);
        v = copia(raiz, fim);
        t1 = steady_clock::now();
        heapsort_(v, i);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        free(v);

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_ordenado(&raiz, &fim, i);
        v = copia(raiz, fim);
        t1 = steady_clock::now();
        countingsort_(v, i);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        free(v);
        destroi(&raiz);

        fprintf(arq, "\n");
    }
}

// Calcula e imprime o tempo para vetor inverso
void teste_inverso(FILE *arq, int i, int f, int s){

    fprintf(arq, "[[REVERSE]]\n");
    fprintf(arq, "%6s\t%12s\t%12s\t%12s\t%12s\t%12s\t%12s\n", "n", "Selection", "Insertion", "Merge", "Quick", "Heap", "Counting");
    fprintf(arq, "----------------------------------------------------------------------------------------------------\n");
    tlista *raiz = NULL, *fim = NULL;
    int *v;
    steady_clock::time_point t1, t2;
    duration<double> delta; // duration_cast<duration<double>>();
    for(; i<=f; i+=s){
        fprintf(arq, "%6d\t", i);
        cria_inverso(&raiz, &fim, i);
        t1 = steady_clock::now();
        selectionsort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        
        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_inverso(&raiz, &fim, i);
        t1 = steady_clock::now();
        insertionsort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_inverso(&raiz, &fim, i);
        t1 = steady_clock::now();
        mergesort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_inverso(&raiz, &fim, i);
        t1 = steady_clock::now();
        quicksort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_inverso(&raiz, &fim, i);
        v = copia(raiz, fim);
        t1 = steady_clock::now();
        heapsort_(v, i);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        free(v);

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_inverso(&raiz, &fim, i);
        v = copia(raiz, fim);
        t1 = steady_clock::now();
        countingsort_(v, i);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        free(v);
        destroi(&raiz);

        fprintf(arq, "\n");
    }
}

// Calcula e imprime o tempo para vetor quase ordenado
void teste_quase(FILE *arq, int i, int f, int s){

    fprintf(arq, "[[NEARLY ORDERED]]\n");
    fprintf(arq, "%6s\t%12s\t%12s\t%12s\t%12s\t%12s\t%12s\n", "n", "Selection", "Insertion", "Merge", "Quick", "Heap", "Counting");
    fprintf(arq, "----------------------------------------------------------------------------------------------------\n");
    tlista *raiz = NULL, *fim = NULL;
    int *v;
    steady_clock::time_point t1, t2;
    duration<double> delta; // duration_cast<duration<double>>();
    for(; i<=f; i+=s){
        fprintf(arq, "%6d\t", i);
        cria_quase(&raiz, &fim, i);
        t1 = steady_clock::now();
        selectionsort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        
        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_quase(&raiz, &fim, i);
        t1 = steady_clock::now();
        insertionsort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_quase(&raiz, &fim, i);
        t1 = steady_clock::now();
        mergesort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_quase(&raiz, &fim, i);
        t1 = steady_clock::now();
        quicksort_(&raiz, &fim, compara);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_quase(&raiz, &fim, i);
        v = copia(raiz, fim);
        t1 = steady_clock::now();
        heapsort_(v, i);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        free(v);

        destroi(&raiz);
        raiz = NULL; fim = NULL;
        cria_quase(&raiz, &fim, i);
        v = copia(raiz, fim);
        t1 = steady_clock::now();
        countingsort_(v, i);
        t2 = steady_clock::now();
        delta = duration_cast<duration<double>>(t2 - t1);
        fprintf(arq, "    %.6lfs\t", delta.count());
        free(v);
        destroi(&raiz);

        fprintf(arq, "\n");
    }
}

// Calcula e imprime o tempo para vetor aleatório
void teste_aleatorio(FILE *arq, int i, int f, int s, int r){

    fprintf(arq, "[[RANDOM]]\n");
    fprintf(arq, "%6s\t%12s\t%12s\t%12s\t%12s\t%12s\t%12s\n", "n", "Selection", "Insertion", "Merge", "Quick", "Heap", "Counting");
    fprintf(arq, "----------------------------------------------------------------------------------------------------\n");
    tlista *raiz = NULL, *fim = NULL;
    tlista *auxi = NULL, *auxf = NULL;
    int *v, j;
    double *media = (double*)calloc(6, sizeof(double));
    steady_clock::time_point t1, t2;
    duration<double> delta; // duration_cast<duration<double>>();
    for(; i<=f; i+=s){
        fprintf(arq, "%6d\t", i);
        for(j=0; j<6; j++){
            media[j] = 0;
        }
        for(j = 0; j<r; j++){
            cria_aleatorio(&raiz, &fim, i);
            copia(&auxi, &auxf, raiz);
            t1 = steady_clock::now();
            selectionsort_(&auxi, &auxf, compara);
            t2 = steady_clock::now();
            delta = duration_cast<duration<double>>(t2-t1);
            media[0] += delta.count();
            destroi(&auxi);
            auxi = NULL; auxf = NULL;
            copia(&auxi, &auxf, raiz);
            t1 = steady_clock::now();
            insertionsort_(&auxi, &auxf, compara);
            t2 = steady_clock::now();
            delta = duration_cast<duration<double>>(t2-t1);
            media[1] += delta.count();
            destroi(&auxi);
            auxi = NULL; auxf = NULL;

            copia(&auxi, &auxf, raiz);
            t1 = steady_clock::now();
            mergesort_(&auxi, &auxf, compara);
            t2 = steady_clock::now();
            delta = duration_cast<duration<double>>(t2-t1);
            media[2] += delta.count();
            destroi(&auxi);
            auxi = NULL; auxf = NULL;

            copia(&auxi, &auxf, raiz);
            t1 = steady_clock::now();
            quicksort_(&auxi, &auxf, compara);
            t2 = steady_clock::now();
            delta = duration_cast<duration<double>>(t2-t1);
            media[3] += delta.count();
            destroi(&auxi);
            auxi = NULL; auxf = NULL;

            copia(&auxi, &auxf, raiz);
            v = copia(auxi, auxf);
            t1 = steady_clock::now();
            heapsort_(v, i);
            t2 = steady_clock::now();
            delta = duration_cast<duration<double>>(t2-t1);
            media[4] += delta.count();
            free(v);
            

            v = copia(auxi, auxf);
            t1 = steady_clock::now();
            countingsort_(v, i);
            t2 = steady_clock::now();
            delta = duration_cast<duration<double>>(t2-t1);
            media[5] += delta.count();
            destroi(&auxi);
            destroi(&raiz);
            raiz = NULL; fim = NULL; auxi = NULL; auxf = NULL;
        }
        for(j=0; j<6; j++){
            media[j]/=r;
            fprintf(arq, "    %.6lfs\t", media[j]);
        }

        fprintf(arq, "\n");
        destroi(&raiz);
        destroi(&auxi);
        raiz = NULL; fim = NULL; auxi = NULL; auxf = NULL;
    }
}

int main()
{
    FILE *arq = fopen("saida.txt", "w");
    srand(time(NULL));
    tlista *raiz = NULL;
    tlista *fim = NULL;

    steady_clock::time_point t1, t2;
    duration<double> delta;

    int i1, i2, step, rep;
    printf("\nDIGITE O TAMANHO INICIAL: ");
    scanf("%d", &i1);
    printf("DIGITE O TAMANHO FINAL: ");
    scanf("%d", &i2);
    printf("DIGITE O STEP: ");
    scanf("%d", &step);
    printf("DIGITE O NUMERO DE REPETICOES: ");
    scanf("%d", &rep);

    t1 = steady_clock::now();
    teste_aleatorio(arq, i1, i2, step, rep);
    t2 = steady_clock::now();
    delta = duration_cast<duration<double>>(t2-t1);
    printf("TESTE ALEATORIO COMPLETO EM: %.6lfs\n", delta.count());
    fprintf(arq, "\n");
    t1 = steady_clock::now();
    teste_ordenado(arq, i1, i2, step);
    t2 = steady_clock::now();
    delta = duration_cast<duration<double>>(t2-t1);
    printf("TESTE ORDENADO COMPLETO EM: %.6lfs\n", delta.count());
    fprintf(arq, "\n");
    t1 = steady_clock::now();
    teste_quase(arq, i1, i2, step);
    t2 = steady_clock::now();
    delta = duration_cast<duration<double>>(t2-t1);
    printf("TESTE QUASE ORDENADO COMPLETO EM: %.6lfs\n", delta.count());
    fprintf(arq, "\n");
    t1 = steady_clock::now();
    teste_inverso(arq, i1, i2, step);
    t2 = steady_clock::now();
    delta = duration_cast<duration<double>>(t2-t1);
    printf("TESTE INVERSO COMPLETO EM: %.6lfs\n", delta.count());
    fclose(arq);
    return 0;
}
