#include "inversoMult.h"

int InversoMultModular::mod(int num, int modulo1)
{
    if (num < 0)
        num = modulo1 + (num % modulo1);
    return num % modulo1;
}

int InversoMultModular::inversa(int cont)
{
    if (cont == 0)
        return 0;
    else if (cont == 1)
        return 1;
    return mod(inversa(cont - 2) - (inversa(cont - 1) * cocientes[cont - 2]), modulo);
}

int InversoMultModular::inversoMult(int num)
{
    int numInverso;
    int cont, auxNum;
    int sizeCocientes;
    int moduloAux = modulo;

    cocientes.resize(10);

    for (cont = 0; num > 1 ; ++cont)
    {
        if ((sizeCocientes = cocientes.size() + 1) <= cont)
            cocientes.resize(sizeCocientes + 5);

        cocientes[cont] = moduloAux / num;
        auxNum = num;
        num = moduloAux % num;
        moduloAux = auxNum;
    }

    if (num < 1)
        return -1;

    numInverso = inversa(cont + 1);

    return numInverso;
}
