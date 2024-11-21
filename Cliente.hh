#ifndef CLIENTE_HH
#define CLIENTE_HH

#include <string>

class Cliente {
public:
    // Constructor por defecto
    Cliente();

    // Constructor con parámetros
    Cliente(const std::string& nombre, int tiempoServicio);

    // Obtener el nombre del cliente
    std::string obtenerNombre() const;

    // Obtener el tiempo de servicio requerido
    int obtenerTiempoServicio() const;

private:
    std::string nombre;
    int tiempoServicio;
};

#endif // CLIENTE_HH