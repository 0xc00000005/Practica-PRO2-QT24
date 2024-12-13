/**
 * @file Cjt_clientes.hh
 * @brief Declaración de la clase Cjt_clientes que gestiona un conjunto de clientes.
 */

#ifndef CJT_CLIENTES_HH
#define CJT_CLIENTES_HH

#include "Cliente.hh"
#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>
#endif

/**
 * @class Cjt_clientes
 * @brief Clase que representa un conjunto de clientes y proporciona operaciones para gestionarlos.
 */
class Cjt_clientes {
public:
    /**
     * @brief Constructor de la clase Cjt_clientes.
     * Inicializa el conjunto vacío.
     * \pre cierto
     * \post El resultado es un conjunto de clientes vacío.
     * \coste constante
     */
    Cjt_clientes();

    /**
     * @brief Añade un nuevo cliente.
     * \pre El BinTree de salas no está vacío.
     * \post El conjunto de clientes contiene un nuevo cliente.
     * \coste Lineal respecto al número de salas.
     */
    void nuevo_cliente(const BinTree<std::string>& bintree_salas);

    /**
     * @brief Recupera un cliente por su ID.
     * \pre El cliente con el ID especificado existe.
     * \post El cliente con el ID especificado.
     * \coste constante
     */
    Cliente& obtener_cliente(int id);

    /**
     * @brief Añade un cliente a la lista de clientes con productos no deseados.
     * \pre Hay un cliente con el ID especificado.
     * \post El cliente con productos no deseados se añade a la lista.
     * \coste constante
     */
    void agregar_cliente_con_productos_no_deseados(int id);

    /**
     * @brief Imprime los IDs de los clientes con productos no deseados.
     * \pre cierto
     * \post Los IDs de los clientes con productos no deseados se imprimen por pantalla.
     * \coste lineal respecto al número de clientes.
     */
    void imprimir_clientes_con_productos_no_deseados() const;

private:
    /**
     * @brief Incrementa el contador de IDs.
     * \pre cierto
     * \post El contador de IDs se incrementa en 1.
     * \coste constante
     */
    static int contador;

    /**
     * @brief Lista de clientes.
     */
    std::vector<Cliente> clientes;

    /**
     * @brief Incrementa el contador de IDs.
     * \pre El contador está inicializado.
     * \post El contador de IDs se incrementa en 1.
     * \coste constante
     */
    void incrementar_contador();

    /**
     * @brief Construye un subárbol mínimo para un cliente.
     * \pre El cliente está inicializado y el árbol no está vacío.
     * \post El subárbol mínimo para el cliente.
     * \coste lineal respecto al número de salas.
     */
    BinTree<std::string> construir_subarbol_minimo(Cliente& cliente, const BinTree<std::string>& arbol);
    
    /**
     * @brief Calcula la ruta de un subárbol.
     * \pre El subárbol no está vacío.
     * \post La ruta del subárbol se imprime por pantalla.
     * \coste lineal respecto al número de nodos del subárbol.
     */
    void calcular_ruta_subarbol(const BinTree<std::string>& subarbol);

    /**
     * @brief Lista de clientes con productos no deseados.
     */
    std::set<int> clientes_con_productos_no_deseados;
};

#endif /// CJT_CLIENTES_HH