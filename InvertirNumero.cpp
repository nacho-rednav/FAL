#include <iostream>

#include <fstream>
using namespace std;

//arrayDigs(num) = {
//P {Primer digito distinto de cero}
int invertir(int num, int invert) {
    /* Sea n el número di dígitos de num, se considera cero si num es cero
    *        {  k1 si n = 0
    * T(n) = { T(n-1) + k2 si n>0
    *          En cada llamada num tiene un digito menos
    * Por el teorema de la resta tiene un coste de O(n)
    */
    if (num < 10) {
        return invert*10 + num;
    }
    else {
        invert = invert * 10 + num % 10;
        num = num / 10;
        return invertir(num, invert);
    }
}
//Q {invert = 

int algoritmo(int num) {
    return invertir(num, 0);
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int num, result;
    cin >> num;
    if (num == 0)
        return false;
    //Resolver problema
    result = algoritmo(num);
    //Escribir resultado
    cout << result << endl;
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