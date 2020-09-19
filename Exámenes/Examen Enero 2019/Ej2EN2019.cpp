#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct data {
	std::string res;
	int ini;
	int fin;
};


/*
	T(n) = c			n = 1
	T(n) = T(n/2) + c	n > 1
		 = T(n/2^2) + c + c
		 = T(n/2^3) + c + c + c
		 = T(n/2^k) + c*k
		 =...
		 = T(1) + log(n) *c (pertenece a) O(log(n)) siendo n el número de elementos del vector: fin - ini

*/

data resolver(std::vector<int> const& creciente, std::vector<int> const& decreciente, int ini, int fin) {

	if (ini == fin) {
		if (creciente[ini] == decreciente[ini]) return{ "SI",ini };
		else if (creciente[ini] < decreciente[ini]) return { "NO",ini,ini + 1 };
		else return{ "NO",ini - 1,ini };
	}
	else {
		int m = (ini + fin) / 2;

		if (creciente[m] == decreciente[m]) return{ "SI",m };
		else if (creciente[m] > decreciente[m]) return resolver(creciente, decreciente, ini, m);
		else return resolver(creciente, decreciente, m + 1, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n==0)
		return false;

	std::vector<int> creciente(n);
	std::vector<int> decreciente(n);

	for (int& m : creciente) std::cin >> m;
	for (int& k : decreciente) std::cin >> k;

	data sol;
	sol = resolver(creciente, decreciente, 0, n - 1);

	// escribir sol
	if (sol.res == "SI")
		std::cout << sol.res << " " << sol.ini << "\n";
	else std::cout << sol.res << " " << sol.ini << " " << sol.fin << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej2EN2019.txt");
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