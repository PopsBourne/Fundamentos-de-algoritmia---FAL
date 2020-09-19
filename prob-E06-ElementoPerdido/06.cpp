/*
	T(n) = c			n=0,1
	T(n) = T(n/2) + c	n>2

	T(n) pertenece a O(log(n))
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int resolver(std::vector<int> const& vA, std::vector<int> const& vB, int const& ini, int const& fin) {

	if (ini == fin) return vA[ini];
	else if (ini + 1 == fin) {
		if (vA[ini] == vB[ini])return vA[fin];
		else return vA[ini];
	}
	else {
		int m = (ini + fin) / 2;

		if (vA[m] < vB[m])
			return resolver(vA, vB, 0, m);
		else
			return resolver(vA, vB, m + 1, fin);
	}

}

void resuelveCaso() {
	int numA;
	// lectura del vector A
	std::cin >> numA;
	std::vector<int> vA(numA);
	for (int i = 0; i < numA; ++i)
		std::cin >> vA[i];
	// lectura del vector B
	std::vector<int> vB(numA - 1);
	for (int j = 0; j < numA - 1; ++j)
		std::cin >> vB[j];
	// resolver
	if (vB.empty()) std::cout << vA[0] << "\n";
	else if (vA[0] != vB[0]) std::cout << vA[0] << "\n";
	else if (vA[numA - 1] != vB[numA - 2]) std::cout << vA[numA - 1] << "\n";
	else std::cout << resolver(vA, vB, 0, numA - 1) << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("06.txt");
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