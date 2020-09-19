#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



// función que resuelve el problema
bool resolver(std::vector<int> const& v, int const& p) {
	int max = 0;
	for (int j = 0; j < p; ++j)
		if (v[j] > max)max = v[j];

	for (int i = p + 1; i < v.size(); ++i)
		if (v[i] <= max)return false;
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam, p;
	std::cin >> tam >> p;

	std::vector<int> v(tam);
	for (int& n : v) std::cin >> n;

	bool sol = resolver(v, p);
	// escribir sol
	if (sol) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("31.txt");
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