/* Programa que simula un tunel de trafico.
   Se ha implemnetado la clase tunel para poder controlar el flujo de vehiculos
   El programa pide datos a traves de varios bucles y despues los procesa y los
   muestra.
   Se han usado tambien las clases instantes y formateador de doubles.
   La clase proporciona los metodos para poder almacenar las matriculas,
   el tiempo de netraa y de salida de los vehiculos, asi como para calcular
   su velocidad */

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

class Instante{
private:
	int horas;
	int minutos;
	int segundos;
	
	static const int SEGUNDOS_HORA = 3600;
	static const int SEGUNDOS_MINUTO = 60;
	static const int MINUTOS_HORA = 60;
	static const int HORAS_DIA = 24;
	
	void AjusteTiempo(){
		while(segundos >= 60){
			minutos++;
			segundos = segundos - 60;
		}
		while(minutos >= 60){
			horas++;
			minutos = minutos - 60;
		}
	}
	
public:
	Instante()
	:horas(0),
	 minutos(0),
	 segundos(0)
	 {
	 }
	
	Instante(int hora, int minuto, int segundo)
	:horas(hora),
	 minutos(minuto),
	 segundos(segundo)
	 {
	 }
	 
	double ConversionHoras(){
		double horas_totales;
		double minutos_reales;
		double segundos_reales;
		
		minutos_reales = minutos;
		segundos_reales = segundos;
		
		horas_totales = horas + minutos_reales / SEGUNDOS_MINUTO + segundos_reales / SEGUNDOS_HORA;
		
		return horas_totales;
	}
	 
	int ConversionMinutos(){
		int minutos_totales;
		
		minutos_totales = horas * SEGUNDOS_HORA + minutos + segundos / SEGUNDOS_MINUTO;
		
		return minutos_totales;
	}
		 
	 int ConversionSegundos(){
		int segundos_totales;
		
		segundos_totales = horas * SEGUNDOS_HORA + minutos * SEGUNDOS_MINUTO + segundos;
		
		return segundos_totales;
	}
	
	string PrintInstante(){
		AjusteTiempo();
		string instante;
		instante =
		to_string(horas) + "h "
		+ to_string(minutos) + "' "
		+ to_string(segundos)+ "''";
		
		return instante;
	}
	
	string MinutosPasados(){
		string frase;
		
		frase = "Han pasado: " +
			to_string(ConversionMinutos())
			+ " minutos";
		
		return frase; 
	}
	
		string SegundosPasados(){
		string frase;
		
		frase = "Han pasado: " +
			to_string(ConversionSegundos())
			+ " segundos";
		
		return frase; 
	}
	
	void SetSegundos(int tiempo){
		 int minutos_enteros;
      const int SEGUNDOS_EN_1_DIA = SEGUNDOS_MINUTO
                                    * MINUTOS_HORA
                                    * HORAS_DIA;

      if (tiempo < SEGUNDOS_EN_1_DIA){
         segundos = tiempo % SEGUNDOS_MINUTO;
         minutos_enteros  = tiempo / SEGUNDOS_MINUTO;
         minutos  = minutos_enteros % MINUTOS_HORA;
         horas   = minutos_enteros / MINUTOS_HORA;
      }
   }
	
	int Horas(){
		return horas;
	}
	
	int Minutos(){
	return minutos;
	}	
		
	int Segundos(){
		return segundos;
	}
};

Instante RestaInstantes(Instante instante_inicial, Instante instante_final){
	int resta;
	resta = abs(instante_final.ConversionSegundos() - instante_inicial.ConversionSegundos());
	Instante instante_diferencia;
	instante_diferencia.SetSegundos(resta);
	return instante_diferencia;
}

class Tunel{
private:
	static const int TAMANIO = 500;
	static const int NULO = -1;
	double longitud;
	int indice;
	string matriculas[TAMANIO];
	int entradas[TAMANIO];
	int salidas[TAMANIO];
	
	int RecuperaMatricula(string matricula){
		int indice_matricula;
		for(int i = 0; i < indice; i++){
			if(matriculas[i] == matricula){
				indice_matricula = i;
			}
		}
		
		return indice_matricula;
	}
	
public:
	Tunel(double kilometros){
		longitud = kilometros;
		for(int i = 0; i < TAMANIO; i++){
			entradas[i] = NULO;
			salidas[i] = NULO;
		}
	}
	
	void Entra(int indice ,string matricula, long long segundos){
		matriculas[indice] = matricula;
		entradas[indice] = segundos;
	}
	
