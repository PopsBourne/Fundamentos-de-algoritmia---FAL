#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
char resolver(std::vector<char> const& v, int const& ini, int const& fin) {

	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) {
		if (v[fin] - v[ini] > 1) return v[ini] + 1;
	}
	int m = (ini + fin) / 2;

	if (v[m] - v[ini] > v[fin] - v[m + 1])
		return resolver(v, ini, m);
	else if (v[m] - v[ini] < v[fin] - v[m + 1])
		return resolver(v, m + 1, fin);
	else if (v[m + 1] - v[m] > 1) return v[m] + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char ini, fin;
	std::cin >> ini >> fin;
	int tam = fin - ini;
	std::vector<char> v(tam);

	for (char& n : v)
		std::cin >> n;

	if (v[0] != ini) {
		char sol = ini;
		std::cout << sol << "\n";
	}
	else if (v[tam - 1] != fin) {
		char sol = fin;
		std::cout << sol << "\n";
	}
	else std::cout << resolver(v, 0, tam - 1) << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("04.txt");
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