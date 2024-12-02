#include "Caja.hh"
#include <queue>

// Constructor por defecto
Caja::Caja() : idCaja(0), proximo_libre(0, 0, 0) {}

// Constructor con identificador
Caja::Caja(int id) : idCaja(id), proximo_libre(0, 0, 0) {}

void Caja::asignar_cliente(const Cliente& cliente, const Hora& hora_actual) {
    // Calcular tiempo de atención para este cliente
    int tiempo_atencion = 14 + cliente.numero_productos(); // 10 segundos + 1 segundo por producto

    // Actualizar el tiempo en que la caja estará libre
    if (proximo_libre.menor(hora_actual)) {
        proximo_libre = hora_actual;
    }
   proximo_libre.sumar_segundos(tiempo_atencion);

    // Agregar el cliente a la cola
    cola_clientes.push(cliente);
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
    std::queue<Cliente> temp_queue = cola_clientes;
    while (!temp_queue.empty()) {
        Cliente cliente = temp_queue.front();
        temp_queue.pop();

        //int tiempo_atencion = 10 + cliente.numero_productos(); // 10 seconds + 1 second per product
        //tiempo.sumar_segundos(tiempo_atencion);
    }

    // Update proximo_libre
    proximo_libre = tiempo;
}

void Caja::imprimir_estado() const {
    std::cout << "ID Caja: " << idCaja << std::endl;
    std::cout << "Proximo libre: ";
    proximo_libre.escribir_hora();
    cout << std::endl;
    std::cout << "Clientes en cola: " << cola_clientes.size() << std::endl;
}