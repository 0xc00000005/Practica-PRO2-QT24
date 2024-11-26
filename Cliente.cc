#include "Cliente.hh"


// Constructor por defecto
Cliente::Cliente() {}

// Constructor con parámetros
Cliente::Cliente(const int id)
    : id(id) {}

// Obtener el ID del cliente
int Cliente::obtenerId() const {
    return id;
}


void Cliente::desea() const {
    for(const auto& nombre : items){
        // Parece que el problema está en que no accede a nombre
        std::cout << nombre << std::endl;
    }
}

void Cliente::guardar_items(const std::vector<std::string>& itemscin){
    items=itemscin;
}