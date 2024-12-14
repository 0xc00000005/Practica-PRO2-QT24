/**
 * @file Cjt_cajas.hh
 * @brief Declaración de la clase Cjt_cajas que gestiona las cajas de la tienda.
 */

#ifndef CJT_CAJAS_HH
#define CJT_CAJAS_HH

#include "Hora.hh"
#include "Caja.hh"
#include "Cjt_clientes.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <queue>
#include <iostream>
#endif

/**
 * @class Cjt_cajas
 * @brief Clase que representa un conjunto de cajas y proporciona operaciones para gestionarlas.
 */
class Cjt_cajas {
public:
    /**
     * @brief Constructor por defecto.
     * Inicializa el número de cajas en 0.
     * \pre cierto
     * \post El resultado es un conjunto de cajas vacío.
     * \note Constante
     */
    Cjt_cajas();

    /**
     * @brief Establece el número de cajas disponibles.
     * \pre n > 0
     * \post Se crean n cajas.
     * \note lineal respecto al número de cajas.
     */
    void establecer_num_cajas(int n);

    /**
     * @brief Asigna una caja a un cliente.
     * \pre Cliente no asignado a ninguna caja. Hora actual válida.
     * \post El cliente es asignado a una caja.
     * \note Constante
     */
    int asignar_caja(const Cliente& cliente, const Hora& hora_actual);

    /**
     * @brief Expedir ticket para un cliente.
     * \pre Cliente con productos a comprar.
     * \post Se asigna una caja al cliente y se imprime la hora de salida.
     * \note constante.    
     */    
    void expedir_ticket(Cjt_clientes& clientes);

    /**
     * @brief Escribe los detalles de una caja.
     * \pre id_caja > 0
     * \post Se imprime los clientes asignados a la caja y su hora de salida.
     * \note constante
     */
    void escribir_caja_singular(int id_caja);

    /**
     * @brief Escribe los detalles de todas las cajas.
     * \pre cierto
     * \post Se imprime los clientes asignados a cada caja.
     * \note lineal respecto al número de cajas.
     */
    void escribir_cajas_plural();

private:

    /**
     * @brief Contiene el número de cajas.
     */
    int num_cajas;

    /**
     * @brief Vector de cajas.
     */
    std::vector<Caja> cajas;

    /**
     * @brief Busca la mejor caja disponible según la hora actual.
     * \pre Hora actual válida.
     * \post Se devuelve el ID de la caja más adecuada.
     * \note lineal respecto al número de cajas.
     */
    int buscar_mejor_caja(const Hora& hora_actual) const;

    /**
     * @brief Actualiza la próxima hora donde estará libre la caja.
     * \pre id_caja > 0, hora actual válida.
     * \post La caja actualiza la hora.
     * \note constante
     */
    void actualizar_tiempo_caja(int id_caja, const Hora& hora_actual);
};

#endif