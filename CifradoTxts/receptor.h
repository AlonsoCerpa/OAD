#ifndef RECEPTOR_H_INCLUDED
#define RECEPTOR_H_INCLUDED

#include <string>

#include "emisor.h"
#include "funciones.h"

class Receptor
{
public:
	Receptor(int _invMultCteDec, int _cteDesplazamiento)
		: invMultCteDec{_invMultCteDec}, cteDesplazamiento{_cteDesplazamiento} {}



	string descifrar(string mensajeCifrado)
	{
		string descifrado;
		int cifradoLength = mensajeCifrado.length();

		if (invMultCteDec == 1)  //Desplazamiento puro
		{
			for (int i = 0; i < cifradoLength; ++i)
			{
				descifrado += alfabeto[modulo(alfabeto.find(mensajeCifrado[i]) - cteDesplazamiento, alfabetoLength)];
			}
		}

		else if (cteDesplazamiento == 0)  //Decimacion pura
		{
			for (int i = 0; i < cifradoLength; ++i)
			{
				descifrado += alfabeto[modulo(invMultCteDec * alfabeto.find(mensajeCifrado[i]), alfabetoLength)];
			}
		}

		else                        //Sustitucion afin
		{
			for (int i = 0; i < cifradoLength; ++i)
			{
				descifrado += alfabeto[modulo(invMultCteDec * (alfabeto.find(mensajeCifrado[i]) - cteDesplazamiento), alfabetoLength)];
			}
		}

		return descifrado;
	}


private:
	int invMultCteDec;
	int cteDesplazamiento;
};

#endif //RECEPTOR_H_INCLUDED