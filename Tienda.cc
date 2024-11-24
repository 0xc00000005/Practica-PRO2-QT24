#include "Tienda.hh"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef BinTree<string> BT;
// Constructor
Tienda::Tienda() {
    bintree_salas = BT();
}

// Función auxiliar para encontrar el subárbol que contiene el item y registrar el camino
BT Tienda::encontrar_subarbol(const BT& arbol, const std::string& item, std::vector<std::string>& camino) {
    if (arbol.empty()) return BT();

    if (arbol.value() == item) {
        return BT(arbol.value());
    }

    // Buscar en el subárbol izquierdo
    camino.push_back("left");
    BT subarbol_izq = encontrar_subarbol(arbol.left(), item, camino);
    if (!subarbol_izq.empty()) {
        return BT(arbol.value(), subarbol_izq, BT());
    }
    camino.pop_back();

    // Buscar en el subárbol derecho
    camino.push_back("right");
    BT subarbol_der = encontrar_subarbol(arbol.right(), item, camino);
    if (!subarbol_der.empty()) {
        return BT(arbol.value(), BT(), subarbol_der);
    }
    camino.pop_back();

    return BT();
}

void Tienda::nuevo_cliente() {
    Cliente nuevoCliente;
    int id = nuevoCliente.obtenerId();

    // Leer los items que el cliente desea
    std::vector<std::string> items;
    std::string item;
    while (std::cin >> item && item != "#") {
        items.push_back(item);
    }
    int num_items = items.size();

    // Por simplicidad, manejaremos solo el primer item
    if (num_items > 0) {
        std::string item = items[0];
        std::vector<std::string> camino;
        BT subarbol = encontrar_subarbol(bintree_salas, item, camino);

        // Mostrar el subárbol
        std::cout << "Subarbol del cliente " << id << ":\n";
        subarbol.setOutputFormat(BT::VISUALFORMAT);
        std::cout << subarbol << std::endl;

        // Mostrar el recorrido
        std::cout << "Recorrido por la tienda del cliente " << id << ":\n";
        std::cout << bintree_salas.value() << std::endl;
        for (const std::string& dir : camino) {
            std::cout << dir << std::endl;
        }
        std::cout << "back" << std::endl;
    }

    clientes[id] = nuevoCliente;
}

void Tienda::leer_salas() {
    bintree_salas = leer_salas_private();
}

/*void Tienda::leer_cajas() {
    int num;
    cin >> num;
    cajas.resize(num);
    cout << "Hay " << num << " cajas\n";
}*/

BT Tienda::leer_salas_private() {
    BinTree<string> t;
    t.setInputOutputFormat(BT::VISUALFORMAT);
    cin >> t;
    return t;
}
