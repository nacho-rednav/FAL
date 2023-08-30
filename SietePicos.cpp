#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// P { n >= 2 }
int algoritmo(vector<int> const& v) {
    int i = 1, r = 0;
    int n = (int)v.size();
    
    //F. Cota: n-i
    //Coste: O(n) siendo n el número de elementos
    //I: 1 <= i <= n-1 
    while (i < n-1) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1])
            r++;
        i++;
    }
    if (v[0] > v[n-1] && v[0] > v[1])
        r++;
    if (v[n - 1] > v[0] && v[n - 1] > v[n - 2])
        r++;

    return r;
}
//Q{ r = (#i : 1 <= i < n-1 : v[i]>v[i-1] && v[i]>v[i+1]) + 1 if(}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n; cin >> n;
    if (n==0)
        return false;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    //Resolver problema
    int r = algoritmo(v);
    //Escribir resultado
    cout << r << endl;
    return true;
}


int main() {
    while (resuelveCaso());
}