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
    int n;       
    Adj **lista; 
} Grafo;

// cria grafo com N vértices
Grafo* criarGrafo(int n) {
    Grafo* g = malloc(sizeof(Grafo));
    g->n = n;
    g->lista = malloc(n * sizeof(Adj*));
    for (int i = 0; i < n; i++) g->lista[i] = NULL;
    return g;
}

// insere aresta ponderada (direcionada)
void inserirAresta(Grafo* g, int origem, int destino, int peso) {
    Adj* novo = malloc(sizeof(Adj));
    novo->vertice = destino;
    novo->peso = peso;
    novo->prox = g->lista[origem];
    g->lista[origem] = novo;
}

// imprime o grafo
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

// saída (quantas arestas saem do vértice)
int grauSaida(Grafo* g, int v) {
    int grau = 0;
    Adj* p = g->lista[v];
    while (p) {
        grau++;
        p = p->prox;
    }
    return grau;
}

// entrada (quantas arestas chegam ao vértice)
int grauEntrada(Grafo* g, int v) {
    int grau = 0;
    for (int i = 0; i < g->n; i++) {
        Adj* p = g->lista[i];
        while (p) {
            if (p->vertice == v) grau++;
            p = p->prox;
        }
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

    printf("Grau de saída do vértice 0: %d\n", grauSaida(g, 0));
    printf("Grau de entrada do vértice 4: %d\n", grauEntrada(g, 4));

    return 0;
}