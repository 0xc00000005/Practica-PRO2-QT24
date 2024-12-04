#include "Cliente.hh"
#include "Cjt_clientes.hh"
#include <algorithm>

// Constructor por defecto
Cliente::Cliente() : id(0), productos_no_deseados(0), cjt_clientes(nullptr) {}

// Constructor con parámetros
Cliente::Cliente(int id, Cjt_clientes* cjt_clientes) : id(id), productos_no_deseados(0), cjt_clientes(cjt_clientes) {}

//int Cliente::productos_no_deseados = 0;

// Obtener el ID del cliente
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

void Cliente::guardar_items(const std::vector<std::string>& itemscin){
    items=itemscin;
}

void Cliente::guardar_items_comprados(const std::vector<std::string>& itcmcin){
    items_comprados=itcmcin;
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
    // Check if the product exists in 'salas_depuradas'
    if (std::find(items.begin(), items.end(), producto) == items.end()) {
        // Product not found in 'salas_depuradas', increase 'productos_no_deseados'
        productos_no_deseados += cantidad;
        // Notify Cjt_clientes
        if (cjt_clientes) {
            cjt_clientes->agregar_cliente_con_productos_no_deseados(id);
        }
    }

    // Save the product and its quantity
    productos.push_back({producto, cantidad});
}

int Cliente::numero_productos() const {
    int total = 0;
    for (const auto& p : productos) {
        total += p.second;
    }
    return total;
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