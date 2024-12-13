/**
 * @file Cliente.hh
 * @brief Especificación de la clase Cliente
 */
#ifndef CLIENTE_HH
#define CLIENTE_HH

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#endif

/**
 * @brief Declaración adelantada de la clase Cjt_clientes para evitar dependencias circulares
 */
class Cjt_clientes;

/**
 * @class Cliente
 * @brief Clase que representa un cliente de la tienda
 */
class Cliente {
public:
    /**
     * @brief Constructor por defecto
     * \pre cierto
     * \post El resultado es un cliente vacío
     * \coste Constante
     */
    Cliente();

    /**
     * @brief Constructor con parámetros
     * \pre id > 0, cjt_clientes != nullptr
     * \post El resultado es un cliente con identificador id y parte del conjunto de clientes.
     * \coste Constante
     */
    Cliente(int id, Cjt_clientes* cjt_clientes);

    /**
     * @brief Obtener el identificador del cliente
     * \pre cierto
     * \post Retorna el identificador del cliente
     * \coste Constante
     */
    int obtenerId() const;

    /**
     * @brief Guarda un producto en el vector de productos del cliente
     * \pre producto != "", cantidad > 0
     * \post Se añade el producto al vector de productos del cliente
     * \coste Lineal respecto al número de productos
     */
    void guardar_producto(const std::string& producto, int cantidad);

    /**
     * @brief Consulta el número de productos del cliente
     * \pre cierto
     * \post Retorna el número de productos del cliente
     * \coste Constante
     */
    int numero_productos() const;

    /**
     * @brief Aumenta el número de productos no deseados
     * \pre cierto
     * \post Se incrementa en 1 el número de productos no deseados
     * \coste Constante
     */
    void aumentar_productos_no_deseados();

    /**
     * @brief Consulta si el cliente tiene productos no deseados
     * \pre cierto
     * \post Retorna true si el cliente tiene productos no deseados, false en caso contrario
     * \coste Constante
     */
    bool check_productos_no_deseados() const;

    /**
     * @brief Imprime los productos no deseados del cliente
     * \pre cierto
     * \post Se imprime el número de productos no deseados del cliente
     * \coste Constante
     */
    int imprimir_productos_no_deseados() const;

    /**
     * @brief Guarda las salas que el cliente desea visitar
     * \pre sala != ""
     * \post Se añade la sala al vector de salas del cliente
     * \coste Logarítmico respecto al número de salas
     */
    void pb_sala(const std::string& sala);

    /**
     * @brief Guarda los items que el cliente desea comprar
     * \pre itemscin != ""
     * \post Se añade el item al conjunto de items del cliente
     * \coste Logarítmico respecto al número de items
     */
    void guardar_items(const std::string& itemscin);

    /**
     * @brief Imprime los items que el cliente desea comprar
     * \pre El cliente tiene items
     * \post Se imprime los items que el cliente desea comprar en orden alfabético
     * \coste Lineal respecto al número de items
     */
    void desea() const;

    /**
     * @brief Imprime las salas que el cliente desea visitar
     * \pre El cliente tiene salas
     * \post Se imprime las salas que el cliente desea visitar en orden alfabético
     * \coste Lineal respecto al número de salas
     */
    void salas_a_visitar() const;

    /**
     * @brief Aumenta el número de productos del cliente
     * \pre num > 0
     * \post Se incrementa en num el número de productos del cliente
     * \coste Constante
     */
    void aumentar_num_productos(int num);

    /**
     * @brief Consulta si el set items del cliente contiene "item"
     * \pre item != ""
     * \post Retorna true si el cliente contiene el item, false en caso contrario
     * \coste Logarítmico respecto al número de items
     */
    bool contiene_item(const std::string& item) const;


private:
    /**
     * @brief Identificador del cliente
     */
    int id;

    /**
     * @brief Número de productos del cliente
     */
    int num_productos;

    /**
     * @brief Número de productos no deseados
     */
    int productos_no_deseados;

    /**
     * @brief Puntero al conjunto de clientes al que pertenece el cliente
     */
    Cjt_clientes* cjt_clientes;

    /**
     * @brief Vector de productos y cantidad del cliente
     */
    std::vector<std::pair<std::string, int>> productos;

    /**
     * @brief Set de items que el cliente desea comprar
     */
    std::set<std::string> items;

    /**
     * @brief Set de items que finalmente compra el cliente
     */
    std::vector<std::string> items_comprados;

    /**
     * @brief Set de salas que el cliente desea visitar
     */
    std::set<std::string> salas_depuradas;
    
};

#endif /// CLIENTE_HH