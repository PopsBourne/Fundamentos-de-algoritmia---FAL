#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct data {
	int seg;
	std::vector<int> ini;
};


/*
	requires 2 <= x < n
	requires forall w:: -1000 <= w <= 1000
	ensures b == forall::r 0 <= r < w.length --> |w[r] - w[r-1]| <= 1
*/
void resolver(data& s, int const& x, int const& n, std::vector<int> const& v) {
	int cont = 1;
	
	//invariant 0 <= i < w.length
	//invariant forall cont:: 0<= cont < i
	//forall x:: 0 <= x < i --> cont >= x
	for (int i = 1; i < n; ++i) {
		if (abs(v[i] - v[i - 1]) <= 1) {
			cont++;
		}
		else {
			if (cont >= x) {
				s.seg++;
				cont = 1;
			}
			s.ini[s.seg] = i;
		}
	}
	if (cont >= x) s.seg++;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, x;

	std::cin >> n >> x;
	if (n == 0 && x == 0)
		return false;

	data sol;
	sol.seg = 0;
	sol.ini.resize(n, 0);
	std::vector<int> v(n);

	for (int& m : v) std::cin >> m;

	resolver(sol, x, n,v);
	//recorrer hasta seg-1
	std::cout << sol.seg << " ";
	for (int i = 0; i < sol.seg; ++i) {
		std::cout << sol.ini[i] << " ";
	}
	std::cout << "\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej1EN2019.txt");
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
