/**
 * @mainpage Práctica QT2024 PRO2: Megathlon.
 
Programa que se encarga de gestionar el flujo de clientes en una tienda Megathlon.

Gestiona la ruta de los clientes por la tienda dependiendo de su lista de la compra y organiza
la expedición de tickets en las cajas de la tienda para optimizar el tiempo de espera de los clientes.
*/

/** @file program.cc
    @brief Programa principal.
*/

#include "Caja.hh"
#include "Tienda.hh"
#include "Cliente.hh"
#include "Cjt_clientes.hh"
#include "Cjt_cajas.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include <iostream>
#endif


using namespace std;

/** @brief Programa principal para la gestión de Megathlon.
*/
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
            cout << "#nuevo_cliente" << endl;
            cjtclientes.nuevo_cliente(megathlon.recuperar_arbol());
        } else if (instruccion == "quiere_comprar") {
            int id;
            cin >> id;
            cout << "#quiere_comprar " << id << endl;
            const Cliente& cliente = cjtclientes.obtener_cliente(id);
            cliente.desea();
        } else if (instruccion == "salas_a_visitar") {
            int id;
            cin >> id;
            cout << "#salas_a_visitar " << id << endl;
            const Cliente& cliente = cjtclientes.obtener_cliente(id);
            cliente.salas_a_visitar();
        } else if (instruccion == "pago_cliente") {
            cout << "#pago_cliente ";
            cjtcajas.expedir_ticket(cjtclientes);
        } else if (instruccion == "escribir_caja") {
            int id;
            cin >> id;
            cout << "#escribir_caja " << id << " ";
            cjtcajas.escribir_caja_singular(id);
        } else if (instruccion == "escribir_cajas") {
            cout << "#escribir_cajas ";
            cjtcajas.escribir_cajas_plural();
        } else if (instruccion == "compra_y_no_quiere") {
            int id;
            cin >> id;
            cout << "#compra_y_no_quiere " << id << endl;
            const Cliente& cliente = cjtclientes.obtener_cliente(id);
            cout << cliente.imprimir_productos_no_deseados() << endl;
        } else if (instruccion == "compran_y_no_quieren") {
            cout << "#compran_y_no_quieren" << endl;
            cjtclientes.imprimir_clientes_con_productos_no_deseados();
        }
        cout << endl;
        cin >> instruccion;
    }
    cout << "#fin" << endl;
    return 0;
}