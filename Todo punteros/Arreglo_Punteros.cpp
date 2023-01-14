#include <iostream>

using namespace std;

int main()
{

    int arreglo[] = {1, 2, 3, 4, 5};

    int *dir_numeros;

    dir_numeros = arreglo;

    for (int i = 0; i < 5; i++)
    {
        cout << "Elemento del arreglo [" << i << "]: " << *dir_numeros<< endl;
        *dir_numeros++;

        cout<< "Posicion de memoria de["<<i<<"]: "<<dir_numeros<<endl;
    }
 
    return 0;
}