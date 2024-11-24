#include "Cliente.hh"

// Inicialización del contador estático
int Cliente::contador = 0;

// Constructor por defecto
Cliente::Cliente()
    : id(++contador) {}

// Constructor con parámetros
Cliente::Cliente(const int id)
    : id(id) {}

// Obtener el ID del cliente
int Cliente::obtenerId() const {
    return id;
}

// Obtener el contador actual
int Cliente::getContador() {
    return contador;
}
