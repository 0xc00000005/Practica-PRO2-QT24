#include "Caja.hh"
#include <queue>

// Constructor por defecto
Caja::Caja() : idCaja(0), tiempo_espera(0) {}

// Constructor con identificador
Caja::Caja(int id) : idCaja(id), tiempo_espera(0) {}

void Caja::asignar_cliente(const Cliente& cliente, const Hora& hora_actual) {
    cola_clientes.push(cliente);
    // Suponiendo que el tiempo de espera se incrementa por cada cliente añadido
    tiempo_espera += cliente.tiempo_transaccion();
}

int Caja::tiempo_espera_estimado() const {
    return tiempo_espera;
}

int Caja::numero_clientes_en_cola() const {
    return cola_clientes.size();
}

void Caja::atenderCliente(const Cliente& cliente) {
    if (!cola_clientes.empty()) {
        cola_clientes.pop();
        // Suponiendo que el tiempo de espera se reduce por cada cliente atendido
        tiempo_espera -= cliente.tiempo_transaccion();
    }
}

int Caja::obtenerId() const {
    return idCaja;
}