/*
 En este ejercicio no hace falta construir ningún programa. Debe
crear un fichero de texto (con extensión cpp o txt) explicando qué problemas observa
en los siguientes condicionales:


a) 
char tipo_radar;
cin >> tipo_radar;
if (tipo_radar == 'F' && tipo_radar == 'f')

	-El if no tiene sentido pues solo realiza si se cumplen las dos condiciones,
	cosa imposible pues estas son mutuamente excluyentes al no poder tener la misma variable dos valores diferentes.


b) 
double velocidad;
cin >> velocidad;
if (velocidad > 100 && velocidad < 70)
	cout << "\nVelocidad fuera del rango";

	-El if nunca llegara a cumplirse pues si velocidad es mayor que 100 no puede ser menor que 70 y viceversa,
	y para que el if se cumpla ambas condiciones deben de ser verdaderas.

	

c)
double velocidad;
cin >> velocidad;
if (velocidad > 100 || velocidad > 110)
	cout << "Velocidad excesiva";

	-La condición es excesivamente larga pues no se puede dar un caso en el que velocidad sea mayor que 110 
pero menor que 100, por lo tanto con escribit "velocidad > 100" se obtendría el mismo resultado.
*/

