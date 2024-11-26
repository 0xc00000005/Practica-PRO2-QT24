#ifndef CJT_CLIENTES_HH
#define CJT_CLIENTES_HH

#include <string>
#include <vector>
#include "Cliente.hh"
#include "BinTree.hh"

class Cjt_clientes {
public:
    // Constructor
    Cjt_clientes();

    // Añadir un nuevo cliente y mostrar el subárbol e instrucciones
    void nuevo_cliente(const BinTree<std::string>& bintree_salas);

    // Recuperar un cliente por su ID (devuelve una referencia constante)
    const Cliente& obtener_cliente(int id) const;

private:
    // Contador estático para generar IDs
    static int contador;

    // Vector de clientes registrados en la tienda
    std::vector<Cliente> clientes;

    // Incrementar contador
    void incrementar_contador();

    // Funciones auxiliares
    bool encontrar_subarbol(const BinTree<std::string>& arbol, const std::string& item, std::vector<std::string>& camino);
    BinTree<std::string> construir_subarbol(const std::vector<std::string>& camino);
};

#endif // CJT_CLIENTES_HH