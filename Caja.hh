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

    // Asignar un cliente a la caja
    void asignar_cliente(const Cliente& cliente, const Hora& hora_actual);

    // Obtener el tiempo de espera estimado para un nuevo cliente
    int tiempo_espera_estimado(const Hora& hora_actual) const;

    // Obtener el próximo tiempo libre de la caja
    Hora get_proximo_libre() const;

    // Obtener el número de clientes en cola
    int num_clientes_asignados() const;

    // Verificar si la caja está disponible en la hora actual
    bool esta_disponible(const Hora& hora_actual) const;

    // Obtener el identificador de la caja
    int obtenerId() const;

private:
    int idCaja;
    Hora proximo_libre; // Hora en que la caja estará libre
    std::queue<Cliente> cola_clientes; // Cola de clientes
};

#endif // CAJA_HH