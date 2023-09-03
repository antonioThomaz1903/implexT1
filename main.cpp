#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include"t1lib.h"

void imprime(tlista *raiz, FILE *arq){
    tlista *p;
    for(p = raiz; p!=NULL; p=p->prox){
        fprintf(arq, "%d\n", *(int*)p->dado);
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

int main()
{
    clock_t tempo;
    FILE *arq = fopen("saida.txt", "w");

    tlista *raiz = NULL;
    tlista *fim = NULL;

    cria_aleatorio(&raiz, &fim, 5000);
    imprime(raiz, arq);

    fprintf(arq, "\nQUICKSORT\n");
    tempo = clock();
    quicksort_(&raiz, &fim, compara);
    tempo = clock() - tempo;
    printf("\nTEMPO DECORRIDO QUICKSORT: %.5lfs\n", (float)tempo/CLOCKS_PER_SEC);

    imprime(raiz, arq);
    destroi(&raiz);
    fclose(arq);

    return 0;
}
