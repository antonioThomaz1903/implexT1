#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<chrono>
#include"t1lib.h"

using namespace std;
using namespace chrono;

void imprime(tlista *raiz){
    tlista *p;
    for(p = raiz; p!=NULL; p=p->prox){
        printf("%d\n", *(int*)p->dado);
    }
}

void imprime(int *v, int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", v[i]);
    }
}

int compara(void*a, void*b){
    if(*(int*)a == *(int*)b){
        return 0;
    }
    if(*(int*)a > *(int*)b){
        return -1;
    }
    return 1;
}

void teste_ordenado(FILE *arq, int i, int f, int s){

    fprintf(arq, "[[SORTED]]\n");
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

int main()
{
    FILE *arq = fopen("saida.txt", "w");
    tlista *raiz = NULL;
    tlista *fim = NULL;

    int i1, i2, step, rep;
    printf("\nDIGITE O TAMANHO INICIAL: ");
    scanf("%d", &i1);
    printf("DIGITE O TAMANHO FINAL: ");
    scanf("%d", &i2);
    printf("DIGITE O STEP: ");
    scanf("%d", &step);
    printf("DIGITE O NUMERO DE REPETICOES: ");
    scanf("%d", &rep);

    teste_ordenado(arq, i1, i2, step);

    // steady_clock::time_point t1 = steady_clock::now();
    // quicksort_(&raiz, &fim, compara);
    // steady_clock::time_point t2 = steady_clock::now();
    // duration<double> tempo = duration_cast<duration<double>>(t2 - t1);

    fclose(arq);
    return 0;
}
