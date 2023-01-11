#include <iostream>

using namespace std;

// Mi estructura
struct DatosPersonales
{
    char nombre[20];
    char deporte[30];
    int edad;

} persona1;

// Prototipos de Funciones
void pedirDatos();
void mostrarDatos(DatosPersonales);

int main()
{
    pedirDatos();
    mostrarDatos(persona1);

    return 0;
}

void pedirDatos()
{
    cout << "Ingrese su nombre: ";
    cin.getline(persona1.nombre, 20, '\n'); /*cin.getline hara que guarde toda la linea de el nombre hasta llegar a un salto de linea, pero con solo 20 espacios, persona1 nos permite ingresar
    a la estructura*/
    cout << "Ingrese su edad: ";
    cin >> persona1.edad; // Como la edad es de tipo entero, facilmente podemos guardarlo con un "cin", la variable persona1, nos permite ingresar a la estructura
    cout << "Ingrese su deporte favorito: ";
    cin.getline(persona1.deporte, 30, '\n');
}

void mostrarDatos(DatosPersonales X)
{ // DatosPersonales sera siempre la estructura y tendra una variable x que accedera a los campos de la estructura (Llama X por conveniencia para no externder la funcion)
    cout << "\n\nNombre: " << X.nombre << endl;
    cout << "Edad: " << X.edad << endl;
    cout << "Deporte: " << X.deporte << endl;
}