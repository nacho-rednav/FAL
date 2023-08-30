#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool recursiva(long long int n, int& tam) {
    if (n < 10) {
        tam = 1;
        return true;
    }
    else {
        if (recursiva(n / 10, tam)) {
            tam++;
            return n % tam == 0;
        }
    }
    return false;
}

bool recursiva(long long int n) {
    int tam = 0;
    return recursiva(n, tam);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    long long int n; cin >> n;
    if (!std::cin)
        return false;
    //Resolver problema
    bool r = recursiva(n);
    //Escribir resultado
    if (r)
        cout << "POLIDIVISIBLE" << endl;
    else
        cout << "NO POLIDIVISIBLE" << endl;

    return true;
}


int main() {
    /*
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
*/
    while (resuelveCaso());


    return 0;
}