#include "Tienda.hh"
#include <iostream>
#include <vector>
#include <algorithm>

// Constructor
Tienda::Tienda() {
    bintree_salas = BinTree<std::string>();
}

// Función auxiliar para encontrar el subárbol que contiene el item y registrar el camino
BinTree<std::string> Tienda::encontrar_subarbol(const BinTree<std::string>& arbol, const std::string& item, std::vector<std::string>& camino) {
    if (arbol.empty()) return BinTree<std::string>();

    if (arbol.value() == item) {
        return BinTree<std::string>(arbol.value());
    }

    // Buscar en el subárbol izquierdo
    camino.push_back("left");
    BinTree<std::string> subarbol_izq = encontrar_subarbol(arbol.left(), item, camino);
    if (!subarbol_izq.empty()) {
        return BinTree<std::string>(arbol.value(), subarbol_izq, BinTree<std::string>());
    }
    camino.pop_back();

    // Buscar en el subárbol derecho
    camino.push_back("right");
    BinTree<std::string> subarbol_der = encontrar_subarbol(arbol.right(), item, camino);
    if (!subarbol_der.empty()) {
        return BinTree<std::string>(arbol.value(), BinTree<std::string>(), subarbol_der);
    }
    camino.pop_back();

    return BinTree<std::string>();
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
        BinTree<std::string> subarbol = encontrar_subarbol(bintree_salas, item, camino);

        // Mostrar el subárbol
        std::cout << "Subarbol del cliente " << id << ":\n";
        subarbol.setOutputFormat(BinTree<std::string>::VISUALFORMAT);
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

void Tienda::leer_cajas() {
    int num;
    cin >> num;
    cajas.resize(num);
    cout << "Hay " << num << " cajas\n";
}

BinTree<std::string> Tienda::leer_salas_private() {
    BinTree<string> t;
    t.setInputOutputFormat(BT::VISUALFORMAT);
    cin >> t;
    return t;
}
