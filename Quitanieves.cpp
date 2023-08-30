#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
La soluci�n es un vector de tama�o n que representa cada carretera y para
cada carretera elijo qu� m�quina va, tambi�n puede no ir ninguna

El �rbol por lo tanto tiene profundidad n y ramificaci�n m+1.
El tama�o del espacio de soluciones es (m+1)^n

Las restricciones impl�citas son que valoresd el vector de soluciones estar�n en el
rango -1, m-1
Las restricciones expl�citas son que una m�quina s�lo puede ir a una carretera

La poda consiste en que para cada carretera guardo en un vector el m�ximo de calidad
que se puede obtener de las siguientes carreteras. Si la calidad que se lleva m�s ese m�ximo de calidad
es menor que el mejor resultado encontrado podo esa rama.
Calcularlo tiene coste de n*m y usarla tiene coste cte en las llamadas.
*/



void vueltaAtras(vector<vector<int>>const& calidades, vector<int>const& anchMaqs,
    vector<int>const& anchCalles, int n, int m,
    vector<bool>& asignadas, vector<int>& sol, int cal,
    int& cal_M, int k, vector<int>& sol_M, vector<int>const& sumaCals) {
    int i = 0;
    
    while (i < m) { 
        if (anchMaqs[i] <= anchCalles[k]
            && !asignadas[i]) {
            sol[k] = i;
            asignadas[i] = true;
            cal += calidades[i][k];
            if (cal + sumaCals[k] > cal_M) {
                if (k == n - 1) {
                    cal_M = cal;
                    sol_M = sol;
                }
                else {
                    vueltaAtras(calidades, anchMaqs, anchCalles, n, m,
                        asignadas, sol, cal, cal_M, k + 1, sol_M, sumaCals);
                }
            }
            asignadas[i] = false;
            cal -= calidades[i][k];
        }
        i++;
    }
    //Ninguna m�quina se asigna a esta carretera
    sol[k] = -1;
    if (cal + sumaCals[k] > cal_M) {
        if (k == n - 1) {
            cal_M = cal;
            sol_M = sol;
        }
        else {
            vueltaAtras(calidades, anchMaqs, anchCalles, n, m,
                asignadas, sol, cal, cal_M, k + 1, sol_M, sumaCals);
        }
    }
}

void calculoEst(vector<vector<int>>const& calidades, vector<int>& sumaCals, int n, int m) {
    vector<int> aux(n);
    int maximo;
    for (int i = 0; i < n; i++) {
        maximo = calidades[0][i];
        for (int j = 1; j < m; j++) {
            maximo = max(maximo, calidades[j][i]);
        }
        aux[i] = maximo;
    }
    sumaCals[n - 1] = 0;
    for (int i = n-2; i>=0; i--) {
        sumaCals[i] = sumaCals[i + 1] + aux[i + 1];
    }
}

void algoritmo(vector<vector<int>>const& calidades, vector<int>const& anchMaqs,
    vector<int>const& anchCalles, int n, int m, int& res) {
    vector<bool>mqsAsignadas(m, false);
    vector<int>sol(n);
    vector<int>sol_M(n);
    vector<int>sumaCals(n);
    if (m == 0)
        res = 0;
    else {
        calculoEst(calidades, sumaCals, n, m);
        vueltaAtras(calidades, anchMaqs, anchCalles, n, m,
            mqsAsignadas, sol, 0, res, 0, sol_M, sumaCals);
    }
}
    

void resuelveCaso() {
    //resuelve aqui tu caso
    //Lee los datos
    int m, n, aux, r;
    cin >> m >> n;
    vector<int>anchMaqs(m);
    vector<int>anchCalles(n);
    vector<vector<int>>calidades(m);
    for (int i = 0; i < m; i++)
        cin >> anchMaqs[i];
    for (int i = 0; i < n; i++)
        cin >> anchCalles[i];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aux;
            calidades[i].push_back(aux);
        }
    }
       //Calcula el resultado
    r = 0;
    algoritmo(calidades, anchMaqs, anchCalles, n, m, r);
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