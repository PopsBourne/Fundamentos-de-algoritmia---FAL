
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int>& v, int const& tam, int& par) {
	for (int i = 0; i < tam; ++i) {
		if (v[i] % 2 == 0) {
			v[par] = v[i];
			par++;
		}
	}
	v.resize(par);
	return v;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam, par;
	std::cin >> tam;

	std::vector<int> v(tam);
	for (int& n : v) std::cin >> n;

	par = 0;
	std::vector<int> sol = resolver(v, tam, par);
	// escribir sol
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("30.txt");
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