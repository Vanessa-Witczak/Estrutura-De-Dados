#include <stdio.h>
int mod(int a, int b){
    if(a<b)
       return a;
    else
       return mod (a - b , b);
}
int main (){
    printf("%d", mod(10,3));
}