#ifndef HORA_HH
#define HORA_HH

#include <iostream>
using namespace std;

class Hora
{

private:
	int horas;
	int minutos;
	int segundos;

public:
	Hora();

	Hora(int h, int m, int s);

	void leer_hora();

	bool menor(Hora h);

	bool igual(Hora h);

	void sumar_segundos(int seg);

	void pasar_a_hms(int s);

	int pasar_a_seg();

	void restar_horas(Hora h);

	void escribir_hora() const;
};
#endif
