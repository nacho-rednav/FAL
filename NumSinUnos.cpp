#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int calculoPow(int n) {
    int pow = 1;
    n = n / 10;
    while (n > 0) {
        pow = pow * 10;
        n = n / 10;
    }
    return pow;
}

int numUnos(int pow) {
    if (pow == 1)
        return 0;
    else
        return 
}

int numConUnos(int& n, int pow, int unos) {
    int aux;
    if (n == 0)
        return unos;
    else {
        aux = n % 10;
        unos = aux + 1 - pow - (aux / pow) * numUnos(pow);
    }
}

int algoritmo(int n) {
    int i = calculoPow(n);
    int pre = n;
    int unos = numConUnos(pre, 1, 1);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n, r; cin >> n;
    if (!std::cin)
        return false;


    //Resolver problema
    r = algoritmo(n);
    //Escribir resultado
    cout << r << endl;
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}