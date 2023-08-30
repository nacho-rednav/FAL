#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//{v.size() >= 0 && d > 0}
//fun               in                  in        dev: bool fallo
bool algoritmo(vector<int> const& v, int d) {
    bool fallo = false;
    int i = 1, reps = 1;

    //Coste: O(v.size() - 1) En el peor caso, que si cumpla las condiciones
    //Funcion de cota: v.size() - i
    //I = 1 <= i <= v.size() && fallo = exists j : 0 < j < i : v[j] < v[j-1] || v[j] > v[j-1]+1) || !divertido(v,d, j, i)
    //    && reps = # j : 0 <= j <= i : v[j] = v[i] && !exists q : j < q < i : v[j] <! v[i] }
    while (i < (int)v.size() && !fallo) {
        reps++;
        if (v[i] != v[i - 1]) reps = 1;
        fallo = (v[i]<v[i - 1] || v[i] > v[i-1]+1 ||reps > d);
        i++;
    }
    return !fallo;
}
//divertido(v, d, i, fj) { !exists p, q: i <= p < q <= fj && (forall i : p <= i < q - 1 : v[i] = v[i+1]) : q - p > d}
// Q { fallo = exists i : 0 < i < v.size() : v[i] < v[i-1] || v[i] > v[i-1]+1) || !divertido(v,d, 0, v.size())}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    bool result;
    int n = 0, d = 0;
    cin >> d >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    result = algoritmo(v, d);
       //Escribe el resultado
    if (result)
        cout << "SI" << endl;
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