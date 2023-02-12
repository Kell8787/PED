#include <iostream>

using namespace std;

struct Pizzas
{
    string nombre;
    float precio;
    int porciones;
};

struct Pila
{
    Pizzas datos;
    Pila *siguiente;
};

void initialize();
bool empty();
void push(Pizzas pizza);
Pizzas pop();
Pizzas top();
void contador();
void mostrarEliminar();

Pila *stack;

int main()
{

    initialize();
    int opcion = 0;

    Pizzas pepperoni = {"Pizza de Pepperoni", 15.99, 12};
    Pizzas hongos = {"Pizza de Hongos", 19.99, 16};
    Pizzas jamon = {"Pizza de Jamon", 11.99, 8};

    push(pepperoni);
    push(hongos);
    push(jamon);

    bool continuar = true;

    do
    {
        cout << "-------------Menu----------------\n";
        cout << "1) Mostrar y Eliminar.\n 2)Mostrar numero de Elementos. \n  3)Salir.\n";
        cout << "Su opcion elegida es: ";
        cin >> opcion; cin.ignore();

        switch (opcion)
        {
        case 1:
            mostrarEliminar();
            break;
        case 2:
            contador(); 
            break;
        case 3: 
            continuar = false ;
            break;
        default: 
            cout << "Opcion erronea." << endl;
            break;
        }
    } while (continuar);

    return 0;
}

void initialize()
{
    stack = NULL;
}

bool empty()
{
    return stack == NULL;
}

void push(Pizzas pizza)
{
    Pila *unNodo = new Pila;
    unNodo->datos = pizza;
    unNodo->siguiente = stack;

    stack = unNodo;
}

Pizzas pop()
{
    if (!empty())
    {
        Pila *unNodo = stack;
        Pizzas pizza = stack->datos;
        stack = stack->siguiente;

        delete (unNodo);
        return pizza;
    }
    else
    {
        return {" ", 0, 0};
    }
}

Pizzas top()
{
    if (!empty())
    {
        return stack->datos;
    }
    else // Underflow!
    {
        return {" ", 0, 0};
    }
}


void mostrarEliminar()
{

    if (!empty())
        cout << "La pila no esta vacia!!\n\n";

    // Mostrar la información de la pila
    // Continuar hasta que la pila este vacia
    while (!empty())
    {
        Pizzas uPizza = top();
        cout << "\n-------------------------------------\n";
        cout << "Nombre: " << uPizza.nombre << "\n";
        cout << "Precio: " << uPizza.precio << "\n";
        cout << "Porciones: " << uPizza.porciones << "\n";
        cout << "-------------------------------------\n";

        // Eliminando la dona de arriba de la pila
        pop();
    }
}

void contador()
{  
    int i=1;
    Pila *unNodo=stack;

    if(!empty())
    {
        while (unNodo->siguiente != NULL)
            {
            unNodo = unNodo->siguiente;
            i++;
            }

        cout << "La cantidad de pizzas es " << i << endl;
    }
}
