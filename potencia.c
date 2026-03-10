#include <stdio.h>
int pot(int base,int exp){
    if(exp == 0)
       return 1;
    else
       return base * pot (base, exp -1);
}
int main() {
    printf("%d", pot (6,3));
}