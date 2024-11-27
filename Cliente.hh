#ifndef CLIENTE_HH
#define CLIENTE_HH

#include <iostream>
#include <string>
#include <vector>

class Cliente {
public:
    // Constructor por defecto
    Cliente();

    // Constructor con parámetros
    Cliente(const int id);

    // Obtener el ID del cliente
    int obtenerId() const;

    // Obtener el contador actual

    void desea() const;

    void guardar_items(const std::vector<std::string>& itemscin);

    void guardar_salas(const std::vector<std::string>& salascin);

    void salas_a_visitar() const;

   // void depurar_salas();
   void pb_sala(const std::string& sala);

private:
    int id;
    std::vector<std::string> guardado_salas_visitar;
    std::vector<std::string> items;
    // Se necesita?
    std::vector<std::string> salas_depuradas;
};

#endif // CLIENTE_HH