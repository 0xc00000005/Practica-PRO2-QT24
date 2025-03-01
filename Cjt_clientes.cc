#include "Cjt_clientes.hh"


using namespace std;

typedef BinTree<string> BT;

int Cjt_clientes::contador = 1;

Cjt_clientes::Cjt_clientes() {
    clientes = vector<Cliente>();
}

void Cjt_clientes::incrementar_contador() {
    ++contador;
}


BinTree<string> Cjt_clientes::construir_subarbol_minimo(Cliente& cliente, const BinTree<string>& arbol) {
    if (arbol.empty()) {
        return BinTree<string>();
    }

    // Recursivamente construir subárboles izquierdo y derecho
    BinTree<string> left = construir_subarbol_minimo(cliente, arbol.left());
    BinTree<string> right = construir_subarbol_minimo(cliente, arbol.right());

    // Si el cliente contiene el item actual o alguno de los subárboles no está vacío, se añade al subárbol
    if ((cliente.contiene_item(arbol.value())) || !left.empty() || !right.empty()) {
        cliente.pb_sala(arbol.value()); /// Añadir sala al cliente
        return BinTree<string>(arbol.value(), left, right);
    }

    // Si no se añade el item, se devuelve un árbol vacío
    return BinTree<string>();
}

// Calcula la ruta de un subárbol.
// subarbol Subárbol a recorrer.
void Cjt_clientes::calcular_ruta_subarbol(const BinTree<string>& subarbol) {
    if (subarbol.empty()) return;
    cout << subarbol.value() << endl;
    if (!subarbol.left().empty()) {
        cout << "left" << endl;
        calcular_ruta_subarbol(subarbol.left());
        cout << "back" << endl;
    }
    if (!subarbol.right().empty()) {
        cout << "right" << endl;
        calcular_ruta_subarbol(subarbol.right());
        cout << "back" << endl;
    }
}

// Añade un nuevo cliente a la lista de clientes.
// Árbol binario que representa las salas asociadas al cliente.
void Cjt_clientes::nuevo_cliente(const BinTree<string>& bintree_salas) {
    int id = contador;
    Cliente nuevoCliente(id, this); // Crear un nuevo cliente con el ID actual

    // Leer los items que el cliente desea comprar
    vector<string> items;
    string item;
    while (cin >> item && item != "#") {
        items.push_back(item);
        nuevoCliente.guardar_items(item);
    }

    // Construir el subárbol mínimo para el cliente
    BinTree<string> subarbol = construir_subarbol_minimo(nuevoCliente, bintree_salas);

    // Imprimir el subárbol
    cout << "Subarbol del cliente " << id << ":\n";
    subarbol.setOutputFormat(BT::VISUALFORMAT);
    cout << subarbol << endl;

    // Generar la ruta de recorrido del cliente
    cout << "Recorrido por la tienda del cliente " << id << ":\n";
    calcular_ruta_subarbol(subarbol);

    // Añadir el cliente a la lista de clientes
    clientes.push_back(nuevoCliente);

    // Incrementar el contador de IDs
    incrementar_contador();
}


void Cjt_clientes::agregar_cliente_con_productos_no_deseados(int id) {
    clientes_con_productos_no_deseados.insert(id);
}

void Cjt_clientes::imprimir_clientes_con_productos_no_deseados() const {
    for(auto it = clientes_con_productos_no_deseados.begin(); it != clientes_con_productos_no_deseados.end(); ++it){
        std::cout << *it;
        if(std::next(it) != clientes_con_productos_no_deseados.end()){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

Cliente& Cjt_clientes::obtener_cliente(int id) {
    if (id >= 1) {
        size_t index = static_cast<size_t>(id - 1);
        if (index < clientes.size()) {
            return clientes[index];
        }
    }
    throw std::out_of_range("Cliente no encontrado");
}