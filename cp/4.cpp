#include <iostream>
using namespace std;

struct Ave {
    string nombre;
    string colorPrincipal;
    string fecha;
    bool fotografeado;
};

void fotoAve(Ave *ave);
void selecAvefotografear(Ave *ave, int n);
void almacenarAves(Ave *ave, int n);
void mostrarAve(Ave *ave, int n);
void modificarNombre(Ave *ave, int n);
void modificarColor(Ave *ave, int n);
void validarFoto(Ave *ave, int n);

int main()
{
    int n;
    cout << "Ingrese el numero de mascotas a registrar: \n";
    cin >> n; cin.ignore();
    
    // Declarar arreglo de mascotas
    Ave ave[n];
    // LLenar arreglo de mascotas
    almacenarAves(ave, n);
    
    // Mostrar menu de opciones 
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Mostrar informacion de las Aves\n";
        cout << "2) Fotografear aves\n";
        cout << "3) Modificar el nombre: \n";
        cout << "4) Mofidicar el color del ave: \n";
        cout << "5) Evaluar si la ave ya fue fotografeada: \n";
        cout << "6) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: mostrarAve(ave, n); break;
            case 2: selecAvefotografear(ave, n); break;
            case 3: modificarNombre(ave, n); break;
            case 4: modificarColor(ave, n); break;
            case 5: validarFoto(ave, n); break;
            case 6: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}

void fotoAve(Ave *ave) {
    ave->fotografeado = true;
}

void selecAvefotografear(Ave *ave, int n) {


    // Se solicita al usuario el indice o id
    // de la mascota que este desea vacunar

    int cantidad;
    cout << "Ingrese la ave a fotografear: \n";
    cin >> cantidad; cin.ignore();
    
    // Validar que el indice sea valido
    if (cantidad < 0 || cantidad >= n) {
        cout << "El numero de ave ingresada no es valida.\n";
        return;
    }
    
    // Indireccion a la mascota almacenada  
    // en cierto indice del arreglo
    Ave *ptr_ave = &ave[cantidad];
    fotoAve(ptr_ave);
    cout << "El ave ya ha sido fotografeada.\n";
}

void almacenarAves(Ave *ave, int n) {
    Ave aveActual;
    for (int i = 0; i < n; i++) {
        cout << "---------- Informacion del ave ----------\n";
        cout << "Ingresa el nombre: \n";
        getline(cin, aveActual.nombre);

        cout << "Ingrese el color principal del ave: \n";
        getline(cin, aveActual.colorPrincipal);
        
        cout << "Fecha de ingreso(DD/MM/YY): \n";
        getline(cin, aveActual.fecha);

        // Por defecto ninguna mascota ha sido fotografeada
        aveActual.fotografeado = false;
        
        ave[i] = aveActual;
    }
}

void mostrarAve(Ave *ave, int n) {
    for (int i = 0; i < n; i++) {
        Ave *aveActual = &ave[i];
        cout << "\n\n---------- Informacion del Ave[" << i << "]: ----------\n";
        cout << "Nombre: " << aveActual->nombre << "\n";
        cout << "Color principal: " << aveActual->colorPrincipal << "\n";
        cout << "Fecha de ingreso: " << aveActual->fecha << "\n";
        
        if (aveActual->fotografeado)
            cout << "Esta mascota ha sido fotografeada!\n";
        else
            cout << "Esta mascota NO ha sido fotografeada!\n";
    }
}

void modificarNombre(Ave *ave, int n){
    
    int cantidad;
    cout << "Ingrese la ave a cambiar el nombre: \n";
    cin >> cantidad; cin.ignore();

    if (cantidad < 0 || cantidad >= n) {
        cout << "El numero de ave ingresada no es valida.\n";
        return;
    }

    cout << "Ingrese el nombre: \n";
    cin >> ave[cantidad].nombre;
    
    
}

void modificarColor(Ave *ave, int n){
    
    int cantidad;
    cout << "Ingrese la ave a cambiar el color: \n";
    cin >> cantidad; cin.ignore();

    if (cantidad < 0 || cantidad >= n) {
        cout << "El numero de ave ingresada no es valida.\n";
        return;
    }

    cout << "Ingrese el color del ave: \n";
    cin >> ave[cantidad].colorPrincipal;
    
    
}

void validarFoto(Ave *ave, int n){

    int cantidad;
    cout << "Ingrese la ave a evaluar: \n";
    cin >> cantidad; cin.ignore();

    if (cantidad < 0 || cantidad >= n) {
        cout << "El numero de ave ingresada no es valida.\n";
        return;
    }

    if(ave->fotografeado = true){
        cout << "\n\nYa ha sido fotografeada." << endl;
    }
    else{
        cout << "\n\nLa ave aun no ha sido fotografeada." << endl;
    }
}