#include<iostream>
#include<stdlib.h>
#include"t1lib.h"

int compara(void*a, void*b){
    if(*(int*)a == *(int*)b){
        return 1;
    }
    return 0;
}

int main()
{
    tlista *raiz = NULL;
    tlista *fim = NULL;

    int i = 1, j = 2, k = 3;
    add(&raiz, &fim, &i);
    add(&raiz, &fim, &j);
    add(&raiz, &fim, &k);

    std::cout << std::endl << *(int*)(raiz->dado) << std::endl;
    std::cout << *(int*)(raiz->prox->dado) << std::endl;
    std::cout << *(int*)(raiz->prox->prox->dado) << std::endl;

    tlista *teste = getByIndex(raiz, fim, 2, 3);
    std::cout << "elemento 2: " << *(int*)(teste->dado) << std::endl;

    int l = 2;
    teste = getByKey(raiz, fim, compara, &l, 3);

    std::cout << "elemento '2':" << teste->i;

    return 0;
}
