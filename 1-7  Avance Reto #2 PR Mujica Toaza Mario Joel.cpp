#include <iostream>
#include <math.h>
using namespace std;
int opc;
int opc1,opc2;
int opc01,opc02;
void menu2d();
void menu3d();
void menu3lados();
void trianguloR();
void trianguloI();
void menu4lados();
void cuadrado();
void rectangulo();
void esfera();
void cilindro();
void prismat();
void prismar();
float Base,Base2,Altura,Lado,Hipo,AreaT,AreaC,AreaR,PerT,PerC,PerR,vol,Radio;
int main()
{
	do
	{
	
	int opc;
	cout<<"        Menu Principal"<<endl;
	cout<<"Figura geometrica 2D............[ 1 ]"<<endl;
	cout<<"Figura Geometricas 3D...........[ 2 ]"<<endl;
	cout<<"Salir...........................[ 3 ]"<<endl;
	cout<<"Elija la Opcion"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1:
			void menu2d();
		break;
		case 2 :
			void menu3d();
		break;
	}	
} while(opc !=3);
}
void menu2d(int opc1)
{
	system("cls");
	cout<<"        Menu Figuras 2D"<<endl;
	cout<<"Figura de Tres Lados....[ 1 ]"<<endl;
	cout<<"Figura de Cuatro Lados..[ 2 ]"<<endl;
	cout<<"Salir...................[ 3 ]"<<endl;
	cout<<"Elija la Opcion"<<endl;
	cin>>opc1;
	switch(opc1)	
	{
		case 1 :
			void menu3lados();
		break;
		case 2 :
			void menu4lados();
		break;
	}	
}

void menu3lados()
{
	system("CLS");
	cout<<"            Menu FIGURAS DE TRES LADOS "<<endl;
	cout<<"TRIANGULO RECTANGULO (AREA Y PERIMETRO)....[ 1 ]"<<endl;
	cout<<"TRINGULO ISOCELES (AREA Y PERIMETRO).......[ 2 ]"<<endl;
	cout<<"Salir......................................[ 3 ]"<<endl;
	cout<<"Elija la Opcion"<<endl;
	cin>>opc01;
	switch(opc01)
	{
	case 1 :
	void trianguloR();
	break;
	case 2 :
	void trianguloI();
	break;	
	}

}

void menu4lados()
{
	do
	{
		system("CLS");
		cout<<"      Menu FIGURAS DE CUATRO  LADOS "<<endl;
	    cout<<"Cuadrado (AREA Y PERIMETRO)....[ 1 ]"<<endl;
		cout<<"Rectangulo (AREA Y PERIMETRO)..[ 2 ]"<<endl;
		cout<<"Salir..........................[ 3 ]"<<endl;
		cout<<"Elija la Opcion"<<endl;
		cin>>opc02;
		switch(opc02)
		{
			case 1 :
			void cuadrado();
			break;
			case 2 :
			void rectangulo();
			
			break;
		}
	}while(opc02!=3);
}
void menu3d()
{
	do
	{
	
		system("CLS");
		cout<<" Menú FIGURAS GEOMETRICAS 3D "<<endl;
    	cout<<"ESFERA(VOLUMEN)..................[ 1 ]"<<endl;
		cout<<"PRISMA TRIANGULAR(VOLUMEN).......[ 2 ]"<<endl;
		cout<<"PRISMA RECTANGULAR(VOLUMEN)......[ 3 ]"<<endl;
		cout<<"CILINDRO(VOLUMEN)................[ 4 ]"<<endl;
		cout<<"Salir............................[ 5 ]"<<endl;
		cout<<"Elija la Opcion"<<endl;
		cin>>opc2;
		switch(opc2)
		{
			case 1 :
				void esfera();
			break;
			case 2 :
				void prismat();
			break;
			case 3 :
				void prismar();
			break;
			case 4 :
				void cilindro();
			break;
		}
	}while(opc2!=5);
}
void esfera()
{
		system("CLS");
		cout<<"ingrese su radio"<<endl;	
		cin>>Radio;
		vol=(3/4)*(3.14)*(Radio*Radio*Radio);
	    cout<<"El volumen  de la esfera es:"<<vol<<endl;
}
void prismat()
{
	system("CLS");
	cout<<"ingrese la  altura "<<endl;
	cin>>Altura;
	cout<<"Ingrese la base "<<endl;
	cin>>Base;
	vol=((Altura*(Base*Base))* sqrt(3))/4;
	cout<<"El Volumen de su prisma Triangular: "<<vol<<endl;
}
void prismar()
{
	system("CLS");
	cout<<"Ingrese su Base 1"<<endl;
	cin>>Base;
	cout<<"ingrese su Base 2"<<endl;
	cin>>Base2;
	cout<<"ingrese la Altura"<<endl;
	cin>>Altura;
	vol=Base*Base2*Altura;
	cout<<"EL volumen de ese prisma rectangular es : "<<vol<<endl;
}
void cilindro (){
	system("CLS");
	cout<<"ingrese el Radio"<<endl;
	cin>>Radio;	
	cout<<"ingrese la Altura"<<endl;
	cin>>Altura;
	vol=3.14*(Radio*Radio)*Altura;
	cout<<"El volumen del cilindro es: "<<vol<<endl;
}
void cuadrado(){
	system("CLS");
	cout<<"Ingrese un Lado:"<<endl;
	cin>>Lado;
	AreaC=Lado*Lado;
	PerC=Lado*4;
	cout<<"La Area es:"<<AreaC<<endl;
	cout<<"El Perimetro es:"<<PerC<<endl;
}
void rectangulo ()
{
		system("CLS");
		cout<<"Ingrese La Base:"<<endl;
		cin>>Base;
		cout<<"ingrese la Altura:"<<endl;
		cin>>Altura;
		AreaR=(Base*Altura);
	  	PerR=2*Altura+2*Base;
		cout<<"La Area es: "<<AreaR<<endl;
		cout<<"El Perimetro es: "<<PerR<<endl;
}
void trianguloR()
{
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
}
void trianguloI()
{
	system("CLS");
	cout<<"Ingrese La Base:"<<endl;
	cin>>Base;
	cout<<"ingrese la Altura:"<<endl;
	cin>>Altura;
	AreaT=(Base*Altura)/2;
	PerT=2*Altura+Base;
	cout<<"La Area es:"<<AreaT<<endl;
	cout<<"El Perimetro es:"<<PerT<<endl;
}
