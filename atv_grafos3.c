#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;        
    int **matriz; 
} Grafo;

// cria grafo com n vértices
Grafo* criarGrafo(int n) {
    Grafo* g = malloc(sizeof(Grafo));
    g->n = n;
    g->matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->matriz[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) g->matriz[i][j] = 0; // inicializa sem arestas
    }
    return g;
}

// insere aresta ponderada (não direcionada)
void inserirAresta(Grafo* g, int v1, int v2, int peso) {
    g->matriz[v1][v2] = peso;
    g->matriz[v2][v1] = peso; // simétrico
}

// imprime grafo
void imprimir(Grafo* g) {
    printf("Matriz de adjacência (pesos):\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%2d ", g->matriz[i][j]);
        }
        printf("\n");
    }
}

// grau do vértice
int grau(Grafo* g, int v) {
    int grau = 0;
    for (int j = 0; j < g->n; j++) {
        if (g->matriz[v][j] != 0) grau++;
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