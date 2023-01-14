#include <iostream>

using namespace std;

int main()
{

    int arreglo[10];

    int *puntero_arreglo;

    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese un numero[" << i << "]: ";
        cin >> arreglo[i];
    }

    puntero_arreglo = arreglo;

    for (int i = 0; i < 10; i++)
    {
        if (*puntero_arreglo % 2 == 0)
        {
            cout << "El numero " << *puntero_arreglo << " es par." << endl;
            cout << "Su posicion de memoria es: " << puntero_arreglo << endl;
        }

        else
        {
            cout << "El numero " << *puntero_arreglo << " es impar." << endl;
            cout << "Su posicion de memoria es: " << puntero_arreglo << endl;
        }
        
        puntero_arreglo++;
    }

    return 0;
}