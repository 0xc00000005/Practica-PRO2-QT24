#ifndef SALA_HH
#define SALA_HH

#include <vector>
#include "Caja.hh"
#include "Cliente.hh"
#include "PRO2Excepcio.hh"

class Sala {
public:
    // Constructor
    Sala(int numCajas);

    // Métodos para gestionar clientes
    void agregarCliente(const Cliente& cliente);
    void atenderClientes();

    // Métodos para obtener información de la sala
    int numClientesEnEspera() const;
    int numCajasDisponibles() const;

private:
    std::vector<Caja> cajas;
    std::vector<Cliente> clientesEnEspera;
};

#endif // SALA_HH