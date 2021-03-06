#include <iostream>
#include <vector>

#include "inversoModular.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num, mod, resultado;

    cout << "numero: ";
    cin >> num;

    while (num >= 0)
    {
        cout << "mod: ";
        cin.ignore();
        cin >> mod;
        InversoMultModular inversoM(mod);
        resultado = inversoM.inversoMult(num);
        if (resultado == -1)
            cout << "no tiene inverso multiplicativo" << endl << endl;
        else
            cout << "su inverso multiplicativo es: " << resultado << endl << endl;
        cout << "numero: ";
        cin.ignore();
        cin >> num;
    }

    return 0;
}
