#include <iostream>
using namespace std;

/* Programadores: Jorge Andres Duran Campos y Diego Quiros Artiñano
   Fecha: 09/05/2021
   Objetivo del programa: Calcular operaciones logicas binarias a partir de 2
   numeros enteros proporcionados por el usuario.
*/

int pot(int n, int e){   //Calcula potencias (El pow() de la biblioteca <math.h> daba errores no deseados)
	int potencia=1;
	for(int i=1;i<=e;i++){
		potencia*=n;
	}
	return potencia;
}

int binario(int n){   //Convierte el numero int a numero binario
	int resultado=0;
	for(int i=0;i<8;i++,n/=2){
		resultado+=(n%2)*(pot(10,i));
	}
	return resultado;
}
	
int AND(int n, int m){   //Realiza la operacion logica AND
	int resultado=0;
	for(int i=0;i<8;i++,n/=10,m/=10){
		if(n%10==1 && m%10==1){
			resultado+=pot(10,i);
		}
	}
	return resultado;
}
	
int OR(int n, int m){   //Realiza la operacion logica OR
	int resultado=0;
	for(int i=0; i<8; i++,n/=10,m/=10){
		if(n%10==1 || m%10==1){
			resultado+=pot(10,i);
		}
	}
	return resultado;
}
	
int XOR(int n, int m){   //Realiza la operacion logica XOR
	int resultado=0;
	for(int i=0;i<8;i++,n/=10,m/=10){
		if(n%10!=m%10){
			resultado+=pot(10,i);
		}
	}
	return resultado;
}
	
int NOT(int n){   //Realiza la operacion logica NOT
	int resultado=0;
	for(int i=0;i<8;i++,n/=10){
		if(n%10==0){
			resultado+=pot(10,i);
		}
	}
	return resultado;
}
	
int ADD(int n, int m){   //Realiza la operacion logica ADD
	int resultado=0;
	int arrendamiento=0;
	for(int i=0;i<9;i++,n/=10,m/=10){
		switch (n%10 + m%10 + arrendamiento){   //Da como resultado los "1" que se están sumando en la respectiva columna
		case 0:
			arrendamiento=0;
			break;
		case 1:
			arrendamiento=0;
			resultado+=pot(10,i);
			break;
		case 2:
			arrendamiento=1;
			break;
		case 3:
			arrendamiento=1;
			resultado+=pot(10,i);
			break;
		}
	}
	return resultado;
}
	
string menu(){   //Guarda la lista de funciones para mostrarla al usuario en el main
	string lista;
	lista+="1. AND\n";
	lista+="2. OR\n";
	lista+="3. XOR\n";
	lista+="4. NOT\n";
	lista+="5. ADD\n";
	lista+="Que accion desea realizar?: ";
	return lista;
}

int main(int argc, char *argv[]) {
	int operacion;
	int numero1;
	int numero2;
	int deseo;
	bool continuar;
	do{
		system("CLS");
		cout<<menu();
		cin>>operacion;
		system("CLS");
		switch(operacion){
		case 1:
			cout<<"Digite el numero 1: ";
			cin>>numero1;
			cout<<"Digite el numero 2: ";
			cin>>numero2;
			//Primer validación de error: Numero mayor a 255 o tipo de digito incorrecto
			if(numero1<0||numero1>255||numero2<0||numero2>255||!cin>>numero1||!cin>>numero2){
				cout<<"\n\nError: Digito ingresado incorrecto";
				cin.ignore();
				cin.clear();
				cin.get();
				break;
			}
			numero1=binario(numero1);
			numero2=binario(numero2);
			cout<<endl<<"El numero 1 en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero1;
			cout<<endl<<"El numero 2 en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero2;
			cout<<endl<<" AND de ambos numeros es:  ";
			cout.fill('0');
			cout.width(8);
			cout<<AND(numero1,numero2);
			break;
		case 2:
			cout<<"Digite el numero 1: ";
			cin>>numero1;
			cout<<"Digite el numero 2: ";
			cin>>numero2;
			//Primer validación de error: Numero mayor a 255 o tipo de digito incorrecto
			if(numero1<0||numero1>255||numero2<0||numero2>255||!cin>>numero1||!cin>>numero2){
				cout<<"\n\nError: Digito ingresado incorrecto";
				cin.ignore();
				cin.clear();
				cin.get();
				break;
			}
			numero1=binario(numero1);
			numero2=binario(numero2);
			cout<<endl<<"El numero 1 en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero1;
			cout<<endl<<"El numero 2 en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero2;
			cout<<endl<<"  OR de ambos numeros es:  ";
			cout.fill('0');
			cout.width(8);
			cout<<OR(numero1,numero2);
			break;
		case 3:
			cout<<"Digite el numero 1: ";
			cin>>numero1;
			cout<<"Digite el numero 2: ";
			cin>>numero2;
			//Primer validación de error: Numero mayor a 255 o tipo de digito incorrecto
			if(numero1<0||numero1>255||numero2<0||numero2>255||!cin>>numero1||!cin>>numero2){
				cout<<"\n\nError: Digito ingresado incorrecto";
				cin.ignore();
				cin.clear();
				cin.get();
				break;
			}
			numero1=binario(numero1);
			numero2=binario(numero2);
			cout<<endl<<"El numero 1 en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero1;
			cout<<endl<<"El numero 2 en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero2;
			cout<<endl<<" XOR de ambos numeros es:  ";
			cout.fill('0');
			cout.width(8);
			cout<<XOR(numero1,numero2);
			break;
		case 4:
			cout<<"Digite el numero: ";
			cin>>numero1;
			//Primer validación de error: Numero mayor a 255 o tipo de digito incorrecto
			if(numero1<0||numero1>255||!cin>>numero1){
				cout<<"\n\nError: Digito ingresado incorrecto";
				cin.ignore();
				cin.clear();
				cin.get();
				break;
			}
			numero1=binario(numero1);
			cout<<endl<<"El numero en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero1;
			cout<<endl<<"   NOT del numero es:    ";
			cout.fill('0');
			cout.width(8);
			cout<<NOT(numero1);
			break;
		case 5:
			cout<<"Digite el numero 1: ";
			cin>>numero1;
			cout<<"Digite el numero 2: ";
			cin>>numero2;
			//Primer validación de error: Numero mayor a 255 o tipo de digito incorrecto
			if(numero1<0||numero1>255||numero2<0||numero2>255||!cin>>numero1||!cin>>numero2){
				cout<<"\n\nError: Digito ingresado incorrecto";
				cin.ignore();
				cin.clear();
				cin.get();
				break;
			}
			numero1=binario(numero1);
			numero2=binario(numero2);
			cout<<endl<<"El numero 1 en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero1;
			cout<<endl<<"El numero 2 en binario es: ";
			cout.fill('0');
			cout.width(8);
			cout<<numero2;
			cout<<endl<<" ADD de ambos numeros es:  ";
			cout.fill('0');
			cout.width(8);
			cout<<ADD(numero1,numero2);
			break;
		default:
			//Segunda validación de error: Numero de operacion o tipo de digito incorrecto
			cout<<"\nError: Digito ingresado incorrecto";
			if(!cin>>operacion){
				cin.ignore();
				cin.clear();
				cin.get();
			}
		}
		cout<<"\n\nDesea seguir realizando operaciones?\n";
		cout<<"Si = 1 || No = 0 : ";
		cin>>deseo;
		continuar=deseo==1;
	} while(continuar);
	system("CLS");
	cout<<"Hasta luego!!!";
	return 0;
}
