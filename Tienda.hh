/**
 * @file Tienda.hh
 * @brief Declaración de la clase Tienda que representa la organización de la tienda.
 */
#ifndef TIENDA_HH
#define TIENDA_HH

#include <string>
#include <vector>
#include "Cliente.hh"
#include "BinTree.hh"

/**
 * @class Tienda
 * @brief Clase que representa la organización de la tienda.
 */
class Tienda {
public:
    /**
     * @brief Constructor por defecto
     * \pre cierto
     * \post El resultado es una tienda sin salas
     * \coste Constante
     */
    Tienda();

    /**
     * @brief Leer la organización de las salas de la tienda
     * \pre cierto
     * \post Se lee la organización de las salas de la tienda
     * \coste Lineal respecto al número de salas
     */
    void leer_salas();

    /**
     * @brief Recuperar el árbol de salas de la tienda
     * \pre cierto
     * \post Se retorna el árbol de salas de la tienda
     * \coste Constante
     */
    BinTree<std::string> recuperar_arbol();

private:
    /**
     * @brief Contiene la organización de las salas de la tienda en formato árbol binario de strings
     */
    BinTree<std::string> bintree_salas;

    /**
     * @brief Leer la organización de las salas de la tienda
     * \pre cierto
     * \post Retorno un árbol binario a partir de la entrada
     * \coste Lineal respecto al número de salas
     */
    BinTree<std::string> leer_salas_private();
};

#endif /// TIENDA_HH