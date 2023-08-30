#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int algoritmo(vector<int> const& v, int p, int n) {
    int maxPartituras = p - n, cont = 0, i = 0;
    if (maxPartituras == 0) return v[0];
    vector<int>sol(n, 1);


    while (cont < maxPartituras) {
        sol[i]++;
        cont++;
        if (v[i] / sol[i] < v[i + 1] / sol[i + 1])
            i++;
    }
    return v[i] / sol[i];
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int p, n;
    cin >> p >> n;

    if (!std::cin)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    //Resolver problema
    int r = algoritmo(v, p, n);
    //Escribir resultado
    cout << r << endl;
    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}