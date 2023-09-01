#include<stdio.h>
#include<stdlib.h>
#include"t1lib.h"

void imprime(tlista *raiz){
    tlista *p;
    for(p = raiz; p!=NULL; p=p->prox){
        printf("%d\n", *(int*)p->dado);
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
    tlista *raiz = NULL;
    tlista *fim = NULL;
    cria_aleatorio(&raiz, &fim, 10);
    imprime(raiz);

    printf("\nCOUNTING\n");
    countingsort_(&raiz, &fim);
    imprime(raiz);

    return 0;
}
