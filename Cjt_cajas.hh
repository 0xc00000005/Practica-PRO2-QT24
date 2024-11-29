#include <vector>
#include <queue>
#include <iostream>
#include "Hora.hh"
#include "Caja.hh"

class Cjt_cajas {
public:
    // Constructor
    Cjt_cajas();

    void establecer_num_cajas(int n);

    int asignar_caja(const Cliente& cliente, const Hora& hora_actual);

    Hora calcular_hora_salida(const Hora& hora_actual, int id_caja);

    void imprimir_estado() const;

    void expedir_ticket(const Cliente& cliente) const;

private:
    int num_cajas;

    std::vector<Caja> cajas;

    int buscar_mejor_caja(const Hora& hora_actual) const;

    void actualizar_tiempo_caja(int id_caja);
}