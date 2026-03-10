#include <stdio.h>
int tamanho(char *str) {
    if (*str == '\0') { 
        return 0;
    } else {
        return 1 + tamanho(str + 1); 
    }
}

int main() {
    char texto[] = "select";
    
    printf("String: %s\n", texto);
    printf("Quantidade de caracteres: %d\n", tamanho(texto));
    
    return 0;
}