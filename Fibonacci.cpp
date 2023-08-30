#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct matriz {
    long long int m1, m2, m3;
};

void multiplica(matriz& matF, matriz& mat1, matriz& mat2) {
    matF.m1 = mat1.m1 * mat2.m1 + mat1.m2 * mat2.m2;
    matF.m2 = mat1.m1 * mat2.m2 + mat1.m2 * mat2.m3;
    matF.m3 = mat1.m2 * mat2.m2 + mat1.m3 * mat2.m3;
}

void mezcla(long long int n, matriz& mat1, matriz& matF) {
    matriz n1, aux;

    multiplica(matF, mat1, mat1);
    if (n % 2 == 1) {
        n1.m1 = 0; n1.m2 = 1; n1.m3 = 1;
        aux.m1 = matF.m1; aux.m2 = matF.m2; aux.m3 = matF.m3;
        multiplica(matF, aux, n1);
    }
}

void divFibo(long long int n, matriz& mat){
    matriz mat1;

    if (n == 1) {
        mat.m1 = 0;
        mat.m2 = 1;
        mat.m3 = 1;
    }
    else {
        divFibo(n / 2, mat1);
        mezcla(n, mat1, mat);
    }
}

long long int algoritmo(long long int n) {
    matriz mat1, matF;

    if (n == 1)return 1;

    divFibo(n / 2, mat1);
    mezcla(n, mat1, matF);

    return matF.m2 % 46337;
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    long long int n; cin >> n;
    if (n == 0)
        return false;


    //Resolver problema
    long long int r = algoritmo(n);
    //Escribir resultado
    cout << r << endl;
    return true;
}


int main() {


    while (resuelveCaso());

    return 0;
}