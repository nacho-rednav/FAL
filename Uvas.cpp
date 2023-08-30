#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

/*
La solucion consiste en un vector que guarda de cada uva si se elige o no se elige
El árbol es de profundidad uvas, ramificacion 2. Espacio de soluciones de tamaño 2^uvas

Explícitas: Los valores sean true o false
Implícitas: debe haber 12 uvas como mucho, la suma de los pesos de esas uvas será menor que el max especificado
*/

void vueltaAtras(vector<int>const& uvas, int n, int maxPeso, int& solAgrupaciones,
    vector<bool>& elegidas, int peso, int uva, int numElegidas, int min) {
    int i = 0;

    while (i < 2) {
        if (i == 0) {
            elegidas[uva] = true;
            numElegidas++;
            peso += uvas[uva];
        }
        else if (i == 1) {
            elegidas[uva] = false;
        }
        if (peso + (min *(12 - numElegidas)) <= maxPeso) {
            if (numElegidas == 12)
                solAgrupaciones++;
            else if (numElegidas < 12 && uva < n - 1)
                vueltaAtras(uvas, n, maxPeso, solAgrupaciones, elegidas, peso, 
                    uva + 1, numElegidas, min);
        }
        if (i == 0) {
            elegidas[uva] = false;
            numElegidas--;
            peso -= uvas[uva];
        }
        i++;
    }
}
/*
Los marcadores son elegidas, que guarda si una uva se elige o no, peso que lleva el peso que se lleva
y numElegidas que nos dice cuántas uvas llevamos elegidas
*/

/*
En la estimación calculo el mínimo del vector, coste lineal, y después utilizo ese mínimo.
En cada llamada si el peso que llevamos más que todas las uvas siguientes pesen lo mínimo posible
es mayor que el peso máximo se descarta la rama
*/
void calcEstimacion(vector<int> v, int n, int& mini) {
    sort(v.begin(), v.end());

    mini = v[0];
    for (int i = 0; i < n; i++) {
        mini = min(mini, v[i]);
    }
}

void algoritmo(vector<int>const& v, int n, int max, int& r) {
    r = 0;
    vector<bool>elegidas(n, false);

    int min;
    calcEstimacion(v, n, min);
    vueltaAtras(v, n, max, r, elegidas, 0, 0, 0,  min);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int max, n;
    cin >> max >> n;
    if (max == 0 && n == 0)
        return false;

    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    //Resolver problema
    int r;
    algoritmo(v, n, max, r);
    //Escribir resultado
    cout << r << endl;
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
    return 0;
    */
    while (resuelveCaso());

    return 0;
}