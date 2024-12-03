#include "Caja.hh"
#include <queue>

// Constructor por defecto
Caja::Caja() : idCaja(0), proximo_libre(0, 0, 0) {}

// Constructor con identificador
Caja::Caja(int id) : idCaja(id), proximo_libre(0, 0, 0) {}

void Caja::asignar_cliente(const Cliente& cliente, const Hora& hora_actual) {
    // Calculate service time for this client
    int tiempo_atencion = 14 + cliente.numero_productos(); // 14 seconds + 1 second per product

    // Update the time when the caja will be free
    if (proximo_libre.menor(hora_actual)) {
        proximo_libre = hora_actual;
    }

    // Calculate the client's departure time
    Hora hora_salida = proximo_libre;
    hora_salida.sumar_segundos(tiempo_atencion);
    proximo_libre = hora_salida;

    // Add the client and their departure time to the queue
    cola_clientes.push(std::make_pair(cliente, hora_salida));
}

int Caja::tiempo_espera_estimado(const Hora& hora_actual) const {
    if (proximo_libre.menor(hora_actual)) {
        return 0;
    }
    Hora temp;
    temp = proximo_libre;
    temp.restar_horas(hora_actual);
    return temp.pasar_a_seg();
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

void Caja::actualizar_libre(const Hora& hora_actual) {
    // Recalculate proximo_libre based on the clients in the queue

    // Start from the current time or the existing proximo_libre, whichever is later
    Hora tiempo = (proximo_libre.menor(hora_actual)) ? hora_actual : proximo_libre;

    // Calculate the total service time for clients in the queue
    std::queue<std::pair<Cliente, Hora>> temp_queue = cola_clientes;
    while (!temp_queue.empty()) {
        std::pair<Cliente, Hora> cliente_con_salida = temp_queue.front();
        temp_queue.pop();
    }

    // Update proximo_libre
    proximo_libre = tiempo;
}

void Caja::escribir_caja(const Hora& hora) {

    std::queue<std::pair<Cliente, Hora>> temp_queue = cola_clientes;

    while (!temp_queue.empty()) {
        const std::pair<Cliente, Hora>& cliente_con_salida = temp_queue.front();

        // Check if the client is still in the queue at the given time
        if (hora.menor(cliente_con_salida.second) or hora.igual(cliente_con_salida.second) {
            // Output client ID
            std::cout << cliente_con_salida.first.obtenerId() << " ";
            // Output client's departure time
            cliente_con_salida.second.escribir_hora();
            std::cout << " ";
        }

        temp_queue.pop();
    }

    std::cout << std::endl;
}