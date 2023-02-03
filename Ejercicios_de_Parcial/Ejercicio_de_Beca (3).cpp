#include <iostream>

using namespace std;

struct datoEstudiante
{
    string nombre;
    float cuota;
    int mesesPagar;
    int beca;
    float descuento;

}estudiante01;

float becaDescuento;

void pedirDatos();
void mostrarDatos();
float descuento(int);

float descuento75();
float descuento45();
float descuento25();



int main(){

    float cuotaFinal;

    pedirDatos();
    mostrarDatos();


    return 0;
}

void pedirDatos()
{

    
    cout << "Ingrese el nombre: \n";
    getline(cin, estudiante01.nombre);
    cout << "Ingrese la cuota: \n";
    cin >> estudiante01.cuota;

    cout << "Ingrese el tipo de beca que tiene: \n";
    cout << " 1- Beca del 75% \n 2- Beca del 45% \n 3- Beca del 25%\n 4- No tiene beca.\n";

    switch (estudiante01.beca)
   {
    case 1:
        descuento75();
    break;

    case 2:
        descuento45();
    break;

    case 3: 
        descuento25();
    break;
    case 4:

   
   default:
    break;
   }
    cin >> estudiante01.beca;

    cout << "Cuanto meses pagara: \n";
    cin >> estudiante01.mesesPagar;

}

float descuento(int)
{   
    float descuentoxd;
    float descuento;

    if (estudiante01.mesesPagar >= 2)
    {
        descuento= estudiante01.cuota*0.15;
    }

    return descuento;
}


float descuento75(){
    float descuento75;
    descuento75=estudiante01.beca*0.75;

    return estudiante01.cuota-descuento75;
}


float descuento45(){
    float descuento45;
    descuento45=estudiante01.beca*0.45;

    return estudiante01.cuota-descuento45;
}


float descuento25(){
    float descuento25;
    descuento25=estudiante01.beca*0.25;

    return estudiante01.cuota-descuento25;
}


void mostrarDatos()
{
    
    cout << "\n-------------------------------------\n";
    cout << "Nombre: " << estudiante01.nombre <<endl;
    cout << "Couta: " << estudiante01.cuota << endl;
    cout << "Cuota Final es con tipo de beca [" << estudiante01.beca << "] y su total a pagar es: " << estudiante01.cuota << endl;
    
    if (estudiante01.mesesPagar>=2)
    {
        cout << "Se le aplico descuento del 15%" << endl;
    }
    else
    {
        cout << "No le se aplico el descuento" << endl;
    }

    cout << "";
    


}
