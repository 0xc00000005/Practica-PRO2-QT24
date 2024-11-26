#ifndef TIENDA_HH
#define TIENDA_HH

#include <string>
#include <vector>
#include "Cliente.hh"
#include "BinTree.hh"

class Tienda {
public:
    // Constructor
    Tienda();

    // Leer las salas y construir el árbol de la tienda
    void leer_salas();

    // Añadir un nuevo cliente y mostrar el subárbol e instrucciones
    void nuevo_cliente();

    void incrementar_contador();

    // Recuperar un cliente por su ID (devuelve una referencia constante)
    const Cliente& obtener_cliente(int id) const;

private:
    // Árbol binario que representa las salas de la tienda
    BinTree<std::string> bintree_salas;

    // Mapa de clientes registrados en la tienda
    std::vector<Cliente> clientes;

    static int contador;

    // Funciones auxiliares
    bool encontrar_subarbol(const BinTree<std::string>& arbol, const std::string& item, std::vector<std::string>& camino);
    BinTree<std::string> construir_subarbol(const std::vector<std::string>& camino);
    BinTree<std::string> leer_salas_private();
};

#endif // TIENDA_HH