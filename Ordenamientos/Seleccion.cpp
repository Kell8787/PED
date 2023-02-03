#include <iostream>

using namespace std;

int main(){

    //Actividad no evaluada aplicar sizeof() para conocer el tamaño del arreglo
    //Solicitar usuario los valores y el tamaño del arreglo 
    //Colocar en función el método selección   

    //Declarar un arreglo 
    int arreglo[] = {4,8,9,55,6,1,3};
    //Almacenar el valor de intercambio
    int aux; 
    //Almacenar el valor minimo
    int min; 

    //Implementar el método de selección
    //Recorrido 
    for (int i = 0; i < 7 ; i++)
    {
        //Hipotesis, que el primer valor del arreglo es el menor
        min = i;
        //Segundo recorrido se inicia en la segunda posición
        for (int j = i + 1; j < 7; j++)
        {
            //Comparación entre elemento actual con el primer valor que se estableció como menor
            if(arreglo[j]<arreglo[min]){
                //Establecer el elemento actual como el menor valor
                min = j;
            }
        }
        //Intercambio de valores del arreglo
        aux = arreglo[i];
        arreglo[i]=arreglo[min];
        arreglo[min] = aux; 
    }

    //Imprimir los valores del arreglo ordenados por el método de selección
    for (int i = 0; i < 7 ; i++)
    {
        cout<<arreglo[i]<<endl;
    }
    




    return 0;
}