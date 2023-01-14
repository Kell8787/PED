#include <iostream>

using namespace std;

void miFuncion(int *);

int main()
{

    int a = 5;

    cout << "Por referencias" << endl;
    cout << "El valor de a es: " << a << endl;
    miFuncion(&a);

    cout << "El valor de a es: " << a << endl;

    return 0;
}

void miFuncion(int *b)
{
    cout << "El valor de b es: " << *b << endl;
    *b = 10;
    cout << "El valor de b es: " << *b << endl;
}
