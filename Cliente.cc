#include "Cliente.hh"

// Constructor por defecto
Cliente::Cliente() 
    : id(++contador) {}

// Constructor con parámetros
Cliente::Cliente(const int id) {
    // Aquí se usa this porque los nombres de los parámetros (nombre) son idénticos 
    // a los nombres de los atributos de la clase. Sin this, el compilador asumiría que 
    // nombre se refieren a los parámetros, no a los atributos.
    this->id = id;
}

// Obtener el nombre del cliente
int Cliente::obtenerId() const {
    return id;
}

int Cliente::getContador() const {
    return contador;
}
