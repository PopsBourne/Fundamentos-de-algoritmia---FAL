/*
	T(n) = c		n<10
	T(n) + c		n>=10

	T(n) pertenece a O(log(n))
*/

#include <iostream>
#include <iomanip>
#include <fstream>

struct data {
	int n;
	int tam;
};

// función que resuelve el problema
data resolver(int const& num) {

	if (num < 10)
		return{ num,10 };
	else {
		data d = resolver(num / 10);

		return { d.n + (num % 10) * d.tam, d.tam * 10 };
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	if (num == 0)
		return false;

	data sol = resolver(num);

	// escribir sol
	std::cout << sol.n << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("14.txt");
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
