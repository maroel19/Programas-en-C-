#include <iostream>
#include <math.h>
using namespace std;
int main (){
	int Opc,Opc1,Opc2;int OpcO1,OpcO2;int OpcP;
	float Base,Base2,Altura,Lado,Hipo,AreaT,AreaC,AreaR,PerT,PerC,PerR,vol,Radio;
	
	cout<<"        Menu Principal"<<endl;
	cout<<"Figura geometrica 2D............[ 1 ]"<<endl;
	cout<<"Figura Geometricas 3D...........[ 2 ]"<<endl;
	cout<<"Salir...........................[ 3 ]"<<endl;
	cout<<"Elija la Opcion"<<endl;
	cin>>Opc;
	switch(Opc)
	{
		case 1 :
			do{
			
			system("CLS");
				cout<<"        Menu Figuras 2D"<<endl;
	        	cout<<"Figura de Tres Lados....[ 1 ]"<<endl;
				cout<<"Figura de Cuatro Lados..[ 2 ]"<<endl;
				cout<<"Salir...................[ 3 ]"<<endl;
				cout<<"Elija la Opcion"<<endl;
				cin>>Opc1;
				switch(Opc1)
				{
					case 1 :
					system("CLS");
					cout<<"            Menu FIGURAS DE TRES LADOS "<<endl;
	        		cout<<"TRIANGULO RECTANGULO (AREA Y PERIMETRO)....[ 1 ]"<<endl;
					cout<<"TRINGULO ISOCELES (AREA Y PERIMETRO).......[ 2 ]"<<endl;
					cout<<"Salir......................................[ 3 ]"<<endl;
					cout<<"Elija la Opcion"<<endl;
					cin>>OpcO1;
					switch(OpcO1)
					{
						case 1:
							system("CLS");
							cout<<"Ingrese La Base:"<<endl;
							cin>>Base;
							cout<<"ingrese la Altura:"<<endl;
							cin>>Altura;
							cout<<"Ingrese la Hipotenusa"<<endl;
							cin>>Hipo;
							AreaT=(Base*Altura)/2;
							PerT=Base+Altura+Hipo;
							cout<<"La Area es:"<<AreaT<<endl;
							cout<<"El Perimetro es:"<<PerT<<endl;
						break;
					
						case 2:
							system("CLS");
							cout<<"Ingrese La Base:"<<endl;
							cin>>Base;
							cout<<"ingrese la Altura:"<<endl;
							cin>>Altura;
							AreaT=(Base*Altura)/2;
							PerT=2*Altura+Base;
							cout<<"La Area es:"<<AreaT<<endl;
							cout<<"El Perimetro es:"<<PerT<<endl;
						break;
				
					
					}
					break;
			
				case 2:
			
					system("CLS");
					cout<<"      Menu FIGURAS DE CUATRO  LADOS "<<endl;
	        		cout<<"Cuadrado (AREA Y PERIMETRO)....[ 1 ]"<<endl;
					cout<<"Rectangulo (AREA Y PERIMETRO)..[ 2 ]"<<endl;
					cout<<"Salir..........................[ 3 ]"<<endl;
					cout<<"Elija la Opcion"<<endl;
					cin>>OpcO2;
					switch(OpcO2)
					{
						case 1:
							system("CLS");
							cout<<"Ingrese un Lado:"<<endl;
							cin>>Lado;
							AreaC=Lado*Lado;
							PerC=Lado*4;
							cout<<"La Area es:"<<AreaC<<endl;
							cout<<"El Perimetro es:"<<PerC<<endl;
						break;
					
						case 2:
							system("CLS");
							cout<<"Ingrese La Base:"<<endl;
							cin>>Base;
							cout<<"ingrese la Altura:"<<endl;
							cin>>Altura;
							AreaR=(Base*Altura);
							PerR=2*Altura+2*Base;
							cout<<"La Area es: "<<AreaR<<endl;
							cout<<"El Perimetro es: "<<PerR<<endl;
						break;
				
				}
			}
		}while (Opc1 !=3);
		break;
		case 2:
			switch(Opc2)
			{
			case 1 :
				do{
				
					system("CLS");
					cout<<" Menú FIGURAS GEOMETRICAS 3D "<<endl;
	        		cout<<"ESFERA(VOLUMEN)..................[ 1 ]"<<endl;
					cout<<"PRISMA TRIANGULAR(VOLUMEN).......[ 2 ]"<<endl;
					cout<<"PRISMA RECTANGULAR(VOLUMEN)......[ 3 ]"<<endl;
					cout<<"CILINDRO(VOLUMEN)................[ 4 ]"<<endl;
					cout<<"Salir............................[ 5 ]"<<endl;
					cout<<"Elija la Opcion"<<endl;
					cin>>OpcP;
					switch(OpcP)
					{
						case 1:
							system("CLS");
							cout<<"ingrese su radio"<<endl;	
							cin>>Radio;
							vol=(3/4)*(3.14)*(Radio*Radio*Radio);
							cout<<"El volumen  de la esfera es:"<<vol<<endl;
						break;
						case 2:
							system("CLS");
							cout<<"ingrese la  altura "<<endl;
							cin>>Altura;
							cout<<"Ingrese la base "<<endl;
							cin>>Base;
							vol=((Altura*(Base*Base))* sqrt(3))/4;
							cout<<"El Volumen de su prisma Triangular: "<<vol<<endl;
						break;
						case 3 :
							system("CLS");
							cout<<"Ingrese su Base 1"<<endl;
							cin>>Base;
							cout<<"ingrese su Base 2"<<endl;
							cin>>Base2;
							cout<<"ingrese la Altura"<<endl;
							cin>>Altura;
							vol=Base*Base2*Altura;
							cout<<"EL volumen de ese prisma rectangular es : "<<vol<<endl;
						break;
						case 4 :
							system("CLS");
							cout<<"ingrese el Radio"<<endl;
							cin>>Radio;	
							cout<<"ingrese la Altura"<<endl;
							cin>>Altura;
							vol=3.14*(Radio*Radio)*Altura;
							cout<<"El volumen del cilindro es: "<<vol<<endl;
						break;
					}
				}while(OpcP !=5);
			}
		break;
	}
}
