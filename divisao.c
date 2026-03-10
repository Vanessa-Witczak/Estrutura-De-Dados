#include <stdio.h>
int divi (int a, int b){
    if (a < b)
       return 0;
    else
       return 1 + divi (a - b, b);  
}
int main (){
    int a, b;
    printf ("%d", divi (10,3));
}