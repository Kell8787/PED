/*************************************************************************************
Crear un sistema de gestión de colas para un taller, el cual solicite modelo, placa y color
de los autos al entrar en la cola, debe incluir funciones para agregar un automóvil nuevo,
mostrar la cola completa y eliminar el primer automóvil de la cola por medio de un menú.
*************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include "queue.cpp"

using namespace std;

int montoTotal = 0;
Cola cola_carros;

// Funciones.
void agregarCarros();
void mostrarCarros(Carro carro, bool cobrar);
void mostrarTamanio(Cola *q);
void consultarColaCarros(Cola *q);
void mostrarColaVacia();
void eliminarCarro(Cola *q);

int main(){

    inicializar(&cola_carros);
    bool continuar = true;

    cout << "--- Taller cambio de aceite para vehiculos ---\n";

    do
    {
        int opcion = 0;
        cout << "\n1) Agregar carro.";
        cout << "\n2) Consultar fila.";
        cout << "\n3) Mostrar tamanio de la fina.";
        cout << "\n4) Despachar cliente.";
        cout << "\n5) Salir.";
        cout << "\nSu opcion elegida es: ";
        cin >> opcion; cin.ignore();

        switch (opcion)
        {
        case 1:
            agregarCarros();
            break;
        case 2:
            consultarColaCarros(&cola_carros);
            break;
        case 3:
            mostrarTamanio(&cola_carros);
            break;
        case 4:
            eliminarCarro(&cola_carros);
            break;
        case 5:
            cout << montoTotal << "\n";
            continuar = false;
            break;
        default:
            cout << "Su opcion fue erronea!";
            break;
        }
    } while (continuar);
    
}

void agregarCarros(){
    Carro nuevo_carro;

    cout << "--------------------------------\n";
    cout << "--- Agregando nuevo carro a la fila ---\n";
    cout << "Ingrese el modelo del carro: ";
    getline(cin, nuevo_carro.modelo);
    cout << "\nIngrese el color del carro: ";
    getline(cin, nuevo_carro.color);
    cout << "\nIngrese el numero de placa: ";
    getline(cin, nuevo_carro.placa);
    
    
    // Agrego el nuevo carro en la cola de Carros.
    enCola(&cola_carros, nuevo_carro);
}

void mostrarCarros(Carro carro, bool cobrar = false){
    cout << "Carro: " << carro.modelo << "\n";
    cout << "Color: " << carro.color << "\n";
    cout << "Numero de Placa: " << carro.placa << "\n";

    if (cobrar)
    {
        int valor = 25 + rand() % 100;
        int PRECIO_ARREGLAR_CARRO = valor;
        
        cout << "Total a pagar: $" << (carro.precio * PRECIO_ARREGLAR_CARRO) << "\n"; 
        montoTotal += (carro.precio * PRECIO_ARREGLAR_CARRO); 
    }
    
    cout << "--------------------------------\n";
}

void consultarColaCarros(Cola *q){
    if (empty(q)){
        mostrarColaVacia();
        return ;
    }

    Nodo *unNodo = q->frente;
    cout << "----------- INICIO -------------\n";
    cout << "--------------------------------\n";
    mostrarCarros(unNodo->elemento);

    while (unNodo->siguiente != NULL)
    {
        unNodo = unNodo->siguiente;
        cout << "--------------------------------\n";
        mostrarCarros(unNodo->elemento);
    }
    cout << "------------ FINAL -------------\n";
}

void mostrarTamanio(Cola *q){
    int tamanio = tamanioCola(q);
    cout << "\nEl numero de carros es: " << tamanio << "\n";
}

void eliminarCarro(Cola *q){
    if(empty(q)){
        mostrarColaVacia();
        return ;
    }
    Carro carro = desCola(q);
    cout << "------- DESPACHANDO CLIENTE -------\n";
    mostrarCarros(carro, true);
}


void mostrarColaVacia(){
    cout << "\n--------------------------------\n";
    cout << "Cola vacia!\n";
    cout << "--------------------------------\n";
}
