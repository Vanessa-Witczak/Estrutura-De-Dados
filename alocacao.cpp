#include <iostream>
using namespace std;

int main(){
    int *num = new int;
    
    cout << "Digite um numero:";
    cin>> *num;

    cout<< "Dobro:" <<(*num) * 2 << endl;
    cout<< "Triplo:" <<(*num) * 3 << endl;

    delete num;

    return 0;
}