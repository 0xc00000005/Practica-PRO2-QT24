#ifndef CLIENTE_HH
#define CLIENTE_HH

#include <iostream>
#include <string>
#include <vector>

class Cliente {
public:
    // Constructor por defecto
    Cliente();

    // Constructor con parámetros
    Cliente(const int id);

    // Obtener el ID del cliente
    int obtenerId() const;

    // Obtener el contador actual

    void desea() const;

    void guardar_items(const std::vector<std::string>& itemscin);

private:
    int id;
    
    std::vector<std::string> items;
};

#endif // CLIENTE_HH