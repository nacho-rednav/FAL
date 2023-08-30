#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
El arbol de exploracion es de profundidad y ramificacion tam siendo
tam el número de dígitos del número recibido.
El espacio de soluciones es de tamaño n^n
La solución son dos números, los colmillos

Restricciones explícitas: los colmillos están formados por los dígitos del número original
Restricciones implícitas: los colmillos tienen la mitad de dígitos que el origianl,
los colmillos tienen los mismos dígitos y en la misma cantidad que el original, los dos colmillos
no pueden acabar en cero
*/

bool promete(int num, int c1, int c2, int k, int l, int pow) {

    bool comprueba = true;
    if (k == l / 2 + 1) {
        comprueba = !(c1 % 10 == 0 && c2 % 10 == 0) &&
            !(num % 2 == 1 && ((c1 * c2) % 2 == 0)) &&
            !(c1 < pow);
    }
    return comprueba && (c1 * c2 <= num);
}

void vueltaAtras(vector<int>const& v, int num, int l, bool& sol,
    int k, vector<bool>& usados, int c1, int c2, int pow) {
    int i = 0;
    int prev;
    bool colmillo1;
    if (k == l / 2 + 1)
        pow = 1;
    while (i < l && !sol) {
        if (!usados[i]) {
            usados[i] = true;
            if (k <= l / 2) {
                colmillo1 = true;
                prev = c1;
                c1 = v[i]*pow + c1;
            }
            else if ((k > l / 2) && (k <= l)) {
                colmillo1 = false;
                prev = c2;
                c2 = v[i] * pow + c2;
            }

            if (promete(num, c1, c2, k, l, pow)) {
                if (k == l)
                    sol = (num == (c1 * c2));
                else {
                    vueltaAtras(v, num, l, sol, k + 1, usados, c1, c2, pow*10);
                }
            }

            if (colmillo1)
                c1 = prev;
            else if (!colmillo1)
                c2 = prev;
            usados[i] = false;
        }
        i++;
    }
}

void algoritmo(int num, bool& vampiro) {
    vector<int>v;
    int aux = num;
    while (aux > 0) {
        v.push_back(aux % 10);
        aux = aux / 10;
    }
    int l = (int)v.size();
    vector<bool>usados(l, false);
    
    vampiro = false;
    if (!((int)v.size() % 2 == 1))
        vueltaAtras(v, num, l, vampiro, 1, usados, 0, 0, 1);

}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int n; cin >> n;
       //Calcula el resultado
    bool vampiro;
    algoritmo(n, vampiro);
       //Escribe el resultado
    if (vampiro)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
}

int main() {
   /* // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
*/
    return 0;
}