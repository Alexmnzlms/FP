//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

/*
Indique cu�l ser�a el resultado de las siguientes operaciones:
 
int salario_base;      
int salario_final;
int incremento;

salario_base = 1000;
salario_final = salario_base;

incremento = 200;
salario_final = salario_final + incremento;    //salario_final=1200

salario_base = 3500;

cout << "\nSalario base: " << salario_base;
cout << "\nSalario final: " << salario_final;

Responda razonadamente a la siguiente pregunta: �El hecho de realizar la
asignaci�n salario_final = salario_base; hace que ambas variables est�n
ligadas durante todo el programa y que cualquier modificaci�n posterior de
   salario_base
afecte a salario_final ?
*/

#include <iostream>
using namespace std;

int main(){
   int salario_base;
   int salario_final;
   int incremento;

   salario_base  = 1000;
   salario_final = salario_base;

   incremento = 200;
   salario_final = salario_final + incremento;

   cout << "\nSalario base:  " << salario_base;
   cout << "\nSalario final: " << salario_final;
   
   salario_base = 3500;
   
   /*
   La respuesta es que no, una vez realizada la asignacion, el programa asigna el mismo valor tanto a salario_final como a salario_base
   pero la asignacion no se mantiene a lo largo del programa, puediendo posteriormente ser modificadas ambas variables por separado
   */
}

