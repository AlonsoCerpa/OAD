#ifndef INVERSOMODULAR_H_INCLUDED
#define INVERSOMODULAR_H_INCLUDED

#include <vector>

class InversoMultModular
{
public:
    InversoMultModular(int mod) : modulo{mod} {}

    int mod(int num, int modulo);
    int inversa(int cont);
    int inversoMult(int num);

private:
    int modulo;
    std::vector<int> cocientes;
};

#endif // INVERSOMODULAR_H_INCLUDED
