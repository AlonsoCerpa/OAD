#include <iostream>

using std::cout;
using std::endl;

void numeroLetras(int numero)
{
    std::string numeroString = std::to_string(numero);
    unsigned numeroDigitos = numeroString.length();
    unsigned length = numeroDigitos % 3;
    int cont = 0;
    int auxCont;
    unsigned indexNum = 0;
    unsigned indexMilMillon;
    int auxVar1, auxVar2, auxVar3;
    int auxNum;

    std::string milMillon[3] = {"millon", "mil", ""};

    std::string hasta15[16] = {"", "uno", "dos", "tres", "cuatro",
                               "cinco", "seis", "siete", "ocho", "nueve",
                               "diez", "once", "doce", "trece", "catorce",
                               "quince"};

    std::string del30a90[7] = {"treinta", "cuarenta", "cincuenta", "sesenta",
                               "setenta", "ochenta", "noventa"};

    std::string de100a900[9] = {"ciento", "doscientos", "trescientos",
                                "cuatrocientos", "quinientos", "seiscientos",
                                "setecientos", "ochocientos", "novecientos"};



    if (length == 0)
        length = 3;

    if (numero < 0 || numero > 999999999)
    {
        cout << "Numero invalido" << endl;
        return;
    }

    for (int i = numeroDigitos - 3; i > 0; i -= 3)
        ++cont;

    auxCont = cont;

    indexMilMillon = 2 - cont;


    for ( ; cont >= 0; --cont)
    {
        auxNum = std::stoi(numeroString.substr(indexNum, length)); //Obtiene el numero a evaluar
                                                                   //en cada iteracion
        auxVar2 = auxNum;

        //Evalua centenas
        if (auxNum > 100)
        {
            auxVar1 = auxNum/100;
            cout << de100a900[auxVar1 - 1] << " ";
            auxVar2 = auxNum - (auxVar1 * 100);
        }
        if (auxNum == 0 && auxCont == 0)
            cout << "cero";

        else if (auxNum == 100)
            cout << "cien" << " ";

        //Evalua decenas

        else if (auxVar2 == 1 && auxCont == 2 && cont == auxCont)
            cout << "un" << " ";

        else if (auxVar2 == 1 && ((auxCont == 1 && cont == auxCont) || (auxCont == 2 && cont == auxCont - 1)))
            ;

        else if (auxVar2 <= 15)
            cout << hasta15[auxVar2] << " ";

        else if (auxVar2 >= 16 && auxVar2 <= 19)
            cout << "dieci" << hasta15[auxVar2 - 10] << " ";

        else if (auxVar2 == 20)
            cout << "veinte" << " ";

        else if (auxVar2 >= 21 && auxVar2 <= 29)
            cout << "veinti" << hasta15[auxVar2 - 20] << " ";

        else
        {
            auxVar3 = (auxVar2 / 10);
            cout << del30a90[auxVar3 - 3];
            if ((auxVar2 -= auxVar3 * 10) > 0)
            {
                cout << " y " << hasta15[auxVar2] << " ";
            }
        }

        //Evalua millares o millones
        if (auxNum > 0)
            cout << milMillon[indexMilMillon];
        if (auxCont == 2 && cont == auxCont && (auxVar2 - (auxVar2/10) * 10) > 1)    //Para que se escriba "millones"
            cout << "es";                                                            //en vez de millon
        cout << " ";

        ++indexMilMillon;
        indexNum += length;
        length = 3;
    }

    cout << endl;
}

int main()
{
    int num = 0;

    while(num != -1)
    {
        std::cin >> num;
        numeroLetras(num);
    }

    return 0;
}
