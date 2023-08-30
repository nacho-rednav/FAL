#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int minimo(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int busqueda(vector<int> const& v, int i, int f) {
    int m = (i + f) / 2;

    if (f <= i + 1) {
        return minimo(v[i], v[f]);
    }
    else if (v[m] < v[m - 1] && v[m] < v[m + 1])
        return v[m];

    else if (v[m] < v[m - 1]) {
        return busqueda(v, m + 1, f);
    }

    else if (v[m] > v[m - 1]) {
        return busqueda(v, i, m - 1);
    }
}
/*  n = f - i, v.size() en la llamada incial
* 
    T(n) = { k1 si n <= 1
           { T(n/2) + k2 si n > 1

           a = 1, b = 2, k = 0 -> a = b^k
           Por el teorema de la resta T(n) pertenece a O(n^0logn) = O(logn)

*/

int algoritmo(vector<int> const& v) {
    return busqueda(v, 0, (int)v.size() - 1);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n; cin >> n;
    if (!std::cin)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    //Resolver problema
    int min = algoritmo(v);
    //Escribir resultado
    cout << min << endl;
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