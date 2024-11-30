#ifndef CAJA_HH
#define CAJA_HH

#include "Cliente.hh"
#include "Hora.hh"
#include <queue>

class Caja {
public:
    // Constructor por defecto
    Caja();

    // Constructor con identificador
    Caja(int id);

    void asignar_cliente(const Cliente& cliente, const Hora& hora_actual);

    int tiempo_espera_estimado() const;

    int numero_clientes_en_cola() const;

    // Atender a un cliente
    void atenderCliente(const Cliente& cliente);

    // Obtener el identificador de la caja
    int obtenerId() const;

private:
    int idCaja;
    
    int tiempo_espera;

    std::queue<Cliente> cola_clientes;
    
};

#endif // CAJA_HH