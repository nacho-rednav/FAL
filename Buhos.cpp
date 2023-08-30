#include <iostream>
#include<algorithm>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string recursiva(vector<char> frase, int i, int f) {
    if (frase[i] != frase[f])
        return "NO";
    else {
        if (f <= i + 1)
            return "SI";

        return recursiva(frase, i+1, f-1);
    }
}

string algoritmo(string& frase) {
    vector<char> v;
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] != ' ') {
            v.push_back(tolower(frase[i]));
        }
    }
    return recursiva(v, 0,(int)v.size() - 1);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    string frase; getline(cin, frase);
    if (frase == "XXX")
        return false;


    //Resolver problema
    string r = algoritmo(frase);
    //Escribir resultado
    cout << r << endl;
    return true;
}


int main() {

    while (resuelveCaso());

 
    return 0;
}