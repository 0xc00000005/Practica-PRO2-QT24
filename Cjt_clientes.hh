/**
 * @file Cjt_clientes.hh
 * @brief Declaración de la clase Cjt_clientes que gestiona un conjunto de clientes.
 */

#ifndef CJT_CLIENTES_HH
#define CJT_CLIENTES_HH

#include <vector>
#include <string>
#include <set>
#include "BinTree.hh"
#include "Cliente.hh"

/**
 * @class Cjt_clientes
 * @brief Clase que representa un conjunto de clientes y proporciona operaciones para gestionarlos.
 */
class Cjt_clientes {
public:
    /**
     * @brief Constructor de la clase Cjt_clientes.
     * Inicializa el conjunto vacío.
     */
    Cjt_clientes();

    /**
     * @brief Añade un nuevo cliente.
     * @param bintree_salas Árbol binario que representa las salas asociadas al cliente.
     * @details Muestra también el subárbol correspondiente e instrucciones relevantes.
     */
    void nuevo_cliente(const BinTree<std::string>& bintree_salas);

    /**
     * @brief Recupera un cliente por su ID.
     * @param id Identificador único del cliente.
     * @return Referencia constante al cliente buscado.
     * @details Ambos const se utilizan para garantizar que ni el objeto devuelto ni el objeto que llama a la función sean modificados, mejorando así la seguridad y la eficiencia del código.
     */
    const Cliente& obtener_cliente(int id) const;

    //// Method to get a modifiable reference to a client
    Cliente& obtener_cliente(int id);

    //// Function to update the set of clients with unwanted products
    void agregar_cliente_con_productos_no_deseados(int id);

    //// Function to print clients with unwanted products
    void imprimir_clientes_con_productos_no_deseados() const;

private:
    //// Contador estático para generar IDs
    static int contador;

    //// Vector de clientes registrados en la tienda
    std::vector<Cliente> clientes;

    //// Incrementar contador
    void incrementar_contador();
    std::vector<std::string> combinar_caminos_en_orden(const std::vector<std::vector<std::string>>& caminos);

    //// @brief Encuentra el camino desde la raíz hasta un ítem específico.
    //// @param arbol
    //// @param item 
    //// @param camino 
    //// @return Un booleano indicando si se encontró el camino.
    bool encontrar_camino(const BinTree<std::string>& arbol, const std::string& item, std::vector<std::string>& camino);

    //// Function to build the minimal subtree containing all desired items
    //BinTree<std::string> construir_subarbol_minimo(const BinTree<std::string>& arbol, const std::set<std::string>& nodos_incluidos);

    BinTree<std::string> construir_subarbol_minimo(Cliente& cliente, const BinTree<std::string>& arbol);
    void calcular_ruta_subarbol(const BinTree<std::string>& subarbol);

    //// Set of client IDs with unwanted products
    std::set<int> clientes_con_productos_no_deseados;
};

#endif /// CJT_CLIENTES_HH