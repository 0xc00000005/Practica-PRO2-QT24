#ifndef TIENDA_HH
#define TIENDA_HH

#include "BinTree.hh"
#include "Sala.hh"
#include "Cliente.hh"
#include "Caja.hh"
#include <vector>
#include <map>
#include <string>

class Tienda {
public:
    // Constructor
    Tienda();

    // Leer las salas y construir el árbol de la tienda
    void leer_salas();

    // Leer las cajas disponibles
    //void leer_cajas();

    // Añadir un nuevo cliente y mostrar el subárbol e instrucciones
    void nuevo_cliente();

    // Mostrar todos los clientes
    void mostrar_clientes() const;

    // Mostrar el subárbol correspondiente a un cliente
    void subarbol_cliente();

private:
    // Árbol binario que representa las salas de la tienda
    BinTree<std::string> bintree_salas;

    // Lectura recursiva de las salas para construir el árbol
    BinTree<std::string> leer_salas_private();

    // Lista de cajas disponibles
    //std::vector<Caja> cajas;

    // Mapa de clientes registrados en la tienda
    std::map<int, Cliente> clientes;

    // Función auxiliar para encontrar el subárbol y registrar el camino
    bool encontrar_subarbol(const BinTree<std::string>& arbol, const std::string& item, std::vector<std::string>& camino);
    BinTree<std::string> construir_subarbol(const vector<std::string>& camino);
};

#endif // TIENDA_HH