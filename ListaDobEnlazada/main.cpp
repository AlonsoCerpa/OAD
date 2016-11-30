#include <iostream>

using namespace std;

class Nodo
{
public:
    Nodo(int d, Nodo *_ant = nullptr, Nodo *_sig = nullptr)
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

    while (aux2 != nullptr)
    {
        aux = aux2;
        aux2 = aux->sig;
        delete aux;
    }
}

void Lista::insertarInicio(int d)
{
    if (listaVacia())
    {
        Nodo *nuevo = new Nodo(d);
        cabeza = nuevo;
        cola = nuevo;
    }
    else
    {
        Nodo *nuevo = new Nodo(d, nullptr, cabeza);
        cabeza->ant = nuevo;
        cabeza = nuevo;
    }
    ++cont;
}

void Lista::insertarFinal(int d)
{
    if (listaVacia())
    {
        Nodo *nuevo = new Nodo(d);
        cabeza = nuevo;
        cola = nuevo;
    }
    else
    {
        Nodo *nuevo = new Nodo(d, cola);
        cola->sig = nuevo;
        cola = nuevo;
    }
    ++cont;
}

void Lista::insertar(int d, unsigned pos)
{
    if (listaVacia())
    {
        Nodo *nuevo = new Nodo(d);
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
            else
            {
                auxNodo = nuevo->ant;
                auxNodo->sig = nuevo;
            }
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
    Nodo *aux1, *elim;
    while (aux != nullptr && aux->dato != d)
    {
        aux = aux->sig;
    }
    if (aux == nullptr)
        return;        //No se encontro el dato a eliminar

    elim = aux;

    if (aux == cabeza)
    {
        aux = aux->sig;
        cabeza = aux;
        aux->ant = nullptr;
    }
    else if (aux == cola)
    {
        aux1 = aux->ant;
        cola = aux1;
        aux1->sig = nullptr;
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

    while (aux != nullptr && aux->dato != d)
    {
        aux = aux->sig;
        ++i;
    }

    if (aux == nullptr)
    {
        return -1;     //Dato no encontrado
    }
    else
    {
        return i;
    }
}

void Lista::mostrar()
{
    Nodo *aux = cabeza;
    while (aux != nullptr)
    {
        cout << aux->dato << endl;
        aux = aux->sig;
    }
}

int main()
{
    Lista lista;

    for (int i = 0; i < 10; ++i)
    {
        lista.insertarInicio(i);
    }
    lista.insertar(23, 0);  //Dato 23, posicion 0
    lista.insertar(99, 10);
    lista.insertar(42, 3);
    lista.insertarFinal(798);   //cola->dato = 798
    cout << "Mostrando nodos:" << endl;
    lista.mostrar();
    cout << "Largo de la lista: ";
    cout << lista.length() << endl << endl;

    cout << "Eliminando el nodo con el dato 2." << endl;
    lista.eliminar(2);
    cout << "Mostrando nodos:" << endl;
    lista.mostrar();
    cout << "Largo de la lista: ";
    cout << lista.length() << endl << endl;

    cout << "Buscando el nodo con el dato 24:" << endl;
    int posDato = lista.buscar(24);
    if (posDato == -1)
        cout << "No se encontro el nodo" << endl << endl;
    else
        cout << "Se encontro el nodo en la posicion: " << posDato << endl << endl;

    cout << "Buscando el nodo con el dato 42:" << endl;
    posDato = lista.buscar(42);
    if (posDato == -1)
        cout << "No se encontro el nodo" << endl << endl;
    else
        cout << "Se encontro el nodo en la posicion: " << posDato << endl << endl;

    return 0;
}
