#include <iostream>

using namespace std;

int horaMinutos(int *ptr_hora);

int main(){

    int hora;
    int *horaMinuto;

    horaMinuto= &hora;

    cout << "Ingrese la hora: ";
    cin >> hora;

    cout << hora << " en minutos es: " << horaMinutos(horaMinuto) << endl;

    return 0;
}


int horaMinutos(int *ptr_hora){

    return *ptr_hora * 60;
}