
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

template <class T>
using tMatriz = std::vector<std::vector<T>>;

struct data {
	int punt;
	int pres;

	std::vector<int> asignacion;
	std::vector<int> reparto;
};

//i papeles
//k actores

bool esValida(int const& pres_act, int const& pres_max, int const& punt_min, int const& punt_actor, int const& i, int const& k, std::vector<int>const& sol, std::vector<int> const& papeles) {

	if (papeles[k] < 0) return false;
	if (sol[i] > 1) return false;
	if (punt_actor < punt_min) return false;
	if (pres_act > pres_max)return false;

	return true;
}

// función que resuelve el problema
void resolver(int const& nPapeles, int const& nActores, int const& pres_max, int const& punt_min, int& pres_act, int& punt_act, std::vector<int> const& cobro,
	tMatriz<int> const& director, std::vector<int>& sol, std::vector<int>& papeles, int k, data& d) {

	for (int i = 0; i < nActores; ++i) {
		sol[i]++;
		papeles[k]--;
		pres_act += cobro[i];
		punt_act += director[k][i];
		d.reparto[k] = i;

		if (esValida(pres_act, pres_max, punt_min, director[k][i], i, k, sol, papeles)) {
			if (k == nPapeles - 1) {//FIN

				if (punt_act > d.punt) {
					d.pres = pres_act;
					d.punt = punt_act;

					for (int i = 0; i < nPapeles; ++i) {
						d.asignacion[i] = d.reparto[i];
					}
				}
			}
			else {
				if (director[k + 1][i] > d.punt)
					resolver(nPapeles, nActores, pres_max, punt_min, pres_act, punt_act, cobro, director, sol, papeles, k + 1, d);

			}
		}

		sol[i]--;
		papeles[k]++;
		pres_act -= cobro[i];
		punt_act -= director[k][i];
		d.reparto[k] = -1;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nPapeles, nActores, pre, punt, pres_act, punt_act;
	std::cin >> nPapeles >> nActores >> pre >> punt;

	if (nPapeles == 0 && nActores == 0 && pre == 0 && punt == 0)
		return false;

	std::vector<int> cobro(nActores);
	for (int& n : cobro) std::cin >> n;

	tMatriz<int> director;
	director.resize(nPapeles, std::vector<int>(nActores));
	for (int i = 0; i < nPapeles; ++i) {
		for (int j = 0; j < nActores; ++j) {
			std::cin >> director[i][j];
		}
	}


	std::vector<int> sol(nActores, 0);
	std::vector<int> papeles(nPapeles, 1);
	pres_act = 0;
	punt_act = 0;
	data d;

	d.asignacion.resize(nPapeles, -1);
	d.reparto.resize(nPapeles, -1);

	resolver(nPapeles, nActores, pre, punt, pres_act, punt_act, cobro, director, sol, papeles, 0, d);

	// escribir sol
	std::cout << d.punt << " " << d.pres << "\n";
	for (int i = 0; i < nPapeles; ++i) {
		std::cout << i << " " << d.asignacion[i] << "\n";
	}
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej3S12018.txt");
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
