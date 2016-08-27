#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int *vueltoSoles(int vuelto, std::vector<int> monedasBilletes)
{
    int *vueltoArray = new int[8];
    int contador;

    for (int i = 0; i < 8; ++i)
        vueltoArray[i] = 0;

    if (vuelto < 0 || vuelto > 9999)
    {
        cout << "Vuelto invalido" << endl;
        return vueltoArray;
    }

    for (int i = 0; vuelto > 0 && i < 8; ++i)
    {
        if ((contador = vuelto / monedasBilletes[i]) > 0)
        {
            vueltoArray[i] = contador;
            vuelto %= contador * monedasBilletes[i];
        }
    }
    return vueltoArray;
}

void imprimirVuelto(int *vuelto1, std::vector<int> monedasBilletes)
{
    for (unsigned i = 0; i < monedasBilletes.size(); ++i)
    {
        cout << vuelto1[i];
        if (monedasBilletes[i] >= 10)
        {
            cout << " billete";
            if (vuelto1[i] != 1)
                cout <<"s";
        }
        else
        {
            cout << " moneda";
            if (vuelto1[i] != 1)
                cout << "s";
        }
        cout << " de " << monedasBilletes[i] << " sol";

        if (i != 7)
            cout << "es" << endl;
    }
    cout << endl;
}

int main()
{
    std::vector<int> monedasBilletes = {200, 100, 50, 20, 10, 5, 2, 1};
    int vuelto = 0;
    int *vuelto1;

    cout << "Programa 1: Vuelto en soles" << endl;
    cout << "Ingrese -1 para acabar" << endl << endl;

    cout << "Dinero: ";
    std::cin >> vuelto;
    cout << endl;

    while (vuelto != -1)
    {
        vuelto1 = vueltoSoles(vuelto, monedasBilletes);
        imprimirVuelto(vuelto1, monedasBilletes);
        cout << endl;
        cout << "Dinero: ";
        std::cin >> vuelto;
        cout << endl;
    }

    return 0;
}
