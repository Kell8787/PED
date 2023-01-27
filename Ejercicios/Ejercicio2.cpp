#include <iostream>

using namespace std;

struct Producto
{
    string nombre;
    float precio;
    string nombreTienda;
    string localidad;

};

void pedirDatos(Producto *X, int n);
void mostrarDatos(Producto *X, int n);

int main(){
    
    int num;

    cout << "Ingrese la cantidad de protuctos: ";
    cin >> num; cin.ignore();

    Producto X[num];

    pedirDatos(X, num);

    bool continuar = true;

    do
    {
        int opcion = 0;
        cout << "\n1) Mostrar lista de productos\n";
        cout << "2) Salir.\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();

        switch(opcion)
        {
            case 1: mostrarDatos(X, num); break;
            case 2: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        } 
    }while (continuar);
    
    
    
    return 0;
}

void pedirDatos(Producto *X, int n){

    Producto X1;

    for (int i = 0; i < n; i++)
    {  
        cout << "\n----------- Productos ---------" << endl;
        cout << "Ingrese el nombre del producto: \n";
        getline(cin, X1.nombre);

        cout << "Ingrese el precio del producto: \n";
        cin >> X1.precio; cin.ignore();

        cout << "Ingrese el nombre de la Tienda: \n";
        getline(cin, X1.nombreTienda);
        
        cout << "Ingrese la localidad de la Tienda: \n";
        getline(cin, X1.localidad);

        X[i] = X1;
    }
}

void mostrarDatos(Producto *X, int n){
    for (int i = 0; i < n ; i++)
    {
        Producto *X1 = &X[i];
        
        cout << "\n\n----------Lista de Productos----------" << endl;
        cout << "--------------Producto ["<< i + 1 <<"]-------------"<< endl;
        cout << "Nombre: " << X1->nombre << "\n";
        cout << "Precio: " << X1->precio << "\n";
        cout << "Tienda: " << X1->nombreTienda << "\n";
        cout << "Localidad: " << X1->localidad << "\n";


    }
    
}