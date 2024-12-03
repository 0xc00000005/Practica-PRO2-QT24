#include "Cjt_clientes.hh"
#include "Cliente.hh"
#include "BinTree.hh"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>
#include <algorithm>

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

// Función para construir el subarbol a partir del camino
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

// Función para encontrar todos los caminos hacia los items
void Cjt_clientes::encontrar_todos_los_caminos(const BinTree<std::string>& arbol, const std::vector<std::string>& items, std::vector<std::string>& camino_actual, std::vector<std::vector<std::string>>& caminos_resultantes) {
    if (arbol.empty()) return;

    // Añadir el nodo actual al camino
    camino_actual.push_back(arbol.value());

    // Comprobar si el nodo actual es uno de los items
    if (std::find(items.begin(), items.end(), arbol.value()) != items.end()) {
        // Almacenar el camino actual
        caminos_resultantes.push_back(camino_actual);
    }

    // Recorrer el subárbol izquierdo
    if (!arbol.left().empty()) {
        camino_actual.push_back("left");
        encontrar_todos_los_caminos(arbol.left(), items, camino_actual, caminos_resultantes);
        camino_actual.pop_back(); // Quitar "left"
    }

    // Recorrer el subárbol derecho
    if (!arbol.right().empty()) {
        camino_actual.push_back("right");
        encontrar_todos_los_caminos(arbol.right(), items, camino_actual, caminos_resultantes);
        camino_actual.pop_back(); // Quitar "right"
    }

    // Retroceder
    camino_actual.push_back("back");
    camino_actual.pop_back(); // Quitar "back"
    camino_actual.pop_back(); // Quitar el nodo actual
}

// Función para combinar los caminos en un solo recorrido con instrucciones 'back'
std::vector<std::string> Cjt_clientes::combinar_caminos(const std::vector<std::vector<std::string>>& caminos) {
    std::vector<std::string> recorrido;
    if (caminos.empty()) return recorrido;

    recorrido = caminos[0];

    for (size_t i = 1; i < caminos.size(); ++i) {
        // Encontrar el prefijo común
        size_t j = 0;
        while (j < recorrido.size() && j < caminos[i].size() && recorrido[j] == caminos[i][j]) {
            ++j;
        }

        // Añadir pasos 'back' para retroceder al ancestro común
        for (size_t k = recorrido.size(); k > j; --k) {
            recorrido.push_back("back");
        }

        // Añadir el nuevo camino desde el punto de divergencia
        for (size_t k = j; k < caminos[i].size(); ++k) {
            recorrido.push_back(caminos[i][k]);
        }
    }

    return recorrido;
}

// Function to combine paths into a single traversal, including 'back' steps to return to root
std::vector<std::string> Cjt_clientes::combinar_caminos_en_orden(const std::vector<std::vector<std::string>>& caminos) {
    std::vector<std::string> recorrido;
    if (caminos.empty()) return recorrido;

    recorrido = caminos[0]; // Start with the path to the first item

    for (size_t i = 1; i < caminos.size(); ++i) {
        const auto& prev_camino = caminos[i - 1];
        const auto& curr_camino = caminos[i];

        // Find the common prefix length
        size_t j = 0;
        while (j < prev_camino.size() && j < curr_camino.size() && prev_camino[j] == curr_camino[j]) {
            ++j;
        }

        // Add "back" steps for nodes beyond the common ancestor in the previous path
        for (size_t k = prev_camino.size(); k > j; --k) {
            if (prev_camino[k - 1] != "left" && prev_camino[k - 1] != "right") {
                recorrido.push_back("back");
            }
        }

        // Add the divergent part of the current path
        for (size_t k = j; k < curr_camino.size(); ++k) {
            recorrido.push_back(curr_camino[k]);
        }
    }

    // **Add 'back' steps to return to the root after visiting the last item**
    // Calculate the current depth
    size_t depth = 0;
    for (const std::string& step : recorrido) {
        if (step == "back") {
            if (depth > 0) --depth;
        } else if (step != "left" && step != "right") {
            ++depth;
        }
    }

    // Add 'back' steps to return to the root (subtract 1 because root doesn't require 'back')
    for (size_t i = 0; i < depth - 1; ++i) {
        recorrido.push_back("back");
    }

    return recorrido;
}

