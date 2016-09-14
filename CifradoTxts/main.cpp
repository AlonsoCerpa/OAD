#include <iostream>
#include <vector>
#include <fstream>

#include "inversoMult.h"
#include "emisor.h"
#include "receptor.h"

using namespace std;

//Cifrado Afín

string alfabeto{"abcdefghijklmnopqrstuvwxyz \n"};
int alfabetoLength = alfabeto.length();

int main()
{
    int clave, inverso, cteDesplazamiento;
    string cadenaMensaje, auxCadena, cifradoCadena, descifradoCadena;
    InversoMultModular invMult(alfabetoLength);

    ifstream mensaje;
    fstream cifrado;
    ofstream descifrado;

    mensaje.open("/home/alonso/Escritorio/Cifrados/CifradoTxts/mensaje");
    cifrado.open("/home/alonso/Escritorio/Cifrados/CifradoTxts/cifrado");
    descifrado.open("/home/alonso/Escritorio/Cifrados/CifradoTxts/descifrado");    

    while (std::getline(mensaje, auxCadena))
    {
        cadenaMensaje += auxCadena;
        cadenaMensaje += '\n';
    }
    cout << "ingrese una clave: ";
    cin >> clave;
    
    while (invMult.inversoMult(clave) == -1)
    {
        cout << "ingrese una clave: ";
        cin >> clave;
    }

    cteDesplazamiento = 3;

    Emisor emisor(clave, cteDesplazamiento);
    cifradoCadena = emisor.cifrar(cadenaMensaje);
    cout << cifradoCadena << endl;
    cifrado << cifradoCadena;

    inverso = invMult.inversoMult(clave);
    Receptor receptor(inverso, cteDesplazamiento);
    descifradoCadena = receptor.descifrar(cifradoCadena);
    cout << descifradoCadena << endl;
    descifrado << descifradoCadena;

    mensaje.close();
    cifrado.close();
    descifrado.close();

    return 0;
}
