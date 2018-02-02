#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define PI 3.14159265 

//Verifica si un numero es triangular 
bool verificacionDelNumero(int);
int GeneradorRandom();
int VerificarTriangularAnterior(int);
void Ejercicio1();
void Ejercicio2();
int main(){
	int opcionmain;
	cout<<"Menu Principal"<<endl;
	cout<<"1.Ejercicio 1"<<endl;
	cout<<"2.Ejercicio 2"<<endl;
	cout<<"3.Ejercicio 3"<<endl;
	cin>>opcionmain;
	switch(opcionmain){
		case 1:
			Ejercicio1();
			break;
		case 2:
			Ejercicio2()
	}
	return 0;
}
void Ejercicio1(){
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
		contador++;
		acumuladordelwhile=contador;
		if(acumuladordelwhile>=numeroAevaluar){
			return acumuladordelwhile-contador;
		}

	}
}
int GeneradorRandom(){
	srand (time(NULL));
	int random= rand() % 100 +1;
	cout<<"el numero es:"<<random;
	return random;
}
void Ejercicio2(){
	float lado1;
	float lado2;
	float lado3;

	cout<<"Ingrese las dimensiones del triangulo"<<endl;
	cin>>lado1;
	cin>>lado2;
	cin>>lado3;
	if(lado1+lado2<lado3||lado2+lado3<lado1||lado1+lado3=lado2){
		cout<<"No se puede hacer un triangulo con estas dmensiones"<<endl;
	}else{
		float AnguloA= (acos(((lado2^2)+(lado3^2)-(lado1^2))/(2*lado2*lado3)))*180/PI;
		float AnguloB= (acos(((lado1^2)+(lado3^2)-(lado2^2))/(2*lado1*lado3)))*180/PI;
		float AnguloC= (acos(((lado1^2)+(lado2^2)-(lado3^3))/(2*lado1*lado2)))*180/PI;
		cout<<"El angulo A :"<<AnguloA<<endl;
		cout<<"El angulo B :"<<AnguloB<<endl;
		cout<<"El angulo C :"<<AnguloC<<endl;
		if(AnguloA==90||AnguloB==90||AnguloC==90){
			cout<<"El triangulo es rectangulo"<<endl;
		}else{
			cout<<"El triangulo no es rectangulo"<<endl;
		}
		float semiperimetro=(lado1+lado2+lado3)/2;
		float Area=sqrt(semiperimetro*(semiperimetro-lado1)*(semiperimetro-lado2)*(semiperimetro-lado3));
		cout<<"El area del triangulo es :"<<Area<<endl;
	}
}

