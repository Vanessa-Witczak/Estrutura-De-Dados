#include <stdio.h>
#include <stdlib.h>

// nó da lista de adjacência
typedef struct adj {
    int vertice;
    struct adj *prox;
} Adj;

// estrutura do grafo
typedef struct {
    int n;       
    Adj **lista; 
} Grafo;

// cria grafo com n vértices
Grafo* criarGrafo(int n) {
    Grafo* g = malloc(sizeof(Grafo));
    g->n = n;
    g->lista = malloc(n * sizeof(Adj*));
    for (int i = 0; i < n; i++) g->lista[i] = NULL;
    return g;
}

// insere aresta não direcionada
void inserirAresta(Grafo* g, int v1, int v2) {
    Adj* novo1 = malloc(sizeof(Adj));
    novo1->vertice = v2;
    novo1->prox = g->lista[v1];
    g->lista[v1] = novo1;

    Adj* novo2 = malloc(sizeof(Adj));
    novo2->vertice = v1;
    novo2->prox = g->lista[v2];
    g->lista[v2] = novo2;
}

// imprime grafo
void imprimir(Grafo* g) {
    for (int i = 0; i < g->n; i++) {
        printf("v%d: ", i);
        Adj* p = g->lista[i];
        while (p) {
            printf("v%d ", p->vertice);
            p = p->prox;
        }
        printf("\n");
    }
}

// grau de um vértice
int grau(Grafo* g, int v) {
    int grau = 0;
    Adj* p = g->lista[v];
    while (p) {
        grau++;
        p = p->prox;
    }
    return grau;
}

int main() {
    Grafo* g = criarGrafo(5);
    inserirAresta(g, 0, 1);
    inserirAresta(g, 0, 2);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 4);

    imprimir(g);
    printf("Grau do vértice 1: %d\n", grau(g, 1));
    return 0;
}