/*
	T(n) = c			n=1
	T(n) = T(n/2) + c	n > 1
	
	T(n) pertenece a O(log(n))

*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int const& ini, int const& fin, int const& n) {

	if (ini == fin) {
		if (n + ini == v[ini])
			return v[ini];
		else return -1;
	}
	else {
		int m = (ini + fin) / 2;

		if (n + m > v[m]) return resolver(v, m + 1, fin, n);
		else return resolver(v, ini, m, n);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam, n;
	std::cin >> tam >> n;

	std::vector<int> v(tam);

	for (int& n : v) std::cin >> n;

	int sol = resolver(v, 0, tam - 1, n);
	// escribir sol

	if (sol == -1) std::cout << "NO" << "\n";
	else std::cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("08.txt");
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