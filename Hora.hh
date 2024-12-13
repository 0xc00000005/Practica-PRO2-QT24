/**
 * @file Hora.hh
 * @brief Declaración de la clase Hora para gestionar tiempos.
 */
#ifndef HORA_HH
#define HORA_HH

#include <iostream>
using namespace std;

/**
 * @class Hora
 * @brief Clase que permite operar con horas, minutos y segundos.
 */
class Hora
{
public:
	/**
	 * @brief Constructor por defecto.
	 * \pre cierto
	 * \post El resultado es una hora vacía.
	 * \coste Constante
	 */
	Hora();

	/**
	 * @brief Constructor con parámetros.
	 * \pre h, m, s >= 0
	 * \post El resultado es una hora con h horas, m minutos y s segundos.
	 * \coste Constante
	 */
	Hora(int h, int m, int s);

	/**
	 * @brief Leer una hora.
	 * \pre cierto
	 * \post Se lee una hora de la entrada estándar.
	 * \coste Constante
	 */
	void leer_hora();

	/**
	 * @brief Comprobar si una hora es menor que otra.
	 * \pre cierto
	 * \post El resultado indica si la hora es menor que h.
	 * \coste Constante
	 */
	bool menor(Hora h) const;

	/**
	 * @brief Comprobar si una hora es igual a otra.
	 * \pre cierto
	 * \post El resultado indica si la hora es igual a h.
	 * \coste Constante
	 */
	bool igual(Hora h) const;

	/**
	 * @brief Sumar segundos a una hora.
	 * \pre seg >= 0
	 * \post Se suman seg segundos a la hora.
	 * \coste Constante
	 */
	void sumar_segundos(int seg);

	/**
	 * @brief Pasar segundos a horas, minutos y segundos.
	 * \pre s >= 0
	 * \post Se calculan las horas, minutos y segundos equivalentes a s segundos.
	 * \coste Constante
	 */
	void pasar_a_hms(int s);

	/**
	 * @brief Pasar una hora a segundos.
	 * \pre cierto
	 * \post El resultado es el número de segundos equivalentes a la hora.
	 * \coste Constante
	 */
	int pasar_a_seg();

	/**
	 * @brief Restar una hora a otra.
	 * \pre cierto
	 * \post Se resta h a la hora.
	 * \coste Constante
	 */
	void restar_horas(Hora h);

	/**
	 * @brief Escribir una hora.
	 * \pre cierto
	 * \post Se escribe la hora en la salida.
	 * \coste Constante
	 */
	void escribir_hora() const;

private:
	/**
	 * @brief Número de horas.
	 */
	int horas;
	/**
	 * @brief Número de minutos.
	 */
	int minutos;
	/**
	 * @brief Número de segundos.
	 */
	int segundos;

};
#endif
