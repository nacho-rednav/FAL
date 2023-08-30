#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int comp(vector<int> const& v, int num, int i, int f) {
    if (num + i == v[i])
        return v[i];
    else if (num + f == v[f])
        return v[f];
    return -1;
}

//bingo(v, num) { exists j : 0 <= j < v.size() : num + j = v[j] }
//P{v.size() > 0}
//fun busqueda          in          in      in      in      dev int r
int busqueda(vector<int> const& v, int num, int i, int f) {
    int m = (f + i) / 2;
    int r;

    //n = f - i
    //T(n) = { k1 si n <= 1
    //       { T(n/2) + k2 si n > 1
    //Teorema de la division: T(n) € O(logn) siendo n al principio v.size()-1
    if (v[m] == num + m)
        return v[m];
    else if (f <= i + 1)
        return comp(v, num, f, i);
    else if (v[m] < num + m)
        return busqueda(v, num, m + 1, f);
    else if (v[m] > num + m)
        return busqueda(v, num, i, m - 1);
}
//Q{ bingo(v, num) -> r = v[k : 0<= k < v.size && num + k = v[k]]
//     && !bingo(v, num) -> r = -1}
/*
n = f - i, v.size() en la llamada inicial

T(n) = { k1 si n <= 1
       { T(n/2) si n > 1
a = 1, b = 2, k = 0 -> a = b^k
Por el teorema de la division T(n) pertenece a O(n^0logn) = O(logn)
*/

int algoritmo(vector<int> const& v, int num) {
    return busqueda(v, num, 0, (int)v.size() - 1);
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n, num, r; cin >> n >> num;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    r = algoritmo(v, num);
       //Escribe el resultado
    if (r != -1)
        cout << r << endl;
    else
        cout << "NO" << endl;
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