	void Sale(string matricula, long long segundos){
		salidas[RecuperaMatricula(matricula)] = segundos;
	}
	
	bool CompruebaCoche(string matricula){
		bool coche_dentro = false;
		for(int i = 0; i < indice; i++){
			if(matriculas[i] == matricula){
				coche_dentro = true;
			}	
		}
		return coche_dentro;
	}
	
	void SetIndice(int numero){
		indice = numero;
	}
	
	double Velocidad(string matricula){
		double velocidad;
		double horas;
		int indice_matricula;
		for(int i = 0; i < indice; i++){
			if(matriculas[i] == matricula){
				indice_matricula = i;
			}
		}
		Instante tiempo_entrada, tiempo_salida, tiempo_diferencia;
		tiempo_entrada.SetSegundos(entradas[indice_matricula]);
		tiempo_salida.SetSegundos(salidas[indice_matricula]);
		tiempo_diferencia = RestaInstantes(tiempo_entrada,tiempo_salida);
		horas = tiempo_diferencia.ConversionHoras();
		velocidad = longitud / horas;
		
		return velocidad;
	}
	
	string RecuperarMatricula(int posicion){
		return matriculas[posicion];
	}
	
	bool HaSalido( string matricula){
		int indice_matricula;
		bool ha_salido = false;
		for(int i = 0; i < indice; i++){
			if(matriculas[i] == matricula){
				indice_matricula = i;
			}
		}
		if(salidas[indice_matricula] != -1){
			ha_salido = true;
		}
		return ha_salido;
	}
};

class FormateadorDoubles{
private:
   enum class SeparadorDecimal {PUNTO, COMA};
   string izda    = ""; 
   string dcha    = ""; 
   int decimales  = 2;   
   SeparadorDecimal separador = SeparadorDecimal::PUNTO;

   void SetDelimitadores(string delimitador_izda, string delimitador_dcha){
      izda = delimitador_izda;
      dcha = delimitador_dcha;
   }

   double PotenciaEntera(double base, int exponente){
   	double potencia;
   	int exponente_positivo;

   	if (base == 0 && exponente == 0)
   		potencia = NAN;
   	else{
   		exponente_positivo = abs(exponente);
   		potencia = 1;

   		for (int i = 1; i <= exponente_positivo; i++)
   			potencia = potencia * base;
   	}

   	if (exponente < 0)
   		potencia = 1/potencia;

   	return potencia;
   }


   double Redondea(double real, int num_decimales){
      double real_redondeado;
      long long potencia_10;

      potencia_10 = PotenciaEntera(10, num_decimales);
      real_redondeado = round(real * potencia_10);
      real_redondeado = real_redondeado / potencia_10;

      return real_redondeado;
   }

   string EliminaUltimos(string cadena, char a_borrar){
      while (! cadena.empty() && cadena.back() == a_borrar)
         cadena.pop_back();

      return cadena;
   }

public:
   FormateadorDoubles(){
   }

   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha)
   {
      SetDelimitadores(delimitador_izda, delimitador_dcha);
   }

   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha,
                      int num_decimales_a_mantener)
      :FormateadorDoubles(delimitador_izda, delimitador_dcha)
   {
      SetNumeroDecimales(num_decimales_a_mantener);
   }

   void SetSeparadorPunto(){
      separador = SeparadorDecimal::PUNTO;
   }
   void SetSeparadorComa(){
      separador = SeparadorDecimal::COMA;
   }

   void SetNumeroDecimales(int num_decimales_a_mantener){
      if (num_decimales_a_mantener >= 0)
         decimales = num_decimales_a_mantener;
   }

   string GetCadena(double real){
      const int MAX_DIGITOS_PRECISION_DOUBLE = 15;
      int parte_entera;
      int num_digitos_precision;
      string cadena_separador;
      string cadena = "";

      if (real < 0)
         cadena = "-";

      real = abs(real);
      real = Redondea(real, decimales);
      parte_entera = trunc(real);
      cadena = cadena + to_string(parte_entera);
      num_digitos_precision = cadena.size();

      if (real != parte_entera
         && decimales > 0
         && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE){

         if (separador == SeparadorDecimal::PUNTO)
            cadena_separador = ".";
         else
            cadena_separador = ",";

         cadena = cadena + cadena_separador;

         for (int i = 0; i < decimales && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE; i++){
            real = Redondea(real - parte_entera, decimales);
            real = real * 10;
            parte_entera = trunc(real);
            cadena = cadena + to_string(parte_entera);
            num_digitos_precision++;
         }

         while (cadena.back() == '0')
            cadena.pop_back();
      }

      cadena = izda + cadena + dcha;

      return cadena;
   }
};

