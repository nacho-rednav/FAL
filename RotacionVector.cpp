#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int minimo(int a, int b) {
    if (a < b)
        return a;
    return b;
}

//decreciente(v, p, q) { forall j : p <= j < q : v[j] > v[j+1]
//P{v.size() > 0 && exists i : 0 <= i < v.size() : decreciente(v, 0, i) && decreciente(v, i+1, v.size()-1)}
//fun               in              in      in          dev int r
int busqueda(vector<int> const& v, int i, int f) {
    int m = (f + i) / 2;

    if ((int)v.size() == 1)
        return v[0];
    else if (v[0] < v[1])
        return v[0];
    else if (f <= i + 1)
        return minimo(v[i], v[f]);

    else if (v[i] > v[m])
        return busqueda(v, m, f);
    else if (v[i] < v[m])
        return busqueda(v, i, m - 1);
}
//Q{r = min i : 0 <= i < v.size() : v[i]}
/*
n = f - i, v.size() en la llamada inicial

T(n) = { k1 si n <= 1
       { T(n/2) si n > 1
       
       a = 1, b = 2, k = 0 -> a = b^k
       Por el teoremade la division  T(n) pertenece a O(n^0logn) = O(logn)

*/


int algoritmo(vector<int> const& v) {
    if ((int)v.size() == 0)
        return 0;
    return busqueda(v, 0, (int)v.size() - 1);
}


bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
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