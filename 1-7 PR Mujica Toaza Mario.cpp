#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Me guie a el menu de las clase anteriores pero no me corre//
void menu_principal();
void figura_geometrica_2d();
void figura_3_lados();
void figura_4_lados();
void figura_geometrica_3d();
void pantalla();

int main()
{
	char opci;
	menu_principal();
	do
	{
		pantalla();
		printf("            MENU PRINCIPAL");
		printf("Figura geometrica 2d............[ 1 ]");
		printf("Figura geometrica 3d............[ 2 ]");
		printf("Salir...........................[ 0 ]");
		printf("Elija la opcion:");
		opci=getche();
		switch(opci)
		{
			case '1':
					figura_geometrica_2d();
                    break;
			case '2':
                    figura_geometrica_3d();

		}
	}while(opci!='0');
}
void figura_geometrica_2d()
{
		char opci;
	figura_geometrica_2d();
	do
	{
		pantalla();
		printf("Figuras de 3 lados............[ 1 ]");
		printf("Figuras de 4 lados............[ 2 ]");
		printf("Salir.........................[ 0 ]");
		printf("Elija la opcion:");
		opci=getche();
		switch(opci)
		{
			case '1':
					figura_3_lados();
                    break;
			case '2':
                    figura_4_lados();

		}
	}while(opci!='0');
void figura_3_lados();
{
}
void figura_4_lados();
{
}

}

