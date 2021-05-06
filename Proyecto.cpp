#include <iostream>
using namespace std;

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
		if(n%10==1&&m%10==1){
			resultado+=pot(10,i);
		}
	}
	return resultado;
}
	
int OR(int n, int m){   //Realiza la operacion logica OR
	int resultado=0;
	for(int i=0; i<8; i++,n/=10,m/=10){
		if(n%10==1||m%10==1){
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
	
int NOT(int n){   //Realiza la operacion logica XOR
	int resultado=0;
	for(int i=0;i<8;i++,n/=10){
		if(n%10==0){
			resultado+=pot(10,i);
		}
	}
	return resultado;
}
	
int ADD(int n, int m){   //Realiza la operacion logica ADD
	int resultado=0,arrendamiento=0;
	for(int i=0;i<9;i++,n/=10,m/=10){
		switch (n%10+m%10+arrendamiento){
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

int main(int argc, char *argv[]) {
	int operacion,numero1,numero2,deseo;
	bool continuar=true;
	cout<<"Bienvenido! La siguiente es una lista de operaciones en binario:\n\n";
	//Lista de operaciones, comienza el loop
	while(continuar){
		cout<<"1. AND\n";
		cout<<"2. OR\n";
		cout<<"3. XOR\n";
		cout<<"4. NOT\n";
		cout<<"5. ADD\n\n";
		cout<<"Cual operacion desea realizar?: ";
		cin>>operacion;
		system("CLS");
		//Primer validacion de error: Numero de operacion incorrecto
		if(!cin>>operacion||operacion>5||operacion<1){
			cout<<"Error: Valor ingresado incorrecto\n\n";
			cin.ignore();
			cin.clear();
			cin.get();
		}else{
			cout<<"Digite 2 numeros enteros positivos no mayores a 255:\n";
			cout<<"1. ";
			cin>>numero1;
			cout<<"2. ";
			cin>>numero2;
			//Segunda validacion de error: Numeros ingresados incorrectos
			if(!cin>>numero1||!cin>>numero2||numero1>255||numero2>255){
				system("CLS");
				cout<<"Error: Valor ingresado incorrecto\n";
				cin.ignore();
				cin.clear();
				cin.get();
			}else{
				numero1=binario(numero1);
				numero2=binario(numero2);
				cout<<endl<<"El primer numero ingresado en binario es:    ";
				cout.fill('0');
				cout.width(8);
				cout<<numero1<<endl;
				cout<<"El segundo numero ingresado en binario es:   ";
				cout.fill('0');
				cout.width(8);
				cout<<numero2<<endl;
				//Ejecuta la operacion seleccionada
				switch (operacion){
				case 1:
					cout<<"El resultado de la operacion AND es:         ";
					cout.fill('0');
					cout.width(8);
					cout<<AND(numero1,numero2)<<endl;
					break;
				case 2:
					cout<<"El resultado de la operacion OR es:          ";
					cout.fill('0');
					cout.width(8);
					cout<<OR(numero1,numero2)<<endl;
					break;
				case 3:
					cout<<"El resultado de la operacion XOR es:         ";
					cout.fill('0');
					cout.width(8);
					cout<<XOR(numero1,numero2)<<endl;
					break;
				case 4:
					cout<<"El resultado 1 de la operacion NOT es:       ";
					cout.fill('0');
					cout.width(8);
					cout<<NOT(numero1)<<endl;
					cout<<"El resultado 2 de la operacion NOT es:       ";
					cout.fill('0');
					cout.width(8);
					cout<<NOT(numero2)<<endl;
					break;
				case 5:
					cout<<"El resultado de la operacion ADD es:         ";
					cout.fill('0');
					cout.width(8);
					cout<<ADD(numero1,numero2)<<endl;
					break;
				}
			}
			
		}
		//Opcion del usuario de continuar en el sistema
		cout<<"\nDesea continuar?\nSi : 1 || No : Cualquier otro numero\n";
		cin>>deseo;
		continuar=deseo==1;
		system("CLS");
	}
	cout<<"Hasta luego!!!";
	return 0;
}
