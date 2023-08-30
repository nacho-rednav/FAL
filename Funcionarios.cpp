#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
Arbol de profundidad n y ramificacion n. La profundidad está determinada por el número de trabajos y la ramificación por el numero de funcionarios
El espacio de soluciones es de tamaño n^n
La solucion es una tupla dde tamaño n. Cada posicion i de la tupla representa qué funcionario hace el trabajo i

Restricciones explicitas: todo valor de la tupla esta entre 0 y n-1
Implicitas: en la tupla no hay valores repetidos, cada funcionario hace sólo un trabajo

La funcion de poda consiste en un vector que en la posicion k guarda la suma del tiempo minimo que se tarda en realizar los siguientes trabajos
Tiene coste cuadrático al calcularla y cte en las llamadas
*/

bool esValida(vector<bool>const& marcas, int i) {
    return !marcas[i];
}

void vueltaAtras(vector<vector<int>> const& mat, int n, int& tiempoMejor,
    vector<bool>& marcas, vector<int>const& sumaRapido, int k, int tiempo, vector<int>& sol, vector<int>&sol_M) {
    int i = 0;
    while (i < n) {
        if (esValida(marcas, i)) {
            tiempo += mat[i][k];
            marcas[i] = true;
            sol[k] = i;
            if (tiempo + sumaRapido[k] < tiempoMejor) {
                if (k == n - 1) {
                    tiempoMejor = tiempo;
                    sol_M = sol;
                }
                else {
                    vueltaAtras(mat, n, tiempoMejor, marcas, sumaRapido, k+1, tiempo, sol, sol_M);
                }
            }
            tiempo -= mat[i][k];
            marcas[i] = false;
        }
        i++;
    }
}

void calculoPoda(vector<vector <int>>const& mat, vector<int>& sumaRapido, int n) {
    vector<int> rapido(n);
    int aux;
    for (int c = 0; c < n; c++) {
        aux = mat[0][c];
        for (int f = 1; f < n; f++) {
            aux = min(aux, mat[f][c]);
        }
        rapido[c] = aux;
    }
    sumaRapido[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        sumaRapido[i] = sumaRapido[i + 1] + rapido[i + 1];
    }
}

int inicializacion(vector<vector<int>> const& mat, int n) {
    int r=0;
    for (int i = 0; i < n; i++) {
        r += mat[i][i];
    }
    return r;
}

int algoritmo(vector<vector<int>> const& mat, int n) {
    int tiempoMejor;
    vector<bool> marcas(n, false);
    vector<int> sumaRapido(n, 0);
    vector<int>sol(n);
    vector<int>sol_M(n);
    tiempoMejor = inicializacion(mat, n);
    calculoPoda(mat, sumaRapido, n);

    vueltaAtras(mat, n, tiempoMejor, marcas, sumaRapido, 0, 0, sol, sol_M);
    return tiempoMejor;
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n, aux, r; cin >> n;
    if (n==0)
        return false;
    vector<vector<int>>mat(n);
    for (int f = 0; f < n; f++) {
        for (int c = 0; c < n; c++) {
            cin >> aux;
            mat[f].push_back(aux);
        }
    }

    //Resolver problema
    r = algoritmo(mat, n);
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