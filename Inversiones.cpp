#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long long int mezclaInvs(vector<int>& v, int i, int m, int f) {
    vector<int> aux;
    for (int j = i; j <= f; j++) {
        aux.push_back(v[j]);
    }

    int ini = 0, mid = m - i + 1, k = i;
    long long int sum = 0;
    while ((ini <= m - i) && (mid <= f - i)) {
        if (aux[ini] <= aux[mid]) {
            v[k] = aux[ini];
            ini++;
        }
        else if (aux[ini] > aux[mid]) {
            v[k] = aux[mid];
            sum += (long long int)m - i - ini + 1;
            mid++;
        }
        k++;
    }
    while (ini <= m - i) {
        v[k] = aux[ini];
        ini++; k++;
    }
    while (mid <= f - i) {
        v[k] = aux[mid];
        mid++; k++;
    }
    return sum;
}

long long int mergeInversiones(vector<int>& v, int i, int f) {
    int m;
    long long int sum = 0;

    if (i < f) {
        m = (f + i) / 2;
        sum += mergeInversiones(v, i, m);
        sum += mergeInversiones(v, m + 1, f);

        sum += mezclaInvs(v, i, m, f);
        return sum;
    }
    return 0;
}
/*
    n = f - i, es v.size() en la llamada original

    T(n) = {    k1 si n < 1
           { 2*T(n/2) + c*n + k2   si n >= 1

    a = 2, b = 2, k = 1 -> a = b^k
    Por el Tma de la división T(n) pertenece a O(n^k*logn) = O(nlogn)
*/

long long int algoritmo(vector<int> & v) {
    return mergeInversiones(v, 0, (int)v.size() - 1);
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n; cin >> n;
    long long int r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
       //Calcula el resultado
    r = algoritmo(v);
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