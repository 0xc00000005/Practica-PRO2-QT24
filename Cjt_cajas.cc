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
    for(int i = 0; i < num_cajas; ++i){
        if(cajas[i].esta_disponible(hora_actual)){
            if(mejor_caja == -1 || cajas[i].get_proximo_libre() < menor_tiempo){
                mejor_caja = i;
                menor_tiempo = cajas[i].get_proximo_libre();
            }
        }
    }
    return mejor_caja;
}

// Actualizar el tiempo de la caja después de asignar un cliente
void Cjt_cajas::actualizar_tiempo_caja(int id_caja) {
    cajas[id_caja].actualizar_libre();
}