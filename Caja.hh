#ifndef CAJA_HH
#define CAJA_HH

#include "Cliente.hh"

class Caja {
public:
    // Constructor por defecto
    Caja();

    // Constructor con identificador
    Caja(int id);

    // Abrir la caja
    void abrirCaja();

    // Cerrar la caja
    void cerrarCaja();

    // Verificar si la caja está abierta
    bool estaAbierta() const;

    // Atender a un cliente
    void atenderCliente(const Cliente& cliente);

    // Obtener el identificador de la caja
    int obtenerId() const;

private:
    int idCaja;
    bool abierta;
};

#endif // CAJA_HH