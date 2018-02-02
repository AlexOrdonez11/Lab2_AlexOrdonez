#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

//Verifica si un numero es triangular 
bool verificacionDelNumero(int);
int GeneradorRandom();
int VerificarTriangularAnterior(int);

int main(){
	char AnsofUser='s';
	while(AnsofUser=='s'||AnsofUser=='S'){
		cout<<"Menu:"<<endl;
		cout<<"1.-Ingresar un numero y ver si es triangular"<<endl;
		cout<<"2.-Determinar si un numero aleatorio es triangular"<<endl;
		cout<<"3.-Determina el numero triagular previo al numero ingreasdo"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"Ingrese su opcion :";
		int opciontomada;
		cin>>opciontomada;
		switch(opciontomada){
			case 1:
				int numeroparaevaluar;
				cout<<"Ingrese el numero que quiere evaluar :";
				cin>>numeroparaevaluar;
				if(verificacionDelNumero(numeroparaevaluar)){
					cout<<"El numero es triangular"<<endl;
				}else{
					cout<<"El numero no es triangular"<<endl;
				}
				break;
			case 2:
				if(verificacionDelNumero(GeneradorRandom())){
					cout<<"El numero es triangular"<<endl;
				}else{
					cout<<"El numero no es triangular"<<endl;
				}
				break;
			case 3:
				int numeroAevaluar;
				cout<<"Ingrese el numero que quiere evaluar :";
				cin>>numeroAevaluar;
				cout<<"El numero anterior triangular es :"<<VerificarTriangularAnterior(numeroAevaluar)<<endl;
				break;
		}
		cout<<"Desea continuar [s/n]:";
		cin>>AnsofUser;
	}
	
	return 0;
}
bool verificacionDelNumero(int numeroAevaluar){
	int acumuladordelwhile=0;
	int contador=0;
	while(acumuladordelwhile<numeroAevaluar){
		contador++;
		acumuladordelwhile+=contador;
		if(acumuladordelwhile==numeroAevaluar){
			return true;
		}else{
			if(acumuladordelwhile>numeroAevaluar){
				return false;
			}
		}
	}
}
int VerificarTriangularAnterior(int numeroAevaluar){
	int acumuladordelwhile=0;
	int contador=0;
	while(acumuladordelwhile<numeroAevaluar){
		acumuladordelwhile=contador+(contador+1);
		if(acumuladordelwhile>=numeroAevaluar){
			return acumuladordelwhile-(contador+1);
		}
		contador++;	

	}
}
int GeneradorRandom(){
	srand (time(NULL));
	int random= rand() % 100 +1;
	cout<<"el numero es:"<<random;
	return random;
}


