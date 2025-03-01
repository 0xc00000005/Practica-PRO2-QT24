/**
 * @file Caja.hh
 * @brief Declaración de la clase Caja que representa una caja de la tienda.
 */
#ifndef CAJA_HH
#define CAJA_HH

#include "Cliente.hh"
#include "Hora.hh"

#ifndef NO_DIAGRAM
#include <queue>
#include <utility>
#endif

/**
 * @class Caja
 * @brief Clase que representa una caja de la tienda y permite gestionar los clientes y tiempos asignados a ella.
 */
class Caja {
public:
    /**
     * @brief Constructor por defecto.
     * \pre cierto
     * \post El resultado es una caja sin clientes asignados.
     * \note Constante
     */
    Caja();

    /**
     * @brief Constructor con parámetros.
     * \pre id > 0
     * \post El resultado es una caja con identificador id y sin clientes asignados.
     * \note Constante
     */
    Caja(int id);
    
    /**
     * @brief Asignar un cliente a la caja.
     * \pre Cliente no asignado a ninguna caja. Hora actual válida.
     * \post El cliente es asignado a la caja.
     * \note Constante
     */
    void asignar_cliente(const Cliente& cliente, const Hora& hora_actual);

    /**
     * @brief Calcular el tiempo de espera estimado para un cliente.
     * \pre Hora correcta
     * \post El resultado es el tiempo de espera estimado para el cliente.
     * \note Constante
     */
    int tiempo_espera_estimado(const Hora& hora_actual) const;

    /**
     * @brief Actualizar el tiempo de la caja después de asignar un cliente.
     * \pre Hora actual válida.
     * \post El tiempo de la caja es actualizado.
     * \note Lineal respecto al número de clientes en la cola.
     */
    void actualizar_libre(const Hora& hora_actual);

    /**
     * @brief Obtener la hora en que la caja estará libre.
     * \pre cierto
     * \post El resultado es la hora en que la caja estará libre.
     * \note Constante
     */
    Hora get_proximo_libre() const;

    /**
     * @brief Obtener el número de clientes asignados a la caja.
     * \pre cierto
     * \post El resultado es el número de clientes asignados a la caja.
     * \note Constante
     */
    int num_clientes_asignados() const;

    /**
     * @brief Obtener el identificador de la caja.
     * \pre cierto
     * \post El resultado es el identificador de la caja.
     * \note Constante
     */
    int obtenerId() const;

    /**
     * @brief Escribe los detalles de la caja.
     * \pre cierto
     * \post Se imprime los clientes asignados a la caja y su hora de salida.
     * \par Coste:
     * Lineal respecto al número de clientes en la cola.
     */
    void escribir_caja(const Hora& hora);


private:
    /**
     * @brief Identificador de la caja.
     */
    int idCaja;
    /**
     * @brief Hora en que la caja estará libre.
     */
    Hora proximo_libre;
    /**
     * @brief Cola de clientes con su hora de salida.
     */
    std::queue<std::pair<Cliente, Hora>> cola_clientes; 
};

#endif /// CAJA_HH