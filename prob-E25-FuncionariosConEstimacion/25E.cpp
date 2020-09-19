
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

template <class T>

using tMatriz = std::vector<std::vector<T>>;

bool esValida(std::vector<int> const& marca_f, std::vector<int> const& marca_t, int const& i, int const& k) {
	if (marca_f[i] > 1)return false;
	if (marca_t[k] > 1)return false;
	return true;
}


// función que resuelve el problema
void resolver(int const& n, tMatriz<int> const& tiempos, int& solMejor, int& tiempo_act, std::vector<int> const& acum, std::vector<int>& marca_f, std::vector<int>& marca_t, int k) {

	for (int i = 0; i < n; ++i) {
		marca_f[i]++;
		marca_t[k]++;
		tiempo_act += tiempos[k][i];

		if (esValida(marca_f, marca_t, i, k)) {
			if (k == n - 1) {
				if (tiempo_act < solMejor)solMejor = tiempo_act;
			}
			else {
				if (tiempo_act + acum[k + 1] < solMejor)
					resolver(n, tiempos, solMejor, tiempo_act, acum, marca_f, marca_t, k + 1);
			}
		}
		marca_f[i]--;
		marca_t[k]--;
		tiempo_act -= tiempos[k][i];

	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, solMejor, tiempo_act;
	std::cin >> n;
	if (n == 0)
		return false;

	tMatriz<int> tiempos;
	tiempos.resize(n, std::vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> tiempos[i][j];
		}
	}

	solMejor = 0;
	for (int i = 0; i < n; ++i) {
		solMejor += tiempos[i][i];
	}

	std::vector<int> acum(n);
	for (int i = 0; i < n; ++i) {
		int auxMin = solMejor;
		for (int j = 0; j < n; ++j)
			if (auxMin > tiempos[i][j]) auxMin = tiempos[i][j];
		acum[i] = auxMin;
	}

	for (int i = n - 1; i > 0; --i) {
		acum[i - 1] += acum[i];
	}

	std::vector<int> marca_f(n, 0);
	std::vector<int> marca_t(n, 0);
	tiempo_act = 0;

	resolver(n, tiempos, solMejor, tiempo_act, acum, marca_f, marca_t, 0);

	// escribir sol
	std::cout << solMejor << "\n";

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
