#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//P{ v.size() > 0 && D >= 0}
//fun           in              in          dev bool apto
bool algoritmo(vector<int> const& v, int D) {
    bool apto = true;
    int i = 1, base = v[0];

    //Coste: O(v.size()) En el caso de recorrer todo el array
    //Funcion de cota: v.size() - i
    //I: 1 <= i <= v.size() && base = v[min k : 0 <= k < i && creciente(v,k,i): k] 
    //  && apto = forall p, q : 0<= p <= q < i && creciente(v,p,q): v[q]-v[p] <= D
    while (apto && i < (int)v.size()) {
        if (v[i] <= v[i - 1]) {
            base = v[i];
        }
        apto = ((v[i] - base) <= D);

        i++;
    }

    return apto;
}
// creciente(v,i,j) { forall k: i< k < q : v[k] > v[k-1]}
//Q{ apto = !exists p, q : 0<=p< q<=v.size() && creciente(v,p,q): v[q-1]-v[p] > D}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int D, n;
    cin >> D;
    if (!std::cin)
        return false;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //Resolver problema
    bool apta = algoritmo(v, D);
    //Escribir resultado
    if (apta)
        cout << "APTA" << endl;
    else
        cout << "NO APTA" << endl;

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