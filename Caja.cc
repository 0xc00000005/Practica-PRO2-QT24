#include "Caja.hh"
#include <queue>

Caja::Caja() : idCaja(0), proximo_libre(0, 0, 0) {}

Caja::Caja(int id) : idCaja(id), proximo_libre(0, 0, 0) {}

void Caja::asignar_cliente(const Cliente& cliente, const Hora& hora_actual) {

    int tiempo_atencion = 14 + cliente.numero_productos();

    // Actualiza tiempo libre
    if (proximo_libre.menor(hora_actual)) {
        proximo_libre = hora_actual;
    }

    // Calcula hora salida
    Hora hora_salida = proximo_libre;
    hora_salida.sumar_segundos(tiempo_atencion);
    proximo_libre = hora_salida;

    // Añade cliente a la cola
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


int Caja::obtenerId() const {
    return idCaja;
}

void Caja::actualizar_libre(const Hora& hora_actual) {
    /// Recalcula proximo_libre a partir de los clientes en la cola

    /// Empieza con la hora actual o la proxima hora libre, dependiendo de cual sea menor
    Hora tiempo = (proximo_libre.menor(hora_actual)) ? hora_actual : proximo_libre;

    /// Calcular el tiempo total de atención de los clientes en la cola
    std::queue<std::pair<Cliente, Hora>> temp_queue = cola_clientes;
    while (!temp_queue.empty()) {
        std::pair<Cliente, Hora> cliente_con_salida = temp_queue.front();
        temp_queue.pop();
    }

    /// Actualiza proximo_libre
    proximo_libre = tiempo;
}

void Caja::escribir_caja(const Hora& hora) {

    std::queue<std::pair<Cliente, Hora>> temp_queue = cola_clientes;

    while (!temp_queue.empty()) {
        const std::pair<Cliente, Hora>& cliente_con_salida = temp_queue.front();

        // Comprueba si el cliente está aún en la cola en el tiempo dado
        if (hora.menor(cliente_con_salida.second) or hora.igual(cliente_con_salida.second)) {
            std::cout << cliente_con_salida.first.obtenerId() << " ";
            cliente_con_salida.second.escribir_hora();
            std::cout << " ";
        }

        temp_queue.pop();
    }

    std::cout << std::endl;
}