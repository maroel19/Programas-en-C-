/*ARCHIVOS CABECERAS*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
/*DECLARACION DE FUNCIONES*/
char menu();
void ingreso_pila();
void presentar_pila();
void quitar_pila();
void ingresar_arreglo();
void presentar_arreglo();
void quitar_arreglo();
void bp();
void poscf(int colu,int fila);
void marco(int col1,int fil1,int col2, int fil2);
void pantalla();
/*DECLARACION DE VARIABLES*/
struct sestudiante
{
	int codi;		//CODIGO DEL ALUMNO
	int estatura;	//ESTATURA DE ALUMNO
	char nomb[25];	//NOMBRE DEL ALUMNO
	char estado[25];//ESTADO CIVIL DEL ALUMNO
	int edad;		//EDAD DEL ALUMNO 
	 
}estu[200];

int vcod; 	//CONTADOR DE LA CANTIDAD DE DATOS INGRESADO
int vsec=1; //VARIABLE QUE CONTROLA LA SECUENCIA DEL CODIGO
int main()
{
	char resu;
	do
	{
		pantalla();
		resu=menu();
		switch(resu)
		{
			case '1':
				ingresar_arreglo();
				break;
			case '2':
				presentar_arreglo();
				break;
			case '3':
				quitar_arreglo();
				break;
		}
	}while(resu!= '0');
}
char menu()
{
	char opci;
	poscf(3,10);printf("                MENU ALUMNO");
	poscf(3,11);printf("Ingresar........................................[ 1 ]");
	poscf(3,12);printf("Modificar.......................................[ 2 ]");
	poscf(3,13);printf("Eliminar........................................[ 3 ]");
	poscf(3,14);printf("Consulta Individual.............................[ 4 ]");
	poscf(3,15);printf("Oredenamiento por apellido Ascendente...........[ 5 ]");
	poscf(3,16);printf("Ordenamiendo por apellido Descendente...........[ 6 ]");
	poscf(3,17);printf("Salir...........................................[ 0 ]");
	poscf(3,18);printf("Elija la opcion:");
	opci=getche();
	return opci;
}
/*DESARROLLO DE FUNCION*/
void ingresar_arreglo()
{
char auxi[50];
	pantalla();
	poscf(10,9);printf("       INGRESO DE DATOS");
	
	poscf(7,10);printf("Codigo del estudiante.........: %i",vsec);
	estu[vcod].codi=vsec;  
	
	poscf(7,11);printf("Nombre del Alumno....: ");
	gets(estu[vcod].nomb);
	
	poscf(7,12);printf("Estado del Alumno....: ");
	gets(estu[vcod].nomb);
	
	poscf(7,13);printf("Estatura del Alumno...........: ");
	gets(auxi);						
	estu[vcod].estatura=atoi(auxi);

	
	poscf(7,14);printf("Edad del Alumno.....................: ");
	gets(auxi);						
	estu[vcod].edad=atoi(auxi);
			
	vcod++;	
	vsec++;
}

void eliminar_arreglo()
{
	char auxi[50];
	int posi=0;
	int posj=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	printf("\n ELIMINAR DE DATOS");
	printf("\n Codigo de profesion a eliminar...: ");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<cprof;posi++)
	{
		if(codi[posi]==dato)
		{
			printf("\n Codigo del Alumno ................: %i ",codi[posi]);
			printf("\n Nombre del Alumno ...........: %s ",prof[posi][0]);
			printf("\n Edad del Alumno ................: %i ",prof[posi][1]);
			printf("\n Estado del Alumno ..............: %s ",prof[posi][2]);
			
			band=1;
			
			for(posj=posi;posj<cprof;posj++)
			{
				codi[posj]=codi[posj+1];
				strcpy(prof[posj][0],prof[posj+1][0]);
				strcpy(prof[posj][1],prof[posj+1][1]);
				strcpy(prof[posj][2],prof[posj+1][2]);

			}
			posi=posj;
			cprof--;
		}

	}
	if(band==0)
	{
		printf("\n EL REGISTRO NO EXISTE !!!!!");
	}		
	
}

void presentar_arreglo()
{
	int posi=0;
	poscf(61,1);printf("Cod.");
	poscf(66,1);printf("Nombres");
	poscf(99,1);printf("Estatura");
	poscf(109,1);printf("Edad");
	for(posi=0;posi<58;posi++)
	{
		poscf(61+posi,2);printf("=");
		poscf(61+posi,27);printf("=");
	}
	for(posi=0;posi<vcod;posi++)
	{
		poscf(61,3+posi);printf("%i",estu[posi].codi);
		poscf(66,3+posi);printf("%s %s",estu[posi].nomb);
		poscf(99,3+posi);printf("%s",estu[posi].estatura);
		poscf(109,3+posi);printf("%i",estu[posi].edad);
	}
}

void bp()
{
	system("cls");
}
void poscf(int colu,int fila)
{
	COORD coord;
	coord.X=colu;
	coord.Y=fila;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);	
}
void marco(int col1,int fil1,int col2, int fil2)
{
	int posi=0;
	for(posi=fil1;posi<fil2;posi++)
	{
		poscf(col1,posi);printf("%c",186);
		poscf(col2,posi);printf("%c",186);
	}
	for(posi=col1;posi<col2;posi++)
	{
		poscf(posi,fil1);printf("%c",205);
		poscf(posi,fil2);printf("%c",205);
	}
	poscf(col1,fil1);printf("%c",201);
	poscf(col2,fil1);printf("%c",187);
	poscf(col1,fil2);printf("%c",200);
	poscf(col2,fil2);printf("%c",188);
}
void pantalla()
{
	bp();
	marco(0,0,59,29);
	marco(60,0,119,29);
	marco(1,1,58,7);
	poscf(2,2);printf("               UNIVERSIDAD DE GUAYAQUIL");
	poscf(2,3);printf("             TECNOLOGIA DE LA INFORMACION");
	poscf(2,4);printf("                 ESTRUCTURA DE DATOS");
	poscf(2,5);printf("                   SEGUNDO SEMESTRE");
	poscf(2,6);printf("                 EXAMEN DEL PARCIAL 1");
	poscf(62,28);printf("Anterior                                       Siguiente");
	/*consulta_general();*/
	
}

