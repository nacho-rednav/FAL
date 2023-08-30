#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// P { n > 0 }
int algoritmo(vector<int>const& v, int n) {
    int r = -1;
    int i = n - 1, sum = 0, tapa = 0;
    //Coste: bucle que da n iteraciones todas de coste cte, coste en O(n), siendo n el tamaño del vector
    //F.Cota: i
    /*
    I: -1 <= i < n && sum = sum k : i < k < n : v[k] &&
        tapa = max j : i < j < n && (v[j] = sum k : j < k < n : v[k]) v[j] &&
        r = if(noHaySol(v, i)) = -1
            else = max j : i < j < n && v[j] = tapa : j + 1
    */
    while (i >= 0) {
        if (v[i] == sum && v[i] > tapa) {
            r = i + 1;
            tapa = v[i];
        }
        sum += v[i];

        i--;
    }

    return r;
}
//noHaySol(v, i) { !exists j : i < j < n : v[j] = sum k : j < k < n : v[k] }
// Q { (noHaySol(v, -1) && r = - 1) || v[r] = max j : 0 <= j < n && (v[j] = sum k : j < k < n : v[k]) : v[j] }

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n; cin >> n;
    if (n == 0)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    //Resolver problema
    int r = algoritmo(v, n);
    //Escribir resultado
    if (r == -1)
        cout << "NO" << endl;
    else
        cout << "SI " << r << endl;
    return true;
}


int main() {
    /*
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
    */
    while (resuelveCaso());

    return 0;
}