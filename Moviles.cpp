#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int calculoPeso(vector<vector<int>> const& v, int& i) {
    int pi = 0, di = 1, pd = 2, dd = 3;
    int pesoi, pesod;
    const int iAux = i;

    if (v[i][pi] != 0 && v[i][pd] != 0) {
        if (v[i][pi] * v[i][di] == v[i][pd] * v[i][dd])
            return v[i][pi] + v[i][pd];
        return -1;
    }
    else if (v[i][pi] == 0 && v[i][pd] != 0) {
        pesoi = calculoPeso(v, ++i);
        pesod = v[iAux][pd];
        if (pesoi * v[iAux][di] == pesod * v[iAux][dd])
            return pesoi + pesod;
        return -1;
    }
    else if (v[i][pi] != 0 && v[i][pd] == 0) {
        pesod = calculoPeso(v, ++i);
        pesoi = v[iAux][pi];
        if (pesoi * v[iAux][di] == pesod * v[iAux][dd])
            return pesoi + pesod;
        return -1;
    }
    else {
        pesoi = calculoPeso(v, ++i);
        pesod = calculoPeso(v, ++i);
        if (pesoi * v[iAux][di] == pesod * v[iAux][dd] && (pesoi + pesod > 0))
            return pesoi + pesod;
        return -1;
    }
}
/*
n = v.size() - i, en la llamada inicial es el número de submóviles

T(n) = { k1 si n = 1
       { 2
*/

bool algoritmo(vector<vector<int>> const& v) {
    int i = 0;
    int rEquib = calculoPeso(v, i);
    return rEquib != -1;
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n = 4, ind = 0;
    vector<int> vAux(4);
    vector<vector<int>> v;
    bool equilibrio;

    for (int i = 0; i < n; i++) {
        cin >> vAux[ind]; ind++;
        if (ind == 4) {
            v.push_back(vAux);
            ind = 0;
            if (vAux[0] == 0) n += 4;
            if (vAux[2] == 0) n += 4;
        }
    }
       //Calcula el resultado
    equilibrio = algoritmo(v);
       //Escribe el resultado
    if (equilibrio)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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