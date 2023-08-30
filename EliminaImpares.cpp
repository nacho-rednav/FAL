#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void swap(vector<long long int>& v, int i, int p) {
    int aux = v[i];
    v[i] = v[p];
    v[p] = aux;
}

//P { v = V}
void algoritmo(vector<long long int>& v) {
    int p = 0, i = 0;

    //Coste: O(v.size())
    //Funcion de cota: v.size() - i
    //I: 0 <= i <= V.size() && 0<= p <= i && secuenciaPares(v, 0, p) = secuenciaPares(V, 0, i)
    while (i < (int)v.size()) {
        if (v[i] % 2 == 0) {
            swap(v, i, p);
            p++;
        }
        i++;
    }
    v.resize(p);
}
/*secuenciaPares(v,i,j) = v[]  
*   secuenciaPares(v,i, j) = v[i] : secuenciaPares(v, i+1, j) si v[i]%2=0, i < j
*   secuenciaPares(v,i,j) = secuenciaPares(v,i+1,j) si v[i]%2 != 0, i < j
*/

//Q{forall i : 0<= i < v.size() : v[i]%2 = 0 
//  &&  (secuenciaPares(v, 0 , v.size()) = secuenciaPares(V, 0, V.size())}


void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n; cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
       //Calcula el resultado
    algoritmo(v);
       //Escribe el resultado
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
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