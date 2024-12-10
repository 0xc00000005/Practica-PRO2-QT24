#include "Cjt_clientes.hh"
#include "Cliente.hh"
#include "BinTree.hh"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

typedef BinTree<string> BT;

//// Inicialización del contador estático
int Cjt_clientes::contador = 1;


//// @brief Constructor por defecto para inicializar un conjunto de clientes.
Cjt_clientes::Cjt_clientes() {
    clientes = vector<Cliente>();
}

//// @brief Incrementa el contador estático para asignar IDs únicos a los clientes.
void Cjt_clientes::incrementar_contador() {
    ++contador;
}

//// @brief Combina múltiples caminos hacia diferentes ítems en un único recorrido.
//// @param caminos Vector de vectores que contiene caminos individuales hacia los ítems.
//// @return Vector que representa el recorrido combinado.
// Updated 'combinar_caminos_en_orden' function to include returning to the root at the end
std::vector<std::string> Cjt_clientes::combinar_caminos_en_orden(const std::vector<std::vector<std::string>>& caminos) {
    std::vector<std::string> recorrido;
    if (caminos.empty()) return recorrido;

    // Start with the path to the first item
    recorrido = caminos[0];

    // For each subsequent path
    for (size_t i = 1; i < caminos.size(); ++i) {
        const auto& prev_camino = caminos[i - 1];
        const auto& curr_camino = caminos[i];

        // Find the point where paths diverge
        size_t j = 0;
        while (j < prev_camino.size() && j < curr_camino.size() && prev_camino[j] == curr_camino[j]) {
            ++j;
        }

        // Backtrack to the common ancestor
        size_t k = prev_camino.size();
        while (k > j) {
            --k;
            if (prev_camino[k] != "left" && prev_camino[k] != "right") {
                recorrido.push_back("back");
            }
        }

        // Move forward to the next item
        recorrido.insert(recorrido.end(), curr_camino.begin() + j, curr_camino.end());
    }

    // Backtrack from the last item to the root
    const auto& last_camino = caminos.back();
    size_t k = last_camino.size();
    while (k > 1) {
        --k;
        if (last_camino[k] != "left" && last_camino[k] != "right") {
            recorrido.push_back("back");
        }
    }

    return recorrido;
}

//// @brief Construye el subárbol mínimo que contiene un conjunto específico de nodos.
//// @param arbol Árbol binario original.
//// @param nodos_incluidos Conjunto de nodos que deben estar presentes en el subárbol.
//// @return Subárbol que contiene solo los nodos necesarios.
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

//// @brief Crea un nuevo cliente, calcula su recorrido por la tienda y construye su subárbol.
//// @param bintree_salas Árbol binario que representa las salas de la tienda.
void Cjt_clientes::nuevo_cliente(const BinTree<std::string>& bintree_salas) {
    int id = contador;
    Cliente nuevoCliente(id, this); /// Pass 'this' pointer to Cliente

    //// Lee los ítems que desea comprar el cliente
    std::vector<std::string> items;
    std::string item;
    while (std::cin >> item && item != "#") {
        items.push_back(item);
        nuevoCliente.guardar_items(item);
    }
    

    //// Encuentra el camino hacia cada ítem y construye el recorrido
    std::vector<std::vector<std::string>> caminos; //// Vector donde se almacenan los caminos.
    std::set<std::string> nodos_incluidos;

    for (const std::string& item : items) {
        std::vector<std::string> camino;
        if (encontrar_camino(bintree_salas, item, camino)) {
            caminos.push_back(camino);
            /// Collect nodes to include in the minimal subtree
            for (const auto& paso : camino) {
                if (paso != "left" && paso != "right") {
                    nodos_incluidos.insert(paso);
                }
            }
        } else {
            std::cout << "Item " << item << " no encontrado en la tienda.\n";
        }
    }

    //// Combina los caminos en un solo recorrido ordenado
    //// Esto se consigue llamando a combinar_caminos_en_orden().
    std::vector<std::string> recorrido = combinar_caminos_en_orden(caminos);

    //// Construye el subárbol mínimo que contiene todos los nodos necesarios
    //// Esto se consigue llamando a construir_subarbol_minimo().
    BinTree<std::string> subarbol = construir_subarbol_minimo(bintree_salas, nodos_incluidos);

    //// Imprime en consola el subárbol.
    std::cout << "Subarbol del cliente " << id << ":\n";
    subarbol.setOutputFormat(BT::VISUALFORMAT);
    std::cout << subarbol << std::endl;

    //// Imprime en consola el recorrido del cliente.
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

    //// Añade el cliente con todos sus datos al vector de clientes.
    clientes.push_back(nuevoCliente);

    //// Incrementa el contador de ID.
    /// Se consigue llamando a incrementar_contador().
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