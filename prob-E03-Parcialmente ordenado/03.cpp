/*

	T(n) = c				n = 1,2
	T(n) = 2T(n/2) + n		n > 2

	T(n) pertenece a  O(nlog(n))
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct data {
	int max;
	int min;
	bool ordenado;
};

// función que resuelve el problema
data resolver(std::vector<int> const& v, int const& ini, int const& fin) {
	if (ini == fin) return { v[ini], v[ini], true };
	else if (ini + 1 == fin) {
		if (v[ini] <= v[fin]) {

			return { v[fin], v[ini], true };
		}
		else return { 0,0,false };
	}
	else {
		int m = (ini + fin) / 2;
		data izq = resolver(v, ini, m);
		data der = resolver(v, m + 1, fin);

		if (izq.ordenado && der.ordenado && izq.min <= der.min && der.max >= izq.max) return { der.max, izq.min, true };
		else return { 0,0,false };
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int valores;

	std::cin >> valores;
	std::vector<int> v;

	if (!std::cin)
		return false;

	while (valores != 0) {
		v.push_back(valores);
		std::cin >> valores;
	}

	if (!v.empty()) {
		data sol = resolver(v, 0, v.size() - 1);

		// escribir sol
		if (sol.ordenado)
			std::cout << "SI" << "\n";
		else
			std::cout << "NO" << "\n";
	}

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("03.txt");
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