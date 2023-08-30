#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool divide(vector<int> const& v, int i, int f, int& suma) {
    int m, sumaiz= 0, sumad = 0;
    bool degraiz, degrad;

    if (i < f) {
        m = (i + f) / 2;
        degraiz = divide(v, i, m, sumaiz);
        degrad = divide(v, m + 1, f, sumad);
        suma = sumaiz + sumad;
        return(degraiz && degrad && (sumaiz < sumad));
    }
    else {
        suma = v[i];
        return true;
    }
}
/* n = f - i 
* 
* T(n) = { k1   si n = 0
*        { 2*T(n/2) + k2*n  si n >= 1
* Por el teorema de la division pertence a O(nlogn)
*/

bool algoritmo(vector<vector<int>> v) {
    bool degradada = true;
    int i = 0, sum;
    while (degradada && i < v.size()) {
        degradada = divide(v[i], 0, (int)v[i].size() - 1, sum);
        i++;
    }
    return degradada;
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n, m, fila = 0;
    cin >> n >> m;

    if (!std::cin)
        return false;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int col = 0; col < m; col++) {
        cin >> v[fila][col];
        if (col == m - 1 && fila < n-1) {
            fila++; col = -1;
        }
    }

    //Resolver problema
    bool res = algoritmo(v);
    //Escribir resultado
    if (res)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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