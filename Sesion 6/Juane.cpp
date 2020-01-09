#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const int MAX = 100000;
    const int MIN = 1;
    int tope;
    int numero_fraccion;
    double aproximacion;
    double numerador;
    double denominador;
    double pi;
    bool variacion;

    aproximacion = 1;
    numerador = 2.0;
    denominador = 1.0;

    cout << "Introduzca el valor del tope: ";
    cin >> tope;

    while ( tope < MIN || tope > MAX){
        cout << "Introduzca el valor del tope: ";
        cin >> tope;
    }

    for (numero_fraccion = 0; numero_fraccion < tope; numero_fraccion++){
        aproximacion = aproximacion * (numerador / denominador);
        pi = 2*aproximacion;
        variacion = numero_fraccion % 2 == 0;
        if (variacion){
            denominador = denominador + 2;
        }
        else{
            numerador = numerador + 2;
        }
    }
    cout.precision(15);
    cout << "El valor aproximado de pi es " << pi;
}

