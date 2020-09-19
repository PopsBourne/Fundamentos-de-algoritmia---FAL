
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

template <class T>
using tMatriz = std::vector<std::vector<T>>;

struct sol {
	int coste;
	std::vector<int> colores;
};

bool esValida(int const& cm_color, int const& k, int const& i, std::vector<int> const& escalones) {

	if (cm_color < 0) return false;

	if (k > 0) {
		if (escalones[k] == escalones[k - 1]) return false;
	}
	return true;
}

// función que resuelve el problema
void resolver(int const& nEsc, int const& nCol, std::vector<int>& anchos, tMatriz<int>& info_color, std::vector<int>& escalones, int& coste_act, int const& k, sol& s) {

	for (int i = 0; i < nCol; ++i) {
		//marcar
		coste_act += info_color[i][1] * anchos[k];//precio
		info_color[i][0] -= anchos[k];//decremento los cm de ese color por n escalones
		escalones[k] = i;//indico el color k usado en el escalon i

		if (esValida(info_color[i][0], k, i, escalones)) {
			if (k == nEsc - 1) {//FIN
				if (coste_act < s.coste || s.coste == 0) {
					s.coste = coste_act;
					for (int j = 0; j < nEsc; ++j)
						s.colores[j] = escalones[j];
				}
			}
			else {
				if(coste_act < coste_act + info_color[0][1] * anchos[k+1]){
					resolver(nEsc, nCol, anchos, info_color, escalones, coste_act, k + 1, s);

			}
		}
		//desmarcar
		coste_act -= info_color[i][1] * anchos[k];
		info_color[i][0] += anchos[k];
		escalones[k] = 0;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nEsc, nCol, coste_act;

	std::cin >> nEsc;

	if (nEsc == -1)
		return false;

	std::cin >> nCol;

	std::vector<int> anchos(nEsc);//cm de cada escalon
	for (int& n : anchos) std::cin >> n;

	tMatriz<int> info_color;//cm de color y su precio
	info_color.resize(nCol, std::vector<int>(2));

	for (int i = 0; i < nCol; ++i) {
		for (int j = 0; j < 2; ++j) {
			std::cin >> info_color[i][j];
		}
	}

	// std::vector<int> escalones(tam);//vector de escalones con sus medidas como tamaño
	std::vector<int> escalones(nEsc, -1);//para guardar el color asignado a cada escalon
	sol s;
	s.colores.resize(nEsc);
	s.coste = 0;
	coste_act = 0;

	resolver(nEsc, nCol, anchos, info_color, escalones, coste_act, 0, s);

	// escribir sol
	if (s.coste == 0) std::cout << "NO";
	else {
		std::cout << s.coste << "\n";
		for (int i = 0; i < nEsc; ++i)
			std::cout << s.colores[i] << " ";
	}
	std::cout << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej3EN2020.txt");
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
