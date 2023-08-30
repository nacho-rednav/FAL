#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void eleva(int n, int e, int& r) {
    r = (r * r)%31543;
    if (e % 2 == 1)
        r = (r * n)%31543;
}

void divElevacion(int n, int e, int& r) {
    if (e == 1)
        r = n;
    else {
        divElevacion(n, e / 2, r);
        eleva(n, e, r);
    }
}

int algoritmo(int n, int e) {
    int r;

    if (n == 0)return 0;
    if (e == 0)return 1;

    divElevacion(n, e, r);

    return r;
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    long long int num;
    int n, e;
    cin >> num >> e;
    n = num % 31543;
    if (num==0 && e==0)
        return false;

    //Resolver problema
    int r = algoritmo(n, e);
    //Escribir resultado
    cout << r << endl;
    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}