#include "Tienda.hh"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

Tienda::Tienda() {
    bintree_salas = BT();
}

void Tienda::leer_salas() {
    bintree_salas = leer_salas_private();
    bintree_salas.setOutputFormat(BT::VISUALFORMAT);
    std::cout << "Organizacion de las salas:\n" << bintree_salas << std::endl;
}

BinTree<std::string> Tienda::recuperar_arbol(){
    return bintree_salas;
}

BinTree<std::string> Tienda::leer_salas_private() {
    BinTree<string> t;
    t.setInputOutputFormat(BT::VISUALFORMAT);
    std::cin >> t;
    return t;
}
