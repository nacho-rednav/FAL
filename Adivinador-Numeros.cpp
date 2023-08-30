#include <iostream>
using namespace std;

void adivinador(int i, int f) {
	int m = (f + i) / 2;
	string rep;

	if (f == i) {
		cout << "La respuesta es " << i << endl;
		return;
	}

	cout << "Dime si > o <=: " << m;cout << endl;
	cout << "-> "; cin >> rep; cout << endl;
	if (rep == "<=")
		adivinador(i, m);
	else if (rep == ">")
		adivinador(m + 1, f);
}

int main() {

	cout << "Piensa un numero y un intervalo en que se encuentre" << endl;
	cout << "Dame el intervalo: "; int i, f; cin >> i >> f;
	cout << endl;

	adivinador(i, f);

	return 0;
}