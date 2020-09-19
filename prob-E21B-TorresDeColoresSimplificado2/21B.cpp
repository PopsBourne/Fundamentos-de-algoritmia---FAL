
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


enum color { AZUL, ROJO, VERDE };

struct tCuenta {
	int nAzules;
	int nRojos;
	int nVerdes;
};

bool esValida(std::vector<int>& sol, int k, tCuenta c) {

	if (sol[k - 1] == VERDE && sol[k] == sol[k - 1]) return false;
	return true;
}

int marcar(int i, tCuenta& c) {
	switch (i) {
	case AZUL: c.nAzules++; return AZUL;
		break;
	case ROJO: c.nRojos++; return ROJO;
		break;
	case VERDE: c.nVerdes++; return VERDE;
		break;
	}
}

void desmarcar(int i, tCuenta& c) {
	switch (i) {
	case AZUL: c.nAzules--;
		break;
	case ROJO: c.nRojos--;
		break;
	case VERDE: c.nVerdes--;
		break;
	}
}

void tratarSolucion(std::vector<int> const& sol) {

	for (int i = 0; i < sol.size(); i++) {
		switch (sol[i]) {
		case ROJO: std::cout << "rojo "; break;
		case AZUL: std::cout << "azul "; break;
		case VERDE: std::cout << "verde "; break;
		}
	}
	std::cout << "\n";
}


// función que resuelve el problema
void nTorres(std::vector<int>& colores, int const& altura, std::vector<int>& sol, int k, tCuenta c, bool& ok) {

	for (int i = 0; i < colores.size(); ++i) {
			//marco y guardo en la solución
			sol[k] = marcar(i, c);
			colores[i]--;//resto el color utilizado del vector inicial
			//compruebo validez
			if (esValida(sol, k, c)) {
				//compruebo si la torre tiene la altura máxima
				if (k == altura - 1) {
					tratarSolucion(sol);
					ok = true;
				}
				else nTorres(colores, altura, sol, k + 1, c, ok);
			}
			//si no es válida desmarco, y sumo el color en el vector inicial
			desmarcar(i, c);
			colores[i]++;

		}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int altura;
	std::cin >> altura;

	if (altura == 0)
		return false;

	std::vector<int> colores(3);
	std::vector<int> sol(altura);

	tCuenta c;
	c.nRojos = 1;
	c.nAzules = 0;
	c.nVerdes = 0;

	sol[0] = ROJO;
	bool ok = false;

	if(altura==1) std::cout << "rojo" << "\n";
	else {
		nTorres(colores, altura, sol, 1, c, ok);
		// escribir sol
		if (!ok) std::cout << "SIN SOLUCION" << "\n";
	}
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("21B.txt");
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