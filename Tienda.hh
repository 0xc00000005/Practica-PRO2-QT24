#ifndef TIENDA_HH
#define TIENDA_HH

#include "BinTree.hh"
#include "Sala.hh"
#include "Cliente.hh"
#include <vector>
#include <map>

class Tienda {
public:
    // Constructor
    Tienda();

    void leer_salas();

    void leer_cajas();

    void nuevo_cliente();

    void mostrar_clientes() const;

private:
    BinTree<string> bintree_salas;
    BinTree<string> leer_salas_private();
    vector<Caja> Cajas;
    map<int, Cliente> clientes;
};

#endif // TIENDA_HH