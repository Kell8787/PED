#include <iostream>
#include <string>
using namespace std;

struct carro
{
    string modelo;
    string placa;
    string color;
    int precio = 65;

};

typedef struct carro Carro;

// T sera como identificare a Carro

typedef Carro T;
const T noValido = {"", "", "", -1};

struct Nodo
{
    T elemento;
    struct Nodo *siguiente;
    
};

struct Cola
{
    Nodo* frente;
    Nodo* final;
};

void inicializar(Cola *q);
bool empty(Cola *q);
T adelante(Cola *q);
T atras(Cola *q);
void enCola(Cola *q, T x);
T desCola(Cola *q);
int tamanioCola(Cola *q);
