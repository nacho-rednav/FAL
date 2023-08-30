#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//P { v.size() > 0 && exists i: 0 <= i < v.size() : alt < v[i] alt = ALT}
//proc          in                      in      out     out
void algoritmo(vector<int> const& v, int alt, int& p, int& q) {
    int i = 0, pr = 0;
    q = 0, p = 1;

    //Coste: O(v.size()) Todo lo de dentro del bucle tiene coste constante
    //Funcion de cota: v.size() - i
    //I = 0 <= i <= v.size() && q+1 - p = max j, f : 0<=j<=f+1<=i+1 && At(alt,v,j,f):f+1-j
    //  && pr = min j : 0<= j <= i+1 && At(alt, v, j, i) : j
    // && forall j, f : 0 <= j <= f <= i && At(alt, v, j, f) && f - j = q - p: p < j && q < f}

    while (i < (int)v.size()) {
        if (v[i] <= alt) pr = i + 1;
        if (q+1 - p < i+1 - pr) {
            p = pr;
            q = i;
        }
        i++;
    }
}
//At(alt, v, p, q) { forall i: p <= i < q : v[i] > alt}
// Q {q+1 - p = max j, f : 0 <= j <= f <= v.size() && At(alt, v, j, f) : f+1-j
// && forall j, f : 0 <= j <= f <= v.size() && At(alt, v, j, f) && f - j = q - p: p < j && q < f}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n = 0, alt = 0, p = 0, q = 0;
    cin >> n >> alt;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    algoritmo(v, alt, p, q);
       //Escribe el resultado
    cout << p << " " << q << endl;
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