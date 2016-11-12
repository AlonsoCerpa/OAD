#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int numCasillas = 63;
    int tablero[numCasillas];
    int numJugadores;
    int **jugadores;
    bool partida = true;
    int dado;
    int estadoCasilla;
    int *turnosPerdidos;
    int casillaActual;
    int aux;

    cout << "Numero de jugadores: ";
    cin >> numJugadores;
    jugadores = new int*[numJugadores];
    for (int i = 0; i < numJugadores; ++i)
        jugadores[i] = tablero;
    turnosPerdidos = new int[numJugadores];
    for (int i = 0; i < numJugadores; ++i)
        turnosPerdidos[i] = 0;

    srand(time(nullptr));

    //Casillas normales
    for (int i = 0; i < 63; ++i)
        tablero[i] = 0;

    //Casillas especiales
    //Oca
    for (int i = 5; i < 50; i += 9)
        tablero[i] = 1;
    for (int i = 9; i < 63; i += 9)
        tablero[i] = -1;

    //Puente
    tablero[5] = 2;
    tablero[11] = -2;

    //Posada
    tablero[18] = 3;

    //Pozo
    tablero[30] = 4;

    //Laberinto
    tablero[41] = 5;

    //Carcel
    tablero[55] = 6;

    //Dados
    tablero[25] = 7;
    tablero[52] = -7;

    //Calavera
    tablero[57] = 8;

    //Jardín de la Oca
    tablero[62] = 9;

    while (partida)
    {
        for (int i = 0; i < numJugadores && partida; ++i)
        {
            cout << "Jugador " << i << ":" << endl;
            if (turnosPerdidos[i] > 0)
            {
                cout << "-1 turno perdido" << endl;
                --turnosPerdidos[i];
                cout << "Le quedan " << turnosPerdidos[i] << endl;
            }
            else
            {
                casillaActual = jugadores[i] - tablero + 1;
                cout << "Se encuentra en la casilla: " << casillaActual << endl;
                dado = 1 + rand() % 6;
                cout << "Dado: " << dado << endl;
                jugadores[i] += dado;
                if (jugadores[i] >= tablero + numCasillas)
                {
                    aux = jugadores[i] - (tablero + numCasillas - 1);
                    jugadores[i] -= 2 * aux;
                }
                casillaActual = jugadores[i] - tablero + 1;
                cout << "Se encuentra en la casilla: " << casillaActual << endl;
                estadoCasilla = *jugadores[i];

                if (estadoCasilla == 1)
                {
                    cout << "Bien, cayo en la oca, avanza 4" << endl;
                    jugadores[i] += 4;
                    --i;
                    cout << "Tiene un turno adicional" << endl;
                }
                else if (estadoCasilla == -1)
                {
                    cout << "Mal, cayo en la oca, retrocede 4" << endl;
                    jugadores[i] -= 4;
                    --i;
                    cout << "Tiene un turno adicional" << endl;
                }
                else if (estadoCasilla == 2)
                {
                    cout << "Bien, cayo en el puente, avanza la casilla 12" << endl;
                    jugadores[i] += 6;
                    ++turnosPerdidos[i];
                    cout << "Pero perdera un turno" << endl;
                }
                else if (estadoCasilla == -2)
                {
                    cout << "Mal, cayo en el puente, retrocede a la casilla 6" << endl;
                    jugadores[i] -= 6;
                    ++turnosPerdidos[i];
                    cout << "Ademas, perdera un turno" << endl;
                }
                else if (estadoCasilla == 3)
                {
                    cout << "Mal, cayo en la posada, pierde un turno" << endl;
                    ++turnosPerdidos[i];
                }
                else if (estadoCasilla == 4)
                {
                    cout << "Muy mal, cayo en el pozo, pierde dos turnos" << endl;
                    turnosPerdidos[i] += 2;
                }
                else if (estadoCasilla == 5)
                {
                    cout << "Pesimo, cayo en el laberinto, retrocede a la casilla 30" << endl;
                    jugadores[i] -= 12;
                }
                else if (estadoCasilla == 6)
                {
                    cout << "Terriblemente mal, cayo en la carcel, pierde 3 turnos" << endl;
                    turnosPerdidos[i] += 3;
                }
                else if (estadoCasilla == 7)
                {
                    cout << "Excelente cayo en los dados, avanza hasta la casilla 53" << endl;
                    jugadores[i] += 27;
                    cout << "Tiene un turno extra" << endl;
                    --i;
                }
                else if (estadoCasilla == -7)
                {
                    cout << "Que horrible, cayo en los dados, retrocede hasta la casilla 26" << endl;
                    jugadores[i] -= 27;
                    cout << "Tiene un turno extra" << endl;
                    --i;
                }
                else if (estadoCasilla == 8)
                {
                    cout << "Oh no, cayo en la calavera, empieza desde cero" << endl;
                    jugadores[i] = tablero;
                }
                else if (estadoCasilla == 9)
                {
                    cout << "Excelente, ha ganado esta partida" << endl;
                    partida = false;
                }
            }
            cout << endl;
        }
    }
    delete[] jugadores;
    delete[] turnosPerdidos;

    return 0;
}
