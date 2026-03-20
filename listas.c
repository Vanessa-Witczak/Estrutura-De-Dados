#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

Node* inicio = NULL;

Node* criarNo(int valor) {
    Node* novo = malloc(sizeof(Node));
    if (!novo) {
        printf("Erro: sem memória!\n");
        return NULL;
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void inserirIN(int valor) {
    Node* novo = criarNo(valor);
    if (novo) {
        novo->prox = inicio;
        inicio = novo;
    }
}

void inserirFI(int valor) {
    Node* novo = criarNo(valor);
    if (novo) {
        if (!inicio) inicio = novo;
        else {
            Node* temp = inicio;
            while (temp->prox) temp = temp->prox;
            temp->prox = novo;
        }
    }
}

void inserirMe(int valor, int apos) {
    Node* temp = inicio;
    while (temp && temp->valor != apos) temp = temp->prox;
    if (temp) {
        Node* novo = criarNo(valor);
        if (novo) {
            novo->prox = temp->prox;
            temp->prox = novo;
        }
    } else {
        printf("Elemento %d não encontrado!\n", apos);
    }
}

void imprimir() {
    Node* temp = inicio;
    int contador = 0;
    printf("Lista: ");
    while (temp && contador < 100) { 
        printf("%d -> ", temp->valor);
        temp = temp->prox;
        contador++;
    }
    if (contador >= 100) printf("LOOP!\n");
    else printf("NULL\n");
}

void apagarElemento(int valor) {
    Node *temp = inicio, *ant = NULL;
    while (temp) {
        if (temp->valor == valor) {
            if (!ant) inicio = temp->prox;
            else ant->prox = temp->prox;
            free(temp);
            printf("Elemento %d removido!\n", valor);
            return;
        }
        ant = temp;
        temp = temp->prox;
    }
    printf("Elemento %d não encontrado!\n", valor);
}

void apagarLista() {
    Node* temp;
    while (inicio) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
    printf("Lista apagada!\n");
}

int main() {
    setlocale(LC_ALL, "portuguese_Brazil");
    int opcao, valor, apos, interacoes = 0;
    do {
        if (interacoes++ > 200) { // limite de operações
            printf("Encerrando por excesso de operações.\n");
            break;
        }
        printf("\n0-Sair 1-InsIN 2-InsFI 3-InsMe 4-Imprimir 5-ApagarElem 6-ApagarLista\nEscolha: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida!\n");
            break;
        }
        switch (opcao) {
            case 1: printf("Valor: "); scanf("%d", &valor); inserirIN(valor); break;
            case 2: printf("Valor: "); scanf("%d", &valor); inserirFI(valor); break;
            case 3: printf("Valor: "); scanf("%d", &valor); printf("Após qual elemento? "); scanf("%d", &apos); inserirMe(valor, apos); break;
            case 4: imprimir(); break;
            case 5: printf("Qual valor apagar?: "); scanf("%d", &valor); apagarElemento(valor); break;
            case 6: apagarLista(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    return 0;
}