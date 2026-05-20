#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;        // número de vértices
    int **matriz; // matriz de adjacência
} Grafo;

// Cria grafo com n vértices
Grafo* criarGrafo(int n) {
    Grafo* g = malloc(sizeof(Grafo));
    g->n = n;
    g->matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->matriz[i] = calloc(n, sizeof(int)); // inicializa com 0
    }
    return g;
}

// Insere aresta não direcionada
void inserirAresta(Grafo* g, int v1, int v2) {
    g->matriz[v1][v2] = 1;
    g->matriz[v2][v1] = 1;
}

// Imprime grafo
void imprimir(Grafo* g) {
    for (int i = 0; i < g->n; i++) {
        printf("v%d: ", i);
        for (int j = 0; j < g->n; j++) {
            if (g->matriz[i][j]) printf("v%d ", j);
        }
        printf("\n");
    }
}

// Grau de um vértice
int grau(Grafo* g, int v) {
    int grau = 0;
    for (int j = 0; j < g->n; j++) grau += g->matriz[v][j];
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