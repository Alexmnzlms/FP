#include <iostream>
#include <cmath>
using namespace std;

// NO MODIFIQUE ESTA CLASE
class SecuenciaDoubles{
private:
   static const int TAMANIO = 100;                                                             
   double vector_privado[TAMANIO];
   int total_utilizados;

   
   bool EsCorrectoIndice(int pos){
      return 0 <= pos && pos < total_utilizados;
   }
public:
   SecuenciaDoubles()
      :total_utilizados(0) {
   }   
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Aniade(double nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, double nuevo){
      if (EsCorrectoIndice(posicion))
         vector_privado[posicion] = nuevo;
   }

   double Elemento(int indice){
      if (EsCorrectoIndice(indice))
         return vector_privado[indice];
      else
         return NAN;
   }
   
   string ToString(){
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++){
         cadena.append(to_string(vector_privado[i]));
         cadena.append(" ");
         //cadena = cadena + to_string(vector_privado[i])  <- Evitarlo. Muy ineficiente para tamaños grandes;
      }
      
      return cadena;
   }

   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, double buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }
   
   int PrimeraOcurrencia (double buscado){
      return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
   }
   

   /////////////////////////////////////////////////////////////
   // Búsquedas
   
   // Precond: 0 <= izda <= dcha < total_utilizados
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      double minimo;

      minimo = vector_privado[izda];
      posicion_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (vector_privado[i] < minimo){
            minimo = vector_privado[i];
            posicion_minimo = i;
         }

      return posicion_minimo;
   }
   
   int PosicionMinimo(){
      return PosicionMinimoEntre(0, total_utilizados - 1);
   }
   

   // Precond: 0 <= izda <= dcha < total_utilizados
   int PosicionMaximoEntre(int izda, int dcha){
      int posicion_maximo = -1;
      double maximo;

      maximo = vector_privado[izda];
      posicion_maximo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (vector_privado[i] > maximo){
            maximo = vector_privado[i];
            posicion_maximo = i;
         }

      return posicion_maximo;
   }

   int PosicionMaximo(){
      return PosicionMaximoEntre(0, total_utilizados - 1);
   }

};





struct ParFilacolumna{
   int fila;
   int columna;
};

class TablaTemperaturas{
private:
   static const int CAPACIDAD_CIUDADES = 100;
   SecuenciaDoubles temp[CAPACIDAD_CIUDADES];
   int num_ciudades = 0;
   bool IndicesCorrectos(int fil, int col){
      return 0 <= fil && fil < CAPACIDAD_CIUDADES && 0 <= col && col < temp[0].Capacidad();
   }
public:
   TablaTemperaturas()
   {
   }
   
   int CapacidadCiudades(){
      return CAPACIDAD_CIUDADES;
   }
   
   double Valor(int ciudad, int hora){
      if (IndicesCorrectos(ciudad, hora))
         return  temp[ciudad].Elemento(hora);
      else
         return NAN;  
   }
	void Aniade(SecuenciaDoubles horas_nueva_ciudad){
		temp[num_ciudades] = horas_nueva_ciudad;
		num_ciudades++;
	}
	void AniadeTempA(int ciudad, double nueva_temp){
		if ( 0 <= ciudad && ciudad < num_ciudades)
			temp[ciudad].Aniade(nueva_temp);
	}
	int Minimo(int ciudad){
		if ( 0 <= ciudad && ciudad < num_ciudades){
			return temp[ciudad].PosicionMinimo();
		}
		else{
			return -1;
		}
	}
	ParFilacolumna MaximoMinimos(){
		ParFilacolumna maximo_entre_minimos;
		SecuenciaDoubles temp_minimas;
      int minimos_por_fila[num_ciudades];

      for (int i = 0; i < num_ciudades; i++){
         minimos_por_fila[i] = Minimo(i);
			temp_minimas.Aniade( temp[i].Elemento(minimos_por_fila[i]) );
      }

      maximo_entre_minimos.fila = temp_minimas.PosicionMaximo();
      maximo_entre_minimos.columna = minimos_por_fila[maximo_entre_minimos.fila];

      return maximo_entre_minimos;
   }

};



// EN EL PROGRAMA PRINCIPAL
// MODIFIQUE ÚNICAMENTE LO INDICADO
int main(){
   const int TERMINADOR = -1;
	TablaTemperaturas tabla_temperaturas;
	SecuenciaDoubles registro_temp_ciudad;
	ParFilacolumna pos_max_min;
	int num_temp;
	
	cin >> num_temp;
	
	while (num_temp != TERMINADOR){
		for (int j = 0; j < num_temp; j++){
		   double temp;
			cin >> temp;
			registro_temp_ciudad.Aniade(temp);
		}
		
      // Añadir registro_temp_ciudad a la tabla
		tabla_temperaturas.Aniade(registro_temp_ciudad);
      // Limpiar registro_temp_ciudad
		registro_temp_ciudad.EliminaTodos();
      
   	cin >> num_temp;
   }

   pos_max_min = tabla_temperaturas.MaximoMinimos();

	cout << "\n\nMáximo de los mínimos:\nFila: " << pos_max_min.fila
        << "\nColumna: " << pos_max_min.columna
        << "\nValor: " << tabla_temperaturas.Valor(pos_max_min.fila, pos_max_min.columna);
}
