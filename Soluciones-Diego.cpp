//La manera en la que lo soluciono Diego
#include <iostream>
using namespace std;

int pot(int base, int exp) {
    int solucion = 1;
	for(int i = 1; i <= exp; i++) {
        solucion *= base;
    }
    return solucion;
}

int longbin(int n) {
    int numdigi = 0;
    for(int i = n; i > 0; i /= 2) {
        numdigi++;
    }
    return numdigi;
}

int deciBin(int n) {
    int binario = 0, ntemp = n;
	
    for(int i = 0; i < longbin(n); i++) {
		binario += (ntemp % 2) * pot(10, i);
		ntemp /= 2;
    }

    return binario;
}

int _AND(int a, int b){
	int solucion = 0, atemp = a, btemp = b;
	int i = 0;

    while(atemp != 0 && btemp != 0) {
        if(atemp % 10 == 1 && btemp % 10 == 1){
            solucion += 1 * pot(10, i);
        } else {
            solucion += 0 * pot(10, i);
        }
        atemp /= 10;
        btemp /= 10;
        i++;
    }

	return solucion;
}

int _OR(int a, int b) {
	int solucion = 0, atemp = a, btemp = b;
	int i = 0;

    while(atemp != 0 && btemp != 0){
        if(atemp % 10 == 1 || btemp % 10 == 1) {
            solucion += 1 * pot(10, i);
        } else {
            solucion += 0 * pot(10, i);
        }
        atemp /= 10;
        btemp /= 10;
        i++;
    }
    
    return solucion;
}

int _XOR(int a, int b) {
	int solucion = 0, atemp = a, btemp = b;
	int i = 0;

    while(atemp != 0 && btemp != 0) {
        if(atemp % 10 == 1 && btemp % 10 == 0) {
            solucion += 1 * pot(10, i);
        } else if (atemp % 10 == 0 && btemp % 10 == 1) {
            solucion += 1 * pot(10, i);
        } else {
            solucion += 0 * pot(10, i);
        }
        atemp /= 10;
        btemp /= 10;
        i++;
    }

    return solucion;
}

int _NOT(int a) {
	int solucion = 0, atemp = a;
    int i = 0;

    while(atemp != 0){
        if(atemp % 10 == 1) {
            solucion += 0 * pot(10, i);
        } else {
            solucion += 1 * pot(10, i);
        }
        atemp /= 10;
        i++;
    }

	return solucion;
}

int _ADD(int a, int b) {
	int solucion = 0, atemp = a, btemp = b, acarreo = 0;
	int i = 0;
    
    while(atemp != 0 && btemp != 0) {
        if(acarreo + (atemp % 10) + (btemp % 10) == 3) {
            solucion += 1 * pot(10, i);
            acarreo = 1;
        } else if(acarreo + (atemp % 10) + (btemp % 10) == 2) {
            solucion += 0 * pot(10, i);
            acarreo = 1;
        } else if(acarreo + (atemp % 10) + (btemp % 10) == 1) {
            solucion += 1 * pot(10, i);
            acarreo = 0;
        } else {
            solucion += 0 * pot(10, i);
            acarreo = 0;
        }
        atemp /= 10;
        btemp /= 10;
        i++;
    }
	if(acarreo != 0){
		solucion += acarreo * pot(10, i);
	}
    return solucion;
}

int main(int argc, char *argv[]) {
    int number1, number2;
	cin >> number1;
    cin >> number2;
	cout << _AND(number1, number2) << endl;
    cout << _OR(number1, number2) << endl;
    cout << _XOR(number1, number2) << endl;
    cout << _NOT(number1) << endl;
    cout << _ADD(number1, number2) << endl;
    return 0;
}
