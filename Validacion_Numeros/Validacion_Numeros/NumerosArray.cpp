#include<iostream>
#include<math.h>

using namespace std;

bool esPar(int n) {
	bool decision = false;
	if (n % 2 == 0) {
		decision = true;
	}
	return decision;
}

bool isPrime(int numero) {
	bool decision = false;
	if (numero >= 2) {
		int value = (int)pow(numero, 0.5);
		decision = true;
		for (int x = 2; x <= value; x++) {
			if (numero % x == 0) {
				decision = false;
				break;
			}
		} 
	}
	return decision;
}

void imprimirReporte(string tipoDeNumero, int* arreglo, int iArreglo) {
	cout << "Numeros " << tipoDeNumero << ": ";
	int s = 0;
	for (int j = 0; j < iArreglo; j++) {
		cout << arreglo[j] << ", ";
		s += arreglo[j];
	}
	cout << endl;
	cout << "Total de numeros " << tipoDeNumero << ": " << iArreglo << endl;
	cout << "Suma de los numeros " << tipoDeNumero << ": " << s << endl << endl;
}


int main() {

	bool seguir = true;
	int numero;
	char decision;
	int primos[100];
	int noPrimos[100];
	int pares[100];
	int impares[100];
	int i = 0;
	int iPrimos = 0;
	int iNoPrimos = 0;
	int iPares = 0;
	int iImpares = 0;
	int s;
	do {
		cout << "Ingresa un numero entero: ";
		cin >> numero;

		if (esPar(numero)) {
			pares[iPares] = numero;
			iPares++;
		}
		else {
			impares[iImpares] = numero;
			iImpares++;
		}

		if (isPrime(numero)) {
			primos[iPrimos] = numero;
			iPrimos++;
		}
		else {
			noPrimos[iNoPrimos] = numero;
			iNoPrimos++;
		}

		i++;
		if (iPrimos < 100 && iNoPrimos < 100 && iPares < 100 && iImpares < 100) {
			cout << "Desea ingresar otro numero? (S/N): ";
			cin >> decision;
			switch (decision) {
			case 's':
			case 'S':
				break;
			case 'n':
			case 'N':
				seguir = false;
				break;
			}
		}
	} while (seguir && iPrimos < 100 && iNoPrimos < 100 && iPares < 100 && iImpares < 100);

	cout << endl;

	imprimirReporte("pares", pares, iPares);
	imprimirReporte("impares", impares, iImpares);
	imprimirReporte("primos", primos, iPrimos);
	imprimirReporte("noPrimos", noPrimos, iNoPrimos);

	return 0;
}


