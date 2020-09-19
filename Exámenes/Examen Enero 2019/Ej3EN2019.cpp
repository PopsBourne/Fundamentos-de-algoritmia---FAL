#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

template <class T>
using tMatriz = std::vector<std::vector<T>>;


//niños i
//juguetes k

bool esValida(std::vector<int> const& j_edades, std::vector<int> const& n_edades, std::vector<int>const& min_j, int const& i, int const& k, int const& max_j, std::vector<int>const& juguetes) {
	if (j_edades[k] > n_edades[i]) return false;
	if (min_j[i] > max_j) return false;
	if (juguetes[k] > 1) return false;
	return true;
}


// función que resuelve el problema
void resolver(int const& n, int const& j, int const& min, std::vector<int> const& j_edades, std::vector<int> const& n_edades, tMatriz<int> const& stf, std::vector<int>& juguetes, std::vector<int>& min_j, int& stf_max, int stf_act, int const& max_j, int k) {

	for (int i = 0; i < n; ++i) {
		//marco
		min_j[i]++;
		juguetes[k]++;

		if (esValida(j_edades, n_edades, min_j, i, k, max_j, juguetes)) {
			stf_act += stf[i][k];
			if (k == j - 1) {
				if (stf_max < stf_act)
					stf_max = stf_act;

			}
			else if (stf_act + stf[i][k + 1] > stf_max)
				resolver(n, j, min, j_edades, n_edades, stf, juguetes, min_j, stf_max, stf_act, max_j, k + 1);

			stf_act -= stf[i][k];
		}
		//desmarco
		min_j[i]--;
		juguetes[k]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int j, n, min, stf_max, stf_act, max_j;

	std::cin >> j >> n >> min;

	if (j == 0 && n == 0 && min == 0)
		return false;

	std::vector<int> j_edades(j);
	std::vector<int> juguetes(j);
	std::vector<int> n_edades(n);
	std::vector<int> min_j(n, 0);

	for (int& m : j_edades) std::cin >> m;
	for (int& l : n_edades) std::cin >> l;

	tMatriz<int> stf;
	stf.resize(n, std::vector<int>(j));

	for (int i = 0; i < n; ++i) {
		for (int p = 0; p < j; ++p) {
			std::cin >> stf[i][p];
		}
	}

	stf_max = 0;
	//calculo la satisfacción mejor
	for (int i = 0; i < n; ++i) {
		stf_max += stf[i][i];
	}


	stf_act = 0;
	max_j = min + ((j / min) - n) * min;//es el max de juguetes que puede recibir un solo niño sin que falte al resto su mínimo
	resolver(n, j, min, j_edades, n_edades, stf, juguetes, min_j, stf_max, stf_act, max_j, 0);

	std::cout << stf_max << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej3EN2019.txt");
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
