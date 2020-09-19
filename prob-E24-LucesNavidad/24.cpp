#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <cstdlib>

// pos tira k
// color i

bool esValida(std::vector<int>const& sol, std::vector<int> const& colores, int const& k, int const& i, int const& max, int const& consumo) {

	if (k > 1 && (sol[k - 2] == sol[k - 1] && sol[k - 1] == sol[k])) return false;
	if (colores[i] > 1 + (k / 2)) return false;
	if (consumo > max) return false;

	return true;
}



// Agrupar los datos en structs por datos de entrada, datos actuales, marcaje y solMejor
void resolver(std::vector<int> const& consumoLuces, std::vector<int>& sol, std::vector<int>& colores, int k, int& cont, int& consumo, int const& consumoMax, int const& longTira) {

	for (int i = 0; i < consumoLuces.size(); ++i) { //recorro los colores
		sol[k] = i;

		//marco
		consumo += consumoLuces[i];
		colores[i]++;

		if (esValida(sol, colores, k, i, consumoMax, consumo)) {
			if (k == (longTira - 1)) { //FINAL
				cont++;
			}
			else resolver(consumoLuces, sol, colores, k + 1, cont, consumo, consumoMax, longTira);
		}

		//desmarco
		consumo -= consumoLuces[i];
		colores[i]--;
	}
}


bool resuelveCaso() {
	int longitud, numColores, consumoMax, cont, contColor, contSol, consumo;
	std::cin >> longitud;
	if (longitud == 0) return false;
	std::cin >> numColores >> consumoMax;
	std::vector<int> consumoLuces(numColores);
	for (int& i : consumoLuces) std::cin >> i;

	std::vector<int> sol(longitud, 0);
	std::vector<int> colores(numColores, 0);
	cont = 0;
	contColor = 0;
	contSol = 0;
	consumo = 0;

	resolver(consumoLuces, sol, colores, 0, contSol, consumo, consumoMax, longitud);
	std::cout << contSol << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("24.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
