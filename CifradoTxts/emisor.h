#ifndef EMISOR_H_INCLUDED
#define EMISOR_H_INCLUDED

#include <string>

#include "funciones.h"

using std::string;

extern string alfabeto;
extern int alfabetoLength;

class Emisor
{
public:
	Emisor(int cteDecimacion, int cteDesplazamiento)
	{
		if (cteDecimacion == 1)  //Desplazamiento puro
		{
			for (int i = 0; i < alfabetoLength; ++i)
			{
				alfabetoCifrado += alfabeto[modulo(i + cteDesplazamiento, alfabetoLength)];
			}
		}

		else if (cteDesplazamiento == 0)  //Decimacion pura
		{
			for (int i = 0; i < alfabetoLength; ++i)
			{
				alfabetoCifrado += alfabeto[modulo(cteDecimacion * i, alfabetoLength)];
			}
		}

		else                        //Sustitucion afin
		{
			for (int i = 0; i < alfabetoLength; ++i)
			{
				alfabetoCifrado += alfabeto[modulo((cteDecimacion * i) + cteDesplazamiento, alfabetoLength)];
			}
		}
	}

	string cifrar(string mensaje)
	{
		string mensajeCifrado;

		int mensajeLength = mensaje.length();

		for (int i = 0; i < mensajeLength; ++i)
		{
			mensajeCifrado += alfabetoCifrado[alfabeto.find(mensaje[i])];
		}

		return mensajeCifrado;
	}

private:
	string alfabetoCifrado;
};

#endif //EMISOR_H_INCLUDED