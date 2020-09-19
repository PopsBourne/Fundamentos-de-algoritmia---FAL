
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Coste O(n) siendo n el número de elementos del vector

/*
    requires 0 <= n <= 1000
    ensures forall w:: 0 <= w < v.length -->v[w] >= v[w+1]
*/
int resolver(std::vector<int> const & v) {
    int max = 0;
    int cont = 1;

    for (int i = 1; i < v.size(); ++i) {
        //invariant v.length == 0 || 0 <= i < v.length
        //invariant forall k:: 0 <= k <
        if (v[i] <= v[i - 1]) {
            cont++;
        }
        else {
            if (cont > max) max = cont;
            cont = 1;
        }
    }
    if (cont > max) max = cont;
    return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int& m : v) std::cin >> m;

    std::cout<< resolver(v) <<"\n" ;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ej1S22018.txt");
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