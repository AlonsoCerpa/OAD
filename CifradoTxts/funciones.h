#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int modulo(int a, int b)
{
   if (a >= 0)
       return a - (b  * (a / b));
   return a - (b * ((a / b) - 1));
}

#endif // FUNCIONES_H_INCLUDED