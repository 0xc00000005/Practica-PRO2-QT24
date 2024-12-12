#include "Cjt_clientes.hh"
#include "Cliente.hh"
#include "BinTree.hh"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>

using namespace std;

typedef BinTree<string> BT;

//// @brief Contador estático para generar IDs
int Cjt_clientes::contador = 1;

//// @brief Constructor por defecto
Cjt_clientes::Cjt_clientes() {
    clientes = vector<Cliente>();
}

//// @brief Incrementa el contador de IDs
void Cjt_clientes::incrementar_contador() {
    ++contador;
}

//// @brief  Construye un subárbol mínimo para un cliente.
//// @param cliente Referencia al cliente que se está creando. 
//// @param arbol Árbol binario que representa las salas de la tienda.
//// @return BinTree<string> Subárbol mínimo para el cliente.
BinTree<string> Cjt_clientes::construir_subarbol_minimo(Cliente& cliente, const BinTree<string>& arbol) {
    if (arbol.empty()) {
        return BinTree<string>();
    }

    /// Recursivamente construir subárboles izquierdo y derecho
    BinTree<string> left = construir_subarbol_minimo(cliente, arbol.left());
    BinTree<string> right = construir_subarbol_minimo(cliente, arbol.right());

    /// Si el cliente contiene el item actual o alguno de los subárboles no está vacío, se añade al subárbol
    if ((cliente.contiene_item(arbol.value())) || !left.empty() || !right.empty()) {
        cliente.pb_sala(arbol.value()); /// Añadir sala al cliente
        return BinTree<string>(arbol.value(), left, right);
    }

    /// Si no se añade el item, se devuelve un árbol vacío
    return BinTree<string>();
}

//// @brief Calcula la ruta de un subárbol.
//// @param subarbol Subárbol a recorrer.
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

//// @brief Añade un nuevo cliente a la lista de clientes.
//// @param bintree_salas Árbol binario que representa las salas asociadas al cliente.
void Cjt_clientes::nuevo_cliente(const BinTree<string>& bintree_salas) {
    int id = contador;
    Cliente nuevoCliente(id, this); /// Crear un nuevo cliente con el ID actual

    /// Leer los items que el cliente desea comprar
    vector<string> items;
    string item;
    while (cin >> item && item != "#") {
        items.push_back(item);
        nuevoCliente.guardar_items(item);
    }

    /// Construir el subárbol mínimo para el cliente
    BinTree<string> subarbol = construir_subarbol_minimo(nuevoCliente, bintree_salas);

    /// Imprimir el subárbol
    cout << "Subarbol del cliente " << id << ":\n";
    subarbol.setOutputFormat(BT::VISUALFORMAT);
    cout << subarbol << endl;

    /// Generar la ruta de recorrido del cliente
    cout << "Recorrido por la tienda del cliente " << id << ":\n";
    calcular_ruta_subarbol(subarbol);

    /// Añadir el cliente a la lista de clientes
    clientes.push_back(nuevoCliente);

    /// Incrementar el contador de IDs
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

/// @brief Recupera un cliente por su ID (versión no constante).
/// @param id Identificador único del cliente.
/// @return Referencia al cliente.
/// @throw std::out_of_range Si el cliente no existe.
Cliente& Cjt_clientes::obtener_cliente(int id) {
    if (id >= 1) {
        size_t index = static_cast<size_t>(id - 1);
        if (index < clientes.size()) {
            return clientes[index];
        }
    }
    throw std::out_of_range("Cliente no encontrado");
}
