#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct data {
	bool existe;
	int p1;
	int p2;
};

// función que resuelve el problema
data resolver(std::vector<int> const& v1, std::vector<int> const& v2, int const& ini, int const& fin) {

	if (ini == fin) {
		if (v1[ini] == v2[fin]) return { true,ini };
		else {
			if (v1[ini] > v2[ini])return { false,ini - 1,ini };
			else return { false, ini,ini + 1 };
		}
	}
	else {
		int m = (ini + fin) / 2;

		if (v1[m] < v2[m]) return resolver(v1, v2, m+1, fin);
		else return resolver(v1, v2, ini, m);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	if (n == 0)
		return false;

	std::vector<int> v1(n);
	std::vector<int> v2(n);

	for (int& n1 : v1) std::cin >> n1;
	for (int& n2 : v2) std::cin >> n2;

	data sol = resolver(v1, v2, 0, n - 1);

	// escribir sol
	if (sol.existe) std::cout << "SI" << " " << sol.p1 << "\n";
	else std::cout << "NO" << " " << sol.p1 << " " << sol.p2 << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("18.txt");
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
