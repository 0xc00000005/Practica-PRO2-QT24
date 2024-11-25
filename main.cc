#include <iostream>
#include "Caja.hh"
#include "Tienda.hh"
#include "Cliente.hh"

using namespace std;

int main() {
    Tienda megathlon = Tienda();
    megathlon.leer_salas();
    int prov;
    cin >> prov;
    string instruccion;
    while (instruccion != "fin") {
        if (instruccion == "nuevo_cliente") {
            megathlon.nuevo_cliente();
        } else if (instruccion == "quiere_comprar") {
            int id;
            cin >> id;
            const Cliente& cliente = megathlon.obtener_cliente(id);
            cout << "A" << endl;
            cliente.desea();
        } else if (instruccion == "salas_a_visitar") {
            // Function call for salas_a_visitar
        } else if (instruccion == "pago_cliente") {
            // Function call for pago_cliente
        } else if (instruccion == "escribir_caja") {
            // Function call for escribir_caja
        } else if (instruccion == "escribir_cajas") {
            // Function call for escribir_cajas
        } else if (instruccion == "compra_y_no_quiere") {
            // Function call for compra_y_no_quiere
        } else if (instruccion == "compran_y_no_quieren") {
            // Function call for compran_y_no_quieren
        } else if (instruccion == "fin") {
            break;
        }
        cin >> instruccion;
    }
    return 0;
}