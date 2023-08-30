#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//P {v.size() >= 0}
//  fun             in              dev int r
//Coste: O(v.size()-1) si v.size() > 1, O(1) si v.size() <= 1
int algoritmo(vector<int> const& v) {
    int r = 0, i = 0, pr = 0;

    if ((int)v.size() == 1) r = 1;
    //funcion de cota: v.size()-1-i
    /*I = { v.size()!=1 && 0 <= i <= v.size()-1
    *   && pr = min j : 0<=j<=i && Des(v,j,i): j
    *   && r = max p, q :0<=p<=q<=i && Des(v,p,q) : q-p
    *   }
    */
    else {
        while (i < (int)v.size() - 1) {
            if (v[i] < v[i + 1]) pr = i + 1;
            i++;
            if (r < i + 1 - pr) r = i + 1 - pr;
        }
    }
    return r;
}
//Des(v, p, q){forall k: p <= k < q-1:v[k]<v[k+1]}
//Q { r = max p, q: 0<=p<=q<=v.size() && Des(v, p, q): q-p}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n = 0, result = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    result = algoritmo(v);
       //Escribe el resultado
    cout << result << endl;
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