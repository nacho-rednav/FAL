#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//P{ n >= 0 && forall j: 0 <= j < n-1 : v[j]!= 0 }
void algoritmo(vector<int>const& v, vector<int>& res) {
    int i = 1;
    
    res.push_back(v[0]);
    //F.Cota: n - i
    //I: 1 <= i <= n && res[res.size()-1] = max j : (j = 0) || (1 <= j < i && forall p : 1 <= : v[j]
    while (i < (int)v.size()) {
        if (v[i - 1] + 1 != v[i]) {
            if(i != 1 && !(v[i-1] == res[(int)res.size()-1]))
                res.push_back(v[i - 1]);
            res.push_back(-1);
            res.push_back(v[i]);
        }
        i++;
    }
}
//Q{

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n; cin >> n;
    vector<int>v;
    vector<int>res;
    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }
    if (v.size()==0)
        return false;
    v.push_back(0);

    //Resolver problema
    algoritmo(v, res);
    //Escribir resultado
    cout << res[0];
    bool primero = false;
    for (int i = 1; i < res.size()-2; i++) {
        if (res[i] == -1) {
            primero = true;
            cout << ",";
        }
        else {
            if (!primero)
                cout << "-" << res[i];
            else
                cout << res[i];
            primero = false;
        }
        //cout << res[i] << " ";
    }
    cout << endl;
    return true;
}


int main() {


    while (resuelveCaso());

    return 0;
}