#include <iostream>

using namespace std;

int Numerodeoperaciones(int numero1, int numero2);

int main()
{
    int primerNumero, segundoNumero;

    cout << "Ingrese un numero: ";
    cin >> primerNumero;
    cin.ignore();

    cout << "Ingrese el segundo numero: ";
    cin >> segundoNumero;
    cin.ignore();

    cout << "El numero de operciones fue:" << Numerodeoperaciones(primerNumero, segundoNumero);
}

int Numerodeoperaciones(int numero1, int numero2)
{

    int numerOperaciones = 0;

    while (numero1 != numero2)
    {
        if (numero1 > numero2 && numero1 % 2 == 0)
        {
            numero1 = numero1 / 2;
            numerOperaciones++;
        }
        else if (numero1 < numero2 || numero1 % 2 != 0)
        {
            numero1 = numero1 + 1;
            numerOperaciones++;
        }
    }

    return numerOperaciones;
}