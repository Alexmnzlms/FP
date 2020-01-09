/*
	Programa que lee un capital y le aplica un interes definido por el usuario
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double capital;          
	double interes;          
	double total;            
	
	cout << "Por favor introduzca la cantidad a depsitar: ";
	cin >> capital;
	
	cout << "Por favor intruzca su interes: ";  
	cin >> interes;
	
	
	total = capital + (capital * (interes / 100));
	
	cout << "\nSu deuda bancaria asciende a: " << total;
 }
