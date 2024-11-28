#include "Cjt_cajas.hh"

// Constructor
Cjt_cajas::Cjt_cajas() : num_cajas(0) {}

// Establecer número de cajas
void Cjt_cajas::establecer_num_cajas(int n) {
    num_cajas = n;
    cajas.resize(num_cajas);
}

// Asignar caja a un cliente
int Cjt_cajas::asignar_caja(const Cliente& cliente, const Hora& hora_actual) {
    int id_caja = buscar_mejor_caja(hora_actual);
    if (id_caja != -1) {
        cajas[id_caja].asignar_cliente(cliente, hora_actual);
        actualizar_tiempo_caja(id_caja);
    }
    return id_caja;
}

// Calcular hora de salida
Hora Cjt_cajas::calcular_hora_salida(const Hora& hora_actual, int id_caja) {
    return cajas[id_caja].calcular_salida(hora_actual);
}

// Imprimir estado de las cajas
void Cjt_cajas::imprimir_estado() const {
    for(int i = 0; i < num_cajas; ++i){
        std::cout << "Caja " << i+1 << ": ";
        cajas[i].imprimir_estado();
    }
}

// Buscar la mejor caja disponible
int Cjt_cajas::buscar_mejor_caja(const Hora& hora_actual) const {
    int mejor_caja = -1;
    Hora menor_tiempo;
    int menor_num_clientes = -1;

    for (int i = 0; i < num_cajas; ++i) {
        if (cajas[i].esta_disponible(hora_actual)) {
            Hora tiempo_libre = cajas[i].get_proximo_libre();
            int num_clientes = cajas[i].num_clientes_asignados();

            if (mejor_caja == -1 || tiempo_libre < menor_tiempo) {
                mejor_caja = i;
                menor_tiempo = tiempo_libre;
                menor_num_clientes = num_clientes;
            } else if (tiempo_libre == menor_tiempo) {
                if (num_clientes < menor_num_clientes) {
                    mejor_caja = i;
                    menor_num_clientes = num_clientes;
                } else if (num_clientes == menor_num_clientes) {
                    if (i < mejor_caja) {
                        mejor_caja = i;
                    }
                }
            }
        }
    }
    return mejor_caja;
}

// Actualizar el tiempo de la caja después de asignar un cliente
void Cjt_cajas::actualizar_tiempo_caja(int id_caja) {
    cajas[id_caja].actualizar_libre();
}


void Cjt_cajas::expedir_ticket() const {
    int id;
    Hora hora_actual;
    std::cin >> id >> hora_actual;

    // Leer productos y cantidades
    std::string producto;
    int cantidad;
    Cliente cliente(id);

    while (std::cin >> producto && producto != "#") {
        std::cin >> cantidad;
        cliente.guardar_producto(producto, cantidad); // Método para guardar productos en Cliente
    }

    // Asignar caja al cliente
    int id_caja = asignar_caja(cliente, hora_actual);

    // Calcular hora de salida
    Hora hora_salida = calcular_hora_salida(hora_actual, id_caja);

    /*// Evitar tickets con el mismo instante
    static Hora ultima_hora_ticket;
    if (hora_actual == ultima_hora_ticket) {
        hora_actual.incrementar(); // Suponiendo que incrementa un segundo
    }
    ultima_hora_ticket = hora_actual;*/

    // Imprimir ticket
    std::cout << "Cliente: " << id << std::endl;
    std::cout << "Hora de recogida del ticket: " << hora_actual << std::endl;
    std::cout << "Hora de salida de la tienda: " << hora_salida << std::endl;
    std::cout << "Caja asignada: " << id_caja << std::endl;
}
