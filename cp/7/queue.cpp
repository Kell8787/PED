#include <iostream>
#include <string>
#include "queue.hpp"

using namespace std;

void inicializar(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return(q->frente == NULL) ? true : false;
}

T adelante(Cola *q){
    if(empty(q)){
        cout << "Underflow :c" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T atras(Cola *q){
    if(empty(q)){
        cout << "Underflow :c" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enCola(Cola *q, T aux){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = aux;
    unNodo->siguiente = NULL;

    if(q->final == NULL){
        q->frente = unNodo;
    }
    else{
        (q->final)->siguiente = unNodo;
    }

    q->final = unNodo;
}

T desCola(Cola *q){
    if(empty(q)){
        cout << "Underflow :c" << endl;
        return noValido;
    }

    Nodo *unNodo = q->frente;
    T aux = unNodo->elemento;
    q->frente = unNodo->siguiente;

    if(q->frente == NULL){
        q->final = NULL;
        
    }

    delete(unNodo);
    
    return aux;
}

int tamanioCola(Cola *q){
    if (empty(q))
    {
        return 0;
    }

    Nodo *unNodo = q->frente;
    int contador = 1;

    while (unNodo->siguiente != NULL)
    {
        unNodo = unNodo->siguiente;
        contador++;
    }

    return contador;
}