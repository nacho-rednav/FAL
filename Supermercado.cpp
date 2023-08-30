#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Ärbol de profundidad prods, con ramificación sups
    La solución será un vector de tamaño prods en la que se guarda el super en que se compra el producto
    El espacio de búsqueda es de tamaño sups^prods

    Restricciones explicitas: los valores del vector de soluciones están entre 0 y sups-1
    Restricciones implícitas: sólo se pueden comprar tres productos en un mismo super

    La funcion de poda consiste en sumarle al precio que llevamos la suma de los
    precios más baratos de cada producto que falta por comprar.
    Tiene coste perteneciente a O(n^2) calcular el vector y después
    coste cte en la ejecución (es una suma)
*/


bool esValida(vector<int>const& conteo, int i) {
    return conteo[i] + 1 <= 3;
}

void calculoEstimacion(vector<vector<int>>const& mat, vector<int>& sumaBarato) {
    vector<int> rapido;
    int aux;
    int n = (int)sumaBarato.size();

    //Coste será de O(prods*sups) osea que pertenece a O(n^2)
    //Por cada una de las prods iteraciones del primer bucle hay 
    //sups iteraciones del segundo. Lo de dentro de los bucles es de coste cte
    for (int c = 0; c < (int)mat[0].size(); c++) {
        aux = mat[0][c];
        for (int f = 0; f < (int)mat.size(); f++) {
            aux = min(aux, mat[f][c]);
        }
        rapido.push_back(aux);
    }
    sumaBarato[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        sumaBarato[i] = sumaBarato[i + 1] + rapido[i + 1];
    }
}

void vueltaAtras(vector<vector<int>>const& mat, int sups, int prods,
    vector<int>& conteo, int k, int precio, int& mejorEncontrado, vector<int>const& sumaBarato) {
    int i = 0;

    while (i < sups) {
        if (esValida(conteo, i)) {
            precio += mat[i][k];
            conteo[i] += 1;
            if (precio + sumaBarato[k] < mejorEncontrado) {
                if (k == prods - 1) {
                    mejorEncontrado = precio;
                }
                else {
                    vueltaAtras(mat, sups, prods, conteo, k + 1, precio, mejorEncontrado, sumaBarato);
                }
            }
            precio -= mat[i][k];
            conteo[i] -= 1;
        }
        i++;
    }
}

int inicializacion(vector<vector<int>>const& mat, int sups, int prods) {
    int s = 0, r = 0;
    for (int i = 0; i < prods; i++) {
        r += mat[s][i];
        if ((i + 1) % 3 == 0)
            s++;
    }
    return r;
}

int algoritmo(vector<vector<int>>const& mat, int sups, int prods) {
    vector<int> conteo(sups, 0);
    vector<int>sumaBarato(prods, 0);
    int r = inicializacion(mat, sups, prods);
    calculoEstimacion(mat, sumaBarato);
    vueltaAtras(mat, sups, prods, conteo, 0, 0, r, sumaBarato);
    return r;
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int sups, prods, aux, r;
    cin >> sups >> prods;
    vector<vector<int>>mat(sups);
    for (int i = 0; i < sups; i++) {
        for (int j = 0; j < prods; j++) {
            cin >> aux;
            mat[i].push_back(aux);
        }
    }
    //Calcula el resultado
    r = algoritmo(mat, sups, prods);
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