#ifndef INVERSOMULT_H_INCLUDED
#define INVERSOMULT_H_INCLUDED

#include <vector>

class InversoMultModular
{
public:
    InversoMultModular(int mod) : modulo{mod} {}

    int mod(int num, int modulo);
    int inversa(int cont);
    int inversoMult(int num);

    std::vector<int> cocientes;

private:
    int modulo;
};

#endif // INVERSOMULT_H_INCLUDED
