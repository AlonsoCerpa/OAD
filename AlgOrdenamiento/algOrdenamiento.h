#ifndef ALGORDENAMIENTO_H_INCLUDED
#define ALGORDENAMIENTO_H_INCLUDED

#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void bubbleSort(int *firstElem, int *lastElem)
{
	int *auxFirst = firstElem;
	bool intercambio = true;

	while (intercambio)
	{
		intercambio = false;
		for (firstElem = auxFirst; firstElem != lastElem; ++firstElem)
		{
			if (*firstElem > *(firstElem + 1))
			{
				swap(firstElem, firstElem + 1);
				intercambio = true;
			}
		}
		--lastElem;
	}
}

void cocktailSort(int *firstElem, int *lastElem)
{
	int *variablePos;
	bool intercambio = true;
	bool subida = true;

	while (intercambio)
	{
		intercambio = false;

		if (subida)
		{
			for (variablePos = firstElem; variablePos != lastElem; ++variablePos)
			{
				if (*variablePos > *(variablePos + 1))
				{
					swap(variablePos, variablePos + 1);
					intercambio = true;
				}
			}
			subida = false;
			--lastElem;
		}

		else
		{
			for (variablePos = lastElem; variablePos != firstElem; --variablePos)
			{
				if (*variablePos < *(variablePos - 1))
				{
					swap(variablePos, variablePos - 1);
					intercambio = true;
				}
			}
			subida = true;
			++firstElem;
		}
	}
}

void selectionSort(int *firstElem, int *lastElem)
{
	int *variablePos;
	int *posMenorElem;

	for ( ; firstElem < lastElem; ++firstElem)
	{
		variablePos = firstElem;
		posMenorElem = variablePos;
		++variablePos;

		for ( ; variablePos <= lastElem; ++variablePos)
		{
			if (*posMenorElem > *variablePos)
				posMenorElem = variablePos;
		}
		swap(posMenorElem, firstElem);
	}
}

void insertionSort(int *firstElem, int *lastElem)
{
	int *variablePos;
	int *auxFirst;

	if (firstElem != lastElem)
	{
		for (auxFirst = firstElem + 1; auxFirst <= lastElem; ++auxFirst)
		{
			for (variablePos = auxFirst; variablePos > firstElem; --variablePos)
			{
				if (*variablePos < *(variablePos - 1))
					swap(variablePos, variablePos - 1);
			}			
		}
	}
}

void quickSort(int *first, int *last)
{
	int pivot = *(first + (last - first) / 2);
	int aux;
	int *auxFirst = first;
	int *auxLast = last;

	while (first <= last)
	{
		while (*(first) < pivot)
			++first;
		while (*(last) > pivot)
			--last;
		if (first <= last)
		{
			swap(first, last);
			++first;
			--last;
		}
	}

	if (auxFirst < last)
		quickSort(auxFirst, last);
	if (first < auxLast)
		quickSort(first, auxLast);
}



#endif //ALGORDENAMIENTO_H_INCLUDED