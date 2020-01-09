#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

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

class Instante{
private:
	static const int SEGUNDOS_HORA = 3600;
	static const int SEGUNDOS_MINUTO = 60;
	static const int MINUTOS_HORA = 60;
	static const int HORAS_DIA = 24;
	int horas;
	int minutos;
	int segundos;	
		
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
	
   bool EsCorrecto (int hora, int minuto, int segundo){
      return  (0 <= hora    && hora < HORAS_DIA  &&
               0 <= minuto  && minuto < MINUTOS_HORA &&
               0 <= segundo && segundo < SEGUNDOS_MINUTO);
   }
	
public:
	Instante(){
		SetHoraMinutoSegundo(0,0,0);
	}


   Instante(int hora_instante, int minuto_instante, int segundo_instante){
      SetHoraMinutoSegundo(hora_instante,  minuto_instante,  segundo_instante);
   }
	
   void SetHoraMinutoSegundo(int hora_instante,
                             int minuto_instante,
                             int segundo_instante){
      if (EsCorrecto(hora_instante, minuto_instante, segundo_instante)){
         horas = hora_instante;
         minutos = minuto_instante;
         segundos = segundo_instante;
      }
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
	
	string PrintInstante(){
		AjusteTiempo();
		string instante;
		instante =
		to_string(horas) + "h "
		+ to_string(minutos) + "' "
		+ to_string(segundos)+ "''";
		
		return instante;
	}
};

class VehiculoTunel{
private:
	string matricula;
	Instante entrada;
	Instante salida;
	
	bool EsCorrectaMatricula(string matricula_vehiculo){
      return matricula_vehiculo.size() <= 8;
   }

public:
	VehiculoTunel()
	{
	}
	
 	VehiculoTunel(string matricula_vehiculo,
                Instante entrada_vehiculo,
                Instante salida_vehiculo
                )
   {
      SetMatricula(matricula_vehiculo);
      SetInstanteEntrada(entrada_vehiculo);
      SetInstanteSalida(salida_vehiculo);
   }

   string Matricula(){
      return matricula;
   }

   Instante InstanteEntrada(){
      return entrada;
   }

   Instante InstanteSalida(){
      return salida;
   }

   void SetMatricula(string matricula_vehiculo){
      if (EsCorrectaMatricula(matricula_vehiculo)){
         matricula = matricula_vehiculo;
      }
   }

   void SetInstanteEntrada(Instante entrada_vehiculo){
      entrada = entrada_vehiculo;
   }

   void SetInstanteSalida(Instante salida_vehiculo){
      salida = salida_vehiculo;
   }

	double HoraEntrada(){
		return entrada.ConversionHoras();
	}
	
	double HoraSalida(){
		return salida.ConversionHoras();
	}
};

class Tunel{
private:
	static const int NUMERO_MAX_VEHICULOS = 10;
	VehiculoTunel tunel[NUMERO_MAX_VEHICULOS];
	double longitud;
	int entradas_totales;

public:
	Tunel(double kilometros)
	:longitud(kilometros)
	{
	}
	
   int TotalEntradas(){
      return entradas_totales;
   }


   int Indice(string matricula){
   	int indice_matricula;
   	for(int i = 0; i < entradas_totales; i++){
			if(tunel[i].Matricula() == matricula){
				indice_matricula = i;
			}
		}
		return indice_matricula;
   }
	
	VehiculoTunel Vehiculo(int indice){
		VehiculoTunel coche;
		coche = tunel[indice];
		return coche;
	}
	
	void Entra(string coche, Instante instante_entrada){
		VehiculoTunel vehiculo;
		vehiculo.SetMatricula(coche);
		vehiculo.SetInstanteEntrada(instante_entrada);
		tunel[entradas_totales] = vehiculo;
		entradas_totales++;
	}
	
	void Sale(string coche, Instante instante_salida){
		int posicion = Indice(coche);
		tunel[posicion].SetInstanteSalida(instante_salida);
	}
	
	bool HaSalido(int indice){
		if (tunel[indice].HoraSalida() != 0){
			return true;
		}
		else{
			return false;
		}
	}
	
	double Velocidad(int indice){
		double velocidad;
		double horas;
		horas = tunel[indice].HoraSalida() - tunel[indice].HoraEntrada();
		velocidad = longitud / horas;
		return velocidad;
	}
};

int main(){
	
	const char TERMINADOR = '#';
	const char ENTRADA = 'E';
	const char SALIDA = 'S';
	char caracter;
	double longitud_tunel;
	string matricula;
	int hora, minuto, segundo;
	
	cout << "Establezca la longitud del tunel en km\n";
	cin >> longitud_tunel;
	
	Tunel tunel_gest(longitud_tunel);
	
	cout << "\nIntroduzca ahora una E (si quiere realizar una entrada) una S (si quiere realizar una salida) o un # si quiere salir\n";
	cin >> caracter;
	caracter = toupper(caracter);
	while(caracter != TERMINADOR){
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
		
		if(caracter == ENTRADA){
			tunel_gest.Entra(matricula, tiempo);
			cout << "\nEl vehiculo " << matricula << " entra en el instante " << tiempo.PrintInstante();
			cout << "\nIntroduzca la accion deseada(E/S/#)\n";
			cin >> caracter;
			caracter = toupper(caracter);
		}
		else{
			if(caracter == SALIDA){
					tunel_gest.Sale(matricula, tiempo);
					cout << "\nEl vehiculo " << matricula << " sale en el instante " << tiempo.PrintInstante();
				cout << "\nIntroduzca la accion deseada(E/S/#)\n";
				cin >> caracter;
				caracter = toupper(caracter);
			}
			else{
				cout << "No has introducido ni una E ni una S";
				cout << "\nIntroduzca la accion deseada(E/S/#)\n";
				cin >> caracter;
				caracter = toupper(caracter);
			}
		}
	}
	
	cout << "Estos son los datos recogidos durante el programa\n";
	
	for(int i = 0; i < tunel_gest.TotalEntradas(); i++){
		VehiculoTunel coche_datos;
		coche_datos = tunel_gest.Vehiculo(i);
		cout << "\nMatricula: " << coche_datos.Matricula() << '\n';
		if(tunel_gest.HaSalido(i)){
			FormateadorDoubles formateador_velocidad("\nVelocidad: " , " km/h");
			formateador_velocidad.SetNumeroDecimales(1);
			formateador_velocidad.SetSeparadorComa();
			cout << formateador_velocidad.GetCadena(tunel_gest.Velocidad(i)) << '\n';
		}
		else{
			cout << "\nVelocidad: No ha salido\n";
		}
	}
}
