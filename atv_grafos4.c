#include <stdio.h>
#include <stdlib.h>

// nó da lista de adjacência
typedef struct adj {
    int vertice;
    int peso;
    struct adj *prox;
} Adj;

// estrutura do grafo
typedef struct {
    int n;       // número de vértices
    Adj **lista; // vetor de listas
} Grafo;

// cria grafo com N vértices
Grafo* criarGrafo(int n) {
    Grafo* g = malloc(sizeof(Grafo));
    g->n = n;
    g->lista = malloc(n * sizeof(Adj*));
    for (int i = 0; i < n; i++) g->lista[i] = NULL;
    return g;
}

// insere aresta ponderada (não direcionada)
void inserirAresta(Grafo* g, int v1, int v2, int peso) {
    Adj* novo1 = malloc(sizeof(Adj));
    novo1->vertice = v2;
    novo1->peso = peso;
    novo1->prox = g->lista[v1];
    g->lista[v1] = novo1;

    Adj* novo2 = malloc(sizeof(Adj));
    novo2->vertice = v1;
    novo2->peso = peso;
    novo2->prox = g->lista[v2];
    g->lista[v2] = novo2;
}

// imprime grafo
void imprimir(Grafo* g) {
    for (int i = 0; i < g->n; i++) {
        printf("v%d: ", i);
        Adj* p = g->lista[i];
        while (p) {
            printf("v%d(%d) ", p->vertice, p->peso);
            p = p->prox;
        }
        printf("\n");
    }
}

// grau do vértice
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

    inserirAresta(g, 0, 1, 2);
    inserirAresta(g, 0, 2, 12);
    inserirAresta(g, 1, 3, 3);
    inserirAresta(g, 2, 4, 40);
    inserirAresta(g, 3, 4, 8);

    imprimir(g);
    printf("Grau do vértice 2: %d\n", grau(g, 2));

    return 0;
}