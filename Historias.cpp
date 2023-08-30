#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// P { n >= 2 && forall i : 0 <= i < n : v[i] > 0 }
int algoritmo(vector<int>const& v, int n) {
    int i = 1;
    int indMax = 0;
    int r = v[indMax] - v[i];

    //Coste: bucle que da n iteraciones todas de coste cte, O(n)
    //f.Cota: n - i
    //I: 0 <= i <= n && forall j : 0 <= j < i : v[j] <= v[indMax]
    //     && r = max p, q : 0 <= p < q < i : v[p] - v[q]
    while (i < n) {
        r = max(r, v[indMax] - v[i]);

        if (v[i] > v[indMax])
            indMax = i;

        i++;
    }
    return r;
}
//Q { r = max p, q : 0 <= p < q < n : v[p] - v[q] }

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n; cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    int r = algoritmo(v, n);
       //Escribe el resultado
    cout << r << endl;
}

int main() {
    /*
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
*/
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    return 0;
}