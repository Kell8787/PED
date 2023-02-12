#include <iostream>
#include <ctime>

using namespace std;

// haciendo class videogame
class Game
{
private:
    string platform;
    int year;
    int hoursPlayed;

public:
    string title;
    void showGame();
    void AddHours(int);

    Game()
    {
        title = "";
        platform = "";
        year = 0;
        hoursPlayed = 0;
    }
    Game(string _title, string _platform, int _year)
    {
        title = _title;
        platform = _platform;
        year = _year;
        hoursPlayed = 0;
    }
};

// to-do completar funcion
void Game::showGame()
{ 
    cout << "\n------------------------------------------\n";
    cout << "Game: " << title << "\nHoras Jugadas: " << hoursPlayed << "\nPlataforma: " << platform<<endl;
    cout << "------------------------------------------\n";
}

// to-do completar funcion
void Game::AddHours(int hours)
{
    hoursPlayed += hours;
    cout << "\n------------------------------------------\n";
    cout << "Se han agregado: " << hours << "Horas\nHoras jugadas: " << hoursPlayed << endl;
    cout << "------------------------------------------\n";
}

// definicion de lista
typedef Game T;
const T noValido = Game("", "", 0);

struct Nodo
{
    T dato;
    struct Nodo *siguiente;
};

Nodo *lista;

// Funciones
bool comparar(T a, string b);
void insertarNodo();
void mostrarLista();
void buscar();
void agregarAleatorio();

int main()
{
    /* Mis cambios */
    bool continuar = true;

    do
    {
        int opcion = 0;

        cout << "\n\n--------------- Menu ---------------\n";
        cout << " 1) Agregar Videojuego\n 2) Mostrar VideoJuegos\n 3) Buscar y Agregar Horas\n 4) Agregar horas aleatoriamente\n 5) Salir\n";
        cout << "Su opcion es: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            insertarNodo();
            continuar = 1;
            break;
        case 2:
            mostrarLista();
            continuar = 1;
            break;
        case 3:
            buscar();
            break;
        case 4:
            agregarAleatorio();
            break;
        case 5:
            continuar = false;
            break;
        default:
            cout << "Su opcion es erronea!.\n";
            break;
        }
    } while (continuar);

    return 0;
}

void insertarNodo()
{
    struct Nodo *nuevoNodo = new Nodo();

    string titulo, plataforma;

    int year;
    cout << "Ingrese titulo: ";
    getline(cin, titulo);
    cout << "Ingrese plataforma: ";
    getline(cin, plataforma);
    cout << "Ingrese el anio de lanzamiento: ";
    cin >> year;

    nuevoNodo->dato = Game(titulo, plataforma, year);
    struct Nodo *aux = lista;

    if (nuevoNodo != lista)
    {
        if (lista == NULL)
        {
            lista = nuevoNodo;
        }
        else
        {
            while (aux->siguiente != NULL)
            {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevoNodo;
        }
    }
    else
    {
        cout << "No se puede agregar mas nodos\n";
    }
}

void mostrarLista()
{
    struct Nodo *temporal = lista;

    if (lista != NULL)
    {
        while (temporal != NULL)
        {
            temporal->dato.showGame();
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "lista vacia";
    }
}

void buscar()
{
    string ref;
    int HorasAgregar;

    cout << "Ingrese el titulo de el videojuego: ";
    getline(cin, ref);
    cout << "\nIngrese las horas jugadas:";
    cin >> HorasAgregar; cin.ignore();

    Nodo *s = lista;

    while (s != NULL && !comparar(s->dato, ref))
    {
        s = s->siguiente;
    }

    if (s != NULL)
    {
        s->dato.AddHours(HorasAgregar);
    }
}

bool comparar(T a, string b)
{
    return a.title == b;
}

void agregarAleatorio()
{
    struct Nodo *temporal = lista;
    int n;

    if (lista != NULL)
    {
        while (temporal != NULL)
        {
            srand(time(NULL));
            n = rand() % 100;
            temporal->dato.AddHours(n);
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "lista vacia";
    }
}