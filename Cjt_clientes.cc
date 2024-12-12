#include "Cjt_clientes.hh"
#include "Cliente.hh"
#include "BinTree.hh"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>

using namespace std;

typedef BinTree<string> BT;

// Static counter initialization
int Cjt_clientes::contador = 1;

// Constructor
Cjt_clientes::Cjt_clientes() {
    clientes = vector<Cliente>();
}

// Increment the static counter
void Cjt_clientes::incrementar_contador() {
    ++contador;
}

// Build the minimal subtree containing the desired items and update the client's visit list
BinTree<string> Cjt_clientes::construir_subarbol_minimo(Cliente& cliente, const BinTree<string>& arbol) {
    if (arbol.empty()) {
        return BinTree<string>();
    }

    // Recursively build left and right subtrees
    BinTree<string> left = construir_subarbol_minimo(cliente, arbol.left());
    BinTree<string> right = construir_subarbol_minimo(cliente, arbol.right());

    // Check if current node is a desired item

    // If current node is a desired item or if left/right subtrees are not empty, include it
    if ((cliente.contiene_item(arbol.value())) || !left.empty() || !right.empty()) {
        cliente.pb_sala(arbol.value()); // Update client's visit list
        return BinTree<string>(arbol.value(), left, right);
    }

    // Otherwise, return empty tree
    return BinTree<string>();
}

// Traverse the minimal subtree to generate the path
void Cjt_clientes::calcular_ruta_subarbol(const BinTree<string>& subarbol) {
    if (subarbol.empty()) return;
    cout << subarbol.value() << endl;
    if (!subarbol.left().empty()) {
        cout << "left" << endl;
        calcular_ruta_subarbol(subarbol.left());
        cout << "back" << endl;
    }
    if (!subarbol.right().empty()) {
        cout << "right" << endl;
        calcular_ruta_subarbol(subarbol.right());
        cout << "back" << endl;
    }
}

// Updated method for adding a new client
void Cjt_clientes::nuevo_cliente(const BinTree<string>& bintree_salas) {
    int id = contador;
    Cliente nuevoCliente(id, this); // Pass 'this' pointer to Cliente

    // Read the items the client wants to buy
    vector<string> items;
    string item;
    while (cin >> item && item != "#") {
        items.push_back(item);
        nuevoCliente.guardar_items(item);
    }

    // Build the minimal subtree and update client's visit list
    BinTree<string> subarbol = construir_subarbol_minimo(nuevoCliente, bintree_salas);

    // Print the subtree
    cout << "Subarbol del cliente " << id << ":\n";
    subarbol.setOutputFormat(BT::VISUALFORMAT);
    cout << subarbol << endl;

    // Generate and print the path by traversing the minimal subtree
    cout << "Recorrido por la tienda del cliente " << id << ":\n";
    calcular_ruta_subarbol(subarbol);

    // Add the client to the list of clients
    clientes.push_back(nuevoCliente);

    // Increment the ID counter
    incrementar_contador();
}

//// @brief Agrega el ID de un cliente a la lista de clientes con productos no deseados.
//// @param id Identificador único del cliente.
void Cjt_clientes::agregar_cliente_con_productos_no_deseados(int id) {
    clientes_con_productos_no_deseados.insert(id);
}

//// @brief Imprime los IDs de los clientes que tienen productos no deseados.
void Cjt_clientes::imprimir_clientes_con_productos_no_deseados() const {
    for(auto it = clientes_con_productos_no_deseados.begin(); it != clientes_con_productos_no_deseados.end(); ++it){
        std::cout << *it;
        if(std::next(it) != clientes_con_productos_no_deseados.end()){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

/// Recuperar un cliente por su ID (devuelve una referencia constante)
//// @brief Recupera un cliente por su ID.
//// @param id Identificador único del cliente.
//// @return Referencia constante al cliente.
//// @throw std::out_of_range Si el cliente no existe.
const Cliente& Cjt_clientes::obtener_cliente(int id) const {
    if (id >= 1) {
        size_t index = static_cast<size_t>(id - 1);
        if (index < clientes.size()) {
            return clientes[index];
        }
    }
    throw std::out_of_range("Cliente no encontrado");
}

//// @brief Recupera un cliente por su ID (versión no constante).
//// @param id Identificador único del cliente.
//// @return Referencia al cliente.
//// @throw std::out_of_range Si el cliente no existe.
Cliente& Cjt_clientes::obtener_cliente(int id) {
    if (id >= 1) {
        size_t index = static_cast<size_t>(id - 1);
        if (index < clientes.size()) {
            return clientes[index];
        }
    }
    throw std::out_of_range("Cliente no encontrado");
}

//// @brief Encuentra el camino hacia un ítem en el árbol binario.
//// @param arbol Árbol binario donde buscar.
//// @param item Ítem a buscar en el árbol.
//// @param camino Vector donde se almacena el camino encontrado.
//// @return true si se encuentra el ítem, false en caso contrario.
bool Cjt_clientes::encontrar_camino(const BinTree<std::string>& arbol, const std::string& item, std::vector<std::string>& camino) {
    if (arbol.empty()) return false;

    camino.push_back(arbol.value()); //// Añade nodo actual al vector.

    if (arbol.value() == item) {
        return true;
    }

    //// Busca en el subárbol izquierdo.
    if (!arbol.left().empty()) {
        camino.push_back("left");
        if (encontrar_camino(arbol.left(), item, camino)) {
            return true;
        }
        camino.pop_back(); //// Elimina "left".
    }

    //// Search right subtree
    if (!arbol.right().empty()) {
        camino.push_back("right");
        if (encontrar_camino(arbol.right(), item, camino)) {
            return true;
        }
        camino.pop_back(); //// Elimina "right"
    }

    camino.pop_back(); //// Elimina nodo actual.
    return false;
}