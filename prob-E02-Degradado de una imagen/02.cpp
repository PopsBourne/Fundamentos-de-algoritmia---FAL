
/*
	Coste O(nlogn)

	T(n) = c			n = 1,2
	T(n) = 2T(n/2) + n	n > 2

*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct data {
	int suma;
	bool degr;
};

// función que resuelve el problema
data resolver(std::vector<int> const& v, int const& ini, int const& fin) {

	if (ini == fin) return { v[ini],true };
	else if (v[ini] > v[fin]) return { 0,false };
	else {
		int m = (ini + fin) / 2;

		data izq = resolver(v, ini, m);
		data der = resolver(v, m + 1, fin);

		if (izq.suma < der.suma && izq.degr && der.degr) return { izq.suma + der.suma,true };
		else return { 0, false };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int alt, n, valor;
	data sol;
	bool degradado = true;
	std::cin >> alt >> n;
	if (!std::cin)
		return false;

	std::vector<std::vector<int>> v(alt);

	for (int i = 0; i < alt; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> valor;
			v[i].push_back(valor);
		}
		sol = resolver(v[i], 0, n - 1);
		if (!sol.degr) degradado = false;
	}

	// escribir sol
	if (degradado) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("02.txt");
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