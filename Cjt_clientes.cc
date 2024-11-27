#include "Cjt_clientes.hh"
#include "Cliente.hh"
#include "BinTree.hh"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

typedef BinTree<string> BT;

// Inicialización del contador estático
int Cjt_clientes::contador = 1;

// Constructor
Cjt_clientes::Cjt_clientes() {
    clientes = vector<Cliente>();
}

// Incrementar contador
void Cjt_clientes::incrementar_contador() {
    ++contador;
}

// Función auxiliar para encontrar el subárbol y registrar el camino con nombres y direcciones
bool Cjt_clientes::encontrar_subarbol(const BT& arbol, const std::string& item, std::vector<std::string>& camino) {
    if (arbol.empty()) return false;

    // Añadir el nombre de la sala actual
    camino.push_back(arbol.value());

    if (arbol.value() == item) {
        return true;
    }

    // Buscar en el subárbol izquierdo
    camino.push_back("left");
    if (encontrar_subarbol(arbol.left(), item, camino)) {
        return true;
    }
    camino.pop_back(); // Quitar "left"

    // Buscar en el subárbol derecho
    camino.push_back("right");
    if (encontrar_subarbol(arbol.right(), item, camino)) {
        return true;
    }
    camino.pop_back(); // Quitar "right"

    // Si no se encuentra, retroceder
    camino.pop_back(); // Quitar el nombre de la sala actual
    return false;
}

// Función para construir el subárbol a partir del camino
BinTree<string> Cjt_clientes::construir_subarbol(const vector<std::string>& camino) {
    if (camino.empty()) return BT();

    BinTree<string> arbol(camino.back());
    for (int i = camino.size() - 2; i >= 0; --i) {
        std::string dir = camino[i];
        --i;
        if (i < 0) break; // Evitar desbordamiento
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

// Añadir un nuevo cliente y mostrar el subárbol e instrucciones
void Cjt_clientes::nuevo_cliente(const BinTree<std::string>& bintree_salas) {
    int id = contador;
    Cliente nuevoCliente(id);
    std::cout << "ID: " << id << std::endl;

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
            // Mostrar el subárbol
            std::cout << "Subárbol del cliente " << id << ":\n";
            BT subarbol = construir_subarbol(camino);
            subarbol.setOutputFormat(BT::VISUALFORMAT);
            std::cout << subarbol << std::endl;

            // Mostrar el recorrido
            std::cout << "Recorrido por la tienda del cliente " << id << ":\n";
            for (const std::string& paso : camino) {
                nuevoCliente.pb_sala(paso);
                std::cout << paso << std::endl;
            }
            std::cout << "back" << std::endl;
        } else {
            std::cout << "Item " << item << " no encontrado en la tienda.\n";
        }
    }

    // Agregar el cliente al vector
    clientes.push_back(nuevoCliente);
    
    // Incrementar el contador
    incrementar_contador();
}

// Recuperar un cliente por su ID (devuelve una referencia constante)
const Cliente& obtener_cliente(int id) const {
    if (id - 1 >= 0 && id - 1 < clientes.size()) {
        return clientes[id - 1];
    } else {
        throw std::out_of_range("Cliente no encontrado");
    }
}