#include <iostream>
#include "Caja.hh"
#include "Tienda.hh"
#include "Cliente.hh"
#include "Cjt_clientes.hh"
#include "Cjt_cajas.hh"

using namespace std;

int main() {
    Tienda megathlon = Tienda();
    Cjt_clientes cjtclientes = Cjt_clientes();
    megathlon.leer_salas();
    Cjt_cajas cjtcajas = Cjt_cajas();
    int n;
    cin >> n;
    cjtcajas.establecer_num_cajas(n);
    string instruccion;
    while (instruccion != "fin") {
        if (instruccion == "nuevo_cliente") {
            cjtclientes.nuevo_cliente(megathlon.recuperar_arbol());
        } else if (instruccion == "quiere_comprar") {
            int id;
            cin >> id;
            const Cliente& cliente = cjtclientes.obtener_cliente(id);
            cliente.desea();
        } else if (instruccion == "salas_a_visitar") {
            int id;
            cin >> id;
            const Cliente& cliente = cjtclientes.obtener_cliente(id);
            cliente.salas_a_visitar();
        } else if (instruccion == "pago_cliente") {
            int id;
            cin >> id;
            const Cliente& cliente = cjtclientes.obtener_cliente(id);
            cjtcajas.expedir_ticket(cliente);
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