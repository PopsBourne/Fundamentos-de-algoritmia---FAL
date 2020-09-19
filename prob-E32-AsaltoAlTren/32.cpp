
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	int pos;
	int gan;
};

// función que resuelve el problema
sol resolver(std::vector<int> const& v, int const& asalto, int& botin) {
	int j = asalto;
	int pos = 0;
	int max = botin;
	for (int i = 0; i < v.size(); ++i) {//O(n)
		if (j >= v.size())break;
		if (botin - v[i] + v[j] >= max) {
			max = botin - v[i] + v[j];
			pos = i + 1;
		}
		botin = botin - v[i] + v[j];
		++j;
	}
	return { pos, max };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam, asalto, botin;
	std::cin >> tam >> asalto;

	std::vector<int> v(tam);
	for (int& n : v) std::cin >> n;
	botin = 0;

	for (int i = 0; i < asalto; ++i) {
		botin += v[i];
	}
	sol s = resolver(v, asalto, botin);
	// escribir sol
	std::cout << s.pos << " " << s.gan << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("32.txt");
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