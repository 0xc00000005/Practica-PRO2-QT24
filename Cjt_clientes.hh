#ifndef CJT_CLIENTES_HH
#define CJT_CLIENTES_HH

#include <vector>
#include <string>
#include <set>
#include "BinTree.hh"
#include "Cliente.hh"

class Cjt_clientes {
public:
    // Constructor
    Cjt_clientes();

    // Añadir un nuevo cliente y mostrar el subárbol e instrucciones
    void nuevo_cliente(const BinTree<std::string>& bintree_salas);

    // Recuperar un cliente por su ID (devuelve una referencia constante)
    // Ambos const se utilizan para garantizar que ni el objeto devuelto 
    // ni el objeto que llama a la función sean modificados, mejorando así la seguridad y la eficiencia del código.
    const Cliente& obtener_cliente(int id) const;

    // Method to get a modifiable reference to a client
    Cliente& obtener_cliente(int id);

    // Function to update the set of clients with unwanted products
    void agregar_cliente_con_productos_no_deseados(int id);

    // Function to print clients with unwanted products
    void imprimir_clientes_con_productos_no_deseados() const;

private:
    // Contador estático para generar IDs
    static int contador;

    // Vector de clientes registrados en la tienda
    std::vector<Cliente> clientes;

    // Incrementar contador
    void incrementar_contador();
    std::vector<std::string> combinar_caminos_en_orden(const std::vector<std::vector<std::string>>& caminos);

    bool encontrar_camino(const BinTree<std::string>& arbol, const std::string& item, std::vector<std::string>& camino);

    // Function to build the minimal subtree containing all desired items
    BinTree<std::string> construir_subarbol_minimo(const BinTree<std::string>& arbol, const std::set<std::string>& nodos_incluidos);

    // Set of client IDs with unwanted products
    std::set<int> clientes_con_productos_no_deseados;
};

#endif // CJT_CLIENTES_HH