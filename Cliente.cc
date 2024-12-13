#include "Cliente.hh"
#include "Cjt_clientes.hh"
#include <algorithm>

/// Constructor por defecto
Cliente::Cliente() : id(0), num_productos(0), productos_no_deseados(0), cjt_clientes(nullptr) {}

/// Constructor con parámetros
Cliente::Cliente(int id, Cjt_clientes* cjt_clientes) : id(id), num_productos(0), productos_no_deseados(0), cjt_clientes(cjt_clientes) {}

/// Obtener el ID del cliente
int Cliente::obtenerId() const {
    return id;
}

void Cliente::desea() const {
    for(auto it = items.begin(); it != items.end(); ++it){
        std::cout << *it;
        if(std::next(it) != items.end()){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Cliente::guardar_items(const std::string& itemscin){
    items.insert(itemscin);
}

bool Cliente::contiene_item(const std::string& item) const {
    return items.find(item) != items.end();
}

void Cliente::pb_sala(const std::string& sala){
    salas_depuradas.insert(sala);
}

void Cliente::salas_a_visitar() const {
    for(auto it = salas_depuradas.begin(); it != salas_depuradas.end(); ++it){
        std::cout << *it;
        if(std::next(it) != salas_depuradas.end()){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Cliente::guardar_producto(const std::string& producto, int cantidad) {
    if (std::find(items.begin(), items.end(), producto) == items.end()) {
        productos_no_deseados += cantidad;
        // Notificar a Cjt_clientes
        if (cjt_clientes) {
            cjt_clientes->agregar_cliente_con_productos_no_deseados(id);
        }
    }

    // Guardar producto y cantidades
    productos.push_back({producto, cantidad});
    aumentar_num_productos(cantidad);
}

int Cliente::numero_productos() const {
    return num_productos;
}

void Cliente::aumentar_num_productos(int num){
    num_productos += num;
}

void Cliente::aumentar_productos_no_deseados(){
    ++productos_no_deseados;
}

bool Cliente::check_productos_no_deseados() const {
    return productos_no_deseados > 0;
}

int Cliente::imprimir_productos_no_deseados() const {
    return productos_no_deseados;
}
