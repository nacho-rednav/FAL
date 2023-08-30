#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
El árbol tiene profundidad n(número de personas) y ramificación m (número de playas)
El espacio de soluciones es m^n
La solución es una tupla de tamaño n en la que para cada persona se guarda a qué playa va

Las restricciones explícitas: Los valores de la tupla están entre 0 y m-1
Restricciones implícitas:

La funciones de poda son:
Un vector que para cada persona k guarda el máximo de kilos que pueden recoger las personas que van después
Tiene coste cuadrático al crear el vector y cte en las llamadas

Una comprobación de que quedan más o igual de personas por asignar que playas habría que dejar totalment limpias para llegar a l
Tiene coste cte
*/

void tratarKilosLimpias(int& nLimpias, int& kilos, int i,
    vector<int>const& recPorPlaya, vector<int>const& playas, int aumento) {
    if (recPorPlaya[i] + aumento >= playas[i]) {
        kilos += playas[i] - recPorPlaya[i];
        nLimpias += 1;
    }
    else {
        kilos += aumento;
    }
}

bool esValida(vector<int>const& playas, vector<int>const& recPorPlaya, int k, int i) {
    return (recPorPlaya[i] < playas[i]);
}

void vueltaAtras(vector<vector<int>>const& gente, vector<int>const& playas,
    int l, int kilos, int nLimpias,
    vector<int>& recPorPlaya, int k, 
    int& mejorKilos, int& mejorLimp, vector<int>const& sumaKilos) {
    int i = 0, prevK, prevL, aumento;

    while (i < (int)playas.size()) {
        if (esValida(playas, recPorPlaya, k, i)) {
            prevK = kilos; prevL = nLimpias;
            aumento = gente[k][i];
            tratarKilosLimpias(nLimpias, kilos, i, recPorPlaya, playas, aumento);
            recPorPlaya[i] += aumento;
            if ((kilos + sumaKilos[k] > mejorKilos) && ((l - nLimpias) <= ((int)gente.size()-k-1))) {
                if (nLimpias >= l && kilos > mejorKilos) {
                    mejorKilos = kilos; mejorLimp = nLimpias;
                }
                if(k < (int)gente.size()-1) {
                    vueltaAtras(gente, playas, l, kilos, nLimpias,
                        recPorPlaya, k + 1, mejorKilos, mejorLimp, sumaKilos);
                }
            }
            kilos = prevK; nLimpias = prevL;
            recPorPlaya[i] -= aumento;
        }
        i++;
    }
}

void calcularPoda(vector<vector<int>>const& gente, vector<int>& sumaKilos) {
    vector<int> kilos((int)sumaKilos.size());
    int maxi=0, n = (int)gente.size();
    for (int i = 0; i < n; i++) {
        maxi = gente[i][0];
        for (int j = 1; j < (int)gente[i].size(); j++) {
            maxi = max(maxi, gente[i][j]);
        }
        kilos[i] = maxi;
    }
    sumaKilos[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        sumaKilos[i] = sumaKilos[i + 1] + kilos[i + 1];
    }
}

void algoritmo(vector<vector<int>>const& gente, vector<int>const& playas,
    int l, int& kilos, int& nLimpias) {
    vector<int>recogidoPorPlaya((int)playas.size(), 0);
    vector<int>sumaKilos((int)gente.size());
    calcularPoda(gente, sumaKilos);
    vueltaAtras(gente, playas, l, 0, nLimpias,
        recogidoPorPlaya, 0, kilos, nLimpias, sumaKilos);
}

void resuelveCaso() {
    //resuelve aqui tu caso
    int n, m, l, aux;
    int kilos = 0, nLimpias = 0;
       //Lee los datos
    cin >> n >> m >> l;
    vector<int>playas(m);
    for (int i = 0; i < m; i++) {
        cin >> playas[i];
        if (playas[i] == 0)nLimpias += 1;
    }
    vector<vector<int>>gente(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> aux;
            gente[i].push_back(aux);
        }
    }
       //Calcula el resultado
    algoritmo(gente, playas, l, kilos, nLimpias);
       //Escribe el resultado
    if (nLimpias<l)
        cout << "IMPOSIBLE" << endl;
    else
        cout << kilos << " " << nLimpias << endl;
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


