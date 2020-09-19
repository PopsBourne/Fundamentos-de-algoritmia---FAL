
/*
	T(n) = c			n=0,1
	T(n) = 2T(n/2) + n	n>1

	T(n) pertenece a O(nlog(n))
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct data {
	int c;
	std::string nombre;
};

// función que resuelve el problema
data resolver(std::vector<std::pair<std::string, int>> const& v, int const& ini, int const& fin) {

	if (ini == fin) return { v[ini].second, v[ini].first };
	else if (ini + 1 == fin) {
		if (v[ini].second >= v[fin].second) return{ v[ini].second + v[fin].second / 2, v[ini].first };
		else return { v[fin].second + v[ini].second / 2, v[fin].first };
	}
	else {
		int m = (ini + fin) / 2;
		data izq = resolver(v, ini, m);
		data der = resolver(v, m + 1, fin);

		if (izq.c >= der.c) return { izq.c + der.c / 2, izq.nombre };
		else return{ der.c + izq.c / 2, der.nombre };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, c;
	std::string nombre;
	std::cin >> n;
	if (!std::cin)
		return false;

	std::vector<std::pair<std::string, int>> v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> nombre >> c;
		v[i].first = nombre;
		v[i].second = c;
	}

	data sol = resolver(v, 0, n - 1);

	// escribir sol
	std::cout << sol.nombre << " " << sol.c << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("10.txt");
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