#include <iostream>
#include <string>

using namespace std;

struct Libro{
    string nombre;
    int estante, numISBN;
    string genero, autor;
};

typedef Libro datosL;

struct Nodo
{
    datosL datos;
    struct Nodo *siguiente;
};
Nodo *Inicio;

datosL solicitarDatos();
void mostrarDatos(datosL e);
bool comparar(datosL a, datosL b);

int cantidadDato();
void colocarInicio(datosL X);
void colocarFinal(datosL X);
void insertarDespuesDe(datosL X); 
void insertarAntesDe(datosL X);


void agregar();
void mostrar();
void eliminar();
void buscar();



int main(){
    cout << "/***** Listas ******/\n" << endl;
    Inicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar libro \t2) Mostrar todos los libros\n";
        cout << "\t3) Eliminar libro \t4) Buscar libro\n";
        cout << "\t5) Cantidad\t6) Salir \n";
        cout << "\tOpcion elegida: ";
        cin >> opcion; cin.ignore();
        switch(opcion){
            case 1: agregar(); break;
            case 2: mostrar(); break;
            case 3: eliminar(); break;
            case 4: buscar(); break;
            case 5: cout << "Hay " << cantidadDato() << " libros.\n"; break;
            case 6: continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }while(continuar);

    return 0;
    

}

datosL solicitarDatos(){
    datosL e;

    //--- Solicitar datos del libro ---
    cout << "Titulo: "; getline(cin, e.nombre);
    cout << "Estante: "; cin >> e.estante; cin.ignore();
    cout << "Numero ISBN: "; cin >> e.numISBN; cin.ignore();
    cout << "Genero: "; getline(cin, e.genero);
    cout << "Autor: "; getline(cin, e.autor);
    
    //---Devolver el libro --
    return e;
}



void mostrarDatos(datosL e){

    cout << "------------------------------\n";
    cout << "Nombre: " << e.nombre << endl;
    cout << "Estante: " << e.estante << endl;
    cout << "Numero ISBN: " << e.numISBN << endl;
    cout << "Genero: " << e.genero << endl;
    cout << "Autor: " << e.autor << endl;
}

// Compara los carnets de dos estudiantes
bool comparar(datosL a, datosL b){
    return a.numISBN == b.numISBN;
}

int cantidadDato(){
    Nodo *s = Inicio;

    int contador = 0;
    while (s != NULL)
    {
        s = s->siguiente;
        contador ++;
    }
    
    return contador;
}

void colocarInicio(datosL X){
    Nodo *nuevo = new Nodo;
    nuevo->datos = X;
    nuevo->siguiente = Inicio;

    Inicio = nuevo;
}

void colocarFinal(datosL X){
    Nodo *nuevo = new Nodo;
    nuevo->datos = X;
    nuevo->siguiente = NULL;
    
    if (Inicio == NULL) 
    {
        Inicio = nuevo;
    } 
    else 
    {

        Nodo *X = Inicio;
        Nodo *q = NULL;
        while (X != NULL) {
            q = X;
            X = X->siguiente;
        }
        // En este momento q representa...
        // El ultimo nodo antes de NULL
        q->siguiente = nuevo;
    }
}

void insertarDespuesDe(datosL X) {
    cout << "Libro de referencia: \n";
    datosL ref = solicitarDatos();

    Nodo *s = Inicio;
    

    while (s != NULL && !comparar(s->datos, ref))
    {
        s = s -> siguiente;
    }

    if(s == NULL){
        cout << "Libro de referencia NO existe\n";
        return;
    }

    Nodo *nuevo = new Nodo;
    nuevo->datos = X;
    nuevo->siguiente = s->siguiente;
    s->siguiente = nuevo;

    cout << "Libro fue insertado con exito\n";
    
}

void insertarAntesDe(datosL X){
    cout << "Libro de referencia: \n";
    datosL ref = solicitarDatos();
    
    Nodo *s = Inicio, *q = NULL;
    
    // S representa el nodo objetivo es decir...
    // Queremos insertar el nuevo nodo antes de el
    while(s != NULL && !comparar(s->datos, ref)){
        // Para conseguir esto utilizamos un nodo q
        // Que siempre estara un paso atras que s
        q = s;
        s = s->siguiente;
    }
    if(s == NULL){
        cout << "Libro de referencia NO existe\n";
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->datos = X;
    nuevo->siguiente = s;
    
    if(q == NULL)
        Inicio = nuevo;
    else
        q->siguiente = nuevo;
    cout << "Libro insertado con exito\n";
}


void agregar(){
    datosL e = solicitarDatos();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n";
        cout << "\t2) Al final\n";
        cout << "\t3) Despues de\n";
        cout << "\t4) Antes de\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion; cin.ignore();
        switch(opcion){
            case 1: colocarInicio(e); continuar = false; break;
            case 2: colocarFinal(e); continuar = false; break;
            case 3: insertarDespuesDe(e); continuar = false; break;
            case 4: insertarAntesDe(e); continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }while(continuar);
}

void mostrar(){
    Nodo *s = Inicio;

    while (s != NULL) {
        mostrarDatos(s->datos);
        s = s->siguiente;
    }
}

void eliminar(){

    cout << "Eliminar libro: ";
    datosL ref = solicitarDatos();

    Nodo *s = Inicio, *q = NULL;
    while (s != NULL && !comparar(s->datos, ref))
    {
        q = s;
        s = s->siguiente;
    }
    if(s == NULL){
        cout << "El libro a borrar NO existe.\n";
        return;
    }

    if (q == NULL)
        Inicio = s->siguiente;
    else
        q->siguiente = s ->siguiente;
    delete(s);

    cout << "El libro fue eliminado de la lista.\n";

}


void buscar(){
    cout << "Libro a buscar: ";
    datosL ref = solicitarDatos();
    
    Nodo *s = Inicio;

    while(s != NULL && !comparar(s->datos, ref))
        s = s->siguiente;
    
    // Si s!=NULL entonces el elemento SI se encuentra
    // Si s==NULL entonces el elemento NO se encuentra
    if(s != NULL)
        cout << "El dato SI se encuentra\n";
    else
        cout << "El dato NO se encuentra\n";
}