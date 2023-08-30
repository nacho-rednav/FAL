#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void base6(int n, int pow, int& r) {
    if (n / 6 < 6) {
        r = (n / 6) * pow *10+ (n%6)*pow + r;
    }
    else {
        r = (n % 6) * pow + r;
        pow = pow * 10;
        n = n / 6;
        base6(n, pow, r);
    }
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n, r=0; cin >> n;
       //Calcula el resultado
    base6(n, 1, r);
       //Escribe el resultado
    cout << r << endl;
}

int main() {

    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    return 0;
}