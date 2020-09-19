#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	T(n) = c			n=1
	T(n) = T(n/2) + c	n>1
		 =	T(n/2^2) + c + c
		 =	T(n/2^3) + c + c + c
		 =	T(n/2^k) + k*c
		 =  T(1) + log(n)*c (pertenece a) O(log(n)) siendo n el número de elementos del vector
*/

// función que resuelve el problema
int resolver(int const& x, std::vector<int> const& v, int ini, int fin, int& distanciaM, int& posM) {

	if (ini == fin) {
		if (x == v[ini])return v[ini];
		if (distanciaM == -1) return v[ini];
		else {
			if (abs(abs(v[ini]) - abs(x)) < distanciaM) return v[ini];
			return posM;
		}
	}
	else if (ini + 1 == fin) {
		if (x == v[ini]) return v[ini];
		if (x == v[fin]) return v[fin];

		if (distanciaM == -1) {
			if (abs(abs(v[ini]) - abs(x)) <= abs(abs(v[fin]) - abs(x))) return v[ini];
			else return v[fin];
		}
		else {
			if (abs(abs(v[ini]) - abs(x)) <= abs(abs(v[fin]) - abs(x))) {
				if (abs(abs(v[ini]) - abs(x)) < distanciaM) return v[ini];
			}
			else {
				if (abs(abs(v[fin]) - abs(x)) < distanciaM) return v[fin];
			}
			return posM;
		}
	}
	else {
		int m = (ini + fin) / 2;

		if (x == v[m]) return v[m];

		if (x < v[m]) {
			distanciaM = -1;
			return resolver(x, v, ini, m, distanciaM, posM);
		}
		else {
			distanciaM = abs(abs(v[m]) - abs(x));
			posM = v[m];
			return resolver(x, v, m + 1, fin, distanciaM, posM);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, x, disM, posM;
	std::cin >> x >> n;

	std::vector<int>v(n);
	for (int& m : v) std::cin >> m;

	disM = -1;
	posM = 0;
	std::cout << resolver(x, v, 0, n - 1, disM, posM) << "\n";
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej2S22018.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}