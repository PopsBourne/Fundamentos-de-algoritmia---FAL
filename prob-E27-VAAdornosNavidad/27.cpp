#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int>& superficies, std::vector<int>& costes, std::vector<int>& sol, int const& n, int& sumaAct, int& total, int& max, int& espacio, int k) {

	//marcar
	sol[k]++;
	sumaAct += costes[k];
	espacio += superficies[k];

	if (sumaAct <= max) {
		if (k + 1 == n) {
			if (espacio > total)
				total = espacio;
		}
		else resolver(superficies, costes, sol, n, sumaAct, total, max, espacio, k + 1);
	}

	//desmarco
	sol[k]--;
	sumaAct -= costes[k];
	espacio -= superficies[k];

	if (sumaAct <= max) {
		if (k + 1 == n) {
			if (espacio > total)
				total = espacio;
		}
		else resolver(superficies, costes, sol, n, sumaAct, total, max, espacio, k + 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, presupuesto;
	std::cin >> n;
	if (!std::cin)
		return false;

	std::cin >> presupuesto;
	std::vector<int> superficies(n);
	std::vector<int> costes(n);
	std::vector<int> sol(n, 0);

	for (int i = 0; i < n; ++i) {
		std::cin >> costes[i];
		std::cin >> superficies[i];
	}

	int sumaAct = 0;
	int total = 0;
	int espacio = 0;

	resolver(superficies, costes, sol, n, sumaAct, total, presupuesto, espacio, 0);

	// escribir sol
	std::cout << total << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("27.txt");
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