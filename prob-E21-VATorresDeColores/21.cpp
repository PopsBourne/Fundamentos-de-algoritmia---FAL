
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//colores i
//altura k

enum color { AZUL, ROJO, VERDE };

bool esValida(std::vector<int>const& colores, std::vector<int>const& sol, std::vector<int> const& contador, int const& k, int const& i) {

	if (k > 0 && sol[k - 1] == VERDE && sol[k] == VERDE) return false;
	if (contador[AZUL] < contador[VERDE]) return false;

	return true;
}

void tratarSolucion(std::vector<int>const& sol) {

	for (int i = 0; i < sol.size(); ++i) {
		switch (sol[i])
		{
		case ROJO:
			std::cout << "rojo";
			break;
		case VERDE:
			std::cout << "verde";
			break;
		case AZUL:
			std::cout << "azul";
			break;
		}
		std::cout << " ";
	}
	std::cout << "\n";
}

// función que resuelve el problema
void resolver(std::vector<int>& colores, std::vector<int>& sol, std::vector<int>& contador, int k, bool& ok) {

	//recorro los colores
	for (int i = 0; i < colores.size(); ++i) {
		if (colores[i] > 0) {
			//marco
			sol[k] = i;//meto el color i en la altura k
			colores[i]--;//decremento el color usado
			contador[i]++;//incremento el uso de ese color

			if (esValida(colores, sol, contador, k, i)) {
				if (k == sol.size() - 1) {//FINAL
					if (contador[ROJO] > contador[AZUL] + contador[VERDE]) {
						tratarSolucion(sol);
						ok = true;
					}
				}
				else resolver(colores, sol, contador, k + 1, ok);
			}

			//desmarco
			sol[k] = 0;
			colores[i]++;
			contador[i]--;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int alt, az, rj, vd;
	std::cin >> alt;
	if (alt == 0)
		return false;

	std::vector<int> colores(3);
	for (int& n : colores) std::cin >> n;

	std::vector<int> sol(alt, 0);
	std::vector<int> contador(3, 0);
	bool ok = false;
	sol[0] = ROJO;
	colores[ROJO]--;
	contador[ROJO]++;
	resolver(colores, sol, contador, 1, ok);

	// escribir sol
	if (!ok) std::cout << "SIN SOLUCION" << "\n";
	std::cout << "\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("21.txt");
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
