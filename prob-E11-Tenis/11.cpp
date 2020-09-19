/*
	T(n) = c				n=2
	T(n) = 2T(n/2) + c		n> 2

	T(n) pertenece a O(n)
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct data {
	bool ganador;
	int jugados;
};


// función que resuelve el problema
data resolver(std::vector<std::string> const& v, int const& ini, int const& fin, int& r, int const& ronda) {

	if (ini + 1 == fin) {
		r = 1;
		if (v[ini] == "NP" && v[fin] == "NP") return { false,0 };//si no se juega
		else if (v[ini] == "NP" || v[fin] == "NP") return { true,0 };//si no se juega pero se presenta un jugador
		else return { true, 1 };//si se juega
	}
	else {
		int m = (ini + fin) / 2;

		data izq = resolver(v, ini, m, r, ronda);
		data der = resolver(v, m + 1, fin, r, ronda);


		if (r < ronda && izq.ganador && der.ganador) {
			r++;
			return{ true,izq.jugados + der.jugados + 1 };
		}
		else if (!izq.ganador && !der.ganador) {
			r++;
			return { false,izq.jugados + der.jugados };
		}
		else if (izq.ganador || der.ganador) {
			r++;
			return{ true,izq.jugados + der.jugados };
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, ronda, r;
	std::cin >> n;
	if (!std::cin)
		return false;
	std::cin >> ronda;
	std::vector<std::string> v(n);
	for (std::string& m : v) std::cin >> m;
	data sol = resolver(v, 0, n - 1, r, ronda);

	// escribir sol
	std::cout << sol.jugados << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("11.txt");
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