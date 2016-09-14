#include <iostream>

#include "algOrdenamiento.h"

using namespace std;

int main()
{	
	int array[] = {8, 7, 4, 2, 1, 10, 4, 6};
	int sizeArray = sizeof(array) / sizeof(int);

	//bubbleSort(array, array + sizeArray - 1);
	//cocktailSort(array, array + sizeArray - 1);
	//selectionSort(array, array + sizeArray - 1);
	//insertionSort(array, array + sizeArray - 1);
	quickSort(array, array + sizeArray - 1);

	for (int i = 0; i < sizeArray; ++i)
	{
		cout << *(array + i) << " ";
	}
	cout << endl;

	return 0;
}