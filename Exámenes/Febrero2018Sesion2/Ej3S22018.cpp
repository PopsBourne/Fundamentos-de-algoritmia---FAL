
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

template <class T>
using tMatriz = std::vector<std::vector<T>>;

//i carreteras
//k maquinas


bool esValida(std::vector<int> const& a_maquinas, std::vector<int> const& a_carreteras, int const& i, int const& k, std::vector<int>const& m_usadas, std::vector<int>const& c_usadas) {

	if (a_maquinas[k] > a_carreteras[i]) return false;
	if (m_usadas[k] > 1)return false;
	if (c_usadas[i] > 1) return false;

	return true;
}

// función que resuelve el problema
void resolver(std::vector<int> const& a_maquinas, std::vector<int> const& a_carreteras, tMatriz<int> const& calidades, std::vector<int>& m_usadas, std::vector<int>& c_usadas, int& max_calidad, int& calidad_act, int const& m, int k) {

	for (int i = 0; i < a_carreteras.size(); ++i) {
		//marco
		c_usadas[i]++;//asigno una maquina k a una carretera i
		calidad_act += calidades[k][i];//actualizo la calidad actual
		m_usadas[k]++;//incremento el uso de la maquina

		if (esValida(a_maquinas, a_carreteras, i, k, m_usadas, c_usadas)) {
			if (k == m - 1) {//FIN
				if (calidad_act > max_calidad) max_calidad = calidad_act;
			}
			else resolver(a_maquinas, a_carreteras, calidades, m_usadas, c_usadas, max_calidad, calidad_act, m, k + 1);
		}

		//desmarco
		calidad_act -= calidades[k][i];//actualizo la calidad actual
		m_usadas[k]--;//decremento el uso de la maquina
		c_usadas[i]--;//asigno una maquina k a una carretera i
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int m, n, max_calidad, calidad_act;

	std::cin >> m >> n;

	std::vector<int> a_maquinas(m);
	std::vector<int> a_carreteras(n);
	tMatriz<int> calidades;
	calidades.resize(m, std::vector<int>(n));

	for (int& i : a_maquinas) std::cin >> i;
	for (int& j : a_carreteras) std::cin >> j;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> calidades[i][j];
		}
	}

	max_calidad = 0;
	calidad_act = 0;
	std::vector<int> m_usadas(m, 0);
	std::vector<int> c_usadas(n, 0);

	resolver(a_maquinas, a_carreteras, calidades, m_usadas, c_usadas, max_calidad, calidad_act, m, 0);
	// escribir sol

	std::cout << max_calidad << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Ej3S22018.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}