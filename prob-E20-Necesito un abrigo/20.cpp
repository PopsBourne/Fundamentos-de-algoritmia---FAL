
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//abrigo i
//dia k

bool esValida(std::vector<int> const& precipitaciones, std::vector<int> const& soporte, std::vector<int>const& usados, std::vector<int> const& sol, int const& k, int const& i) {
	if (k > 0 && sol[k] == sol[k - 1]) return false;//si el abrigo se repite dos días seguidos
	if (soporte[i] < precipitaciones[k]) return false;//si el abrigo no soporta el grado de precipitación
	if (usados[i] > 2 + (k / 3)) return false;

	return true;
}

// función que resuelve el problema
void resolver(std::vector<int> const& precipitaciones, std::vector<int> const& soporte,
	std::vector<int>& sol, std::vector<int>& usados, int k, int& cont) {

	//recorro los abrigos
	for (int i = 0; i < soporte.size(); ++i) {

		//marco
		sol[k] = i;//meto un abrigo en el día k
		usados[i]++;//incremento el contador de ese abrigo

		//compruebo si es válida
		if (esValida(precipitaciones, soporte, usados, sol, k, i)) {
			if (k == precipitaciones.size() - 1) {//FINAL: ya se han recorrido todos los días
				if (sol[0] != sol[k])cont++;
			}
			else resolver(precipitaciones, soporte, sol, usados, k + 1, cont);
		}
		//si no lo es desmarco
		sol[k] = 0;
		usados[i]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int dias, abrigos, cont;
	std::cin >> dias >> abrigos;
	if (dias == 0 && abrigos == 0)
		return false;

	std::vector<int> precipitaciones(dias);
	for (int& n : precipitaciones) std::cin >> n;

	std::vector<int> soporte(abrigos);
	for (int& m : soporte) std::cin >> m;

	std::vector<int> sol(dias, 0);
	std::vector<int> usados(abrigos, 0);
	cont = 0;

	resolver(precipitaciones, soporte, sol, usados, 0, cont);

	// escribir sol
	if (cont == 0) std::cout << "Lo puedes comprar\n";
	else std::cout << cont << '\n';
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("20.txt");
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