char 	cout << "\nIntroduzca la accion deseada(E/S/#)\n";
	cin >> caracter;
	caracter = toupper(caracter);Introduccion(){
	char caracter;
	cout << "\nIntroduzca la accion deseada(E/S/#)\n";
	cin >> caracter;
	caracter = toupper(caracter);
	return caracter; 
}

int main(){
	
	const char TERMINADOR = '#';
	char caracter;
	double longitud_tunel;
	string matricula;
	int hora, minuto, segundo;
	int indice_vehiculos = 0;
	
	cout << "Establezca la longitud del tunel en km\n";
	cin >> longitud_tunel;
	
	Tunel tunel_gest(longitud_tunel);
	
	cout << "\nIntroduzca ahora una E (si quiere realizar una entrada) una S (si quiere realizar una salida) o un # si quiere salir\n";
	cin >> caracter;
	caracter = toupper(caracter);
	while(caracter != TERMINADOR){
		if(caracter == 'E'){
			cout << "Introduzca la matricula: \n";
			cin >> matricula;
			cout << "Introduzca la horas, minutos y segundos: ";
			cin >> hora;
			while(hora > 23){
				cout << "\nHora incorrecta, pruebe otra vez\n";
				cin >> hora;
			}
			cin >> minuto;
			while(minuto > 59){
				cout << "\nMinutos incorrectos, pruebe otra vez\n";
				cin >> minuto;
			}
			cin >> segundo;
			while(segundo > 59){
				cout << "\nSegundos incorrectos, pruebe otra vez\n";
				cin >> segundo;
			}
			Instante tiempo(hora, minuto, segundo);
			tunel_gest.Entra(indice_vehiculos, matricula, tiempo.ConversionSegundos());
			indice_vehiculos++;
			tunel_gest.SetIndice(indice_vehiculos);
			cout << "\nEl vehiculo " << matricula << " entra en el instante " << tiempo.PrintInstante();
			caracter = 	cout << "\nIntroduzca la accion deseada(E/S/#)\n";
	cin >> caracter;
	caracter = toupper(caracter);Introduccion();
		}
		else{
			if(caracter == 'S'){
				cout << "Introduzca la matricula: \n";
				cin >> matricula;
				if(tunel_gest.CompruebaCoche(matricula)){
					cout << "Introduzca la horas, minutos y segundos: ";
					cin >> hora;
					while(hora > 23){
						cout << "\nHora incorrecta, pruebe otra vez\n";
						cin >> hora;
					}
					cin >> minuto;
					while(minuto > 59){
						cout << "\nMinutos incorrectos, pruebe otra vez\n";
						cin >> minuto;
					}
					cin >> segundo;
					while(segundo > 59){
						cout << "\nSegundos incorrectos, pruebe otra vez\n";
						cin >> segundo;
					}
					Instante tiempo(hora, minuto, segundo);
					tunel_gest.Sale(matricula, tiempo.ConversionSegundos());
					cout << "\nEl vehiculo " << matricula << " sale en el instante " << tiempo.PrintInstante();
				}
				else{
					cout << "El coche que has introducido no ha entrado en el tunel";
				}
				caracter = 	cout << "\nIntroduzca la accion deseada(E/S/#)\n";
	cin >> caracter;
	caracter = toupper(caracter);Introduccion();
			}
			else{
				cout << "No has introducido ni una E ni una S";
				caracter = 	cout << "\nIntroduzca la accion deseada(E/S/#)\n";
	cin >> caracter;
	caracter = toupper(caracter);Introduccion();
			}
		}
	}
	cout << "Estos son los datos recogidos durante el programa\n";
	
	for(int i = 0; i < indice_vehiculos; i++){
		cout << "\nMatricula: " << tunel_gest.RecuperarMatricula(i) << '\n';
		if(tunel_gest.HaSalido(tunel_gest.RecuperarMatricula(i))){
			FormateadorDoubles formateador_velocidad("\nVelocidad: " , " km/h");
			formateador_velocidad.SetNumeroDecimales(1);
			formateador_velocidad.SetSeparadorComa();
			cout << formateador_velocidad.GetCadena(tunel_gest.Velocidad(tunel_gest.RecuperarMatricula(i))) << '\n';
		}
		else{
			cout << "\nVelocidad: No ha salido\n";
		}
	}
}
