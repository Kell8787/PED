/**************************************************************************************
Crear un programa de Árbol Binario de Búsqueda con datos enteros, los datos del árbol 
se deberán ingresar a partir de un arreglo ya sea ingresando datos por el usuario o 
quemado, deberá crear una función para mostrar el subárbol izquierdo o derecho (o 
ambos si desean) en los 3 recorridos (InOrder, PreOrder y PostOrder), ademas deberá
crear una funcion que devuelva el menor dato que se encuentra en el árbol y una función 
que devuelva el dato mayor, una función que indique quien es el nodo raíz, la altura y 
cantidad de nodos del árbol.
***************************************************************************************/

#include <iostream>

using namespace std;

struct arbol
{
    int N;
};


typedef int T;

struct numeros
{
    int dato;
    numeros *left;
    numeros *right;
};

typedef struct numeros *Arbol;

int solicitarNumero();
void mostrarNumero(int numero);
enum compararNumer{menorque, mayorque, igualque};
bool compararNumeros(int a, compararNumer operador, int b);

/***********************************************************/
// Inicializando el arbol

Arbol crearArbol(T x);

// Agregar Nodos
void numeroLeft(Arbol a, T numero);
void numeroRight(Arbol a, T numero);
void agregar(Arbol a);
void agregarNodo(Arbol a, T numero);

/***********************************************************/
// Recorrer Arbol

void inOrden(Arbol a);
void preOrden(Arbol a);
void postOrden(Arbol a);
void recorrerArbol(Arbol a);

/***********************************************************/
// Optener el menor dato, el mayor dato y Raiz
void menorNumero(Arbol a);
void mayorNumero(Arbol a);

int main(){

    cout << "Creando Arbol...\n";

    Arbol arbol = crearArbol(65);

    //const int n = 8;
    //int arreglo[n] = {26, 12, 54, 9, 67, 2, 20, 5};

    const int n = 6;
    int arreglo[n] = {39, 70, 23, 50, 68, 82};

    for (int i = 0; i < n; i++)
    {
        agregarNodo(arbol, arreglo[i]);
    }

    bool continuar = true;
    do
    {
        int opcion = 0;

        cout << "\n Menu: \n";
        cout << "1) Agregar \n";
        cout << "2) Recorrer \n";
        cout << "3) Menor numero \n";
        cout << "4) Mayor numero \n";
        cout << "5) Salir. \n";
        cout << "Su opcion es: ";
        cin >> opcion; cin.ignore();
        switch (opcion)
        {
        case 1:
            agregar(arbol);
            break;
        case 2:
            recorrerArbol(arbol);
            break;
        case 3:
            menorNumero(arbol);
            break;
        case 4:
            mayorNumero(arbol);
            break;
        case 5: 
            continuar = false;
            break;
        default:
            cout << "Su opcion no es valida." << endl;
            break;
        }
    } while (continuar);

    return 0;
}

int solicitarNumero(){
    
    int numero = 0;
    cout << "\nIngresar numero: ";
    cin >> numero; cin.ignore();

    return numero;
}

void mostrarNumero(int numero){
    cout << numero;
}

bool compararNumeros(int a, compararNumer operador, int b){
    bool respuesta = false;
    switch (operador)
    {
    case menorque: 
        respuesta = a < b; 
        break;
    case mayorque:
        respuesta = a > b;
        break;
    case igualque:
        respuesta = a == b;
        break;
    }

    return respuesta;
}


Arbol crearArbol(T x){
    Arbol  y = new numeros;
    y -> dato = x;
    y -> left = NULL;
    y -> right = NULL;

    return y;
}

void numeroLeft(Arbol a, T numero){
    if(a==NULL){
        cout << "Arbol Vacio." << endl;
    }

    else if ( a->left != NULL ){
        cout << "Arbol izquierdo ya existe." << endl;
    }

    else{
        a->left = crearArbol(numero);
    }
}

void numeroRight(Arbol a, T numero){
    if(a==NULL){
        cout << "Arbol Vacio." << endl;
    }
    
    else if( a->right != NULL ){
        cout << "Arbol derecho ya existe." << endl;
    }

    else{
        a->right = crearArbol(numero);
    }
}

void agregar(Arbol a){
    T x = solicitarNumero();
    agregarNodo(a, x);
}

void agregarNodo(Arbol a, T numero){
    Arbol p = a;

    while (true)
    {
        if(compararNumeros(numero, igualque, p->dato)) {
            cout << "El dato ya existe." << endl;
            return;
        }

        else if (compararNumeros(numero, menorque, p->dato)) {
            if ( p->left == NULL )
            {
                break;
            }
            else
            {
                p = p->left;
            }
        }
        else {
            if ( p->right == NULL )
            {
                break;
            }
            else
            {
                p = p->right;
            }
            
        }
    }

    if(compararNumeros(numero, menorque, p->dato)) {
        numeroLeft(p, numero);
    }
    else {
        numeroRight(p, numero);
    }
    
}

void inOrden(Arbol a){
    if ( a != NULL )
    {
        inOrden(a->left);
        cout << " "; mostrarNumero(a->dato);
        inOrden(a->right);
    }
}

void preOrden(Arbol a){
    if ( a != NULL )
    {
        cout << " "; mostrarNumero(a->dato);
        preOrden(a->left);
        preOrden(a->right);
    }
}

void postOrden(Arbol a){
    if ( a != NULL)
    {
        postOrden(a->left);
        postOrden(a->right);
        cout << " "; mostrarNumero(a->dato);
    }
}

void recorrerArbol(Arbol a){
    cout << "\n Recorrido en InOrden: "; inOrden(a); cout << endl;
    cout << " Recorrido en PreOrden: "; preOrden(a); cout << endl;
    cout << " Recorrido en PostOrden: "; postOrden(a); cout << endl;
}

void menorNumero(Arbol a){
    if ( a->left != NULL )
    {
        menorNumero(a->left);
    }

    else 
    {
        cout << a->dato;
    }
}

void mayorNumero(Arbol a){
    if ( a->right != NULL )
    {
        mayorNumero(a->right);
    }

    else 
    {
        cout << a->dato;
    }
}