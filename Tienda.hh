#ifndef TIENDA_HH
#define TIENDA_HH

#include <string>
#include <vector>
#include "Cliente.hh"
#include "BinTree.hh"

class Tienda {
public:
    /// Constructor
    Tienda();

    /// Leer las salas y construir el árbol de la tienda
    void leer_salas();

    BinTree<std::string> recuperar_arbol();

private:
    /// Árbol binario que representa las salas de la tienda
    BinTree<std::string> bintree_salas;

    /// Funciones auxiliares
    BinTree<std::string> leer_salas_private();
};

#endif /// TIENDA_HH