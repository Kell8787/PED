#include <iostream>

using namespace std;

int main(){
   
//Actividad no evaluada aplicar sizeof() para conocer el tamaño del arreglo
//Solicitar usuario los valores y el tamaño del arreglo 
//Colocar en función el método inserción

   //Declarar un arreglo 
   int arreglo[]={4,2,1,5,6};
   //Almacenar la posición
   int pos; 
   //Almacenar el elemento cambio
   int aux; 

    //Método de inserción
    //Recorrido del arreglo
    for (int i = 0; i < 5; i++)
    {
        //posición actual
        pos = i;
        //Número del arreglo
        aux = arreglo[i];
        //Comparación con el número de la izquierda
        while ((pos>0)&&(arreglo[pos-1]>aux))
        {
            //Cambio con el número de la izquierda
            arreglo[pos] = arreglo[pos-1];
            //Iteraciones hacia atras
            pos--;
        }
        //Refrescar cada iteración
        arreglo[pos] = aux;
    }
    
    //Imprimir 
    for (int i = 0; i < 5; i++)
    {
        cout<<arreglo[i]<<endl;
    }
    
    

    return 0;
}