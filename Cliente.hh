#ifndef CLIENTE_HH
#define CLIENTE_HH

#include <string>
#include <vector>
#include <set>

class Cjt_clientes; // Forward declaration

class Cliente {
public:
    // Constructors
    Cliente();
    Cliente(int id, Cjt_clientes* cjt_clientes);

    // Methods
    int obtenerId() const;
    void guardar_producto(const std::string& producto, int cantidad);
    int numero_productos() const;
    void aumentar_productos_no_deseados();
    bool check_productos_no_deseados() const;
    int imprimir_productos_no_deseados() const;
    void pb_sala(const std::string& sala);
    void guardar_items(const std::string& itemscin);
    void guardar_items_comprados(const std::vector<std::string>& itcmcin);
    void desea() const;
    void salas_a_visitar() const;
    void aumentar_num_productos(int num);

private:
    int id;
    int num_productos;
    int productos_no_deseados;
    Cjt_clientes* cjt_clientes; // Pointer to Cjt_clientes
    std::vector<std::pair<std::string, int>> productos;
    std::set<std::string> items;
    std::vector<std::string> items_comprados;
    std::set<std::string> salas_depuradas;
    
};

#endif // CLIENTE_HH