#include <iostream>

using namespace std;

int main()
{
    int numero;

    int *dir_num; // Direccion de memoria de numero
    dir_num = &numero;

    numero = 20;

    cout << "Numero: " << numero << endl;
    cout << "Direccion de memoriua de: " << &numero << endl; //& + cualquier variable significa la direccion de memoria de cualquier variable

    cout << "Numero pero desde el puntero: " << *dir_num << endl;
    cout << "Direccion de memoria de: " << dir_num << endl;

    return 0;
}