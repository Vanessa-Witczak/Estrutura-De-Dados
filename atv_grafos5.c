#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;        // número de vértices
    int **matriz; // matriz de adjacência com pesos
} Grafo;

// cria grafo com N vértices
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

// insere aresta ponderada (direcionada)
void inserirAresta(Grafo* g, int origem, int destino, int peso) {
    g->matriz[origem][destino] = peso; 
}

// imprime grafo
void imprimir(Grafo* g) {
    printf("Matriz de adjacência (direcionado, com pesos):\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%2d ", g->matriz[i][j]);
        }
        printf("\n");
    }
}

// grau de saída de um vértice
int grauSaida(Grafo* g, int v) {
    int grau = 0;
    for (int j = 0; j < g->n; j++) if (g->matriz[v][j] != 0) grau++;
    return grau;
}

// grau de entrada do vértice
int grauEntrada(Grafo* g, int v) {
    int grau = 0;
    for (int i = 0; i < g->n; i++) if (g->matriz[i][v] != 0) grau++;
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