
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct izq {
	int n;
	int lon;
	int rep;
};

struct der {
	int n;
	int lon;
	bool ok;
};

struct sol {
	int lon;
	bool ok;
};


/*
	requires forall i::0<=i<v.size() && v[i-1]<=v[i]<=v[i+1] 
	ensures  v.lenght > 0
*/


izq ascendente(std::vector<int> const& v, bool& ok) {
	int i = 1;
	int cont = 1;
	int lon = 1;
	int max = 1;
	int rep = 0;

	
	//invariant forall i::0<=i<v.size()
	
	while (ok && i < v.size()) {

		if (v[i] >= v[i - 1]) {
			cont++;
			if (v[i] == v[i - 1]) {
				lon++;
				rep++;
			}
			else {
				if (lon > max)max = lon;
				lon = 1;
				rep = 0;
			}
		}
		else {
			ok = false;
			if (lon > max)max = lon;
		}
		i++;
	}
	if (rep > 0)rep++;
	if (lon > max)max = lon;
	return { cont, max, rep };
}

der descendente(std::vector<int> const& v, bool& ok, int const& n, int& cont) {
	int i = n;
	int lon = 1;
	int max = 1;
	while (i < v.size()) {
		if (v[i] <= v[i - 1]) {
			cont++;
			if (v[i] == v[i - 1]) lon++;
			else {
				if (lon > max)max = lon;
				lon = 1;
			}
		}
		else {
			ok = false;
			if (lon > max)max = lon;
		}
		i++;
	}
	if (lon > max)max = lon;
	return { cont, max, ok };
}


sol esEscalera(izq& iz, der& de) {
	if (de.ok) {
		if (iz.lon > de.lon) return{ iz.lon,true };
		else return { de.lon, true };
	}
	else {
		return{ false };
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	izq iz;
	der de;
	sol s;
	bool ok;


	std::cin >> tam;
	if (tam == -1)
		return false;

	std::vector<int> v(tam);
	for (int& n : v) std::cin >> n;

	ok = true;
	iz = ascendente(v, ok);
	ok = true;
	de.n = 0;
	if (iz.lon != v.size())
		de = descendente(v, ok, iz.n, de.n);

	s = esEscalera(iz, de);

	if (s.ok)std::cout << "SI " << s.lon << "\n";
	else std::cout << "NO " << iz.n << " " << de.n << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej1EN2020.txt");
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
