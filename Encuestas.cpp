#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// P { v.size() >= 0}
void algoritmo(vector<long long int> const& v,long long int& sum, int& val) {
    int i = 0, min = v[0], cont = 0;
    sum = 0; val = 0;

    //Coste: O(v.size()) siempre
    //F. Cota = v.size() - i            Qué pasa aquí al inicializar?
    //Invariante = 0 <= i <= v.size() && min = min j : 0 <= j < i: v[j] && cont = # j : 0<= j < i : v[j] = min
    //             && sum = sum j : 0 <= j < i && v[j] > min : v[j] && val  = # j : 0 <= j < i : v[j] > min
    while (i < v.size()) {
        if (v[i] < min) {
            sum = sum + min * cont;
            val += cont;
            min = v[i];
            cont = 1;
        }
        else if (v[i] == min) cont++;
        else {
            sum += v[i];
            val++;
        }
        i++;
    }
}
// Q {sum = sum i: 0 <= i < v.size() && v[i] != min(v) : v[i] && val = # i : 0 <= i < v.size() : v[i] != min(v)}
//min(v) = {min i : 0 <= i < v.size() : v[i]}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n; cin >> n;
    vector <long long int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    long long int sum = 0;
    int val = 0;
    algoritmo(v, sum, val);
       //Escribe el resultado
    cout << sum << " " << val << endl;
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