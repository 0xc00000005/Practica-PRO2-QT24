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

// Función auxiliar para encontrar el subarbol y registrar el camino con nombres y direcciones
bool Tienda::encontrar_subarbol(const BT& arbol, const std::string& item, std::vector<std::string>& camino) {
    if (arbol.empty()) return false;

    // Añadir el nombre de la sala actual
    camino.push_back(arbol.value());

    if (arbol.value() == item) {
        return true;
    }

    // Buscar en el subarbol izquierdo
    camino.push_back("left");
    if (encontrar_subarbol(arbol.left(), item, camino)) {
        return true;
    }
    camino.pop_back(); // Quitar "left"

    // Buscar en el subarbol derecho
    camino.push_back("right");
    if (encontrar_subarbol(arbol.right(), item, camino)) {
        return true;
    }
    camino.pop_back(); // Quitar "right"

    // Si no se encuentra, retroceder
    camino.pop_back(); // Quitar el nombre de la sala actual
    return false;
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
    nuevoCliente.guardar_items(items);
    // Procesar cada item
    for (const std::string& item : items) {
        std::vector<std::string> camino;
        if (encontrar_subarbol(bintree_salas, item, camino)) {
            // Mostrar el subarbol
            std::cout << "Subarbol del cliente " << id << ":\n";
            BT subarbol = construir_subarbol(camino);
            subarbol.setOutputFormat(BT::VISUALFORMAT);
            std::cout << subarbol << std::endl;

            // Mostrar el recorrido
            std::cout << "Recorrido por la tienda del cliente " << id << ":\n";
            for (const std::string& paso : camino) {
                std::cout << paso << std::endl;
            }
            std::cout << "back" << std::endl;
        } else {
            std::cout << "Item " << item << " no encontrado en la tienda.\n";
        }
    }

    clientes[id] = nuevoCliente;
}

// Función para construir el subarbol a partir del camino
BinTree<string> Tienda::construir_subarbol(const vector<std::string>& camino) {
    if (camino.empty()) return BT();

    BinTree<string> arbol(camino.back());
    for (int i = camino.size() - 2; i >= 0; --i) {
        std::string dir = camino[i];
        --i;
        if (dir == "left") {
            arbol = BinTree<string>(camino[i], arbol, BT());
        } else if (dir == "right") {
            arbol = BinTree<string>(camino[i], BT(), arbol);
        } else {
            // Caso no esperado
            arbol = BinTree<string>(camino[i], arbol, BT());
        }
    }
    return arbol;
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
