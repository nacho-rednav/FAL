#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//P { n > 0 && umb >= 0 && forall i : 0 <= i < n : v[i] = 1 || v[i] = 0 }
int algoritmo(vector<int>const& v, int n, int umb) {
    int i = 0;
    int p, q, cont = 0, maxEnc = 0;
    bool principio = false;
    // I : 0 <= i <= n && principio = Exists j : 0 <= j < i : v[j] = 1 }
    // F.Cota = n - i
    while (i < n && !principio) {
        principio = v[i] == 1;
        i++;
    }
    if (principio) {
        p = i-1;
        q = i-1;
        maxEnc = 1;
    }
    //haySegmentoNoValido(v, i) { Exists p, q : 0 <= p <= q = i : !cumple(v, p, q, umb) || forall j: 0 <= j < i : v[j] = 0 }
    //F. Cota = n - i
    // I : 0 <= i <= n && maxEnc = max pi, fi : 0 <= pi <= fi < i && cumple(v, pi, fi, umb): fi - pi + 1
    //      && p = max j : 0 <= j <= q < i && haySegmentoNoValido(v, j) && v[j] = 1 : j  
    //      && q = max j : p <= j < i && v[j] = 1 : j
    //      && cont = #j : p < j < i : v[j] = 0 
    while (i < n) {
        if (v[i] == 0)
            cont++;
        else if (v[i] == 1) {
            if (cont <= umb) {
                q = i;
                maxEnc = max(q - p + 1, maxEnc);
            }
            else if (cont > umb) {
                p = i;
                q = i;
            }
            cont = 0;
        }
        i++;
    }
    return maxEnc;
}
// cumple(v, p , q, umb) { v[p] = v[q] = 1 && (# i : p <= i <= q : v[i] = 0 ) < umb) }
//Q { r = max p, q : 0 <= p <= q < n && cumple(v, p, q , umb) : q -p + 1}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n, lUmb;
    cin >> n >> lUmb;
    if (n == 0 && lUmb == 0)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    //Resolver problema
    int r = algoritmo(v, n, lUmb);
    //Escribir resultado
    cout << r << endl;
    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}

/*// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif*/