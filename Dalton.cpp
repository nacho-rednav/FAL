#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// { 2 <= v.size() }
// fun dalton(vect<int> v) dev string r
string algoritmo(vector<int> const& v) {

    //Coste: O(v.size()) en el peor caso
    
    int i = 0;
    if (v[0] <= v[1]) {
        //Funcion cota: v.size() -1 -i
        //Invariante: 0 <= i <= v.size()-1 && forall j: 0 <= j < i : v[j] < v[j+1]
        while (i < v.size() - 1 && v[i] < v[i + 1])
            i++;
        if(i < v.size() - 1)
            return "DESCONOCIDOS";
    }
    else if (v[0] > v[1]) {
        while (i < v.size() - 1 && v[i] > v[i + 1])
            i++;
        if (i < v.size() - 1)
            return "DESCONOCIDOS";
    }
    return "DALTON";
}
// Q(v) = forall i : 0 <= i < v.size()-1 : v[i] < v[i +1]
// P(v) = forall i : 0 <= i < v.size()-1 : v[i] > v[i +1]
// {(r = "DALTON" && (Q(v) || P(v)) || (r = "DESCONOCIDOS" && !(Q(v) || P(v))}

bool resuelveCaso() {
    int nPersonajes = 0;
    string result;
    //Leer caso de prueba: cin>>...
    cin >> nPersonajes;
    vector<int> v(nPersonajes);

    if (!std::cin || nPersonajes == 0)
        return false;

    else {
        for (int i = 0; i < nPersonajes; i++)
            cin >> v[i];
        //Resolver problema
        result = algoritmo(v);
    }
    //Escribir resultado
    cout << result << "\n";
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