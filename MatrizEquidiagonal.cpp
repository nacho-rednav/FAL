#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool recursiva(vector<vector<int>>const& mat, int& r, int i, int f, int j, int p) {
    int r1i, r1d, r2i, r2d, mc, mf;
    bool ok1I, ok2I, ok1D, ok2D;
    if (i == f && j == p) {
        r = mat[j][i];
        return true;
    }
    else {
        mc = (f + i) / 2;
        mf = (p + j) / 2;
        ok1I = recursiva(mat, r1i, i, mc, j, mf);
        ok2I = recursiva(mat, r2i, i, mc, mf+1, p);
        ok1D = recursiva(mat, r1d, mc + 1, f, j, mf);
        ok2D = recursiva(mat, r2d, mc + 1, f, mf+1, p);
        r = r1i * r2d; //Diagonal principal
        return ok1I && ok2I && ok1D && ok2D && (r == r1d * r2i);
    }
}
/*
n = 

*/

bool algoritmo(vector<vector<int>>const& mat, int& r) {
    return recursiva(mat, r, 0, (int)mat.size() - 1, 0, (int)mat.size() - 1);
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n, aux; cin >> n;
    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aux;
            mat[i].push_back(aux);
        }
    }
    bool siEs;
    int r;
       //Calcula el resultado
    siEs = algoritmo(mat, r);
       //Escribe el resultado
    if (siEs)
        cout << "SI " << r << endl;
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