//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Gaussiana

/*   
Recupere la solución del ejercicio 10 (función gaussiana)
de la relación de problemas I.
Se pide crear un menú principal para que el usuario pueda elegir
las siguientes opciones:

   Introducir Parámetros de la función (esperanza y desviación)
   Salir del programa
   
Si el usuario elige la opción de salir, el programa terminará; si elige
la opción de introducir los parámetros, el programa leerá los
dos parámetros (esperanza y desviación).

La media puede ser un valor cualquiera, p
ero la desviación ha de ser un número positivo.

A continuación, el programa presentará un menú con las siguientes opciones:

   Introducir rango de valores de abscisas
   Volver al menú anterior (el menú principal)

Si el usuario elige volver al menú anterior, el programa debe presentar el
primer menú (el de la introducción de los parámetros) Si el usuario elige
introducir los valores de abscisas, el programa le pedirá un valor minimo ,
un valor maximo (ha de ser mayor que minimo) y un incremento y mostrará
el valor de la función gaussiana en todos los valores de abscisa (x)
entre minimo y maximo a saltos de incremento , es decir,

   minimo, minimo + incremento , minimo + 2*incremento , ···,
   
hasta llegar, como mucho, a maximo .
Después de mostrar los valores de la función, el programa volverá al
menú de introducción del rango de valores de abscisas.
*/


#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

int main(){
   /*
      Como norma general no usaremos nombres de variables como x, y, etc.
      Hacemos una excepción en este programa ya que son nombres
      omnipresentes en Matemáticas.
   */
   
   /*
   (P)arámetros  -> [cin esperanza y desviación] -> (R)ango -> [cin min, max, incremento] -> Resultados ->|
   (S)alir       <--------------------------------- (V)olver <--------------------------------------------|   
   */
   /*
   do{
     Mostrar Menú Ppal (Parámetros o Salir)
     Leer opcion_menu_ppal
     
     if opcion_ppal no es Salir
        Lectura de esperanza y desviación
        
        do{
           Mostrar Menú (Rango o Volver)
           Leer opcion_menu_secundario
           
           if opcion_menu_secundario no es Volver
              Lectura de min, max e incremento
              Mostrar resultados
        }while (opcion_menu_secundario != 'V')
   }while (opcion_ppal != 'S')
   */       
   
   const double PI = 6 * asin(0.5);

   const char OPCION_INTRO_PARAMETROS  = 'P',
              OPCION_SALIR             = 'S',
              OPCION_INTRO_RANGO       = 'R',
              OPCION_VOLVER            = 'V';
   char opcion_menu_ppal, opcion_menu_secundario;
   bool eligio_salir_ppal, eligio_salir_secundario;
   bool es_correcta_opcion_ppal, es_correcta_opcion_secundario;
   double esperanza, desviacion, x, min_x, max_x, incremento;
   double y;                                
   double valor_tipificado, exponente;
   
   cout << "Gaussiana";
   
   do{
      cout << "\n\n---------------------\n" 
           << "Menú Principal\n\n"
           << "Parámetros\n"
           << "Salir\n";
      
      do{
         cout << "\nIntroduzca la opción (" << OPCION_INTRO_PARAMETROS 
              << "/" << OPCION_SALIR << ") ";
         cin >> opcion_menu_ppal;
         opcion_menu_ppal = toupper(opcion_menu_ppal);
         eligio_salir_ppal = opcion_menu_ppal == OPCION_SALIR;
         es_correcta_opcion_ppal = eligio_salir_ppal ||
                                   opcion_menu_ppal == OPCION_INTRO_PARAMETROS;
      }while (! es_correcta_opcion_ppal);
      
      if (! eligio_salir_ppal){
         cout << "\nIntroduzca el valor del parámetro 'esperanza': ";
         cin >> esperanza;
      
         do{
            cout << "\nIntroduzca el valor del parámetro 'desviacion'. "
                 << "Debe ser un número positivo: ";
            cin >> desviacion;
         }while (desviacion < 0);
         
         do{
            cout << "\n\n" 
              << "Menú Secundario\n\n"
              << "Rango\n"
              << "Volver\n";
              
            do{
               cout << "\nIntroduzca la opción (" << OPCION_INTRO_RANGO 
                    << "/" << OPCION_VOLVER << ") ";
               cin >> opcion_menu_secundario;
               opcion_menu_secundario = toupper(opcion_menu_secundario);
               eligio_salir_secundario = opcion_menu_secundario == OPCION_VOLVER;
               es_correcta_opcion_secundario  = eligio_salir_secundario ||
                                         opcion_menu_secundario == OPCION_INTRO_RANGO;
            }while (! es_correcta_opcion_secundario);                                               
            
            if (! eligio_salir_secundario){
               cout << "\nIntroduzca el valor mínimo de la abscisa: ";
               cin >> min_x;
               
               do{
                  cout << "\nIntroduzca el valor máximo de la abscisa. "
                       << "Debe ser un número positivo: ";
                  cin >> max_x;
               }while (max_x < min_x);
            
               do{
                  cout << "\nIntroduzca el valor del incremento. "
                       << "Debe ser un número positivo: ";
                  cin >> incremento;
               }while (incremento < 0);
            
            
               for(x = min_x; x <= max_x; x = x + incremento) {
                  valor_tipificado = (x - esperanza) / desviacion;
                  exponente = -0.5 * valor_tipificado * valor_tipificado;
                  y = exp(exponente) / ( desviacion * sqrt(2*PI) );
                  
                  y = Gaussiana(x, esperanza, desviacion);
                  
                  cout << "\nf(" << x << ")= " << y;
               }
            }
         }while (! eligio_salir_secundario);
      }
   }while (! eligio_salir_ppal);
}
