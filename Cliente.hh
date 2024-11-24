#ifndef CLIENTE_HH
#define CLIENTE_HH

#include <string>

class Cliente {
public:
    // Constructor por defecto
    Cliente();

    // Constructor con parámetros
    Cliente(const int id);

    // Obtener el ID del cliente
    int obtenerId() const;

    // Obtener el contador actual
    static int getContador();

private:
    int id;
    static int contador;
};

#endif // CLIENTE_HH