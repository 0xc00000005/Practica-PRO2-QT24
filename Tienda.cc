#include "Tienda.hh"
#include <iostream>

// Constructor
Tienda::Tienda() {
    bintree_salas = BinTree<string>();
}

void Tienda::nuevo_cliente() {
    Cliente nuevoCliente;
    int id = nuevoCliente.obtenerId();
    clientes[id] = nuevoCliente;
}

void Tienda::leer_salas() {
    bintree_salas = leer_salas_private();
}

void Tienda::leer_cajas() {
    
}

BinTree<std::string> Tienda::leer_salas_private() {
    BinTree<string> t;
    t.setInputOutputFormat(BT::VISUALFORMAT);
    cin >> t;
    return t;
}
