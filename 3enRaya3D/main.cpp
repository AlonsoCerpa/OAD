#include <iostream>

using namespace std;

int main()
{
    int tablero[3][3][3];
    int lenTablero = 27;
    int i, j, k;
    bool partida = true;
    char jugada[3];
    int jugador = 1;
    int contJugadas = 0;
    int aux, aux1;

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            for (k = 0; k < 3; ++k)
                *(*(*(tablero +i) +j) +k) = 0;
        }
    }

    while (partida)
    {
        cout << "Jugador " << jugador << ": ";
        cin >> jugada;

        i = *jugada - '0';
        j = *(jugada + 1) - '0';
        k = *(jugada + 2) - '0';

        *(*(*(tablero +i) +j) +k) = jugador;

        if (jugador == 1)
            ++jugador;
        else
            --jugador;

        for (i = 0; i < 3; ++i)  //Filas
        {
            for (j = 0; j < 3; ++j)
            {
                aux = *(*(*(tablero +i) +j) +0);
                aux1 = aux;
                for (k = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && k < 3; ++k)
                {
                    aux1 = *(*(*(tablero +i) +j) +k);
                }
                if (k == 3 && aux == aux1)
                {
                    partida = false;
                    cout << "Gano el jugador " << aux1 << endl;
                }
            }
        }

        for (i = 0; i < 3; ++i)  //Columnas
        {
            for (k = 0; k < 3; ++k)
            {
                aux = *(*(*(tablero +i) +0) +k);
                aux1 = aux;
                for (j = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && j < 3; ++j)
                {
                    aux1 = *(*(*(tablero +i) +j) +k);
                }
                if (j == 3 && aux == aux1)
                {
                    partida = false;
                    cout << "Gano el jugador " << aux1 << endl;
                }
            }
        }

        for (i = 0; i < 3; ++i) //Diagonales
        {
            aux = *(*(*(tablero +i) +0) +0);
            aux1 = aux;
            for (j = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && j < 3; ++j)
            {
                aux1 = *(*(*(tablero +i) +j) +j);
            }
            if (j == 3 && aux == aux1)
            {
                partida = false;
                cout << "Gano el jugador " << aux1 << endl;
            }

            aux = *(*(*(tablero +i) +0) +2);
            aux1 = aux;
            for (j = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && j < 3; ++j)
            {
                aux1 = *(*(*(tablero +i) +j) +(2 - j));
            }
            if (j == 3 && aux == aux1)
            {
                partida = false;
                cout << "Gano el jugador " << aux1 << endl;
            }
        }

        for (j = 0; j < 3; ++j) //Filas inversas
        {
            for (k = 0; k < 3; ++k)
            {
                aux = *(*(*(tablero +0) +j) +k);
                aux1 = aux;
                for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
                {
                    aux1 = *(*(*(tablero +i) +j) +k);
                }
                if (i == 3 && aux == aux1)
                {
                    partida = false;
                    cout << "Gano el jugador " << aux1 << endl;
                }
            }
        }

        for (j = 0; j < 3; ++j)  //Diagonales inversas
        {
            aux = *(*(*(tablero +0) +j) +0);
            aux1 = aux;
            for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
            {
                aux1 = *(*(*(tablero +i) +j) +i);
            }
            if (i == 3 && aux == aux1)
            {
                partida = false;
                cout << "Gano el jugador " << aux1 << endl;
            }

            aux = *(*(*(tablero +0) +j) +2);
            aux1 = aux;
            for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
            {
                aux1 = *(*(*(tablero +i) +j) +(2 - i));
            }
            if (i == 3 && aux == aux1)
            {
                partida = false;
                cout << "Gano el jugador " << aux1 << endl;
            }
        }

        //Diagonales 2D - 3 planos
        aux = *(*(*(tablero +0) +0) +1);
        aux1 = aux;
        for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
        {
            aux1 = *(*(*(tablero +i) +i) +1);
        }
        if (i == 3 && aux == aux1)
        {
            partida = false;
            cout << "Gano el jugador " << aux1 << endl;
        }

        aux = *(*(*(tablero +0) +2) +1);
        aux1 = aux;
        for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
        {
            aux1 = *(*(*(tablero +i) +(2 - i)) +1);
        }
        if (i == 3 && aux == aux1)
        {
            partida = false;
            cout << "Gano el jugador " << aux1 << endl;
        }

        aux = *(*(*(tablero +0) +1) +0);
        aux1 = aux;
        for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
        {
            aux1 = *(*(*(tablero +i) +1) +i);
        }
        if (i == 3 && aux == aux1)
        {
            partida = false;
            cout << "Gano el jugador " << aux1 << endl;
        }

        aux = *(*(*(tablero +0) +1) +2);
        aux1 = aux;
        for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
        {
            aux1 = *(*(*(tablero +i) +1) +(2 - i));
        }
        if (i == 3 && aux == aux1)
        {
            partida = false;
            cout << "Gano el jugador " << aux1 << endl;
        }

        //Diagonales 3D
        aux = *(*(*(tablero +0) +0) +0);
        aux1 = aux;
        for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
        {
            aux1 = *(*(*(tablero +i) +i) +i);
        }
        if (i == 3 && aux == aux1)
        {
            partida = false;
            cout << "Gano el jugador " << aux1 << endl;
        }

        aux = *(*(*(tablero +0) +0) +2);
        aux1 = aux;
        for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
        {
            aux1 = *(*(*(tablero +i) +i) +(2 - i));
        }
        if (i == 3 && aux == aux1)
        {
            partida = false;
            cout << "Gano el jugador " << aux1 << endl;
        }

        aux = *(*(*(tablero +0) +2) +0);
        aux1 = aux;
        for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
        {
            aux1 = *(*(*(tablero +i) +(2 - i)) +i);
        }
        if (i == 3 && aux == aux1)
        {
            partida = false;
            cout << "Gano el jugador " << aux1 << endl;
        }

        aux = *(*(*(tablero +0) +2) +2);
        aux1 = aux;
        for (i = 1; (aux1 == 1 || aux1 == 2) && aux == aux1 && i < 3; ++i)
        {
            aux1 = *(*(*(tablero +i) +(2 - i)) +(2 - i));
        }
        if (i == 3 && aux == aux1)
        {
            partida = false;
            cout << "Gano el jugador " << aux1 << endl;
        }

        //Impresion de tablero
        cout << "Turno " << contJugadas << endl;
        for (i = 0; i < 3; ++i)
        {
            for (j = 0; j < 3; ++j)
            {
                for (k = 0; k < 3; ++k)
                    cout << *(*(*(tablero +i) +j) +k) << ' ';
                cout << endl;
            }
            cout << endl;
        }

        ++contJugadas;

        if (contJugadas == 27 && partida)
        {
            cout << "Nadie gano el juego" << endl;
            partida = false;
        }
    }

    return 0;
}
