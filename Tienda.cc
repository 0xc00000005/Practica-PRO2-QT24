#include "Tienda.hh"


Tienda::Tienda() {
    bintree_salas = BinTree<string>();
}

void Tienda::leer_salas() {
    bintree_salas = leer_salas_private();
    bintree_salas.setOutputFormat(BinTree<string>::VISUALFORMAT);
    std::cout << "Organizacion de las salas:\n" << bintree_salas << std::endl;
}

BinTree<std::string> Tienda::recuperar_arbol(){
    return bintree_salas;
}

BinTree<std::string> Tienda::leer_salas_private() {
    BinTree<string> t;
    t.setInputOutputFormat(BinTree<string>::VISUALFORMAT);
    std::cin >> t;
    return t;
}
