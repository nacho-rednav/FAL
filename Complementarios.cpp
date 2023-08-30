#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int compInv(int n, int inv) {
    if (n < 10) {
        return inv * 10 + (9-n);
    }
    else {
        inv = inv * 10 + 9 - n % 10;
        n = n / 10;
        return compInv(n, inv);
    }
}

int fcomp(int n, int comp, int pow) {
    if (n < 10) {
        return comp + (9-n)*pow;
    }
    else {
        comp = comp + (9-(n%10)) * pow;
        pow = pow * 10;
        n = n / 10;
        return fcomp(n, comp, pow);
    }
}

void algoritmo(int n, int& r, int& rInv) {
    r = fcomp(n, 0, 1);
    rInv = compInv(n, 0);
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n, r, rInv;
    cin >> n;
       //Calcula el resultado
    algoritmo(n, r, rInv);
       //Escribe el resultado
    cout << r << " " << rInv << endl;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}