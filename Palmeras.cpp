#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//P { n > 0 }
int algoritmo(vector<int>const& v, int n, int kg) {
    int p = 0;
    int q = 0, enPie = 0, r = 0;

    if (n <= 5)
        return n;

    //F. Cota: n - p
    //I: 0 <= p <= n && 0 <= q < p
    //  && r = max: i, j : 0 <= i <= j < p && noMas5(v, j, i, kg) : j- i + 1
    //  && cont = # i : q <= i < p : v[i] >= kg
    //Coste: Bucle coste n, todo lo de dentro es de coste cte por lo que O(n), n = num elementos del vector
    while (p < n) {
        if (v[p] >= kg)
            enPie++;

        if (enPie > 5) {
            if (v[q] >= kg) {
                enPie--;
            }
            q++;
        }

        if (enPie <= 5)
            r = max(r, p - q + 1);
        p++;
    }
    return r;
}
// noMas5(v, p, q, kg) { (#i : p <= i <= q : v[i] >= kg) <= 5 }
// Q { r = max p, q : 0 <= p <= q < n && noMas5(v, p, q, kg) : p - q + 1}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int kg, n;
    cin >> kg >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    int r = algoritmo(v, n, kg);
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