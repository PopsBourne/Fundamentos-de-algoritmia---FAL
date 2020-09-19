

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int const &lon, int ini, int fin) {
	int dif = 0;
	int resta = 0;
	if (ini == fin + 1) {

	}
	else {
		int m = (ini + fin) / 2;

	
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, lon;

	std::cin >> tam;

	if (tam == -1)
		return false;

	std::cin >> lon;
	std::vector<int> v(tam);
	for (int& n : v) std::cin >> n;

	if (v[0] == v[tam - 1] || tam == 1) std::cout << v[0];
	else std::cout << resolver(v, lon, 0, tam - 1);

	std::cout<< "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej2EN2020.txt");
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