// Function to build the minimal subtree containing all the items
BinTree<std::string> Cjt_clientes::construir_subarbol_minimo(const BinTree<std::string>& arbol, const std::set<std::string>& nodos_incluidos) {
    if (arbol.empty()) return BinTree<std::string>();

    BinTree<std::string> left = construir_subarbol_minimo(arbol.left(), nodos_incluidos);
    BinTree<std::string> right = construir_subarbol_minimo(arbol.right(), nodos_incluidos);

    if (nodos_incluidos.find(arbol.value()) != nodos_incluidos.end() || !left.empty() || !right.empty()) {
        return BinTree<std::string>(arbol.value(), left, right);
    } else {
        return BinTree<std::string>();
    }
}

// Función actualizada nuevo_cliente
void Cjt_clientes::nuevo_cliente(const BinTree<std::string>& bintree_salas) {
    int id = contador;
    Cliente nuevoCliente(id, this); // Pass 'this' pointer to Cliente

    // Read the items desired by the client
    std::vector<std::string> items;
    std::string item;
    while (std::cin >> item && item != "#") {
        items.push_back(item);
    }
    nuevoCliente.guardar_items(items);

    // Find paths for each item
    std::vector<std::vector<std::string>> caminos; // Paths to items in order
    std::set<std::string> nodos_incluidos;

    for (const std::string& item : items) {
        std::vector<std::string> camino;
        if (encontrar_camino(bintree_salas, item, camino)) {
            caminos.push_back(camino);
            // Collect nodes to include in the minimal subtree
            for (const auto& paso : camino) {
                if (paso != "left" && paso != "right") {
                    nodos_incluidos.insert(paso);
                }
            }
        } else {
            std::cout << "Item " << item << " no encontrado en la tienda.\n";
        }
    }

    // Combine the paths into a single traversal
    std::vector<std::string> recorrido = combinar_caminos_en_orden(caminos);

    // Build the minimal subtree
    BinTree<std::string> subarbol = construir_subarbol_minimo(bintree_salas, nodos_incluidos);

    // Display the subtree
    std::cout << "Subárbol del cliente " << id << ":\n";
    subarbol.setOutputFormat(BT::VISUALFORMAT);
    std::cout << subarbol << std::endl;

    // Display the traversal
    std::cout << "Recorrido por la tienda del cliente " << id << ":\n";
    for (const std::string& paso : recorrido) {
        if (paso == "back") {
            std::cout << "back" << std::endl;
        } else if (paso == "left" || paso == "right") {
            std::cout << paso << std::endl;
        } else {
            nuevoCliente.pb_sala(paso);
            std::cout << paso << std::endl;
        }
    }

    // Add the client to the vector
    clientes.push_back(nuevoCliente);

    // Increment the counter
    incrementar_contador();
}

// Function to update the set of clients with unwanted products
void Cjt_clientes::agregar_cliente_con_productos_no_deseados(int id) {
    clientes_con_productos_no_deseados.insert(id);
}

// Function to print clients with unwanted products
void Cjt_clientes::imprimir_clientes_con_productos_no_deseados() const {
    for (int id : clientes_con_productos_no_deseados) {
        std::cout << id << " ";
    }
    std::cout << std::endl;
}

// Recuperar un cliente por su ID (devuelve una referencia constante)
const Cliente& Cjt_clientes::obtener_cliente(int id) const {
    if (id - 1 >= 0 && id - 1 < clientes.size()) {
        return clientes[id - 1];
    } else {
        throw std::out_of_range("Cliente no encontrado");
    }
}

Cliente& Cjt_clientes::obtener_cliente(int id) {
    if (id - 1 >= 0 && id - 1 < clientes.size()) {
        return clientes[id - 1];
    } else {
        throw std::out_of_range("Cliente no encontrado");
    }
}

// Function to find the path to a single item
bool Cjt_clientes::encontrar_camino(const BinTree<std::string>& arbol, const std::string& item, std::vector<std::string>& camino) {
    if (arbol.empty()) return false;

    camino.push_back(arbol.value()); // Add current node

    if (arbol.value() == item) {
        return true;
    }

    // Search left subtree
    if (!arbol.left().empty()) {
        camino.push_back("left");
        if (encontrar_camino(arbol.left(), item, camino)) {
            return true;
        }
        camino.pop_back(); // Remove "left"
    }

    // Search right subtree
    if (!arbol.right().empty()) {
        camino.push_back("right");
        if (encontrar_camino(arbol.right(), item, camino)) {
            return true;
        }
        camino.pop_back(); // Remove "right"
    }

    camino.pop_back(); // Remove current node
    return false;
}