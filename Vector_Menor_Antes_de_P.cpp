#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//{v.size() > 0 && 0 <= p < v.size()}
//Coste: O(max(p, v.size() - p - 1))
string algoritmo(vector<int> const& v, int p) {
    string r = "SI";
    int max = v[0], i = 0;
    //Funcion de cota: p - i
    //Invariante: 0 <= i <= p+1 && max = max j : 0 <= j < i : v[j]
    while (i <= p) {
        if (max < v[i]) max = v[i];
        i++;
    }
    int i = p + 1;
    //Funcion de cota: v.size() - i
    //Invariante: p+1 <= i <= v.size() && forall j : p < j < i : max < v[j]
    while (i < v.size() && max < v[i]) {
        i++;
    }
    if (i < v.size()) r = "NO";
    return r;
}
//Q(v) { forall i: p < i < v.size() && (max j : 0 <= j <= p : v[j]) : v[j] < v[i]}
//{ (r = "SI" && Q(v)) || (r = "NO" && !Q(v))}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n = 0, p = 0;
    cin >> n >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    //Calcula el resultado
    string r = algoritmo(v, p);
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