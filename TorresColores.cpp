#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*Primera roja
* numv <= numa DURANTE
* Nunca dos verdes juntas DURANTE
*  numr > numv + numa   FINAL
*/
// 0 -> azul, 1 -> rojo, 2 -> verde

bool esValida(vector<int>& sol, vector<int>const& nColores, vector<int>& conteo, int k, int i) {
    //No es v�lida si no cumple las restricciones o si excede el l�mite del color
    if (i == 2) {
        if (sol[k - 1] == 2)
            return false;
        else if (conteo[2] + 1 > conteo[0])
            return false;
    }
    return conteo[i] + 1 <= nColores[i];
}


bool solucionCorrecta(vector<int>& conteo, int i) {
    conteo[i] += 1;
    bool r = conteo[1] > conteo[0] + conteo[2];
    conteo[i] -= 1;
    return r;
}

void sacarSol(vector<int>const& sol) {
    for (int i = 0; i < (int)sol.size(); i++) {
        switch (sol[i])
        {
        case 0:
            cout << "azul";
            break;
        case 1:
            cout << "rojo";
            break;
        case 2:
            cout << "verde";
        default:
            break;
        }
        if (i != (int)sol.size() - 1)cout << " ";
    }
    cout << endl;
}

/*
�RBOL DE PROFUNDIDAD n, su primer nodo s�lo
*/
void vueltaAtras(int n, vector<int>const& nColores, vector<int>& sol, vector<int>& conteo, bool& haySol, int k) {
    int i = 0;
    while (i < 3) {
        sol[k] = i;    
        if (esValida(sol, nColores, conteo, k, i)) {
            if (k == n - 1) {
                if (solucionCorrecta(conteo, i)) {
                    sacarSol(sol);
                    haySol = true;
                }
            }
            else {
                conteo[i] += 1; //Marcar
                vueltaAtras(n, nColores, sol, conteo, haySol, k + 1);
                conteo[i] -= 1; //Desmarcar
            }
        }
        i++;
    }
}

bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    vector<int> nColores(3);
    cin >> n >> nColores[0]>> nColores[1]>> nColores[2];
    if (n == 0 && nColores[0] == 0 && nColores[1] == 0 && nColores[2] == 0)
        return false;
    vector<int> sol(n);
    sol[0] = 1;
    vector<int> conteo = {0,1,0};
    bool haySol = false;
    //Resolver problema
    if (nColores[1] == 0)
        cout << "SIN SOLUCION" << endl;
    else {
        vueltaAtras(n, nColores, sol, conteo, haySol, 1);
        if (!haySol)
            cout << "SIN SOLUCION" << endl;
    }
    cout << endl;
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