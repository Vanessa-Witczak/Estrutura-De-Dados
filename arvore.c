#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq;
    struct no *dir; 
} No;

No* inserir (No* raiz, int valor){
    if (raiz == NULL){
        No* novo = (No*) malloc (sizeof(No));
        novo -> valor = valor;
        novo -> esq = NULL;
        novo -> dir = NULL;
        return novo;
    }

if (valor < raiz -> valor){
    raiz -> esq = inserir (raiz -> esq, valor);
}else if (valor > raiz -> valor) {
    raiz -> dir = inserir (raiz -> dir, valor);
}

return raiz;

}

void imprimir (No* raiz){
    if (raiz != NULL){
        imprimir (raiz -> esq);
        printf("%d  ", raiz -> valor);    
        imprimir(raiz -> dir);
    }
}

int main () {
    No* raiz = NULL;
    raiz = inserir (raiz, 10);
    raiz = inserir (raiz, 5);
    raiz = inserir (raiz, 20);
    raiz = inserir (raiz, 3);
    raiz = inserir (raiz, 7);

    printf("Árvore: ");
    imprimir(raiz);

    return 0;
}
