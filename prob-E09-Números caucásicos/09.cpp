
#include <iostream>
#include <fstream>
#include <vector>


/*
	T(n) = c			n = 0, 1
	T(n) = 2T(n/2) + n	n > 1

	T(n) pertenece a O(nlog(n))
*/

struct data {
	int res;
	bool cau;
};

// Aqui la funcion recursiva que resuelve el problema
data resolver(std::vector<int> const& v, int const& ini, int const& fin) {

	if (ini == fin) return { 0,true };
	else if (ini + 1 == fin) {
		if (v[ini] % 2 == 0 || v[fin] % 2 == 0) return { 1, true };
		else if (v[ini] % 2 == 0 && v[fin] % 2 == 0) return { 2, true };
		else return { 0, true };
	}
	else {
		int m = (ini + fin) / 2;

		data izq = resolver(v, 0, m);
		data der = resolver(v, m + 1, fin);

		if (abs(izq.res - der.res) <= 2 && izq.cau && der.cau) return { izq.res + der.res, (abs(izq.res - der.res) <= 2 && izq.cau && der.cau) };
		else return { -1,false };
	}
}

// Tratar cada caso
bool resuelveCaso() {
	// Lectura de los datos
	int num;
	std::cin >> num;
	if (num == 0) return false;
	std::vector<int> v(num);
	for (int i = 0; i < num; ++i) {
		std::cin >> v[i];
	}

	// resolver
	data sol = resolver(v, 0, num - 1);
	// Escribir los resultados
	if (sol.cau) std::cout << "SI" << '\n';
	else std::cout << "NO\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("09.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

	// Para restablecer entrada.

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}