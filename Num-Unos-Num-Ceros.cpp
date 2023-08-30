#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//{true}
//Coste: O(v.size())
//Funcion de cota: v.size() - i
//Invariante: 0 <= i <= v.size() && -1 <= p < v.size() && ceros = numCeros(v, i) && unos = numUnos(v, i)
//          && numCeros(v, p+1) = numUnos(v, p+1) && forall k: p < k < i : numUnos(v, k+1) != numCeros(v, k+1)
int algoritmo(vector<int> const& v) {
    int unos = 0, ceros = 0, p = -1, i = 0;
    while (i < v.size()) {
        if (v[i] == 0) ceros++;
        else if (v[i] == 1) unos++;
        if (unos == ceros) p = i;
        i++;
    }
    return p;
}
//{−1 ≤ p < v.size() && numUnos(v, p + 1) = numCeros(v, p + 1)
//&& forall k: p < k < v.size() : numUnos(v, k + 1) != numCeros(v, k + 1)}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
       //Calcula el resultado
    int p = algoritmo(v);
       //Escribe el resultado
    cout << p << endl;
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