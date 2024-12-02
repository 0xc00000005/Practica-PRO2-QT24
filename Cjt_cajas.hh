#ifndef CJT_CAJAS_HH
#define CJT_CAJAS_HH

#include <vector>
#include <queue>
#include <iostream>
#include "Hora.hh"
#include "Caja.hh"
#include "Cjt_clientes.hh"

class Cjt_cajas {
public:
    // Constructor
    Cjt_cajas();

    void establecer_num_cajas(int n);

    int asignar_caja(const Cliente& cliente, const Hora& hora_actual);

    //Hora calcular_hora_salida(const Hora& hora_actual, int id_caja);

    void expedir_ticket(const Cliente& cliente) const;

    // Updated function declaration
    void expedir_ticket(Cjt_clientes& clientes);

    void escribir_caja_singular(int id_caja);
    void escribir_cajas_plural();

private:
    int num_cajas;

    std::vector<Caja> cajas;

    int buscar_mejor_caja(const Hora& hora_actual) const;

    void actualizar_tiempo_caja(int id_caja, const Hora& hora_actual);
};

#endif