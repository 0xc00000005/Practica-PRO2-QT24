#ifndef TIENDA_HH
#define TIENDA_HH

#include "BinTree.hh"
#include "Sala.hh"
#include <vector>

class Tienda {
public:
    // Constructor
    Tienda();

    // Destructor
    ~Tienda();

    void leer_salas();

    void leer_cajas();

private:
    BinTree<Sala> bintree_salas;
    BinTree<Sala> leer_cajas_private();
    vector<Caja> Cajas;
};

#endif // TIENDA_HH