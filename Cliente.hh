#ifndef CLIENTE_HH
#define CLIENTE_HH

#include <iostream>
#include <string>
#include <vector>

class Cliente {
public:
    // Constructor
    Cliente();
    Cliente(int id);

    // Guardar productos y cantidades
    void guardar_producto(const std::string& producto, int cantidad);

    // Obtener el número total de productos
    int numero_productos() const;

    // Otros métodos...
    void desea() const;
    void guardar_items(const std::vector<std::string>& itemscin);
    void guardar_items_comprados(const std::vector<std::string>& itcmcin);
    void salas_a_visitar() const;
    void pb_sala(const std::string& sala);

private:
    int id;
    std::vector<std::pair<std::string, int>> productos; // Lista de productos y cantidades
    std::vector<std::string> items;
    std::vector<std::string> items_comprados;
    std::vector<std::string> salas_depuradas;
};

#endif // CLIENTE_HH