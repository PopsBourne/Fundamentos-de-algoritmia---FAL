
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct data {

	int ini;
	int lon;
};

bool secuenciaMax(int& lon, int const& cont) {

	if (cont > lon) {
		lon = cont;
		return true;
	}
	return false;
}

/*
requires 0<=ini<=fin && 0<=|v|
ensures {forall i::0<=i<=v.size() -> v[i] - 1 == v[i-1]}
*/
data consecutivos(std::vector<int>& v, int& ini, int& fin) {
	int i = 0;
	int aux = 0;
	int max = 0;

	while (i < v.size()) {
		//invariant 0<=i<=v.lenght()
		//
		if (v[i] - 1 == aux) {
			fin++;
			aux = v[i];//para comparar
		}
		else {

			if (secuenciaMax(max, fin)) {
				if (fin == i)ini = 0;
				else ini = i - fin;//se rompe la racha
			}
			fin = 1;
			aux = v[i];
		}
		++i;
	}
	if (secuenciaMax(max, fin)) {
		if (fin == i)ini = 0;
		else ini = i - fin;//se rompe la racha
	}

	return { ini,max };
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, ini, fin;
	std::cin >> tam;

	if (tam == 0)
		return false;

	std::vector<int> v(tam);
	for (int& n : v) std::cin >> n;

	ini = 0;
	fin = 0;

	data sol = consecutivos(v, ini, fin);

	// escribir sol
	std::cout << sol.ini << " " << sol.lon << "\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("39.txt");
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
