
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& v, int ini, int fin) {
	if (v[ini] % 2 != 0) return v[ini];
	if (v[fin] % 2 != 0)return v[fin];

	if (ini == fin) {
		return v[fin];
	}
	else {
		int m = (ini + fin) / 2;

		if (v[m] % 2 != 0) return v[m];
		else {
			int nPares = 0;
			int dif = 0;


			if (m != ini) {
				nPares = v[m] - v[ini] - 2;//caben n pares
				dif = m - ini - 1;
			}
			else {
				nPares = v[fin] - v[m] - 2;//caben n pares
				dif = fin - m - 1;
			}

			if (nPares < 0) {
				if (v[m] % 2 != 0) return v[m];
				else return v[fin];
			}

			if (dif != nPares)
				return resolver(v, ini, m);
			else
				return resolver(v, m + 1, fin);
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, ini, fin;
	std::cin >> tam;

	if (tam == 0)
		return false;

	std::vector<int> v(tam);
	for (int& n : v)std::cin >> n;

	ini = 0;
	fin = tam - 1;

	int sol = resolver(v, ini, fin);

	// escribir sol
	std::cout << sol << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej2S12018.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
