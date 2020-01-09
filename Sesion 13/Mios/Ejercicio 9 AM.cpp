#include <iostream>
#include <string>

using namespace std;

class Dinero{
private:
	int euros;
	int centimos;
	
	void CuadrarSaldo(){
		int euros_ganados = 0;
		int euros_centimos = 100;
		if(centimos >= euros_centimos){
			while(centimos >= euros_centimos){
				centimos = centimos - euros_centimos;
				euros_ganados++;
			}
		}
		euros = euros + euros_ganados;
	}
	
public:
	Dinero()
	:euros(0),
	 centimos(0)
	{
	}

	void SetSaldo(int saldo_euros, int saldo_centimos){
		euros = saldo_euros;
		centimos = saldo_centimos;
		CuadrarSaldo();
	}

	string PrintDinero(){
		string dinero;
		dinero = 
		to_string(euros) + '.' + to_string(centimos);
					
		return dinero;
	}
	
	int SaldoEuros(){
		return euros;
	}
	
	int SaldoCentimos(){
		return centimos;
	}
	
	Dinero Suma( Dinero cantidad_sumar){
		Dinero suma_dineros;
		
		suma_dineros.SetSaldo(euros + cantidad_sumar.SaldoEuros(),
									centimos + cantidad_sumar.SaldoCentimos()
									);
		
		return suma_dineros;
	}	
};

int main(){
	Dinero cuenta, monedero, suma;
	int euros_cuenta, euros_monedero;
	int centimos_cuenta, centimos_monedero;
	
	cout << "Introduzca saldo de la cuenta (Euros, Centimos)\n";
	cin >> euros_cuenta;
	cin >> centimos_cuenta;
	
	cuenta.SetSaldo(euros_cuenta, centimos_cuenta);
	
	cout << "Introduzca saldo del monedero (Euros, Centimos)\n";
	cin >> euros_monedero;
	cin >> centimos_monedero;
	
	monedero.SetSaldo(euros_monedero, centimos_monedero);
	suma = cuenta.Suma(monedero);

	cout << "Tinene un total de: ";
	cout << suma.PrintDinero();
}
