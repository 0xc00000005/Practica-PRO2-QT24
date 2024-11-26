#include "Hora.hh"

Hora::Hora()
{
}

Hora::Hora(int h, int m, int s)
{
	horas = h;
	minutos = m;
	segundos = s;
}

void Hora::leer_hora()
{
	char c;
	cin >> horas;
	cin >> c;
	cin >> minutos;
	cin >> c;
	cin >> segundos;
}

bool Hora::menor(Hora h)
{
	return horas < h.horas or (horas == h.horas and minutos < h.minutos) or (horas == h.horas and minutos == h.minutos and segundos < h.segundos);
}

bool Hora::igual(Hora h)
{
	return horas == h.horas and minutos == h.minutos and segundos == h.segundos;
}

void Hora::sumar_segundos(int seg)
{
	minutos += (segundos + seg) / 60;
	segundos = (segundos + seg) % 60;
	if (minutos >= 60)
	{
		horas += minutos / 60;
		minutos = minutos % 60;
	}
}

void Hora::pasar_a_hms(int s)
{
	horas = s / 3600;
	minutos = (s % 3600) / 60;
	segundos = (s % 3600) % 60;
}

int Hora::pasar_a_seg()
{
	return horas * 3600 + minutos * 60 + segundos;
}

void Hora::restar_horas(Hora h)
{
	if (segundos < h.segundos)
	{
		if (minutos > 0)
		{
			--minutos;
			segundos += 60;
		}
		else if (minutos == 0)
		{
			--horas;
			minutos += 59;
			segundos += 60;
		}
	}
	segundos = segundos - h.segundos;
	if (minutos < h.minutos)
	{
		--horas;
		minutos += 60;
	}
	minutos = minutos - h.minutos;
	horas = horas - h.horas;
}

void Hora::escribir_hora() const
{
	if (horas < 10)
		cout << "0";
	cout << horas << ":";
	if (minutos < 10)
		cout << "0";
	cout << minutos << ":";
	if (segundos < 10)
		cout << "0";
	cout << segundos;
}
