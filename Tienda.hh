#ifndef TIENDA_HH
#define TIENDA_HH

#include "BinTree.hh"
#include "Sala.hh"
#include <vector>

class Tienda {
public:
    // Constructor
    Tienda();

    void leer_salas();

    void leer_cajas();

private:
    BinTree<string> bintree_salas;
    BinTree<string> leer_salas_private();
    vector<Caja> Cajas;
};

#endif // TIENDA_HH