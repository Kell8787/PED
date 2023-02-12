#include <iostream>
#include <ctime>
#include <list> // INcluyendo la libreria de listas

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
    cout << "\nGame: " << title << "\n Horas Jugadas: " << hoursPlayed << "\nPlataforma: " << platform<<endl;
}
// to-do completar funcion
void Game::AddHours(int hours)
{
    hoursPlayed += hours;
    cout << "Se han agregado " << hours << "Horas\nHoras jugadas: " << hoursPlayed;
}

//bool comparar(T a, string b);
void insertarNodo(list<Game> &);
void mostrarLista(list<Game> &);
void buscar();
//void agregarAleatorio();

int main()
{
    list<Game> games;
    /* Mis cambios */
    bool continuar = true;

    do
    {
        int opcion = 0;

        cout << "--------------- Menu ---------------\n";
        cout << " 1) Agregar Videojuego\n 2) Mostrar VideoJuegos\n 3) Buscar y Agregar Horas\n 4) Agregar horas aleatoriamente\n 5) Salir\n";
        cout << "Su opcion es: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            insertarNodo(games);
            continuar = 1;
            break;
        case 2:
            mostrarLista(games);
            continuar = 1;
            break;
        case 3:
            buscar();
            break;
        case 4:
            /* agregarAleatorio(); */
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
void insertarNodo(list<Game> & games)
{
    string titulo, plataforma;

    int year;
    cout << "Ingrese titulo: ";
    getline(cin, titulo);
    cout << "Ingrese plataforma: ";
    getline(cin, plataforma);
    cout << "Ingrese el año de lanzamiento: ";
    cin >> year; cin.ignore();

    Game tmp_game(titulo, plataforma, year); // Creo un temporal, inicializado con mi clase, para poder guardar los datos
    games.push_back(tmp_game); // Este guardara mis datos al final de la lista

}
void mostrarLista(list<Game> & games)
{
    cout << "\n----- Coleccion de video juegos ----- \n";
    Game::showGame();
}   
void buscar()
{
    string ref;
    int HorasAgregar;

    cout << "Ingrese el titulo de el videojuego: ";
    getline(cin, ref);

    cout << "\nIngrese las horas jugadas:";
    cin >> HorasAgregar;
    cin.ignore();

}

/* bool comparar(T a, string b)
{
    return a.title == b;
} */

/* void agregarAleatorio()
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
} */