///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/////////                                                           	 /////////
/////////	   Comprobacion de fallos y errores de desbordamiento     /////////
/////////	   																 		 /////////
/////////                                                             /////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	// A)
	int chico, chico1, chico2;
	chico1 = 1234567;
	chico2 = 1234567;
	chico = chico1 * chico2;
	
	// Se produce un desbordamiento debido a que el valor de chico supera al int al que se le asigna

	//B
	long grande;
	int chico1, chico2;
	chico1 = 1234567;
	chico2 = 1234567;
	grande = chico1 * chico2;	
	
	// Se produce un desbordamiento debido a que el valor de grndde supera al long al que se le asigna
		
	//C
	double resultado, real1, real2;
	real1 = 123.1;
	real2 = 124.2;
	resultado = real1 * real2;
	
	// Se porduce un problema de precision, el double se muestra sin decimales
	
	//D
	double resultado, real1, real2;
	real1 = 123456789.1;
	real2 = 123456789.2;
	resultado = real1 * real2;
	
	//No se produce ningun error en la salida
	
	//E
	double real, otro_real;
	real = 2e34;
	otro_real = real + 1;
	otro_real = otro_real - real;
	
	//Se produce un error debido a que el resultado deberia ser uno y es 0 porque se trabajas con potencias de 10 muy altas
	//F
	double real, otro_real;
	real = 1e+300;
	otro_real = 1e+200;
	otro_real = otro_real * real;
	
	//Se produce un error de precision debido a que en la variable se almacena infinito en lugar del valor del numer

	//G
	float chico;
	double grande;
	grande = 2e+150;
	chico = grande;
	
	//Se produce un error de precision debido a que en la variable se almacena infinito en lugar del valor del numero
}
