#include "Caja.hh"
#include <queue>

// Constructor por defecto
Caja::Caja() : idCaja(0), proximo_libre(0, 0, 0) {}

// Constructor con identificador
Caja::Caja(int id) : idCaja(id), proximo_libre(0, 0, 0) {}

void Caja::asignar_cliente(const Cliente& cliente, const Hora& hora_actual) {
    // Calcular tiempo de atención para este cliente
    int tiempo_atencion = 10 + cliente.numero_productos(); // 10 segundos + 1 segundo por producto

    // Actualizar el tiempo en que la caja estará libre
    if (proximo_libre < hora_actual) {
        proximo_libre = hora_actual;
    }
    proximo_libre = proximo_libre + tiempo_atencion;

    // Agregar el cliente a la cola
    cola_clientes.push(cliente);
}

int Caja::tiempo_espera_estimado(const Hora& hora_actual) const {
    if (proximo_libre < hora_actual) {
        return 0;
    }
    return proximo_libre - hora_actual;
}

Hora Caja::get_proximo_libre() const {
    return proximo_libre;
}

int Caja::num_clientes_asignados() const {
    return cola_clientes.size();
}

bool Caja::esta_disponible(const Hora& hora_actual) const {
    // Aquí puedes implementar lógica adicional si hay horarios de apertura/cierre
    return true;
}

int Caja::obtenerId() const {
    return idCaja;
}