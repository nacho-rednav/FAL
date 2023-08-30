#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int calculo(int a, int b, int x) {
    if (b != x)
        return x;
    return a - 1;
}
int correcto(int a, int b) {
    if (a != -1)
        return a;
    return b;
}

//noEsta(x, v){forall i : 0 <= i < v.size() : v[i] != x}
//P{v.size() > 0 && x2-x1 = v.size() && (noEsta(x2,v) || noEsta(x1,v) || exists i : 0 <= i < v.size() : v[i+1]-v[i]!=1)}
//fun           in                  in          in         dev int r
int busqueda(vector<int> const& v, int i,  int f) {
    int m = (f + i) / 2, r1, r2;

    if (v[m]<v[m+1]-1) {
        return v[m] + 1;
    }
    if (f <= i + 1)
        return -1;

     r1 = busqueda(v, i, m);
     r2 = busqueda(v, m + 1, f);
     return correcto(r1, r2);
}
//Q{ noEsta(x1, v) -> r = x1 && noEsta(x2, v) -> r = x2 && (exists i : 0 <= i < v.size() : v[i+1]-v[i]!=1) -> r = v[i] + 1}
/*
n = f-i
T(n) = { k1 si n <= 1
       { 2*T(n/2) + k2*n^0  si n > 1
Tenemos a = 2, b = 2 y k = 0. Por lo que a > b^k entonces el coste por el teorema
de la division sera de O(n^logb a) = O(n^log2 2) = O(n)
*/

char algoritmo(vector<int> const& v, char f) {
    int ri;
    if (v[(int)v.size() - 1] - v[0] != (int)v.size())
        ri = calculo(v[0], v[(int)v.size() - 1], f);
    
    else {
        ri = busqueda(v, 0, (int)v.size() - 1);
    }
    char r = ri;
    return r;
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n;
    char x1, x2, r;
    cin >> x1 >> x2;
    n = x2 - x1;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x1;
        v[i] = x1;
    }
       //Calcula el resultado
    r = algoritmo(v, x2);
       //Escribe el resultado
    cout << r << endl;
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