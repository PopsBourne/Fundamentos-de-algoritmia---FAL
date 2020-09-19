
/*
    T(n) = c            n=0,1
    T(n) = T(n/2) + c   n > 1

    T(n) pertenece a O(log(n))
*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int const& ini, int const& fin) {

    if (ini == fin) return v[ini];
    else if (ini + 1 == fin) {
        if (v[ini] > v[fin]) return v[fin];
        else return v[ini];
    }
    else {
        int m = (ini + fin) / 2;

        if (v[m] > v[ini] || v[m] < v[m+1])
            return resolver(v, ini, m);
        else
            return resolver(v, m + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    std::cin >> tam;
    if (!std::cin)
        return false;

    std::vector<int> v(tam);
    for (int& n : v) std::cin >> n;

    int sol = resolver(v,0,tam-1);

    // escribir sol
    std::cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("07.txt");
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