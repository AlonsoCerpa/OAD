#include <iostream>

using namespace std;

class Nodo
{
public:
    Nodo(int d, Nodo *_ant, Nodo *_sig)
        : dato(d), ant(_ant), sig(_sig) {}
private:
    int dato;
    Nodo *ant;
    Nodo *sig;

friend class Lista;
};

class Lista
{
public:
    Lista() : cabeza(nullptr), cola(nullptr), cont(0) {}
    ~Lista();
    void insertarInicio(int d);
    void insertarFinal(int d);
    void insertar(int d, unsigned pos);
    void eliminar(int d);
    void eliminarPos(unsigned p);
    bool listaVacia() {return cabeza == nullptr;}
    void mostrar();
    int buscar(int d);
    unsigned length() {return cont;}

private:
    Nodo *cabeza;
    Nodo *cola;
    unsigned cont;
};

Lista::~Lista()
{
    Nodo *aux;
    Nodo *aux2 = cabeza;

    while (cont > 0)
    {
        aux = aux2;
        aux2 = aux->sig;
        delete aux;
        --cont;
    }
}

void Lista::insertarInicio(int d)
{
    if (listaVacia())
    {
        Nodo *nuevo = new Nodo(d, nuevo, nuevo);
        cabeza = nuevo;
        cola = nuevo;
    }
    else
    {
        Nodo *nuevo = new Nodo(d, cola, cabeza);
        cabeza->ant = nuevo;
        cola->sig = nuevo;
        cabeza = nuevo;
    }
    ++cont;
}

void Lista::insertarFinal(int d)
{
    if (listaVacia())
    {
        Nodo *nuevo = new Nodo(d, nuevo, nuevo);
        cabeza = nuevo;
        cola = nuevo;
    }
    else
    {
        Nodo *nuevo = new Nodo(d, cola, cabeza);
        cola->sig = nuevo;
        cabeza->ant = nuevo;
        cola = nuevo;
    }
    ++cont;
}

void Lista::insertar(int d, unsigned pos)
{
    if (listaVacia())
    {
        Nodo *nuevo = new Nodo(d, nuevo, nuevo);
        cabeza = nuevo;
        cola = nuevo;
    }
    else
    {
        unsigned aux = cont / 2;
        if (pos < aux)
        {
            Nodo *auxNodo = cabeza;
            for (unsigned i = 0; i < pos; ++i)
            {
                auxNodo = auxNodo->sig;
            }
            Nodo *nuevo = new Nodo(d, auxNodo->ant, auxNodo);
            auxNodo->ant = nuevo;
            if (cabeza == auxNodo)
            {
                cabeza = nuevo;
            }
            auxNodo = nuevo->ant;
            auxNodo->sig = nuevo;
        }
        else
        {
            Nodo *auxNodo = cola;
            pos = (cont - 1) - pos;
            for (unsigned i = 0; i < pos; ++i)
            {
                auxNodo = auxNodo->ant;
            }
            Nodo *nuevo = new Nodo(d, auxNodo->ant, auxNodo);
            auxNodo->ant = nuevo;
            auxNodo = nuevo->ant;
            auxNodo->sig = nuevo;
        }
    }
    ++cont;
}

void Lista::eliminar(int d)
{
    Nodo *aux = cabeza;
    unsigned i = 0;
    Nodo *elim, *aux1;

    while (i < cont && aux->dato != d)
    {
        aux = aux->sig;
        ++i;
    }
    if (i == cont)
    {
        return;
    }

    elim = aux;

    if (aux == cabeza)
    {
        aux = aux->sig;
        cabeza = aux;
        aux->ant = cola;
        cola->sig = aux;
    }
    else if (aux == cola)
    {
        aux = aux->ant;
        cola = aux;
        aux->sig = cabeza;
        cabeza->ant = aux;
    }
    else
    {
        aux1 = aux->ant;
        aux1->sig = aux->sig;
        aux = aux->sig;
        aux->ant = aux1;
    }

    --cont;
    delete elim;
}

void Lista::eliminarPos(unsigned p)
{
    Nodo *aux = cabeza;
    Nodo *elim, *aux1;
    unsigned i = 0;

    if (p >= cont)
        return;

    while (i < p)
    {
        aux = aux->sig;
        ++i;
    }

    elim = aux;

    if (aux == cabeza)
    {
        aux = aux->sig;
        cabeza = aux;
        aux->ant = cola;
        cola->sig = aux;
    }
    else if (aux == cola)
    {
        aux = aux->ant;
        cola = aux;
        aux->sig = cabeza;
        cabeza->ant = aux;
    }
    else
    {
        aux1 = aux->ant;
        aux1->sig = aux->sig;
        aux = aux->sig;
        aux->ant = aux1;
    }

    --cont;
    delete elim;
}

int Lista::buscar(int d)
{
    Nodo *aux = cabeza;
    int i = 0;

    while (i < cont && aux->dato != d)
    {
        aux = aux->sig;
        ++i;
    }

    if (i == cont)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

void Lista::mostrar()
{
    Nodo *aux = cabeza;
    unsigned i = 0;

    while (i < cont)
    {
        cout << aux->dato << " ";
        aux = aux->sig;
        ++i;
    }
    cout << endl;
}

unsigned josephus(unsigned nPersonas, unsigned cadaMejecutados)
{
    unsigned i = 0;
    Lista soldadosJudios;

    while (i < nPersonas)
    {
        soldadosJudios.insertarFinal(i);
        ++i;
    }

    i = 0;
    while (soldadosJudios.length() > 1)
    {
        soldadosJudios.mostrar();
        i += cadaMejecutados;
        if (i >= soldadosJudios.length())
            i %= soldadosJudios.length();
        soldadosJudios.eliminarPos(i);
        --i;
    }
    soldadosJudios.mostrar();
}

int main()
{
    Lista lista;

    lista.insertarInicio(4);
    lista.mostrar();
    cout << endl;

    lista.insertarInicio(8);
    lista.mostrar();
    cout << endl;

    lista.insertarFinal(32);
    lista.mostrar();
    cout << endl;

    lista.insertarFinal(147);
    lista.mostrar();
    cout << endl;

    lista.insertar(78, 2);
    lista.mostrar();
    cout << endl;

    lista.eliminar(32);
    lista.mostrar();
    cout << endl;

    lista.eliminar(147);
    lista.mostrar();
    cout << endl;

    cout << lista.buscar(78) << endl;

    cout << "Josephus:" << endl;
    josephus(41, 3);

    return 0;
}
