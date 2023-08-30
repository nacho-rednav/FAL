#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int intercambiosYMezcla(vector<int> & v, int i, int m, int f) {
    int r = 0;
    vector<int> aux;
    for (int j = i; j <= f; j++) {
        aux.push_back(v[j]);
    }
    int ini = 0, mid = m - i + 1, k = i;
    while (ini <= m-i && mid <= f-i) {
        if (aux[ini] < aux[mid]) {
            v[k] = aux[ini];
            ini++;
        }
        else if (aux[ini] > aux[mid]) {
            v[k] = aux[mid];
            r += (m - i + 1) - ini;
            mid++;
        }
        k++;
    }
    while (ini <= m - i) {
        v[k] = aux[ini];
        k++; ini++;
    }
    while (mid <= f - i) {
        v[k] = aux[mid];
        k++; mid++;
    }
    return r;
}

int busquedaIntercambios(vector<int> & v, int i, int f){
    int m, sum = 0;
    if (f == i)
        return 0;
    else {
        m = (f + i) / 2;
        sum += busquedaIntercambios(v, i, m);
        sum += busquedaIntercambios(v, m + 1, f);
        sum += intercambiosYMezcla(v, i, m, f);
    }
    return sum;
}
/* n = f - i, que es v.size()-1 en la llamada original
* 
* T(n) = { k1 si n = 0
*        { 2*T(n/2) + c*n + k2 si n > 0
* */

int algoritmo(vector<int> & v) {
    return busquedaIntercambios(v, 0, (int)v.size() - 1);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n; cin >> n;
    if (!std::cin)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    //Resolver problema
    int r = algoritmo(v);
    //Escribir resultado
    cout << r << endl;
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