#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//P {v.size() >= 0}
void algoritmo(vector<int> const& v, int& ind, bool& pastoso) {
    pastoso = false;
    int sum = 0;
    int i = (int) v.size() - 1;


    //Coste: O(v.size()) Caso peor, no hay pastoso y se recorre todo el vector
    //Funcion de cota: i + 1
    //Invariante: -1 <= i < v.size() && sum = sum j : i < j < v.size() : v[j] && pastoso = exists p : i < p < v.size() : siPastoso(v , p)
    //            && pastoso -> ind = max j : i < j < v.size() && siPastoso(v, j) : j}
    while (i != -1 && !pastoso) {
        pastoso = v[i] == sum;
        sum += v[i];
        if (pastoso) ind = i;

        i = i - 1;
    }
}
//Q{pastoso = exists j : 0 <= j < v.size() : siPastoso(v, j) && b -> ind = max i: 0 <= i < v.size() && siPastoso(v, i) : i}
//siPastoso(vector v, int n) {v[j] == sum i : n < i < v.size() : v[i]}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n = 0, ind = 0;
    bool pastoso;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    algoritmo(v, ind, pastoso);
       //Escribe el resultado
    if (pastoso)
        cout << "Si " << ind << endl;
    else
        cout << "No" << endl;
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