#include <iostream>

using namespace std;

void funcionEdad(int *, int numEdad);
void imprimirEdades(int *edad, int numEdad);

int main(){

    int cantidad, *edades;
    cout << "Cantidad de edades: ";
    cin >> cantidad;

    edades = new int [cantidad];

    funcionEdad(edades,cantidad);
    
    imprimirEdades(edades, cantidad);


    return 0;
}


void funcionEdad(int *edad, int numeEdad){

    for (int i = 0; i < numeEdad; i++)
    {
        cout << "Ingrese la edad: ";
        cin >> edad[i];
    }
    
}

void imprimirEdades(int *edad, int numEdad){
    
    for (int i = 0; i < numEdad; i++)
    {
        cout << "La edad en la posicion [" << i <<"] es: " << edad[i] << endl;
    }
    
}