#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int calculadoraModular(int modulo, int operando1, int operando2, char operador)
{
    int resultado;

    if (modulo <= 0)
        return -1;

    if (operador == '+' || operador == '-' || operador == '*')
    {
        if (operador == '+')
            resultado = operando1 + operando2;
        else if (operador == '-')
            resultado = operando1 - operando2;
        else if (operador == '*')
            resultado = operando1 * operando2;
        if (resultado < 0)
            resultado *= -1;
        return resultado % modulo;
    }

    else
        return -1;
}

int main()
{
    int modulo, operando1, operando2, resultado;
    char operador;

    cout << "modulo: ";
    cin >> modulo;
    cout << "operando 1: ";
    cin >> operando1;
    cout << "operando 2: ";
    cin >> operando2;
    cout << "operador: ";
    cin >> operador;

    while (modulo != -1)
    {
        resultado = calculadoraModular(modulo, operando1, operando2, operador);
        cout << resultado << endl << endl;
        cout << "modulo: ";
        cin >> modulo;
        cout << "operando 1: ";
        cin >> operando1;
        cout << "operando 2: ";
        cin >> operando2;
        cout << "operador: ";
        cin >> operador;
    }

    return 0;
}
