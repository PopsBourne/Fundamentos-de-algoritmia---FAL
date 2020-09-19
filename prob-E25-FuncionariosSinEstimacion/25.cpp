
// Consiste en realizar un recorrido por todas las soluciones comprobando para cada una si cumple las codiciones
// para ser una solución satisfactoria, si resulta que no va a ser satisfactoria se deshacen las decisiones previas 
// volviendo a una solución parcial prometedora.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// trabajo i
// funcionario k

bool esValida(std::vector<int>& cont, int const& k, int const& i) {

	if (cont[i] > 1) return false;//no se repite trabajo
	return true;
}


// función que resuelve el problema
void resolver(std::vector<std::vector<int>> const& trabajos, std::vector<int>& sol, int& suma, int& total, std::vector<int>& cont, int k) {

	for (int i = 0; i < trabajos.size(); ++i) {
		sol[k] = i;

		//marcar
		total += trabajos[k][i];
		cont[i]++;

		if (esValida(cont, k, i)) {
			if (k == trabajos.size() - 1) {
				if (total < suma) suma = total;
			}
			else resolver(trabajos, sol, suma, total, cont, k + 1);
		}

		//desmarcar
		total -= trabajos[k][i];
		cont[i]--;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nFunc, valor, suma;
	std::cin >> nFunc;
	if (nFunc == 0)
		return false;

	std::vector<std::vector<int>> trabajos;
	trabajos.resize(nFunc, std::vector<int>(nFunc));
	for (int i = 0; i < nFunc; ++i) {
		for (int j = 0; j < nFunc; ++j) {
			std::cin >> valor;
			trabajos[i][j] = valor;
		}
	}

	int j = 0;
	suma = 0;
	std::vector<int> sol(nFunc);
	for (int i = 0; i < nFunc; ++i) {
		sol[i] = trabajos[i][j];
		suma += sol[i];
		j++;
	}

	std::vector<int> cont(nFunc);


	int total = 0;
	resolver(trabajos, sol, suma, total, cont, 0);

	// escribir sol
	std::cout << suma << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("25.txt");
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
