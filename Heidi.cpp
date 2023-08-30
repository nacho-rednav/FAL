#include <iostream>
#include <vector>

#include <fstream>
using namespace std;

int maximo(int a, int b) {
    if (a < b)return b;
    return a;
}

//P { l > 1 }
//proc          in                      in      out             out
void algoritmo(vector<int> const& v, int l, vector<int>& vr, int& r) {
    int n = (int)v.size();
    int i = n - 1, max = v[i], qr = i;
    r = 0;

    //Coste: O(v.size()) Recorre todo el array siempre, lo del interior del bucle es cte
    //Funcion de cota: i
    //Invariante: -1 <= i < v.size() && max = max j : i <= j < v.size() : v[j] && qr = max j : i <= j < v.size() && (llano(l, v, i, j) || qr = i) : j
    //              && r = max p, q : 0 <= p <= q < v.size() && llano(l, v, p, q) : q - p
    while (i != -1) {
        if (v[i] != max) {
            if (qr - i >= l) {
                r = maximo(r, qr - i);
                vr.push_back(qr);
            }
            if (v[i] < max)
                qr = i - 1;
            else if (v[i] > max) {
                max = v[i];
                qr = i;
            }
        }
        i--;
    }
    if (qr - i >= l) {
        r = maximo(r, qr - i);
        vr.push_back(qr);
    }
}
//¿Como defino un llano?
//decreciente { vector que decrece}
//llano(v, p, q) {(forall i: p <= i < q - 1 && q - 1 <= j < v.size() : v[i] = v[i+1]}
//llanoMaximo(l, v, p, q) { llano(v, p, q) && q - p >= l && (p = 0 || v[p-1] != v[p]) && ( q = v.size() || v[q+1] != v[q])
//vistas(v, c, f) { forall i, j : c <= i < f && f <= j < v.size() : v[j] <= v[i] }
//valido(v) { (exists p, q : 0 <= p < q <= v.size() : llano(v, p, q) && vistas(v, p, q) && q-p >= l) }
//Q { ( !valido -> r = 0) && ( valido -> r = max p, q : 0 <= p < q <= v.size() && llano(v, p, q) && vistas(v, p, q) && q - p >= l : q - p)
//   forall fi : 0 <= fi < vr.size() : (exists j : 0 <= j < fi : llanoMaximo(l, v, j, fi)) && decreciente(vr)} 

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n = 0, l = 0, r = 0;
    vector<int> vr;
    cin >> n >> l;

    if (!std::cin)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    //Resolver problema
    algoritmo(v, l, vr, r);
    //Escribir resultado
    cout << r << " " << (int)vr.size();
    for (int i = 0; i < (int)vr.size(); i++)
        cout << " " << vr[i];
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