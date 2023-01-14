#include <iostream>

using namespace std;

int main(){

    int numeroUsuario;

    int *dir_Numero;

    cout<<"Ingrese un numero entero: ";
    cin>>numeroUsuario; cin.ignore();

    dir_Numero = &numeroUsuario;    // Guardando la posicion de memoria de mi variable numero en mi puntero

    if(*dir_Numero%2==0){
        cout<<"El numero "<<*dir_Numero<<" es par."<<endl;
        cout<<"Su direccion de memoria es: "<<dir_Numero<<endl;
    }
    else{
        cout<<"El numero "<<*dir_Numero<<" es impar."<<endl;
        cout<<"Su direccioin de memoria es: "<<dir_Numero<<endl;
    }



    return 0;

}