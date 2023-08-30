#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
La solución es un vector de tamaño m que representa a los comensales, cada
posicion inidica en qué sitio se sienta
El árbol es de profundidad m y de ramificación n,
el espacio de soluciones es de tamaño n^m

Las restricciones explícitas: todo elemento de la solución está entre 0 y n-1
Restricciones implícitas: si dos comensales no son allegados deben estar a más de dos metros,
                          los elementos de la solución son todos diferentes, no puede repetirse sitio
*/

bool puedeAsignarse(int sitio, int comensal, vector<vector<float>>const& dists, vector<vector<int>>const& allegs,
    vector<int>& sol, vector<bool>& listaAsignados, int& conteoParejas) {
    int i = 0, cont = 0;
    bool sePuede = true;

    if (!listaAsignados[sitio]) {
        while (i < comensal && sePuede) {
            if (allegs[comensal][i] == 1) {
                if (dists[sitio][sol[i]] < 2)
                    cont++;
            }
            else {
                sePuede = dists[sitio][sol[i]] >= 2;
            }
            i++;
        }
        if (sePuede)
            conteoParejas += cont;
        return sePuede;
    }
    return false;
}

/*
ListaAsignados: vector de booleanos que marca si un sitio ya ha sido asignado
sol: la solución, guardo en qué sitio se sienta cada comensal
maxParejas: guarda el número máximo de parejas de allegados a menos de dos metros encontrado hasta el momento
conteoParejas: guarda la cuenta de las parejas de allegados a menos de dos metros encontrado hasta el momento en la rama
*/
void vueltaAtras(vector<vector<float>>const& dists, vector<vector<int>>const& allegs, int n, int m, int& maxParejas, bool& haySol,
    vector<int>& sol, vector<bool>& listaAsignados, int conteoParejas, int comensal, vector<int>const&sumaAllegados) {
    int sitio = 0, prev = conteoParejas;

    while (sitio < n) {
        if (puedeAsignarse(sitio, comensal, dists, allegs, sol, listaAsignados, conteoParejas)) {
            sol[comensal] = sitio;
            listaAsignados[sitio] = true;
            if (conteoParejas + sumaAllegados[comensal] > maxParejas) {
                if (comensal == m - 1) {
                    haySol = true;
                    maxParejas = conteoParejas;
                }
                else {
                    vueltaAtras(dists, allegs, n, m, maxParejas, haySol, sol, 
                        listaAsignados, conteoParejas, comensal + 1, sumaAllegados);
                }
            }
            listaAsignados[sitio] = false;
        }
        conteoParejas = prev;
        sitio++;
    }
}

/*
La función de optimalidad consiste en un vector en el que para cada comensal se guarda
el número de allegados que tienen los comensales que se van a colocar después, tenindo
en cuenta que no se repiten parejas simétricas.
La cota optimista es suponer que todos esos allegados podrán sentarse en posiciones
que estén a menos de dos metros

Calcularla tiene coste O(m^2), aplicarla en las llamadas tiene coste constante
*/
void calcEstimacion(vector<vector<int>>const& allegs, int m, vector<int>& sumaAllegados) {
    vector<int>allegadosIndividual(m, 0);
    int cont = 0;
    for (int i = m-1; i >= 0; i--) {
        cont = 0;
        for (int j = i; j >= 0; j--) {
            if (allegs[i][j] == 1)
                cont++;
        }
        allegadosIndividual[i] = cont;
    }
    
    sumaAllegados[m - 1] = 0;
    for (int i = m - 2; i >= 0; i--) {
        sumaAllegados[i] = sumaAllegados[i + 1] + allegadosIndividual[i + 1];
    }
}

void algoritmo(vector<vector<float>>const& dists, vector<vector<int>>const& allegs, int n, int m, int& r, bool& haySol) {
    vector<int>sol(m), sumaAllegados(m);
    vector<bool>listaAsignados(n, false);
    calcEstimacion(allegs, m, sumaAllegados);
    int cont = 0;
    r = -1;
    haySol = false;
    vueltaAtras(dists, allegs, n, m, r, haySol, sol, listaAsignados, cont, 0, sumaAllegados);
}

void resuelveCaso() {
    //resuelve aqui tu caso
    int n, m, aux;
    float aux2;
    cin >> n >> m;
    vector<vector<float>>distancias(n);
    vector<vector<int>>allegados(m);
       //Lee los datos
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aux2;
            distancias[i].push_back(aux2);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> aux;
            allegados[i].push_back(aux);
        }
    }
       //Calcula el resultado
    int r;
    bool sol;
    algoritmo(distancias, allegados, n, m, r, sol);
       //Escribe el resultado
    if (sol)
        cout << "PAREJAS " << r << endl;
    else
        cout << "CANCELA" << endl;
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