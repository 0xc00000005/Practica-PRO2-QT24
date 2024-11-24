#include "Tienda.hh"

Tienda::Tienda() {
    bintree_salas = BinTree<string>();
}

void Tienda::leer_salas() {
    bintree_salas = leer_salas_private();
}

void Tienda::leer_cajas() {
    
}

void Tienda::nuevo_cliente(){
    
}

BinTree<std::string> Tienda::leer_salas_private() {
    BinTree<string> t;
    t.setInputOutputFormat(BT::VISUALFORMAT);
    cin >> t;
    return t;
}
