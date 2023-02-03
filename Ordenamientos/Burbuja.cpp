#include <iostream>

using namespace std;

int main()
{
    //Actividad no evaluada aplicar sizeof() para conocer el tamaño del arreglo
    //Solicitar usuario los valores y el tamaño del arreglo 
    //Colocar en función el método burbuja 

    // Declaración de un arreglo
    int arreglo[] = {7, 5, 1, 1, 4};
    // Declarar una variable que almacene el valor de intercambio
    int aux;

    /// Método de burbuja
    // Recorrer el arreglo
    for (int i = 0; i < 5; i++)
    {
        // Comparación entre elemento actual y siguiente
        for (int j = 0; j < 5 - 1; j++)
        {
            //Comparación valor actual es mayor a valor siguiente
           if(arreglo[j]>arreglo[j+1]){
            // Intercambio de los valores
            aux = arreglo[j];
            // Número actual es igual al número siguiente
            arreglo[j] = arreglo[j + 1];
            arreglo[j + 1] = aux;
           }
        }
    }

    // Imprimir resultados
    for (int i = 0; i < 5; i++)
    {
        cout<<arreglo[i]<<endl;
    }

    return 0;
}