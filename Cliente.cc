#include "Cliente.hh"

// Constructor por defecto
Cliente::Cliente() {
    nombre = "";
    tiempoServicio = 0;
}

// Constructor con parámetros
Cliente::Cliente(const std::string& nombre, int tiempoServicio) {
    // Aquí se usa this porque los nombres de los parámetros (nombre) son idénticos 
    // a los nombres de los atributos de la clase. Sin this, el compilador asumiría que 
    // nombre se refieren a los parámetros, no a los atributos.
    this->nombre = nombre;
    this->tiempoServicio = tiempoServicio;
}

// Obtener el nombre del cliente
std::string Cliente::obtenerNombre() const {
    return nombre;
}

// Obtener el tiempo de servicio requerido
int Cliente::obtenerTiempoServicio() const {
    return tiempoServicio;
}