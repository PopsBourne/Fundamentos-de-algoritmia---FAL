
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/*
    T(n) = {
        c				(caso base)
        2T(n/2) + 2c	(en cualquier otro caso)
    }
*/


// función que resuelve el problema
bool resolver(int const& k, std::vector<int> const& v, int const &ini, int const &fin) {

    if (ini == fin) return true;
    else if (abs(v[ini] - v[fin]) < k) return false;
    else {
        int m = (ini + fin) / 2;

        bool izq = resolver(k, v, ini, m);
        bool der = resolver(k, v, m + 1, fin);

        if (izq && der) return true;
        else return false;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k, valores, n, ini, fin;

    std::cin >> n >> k;

    if (!std::cin)
        return false;

    std::vector<int> v(n);
    for (int& n : v)
        std::cin >> n;

    ini = 0;
    fin = n-1;
    bool sol = resolver(k, v, ini, fin);

    // escribir sol
    if (sol) std::cout << "SI" << "\n";
    else std::cout << "NO" << "\n";


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("01.txt");
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