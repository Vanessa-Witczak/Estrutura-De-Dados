#include <iostream>
using namespace std;

int main() {
    int num;
    int*p;

    cout << "Digite um numero:";
    cin >> num;

    p = &num;

    cout<< "Dobro:" <<(*p) * 2 << endl;
    cout<< "Triplo:" <<(*p) * 3<< endl;

    return 0;

}