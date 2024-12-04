#include "Cjt_cajas.hh"
#include "Cjt_clientes.hh"

// Constructor
Cjt_cajas::Cjt_cajas() : num_cajas(0) {}

// Establecer número de cajas
void Cjt_cajas::establecer_num_cajas(int n) {
    num_cajas = n;
    cajas.resize(num_cajas);
    std::cout << "Hay " << num_cajas << " cajas" << std::endl;
}

// Asignar caja a un cliente
int Cjt_cajas::asignar_caja(const Cliente& cliente, const Hora& hora_actual) {
    int id_caja = buscar_mejor_caja(hora_actual);
    if (id_caja != -1) {
        cajas[id_caja].asignar_cliente(cliente, hora_actual);
        actualizar_tiempo_caja(id_caja, hora_actual);
    }
    return id_caja;
}

// Buscar la mejor caja disponible
int Cjt_cajas::buscar_mejor_caja(const Hora& hora_actual) const {
    int mejor_caja = -1;
    int menor_tiempo_espera = -1;
    int menor_num_clientes = -1;

    for (int i = 0; i < num_cajas; ++i) {
        if (cajas[i].esta_disponible(hora_actual)) {
            int tiempo_espera = cajas[i].tiempo_espera_estimado(hora_actual);
            int num_clientes = cajas[i].num_clientes_asignados();

            if (mejor_caja == -1 || tiempo_espera < menor_tiempo_espera) {
                mejor_caja = i;
                menor_tiempo_espera = tiempo_espera;
                menor_num_clientes = num_clientes;
            } else if (tiempo_espera == menor_tiempo_espera) {
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
void Cjt_cajas::actualizar_tiempo_caja(int id_caja, const Hora& hora_actual) {
    cajas[id_caja].actualizar_libre(hora_actual);
}

void Cjt_cajas::expedir_ticket(Cjt_clientes& clientes) {
    int id_cliente;
    Hora hora_actual;
    std::cin >> id_cliente;
    // Se lee hora actual
    hora_actual.leer_hora();
    // Escribe detalles operación
    std::cout << id_cliente << " ";
    hora_actual.escribir_hora();
    std::cout << endl;
    // Se recoge cliente actual
    Cliente& cliente = clientes.obtener_cliente(id_cliente);

    // Leer productos y cantidades
    std::string producto;
    int cantidad;
    while (std::cin >> producto && producto != "#") {
        std::cin >> cantidad;
        cliente.guardar_producto(producto, cantidad);
    }
    // Asignar caja al cliente
    // Tiene punta que ahí está el fallo
    int id_caja = asignar_caja(cliente, hora_actual);
    Hora hora_salida = cajas[id_caja].get_proximo_libre();

    // Imprimir ticket
    std::cout << "Cliente " << id_cliente << " compra " << cliente.numero_productos() << " items" << std::endl;
    std::cout << "Cliente " << id_cliente << " va a caja " << (id_caja + 1);
    std::cout << " y saldrá a las ";
    hora_salida.escribir_hora();
    std::cout << std::endl;
}

void Cjt_cajas::escribir_caja_singular(int id_caja) {
    Hora hora;
    hora.leer_hora();
    hora.escribir_hora();
    std::cout << std::endl;
    cajas[id_caja-1].escribir_caja(hora);
}

void Cjt_cajas::escribir_cajas_plural() {
    Hora hora;
    hora.leer_hora();
    hora.escribir_hora();
    std::cout << std::endl;
    for (int i = 0; i < num_cajas; ++i) {
        std::cout << "Caja " << i + 1 << ": ";
        cajas[i].escribir_caja(hora);
    }
}