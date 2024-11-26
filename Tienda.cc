#include "Tienda.hh"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
typedef BinTree<string> BT;

// Constructor
Tienda::Tienda() {
    bintree_salas = BT();
}

void Tienda::leer_salas() {
    bintree_salas = leer_salas_private();
}

BinTree<std::string> Tienda::recuperar_arbol(){
    return bintree_salas;
}

/*void Tienda::leer_cajas() {
    int num;
    cin >> num;
    cajas.resize(num);
    cout << "Hay " << num << " cajas\n";
}*/

BT Tienda::leer_salas_private() {
    BinTree<string> t;
    t.setInputOutputFormat(BT::VISUALFORMAT);
    cin >> t;
    return t;
}
