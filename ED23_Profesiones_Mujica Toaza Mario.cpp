/*MANTENIMIENTO DE PROFESIONES*/
/*ARCHIVO CABECERAS*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
/*DECLARACACION DE FUNCION*/
char menu_profesiones();
void Ingreso();
void Modificacion();
void Eliminacion();
void Consulta_individual();
void Consulta_General();
void Ordenar_Ascendente_codigo();
void Ordenar_descendente_codigo();
void Ordenar_Ascendente_descripcion();
void Ordenar_descendente_descripcion();
/*DECLARACION DE VARIABLES*/
int codi[100];        //CODIGO PROFESION
char prof[100][3][30];  // DESCRIPCION DE PROFESION , SIGLAS DE LA PROFESION , ESTADO DE LA PROFESION 
int cprof;  //CONTADOR DE INGRESO DE PROFESIONES

int main()
{
	char resu;
	do
	{
		resu=menu_profesiones();
		switch(resu)
		{
			case '1':
				Ingreso();	
				break;
			case '2':
				Modificacion();
				break;
			case '3':
				Eliminacion();
				break;
			case '4':
				Consulta_individual();
				break;
			case '5':
				Consulta_General();
				break;
			case '6':
				Ordenar_Ascendente_codigo();
				break;
			case '7':
				Ordenar_descendente_codigo();
				break;
			case '8':
				Ordenar_Ascendente_descripcion();
				break;
			case '9':
				Ordenar_descendente_descripcion();
		}
	}while(resu!='0');
	
}
/*DESARROLLO DE LAS FUNCIONES*/
char menu_profesiones()
{
	char opci;	
	printf("\n MENU PRINCIPAL");
	printf("\n Ingreso.............................[1]");
	printf("\n Modificacion........................[2]");
	printf("\n Eliminacion.........................[3]");
	printf("\n Consulta individual.................[4]");
	printf("\n Consulta General....................[5]");
	printf("\n Ordenar Ascendente por codigo.......[6]");
	printf("\n Ordenar descendente por codigo......[7]");
	printf("\n Ordenar Ascendente por descripcion..[8]");
	printf("\n Ordenar descendente por descripcion [9]");
	printf("\n Salir...............................[0]");
	printf("\n Elija la opcion: ");
	opci=getch();
	return opci;
}

void Ingreso()
{
	char auxi[50];
	printf("\n INGRESO DE DATOS");
	
	printf("\n Codigo de profesion........: ");
	gets(auxi);
	codi[cprof]=atoi(auxi); 
	
	printf("\n Descripcion de la profesion...: ");
	gets(prof[cprof][0]);
	
	printf("\n Siglas de la profesion ...: ");
	gets(prof[cprof][1]);
	
	printf("\n Estado de la profesion ...: ");
	gets(prof[cprof][2]);
	
	
	cprof++;	
}
void Modificacion()
{
	char auxi[50];
	int posi=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	printf("\n MODIFICAR DE DATOS");
	printf("\n Codigo de profesion a modificar...: ");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<cprof;posi++)
	{
		if(codi[posi]==dato)
		{
			printf("\n Codigo de profesion ................: %i ",codi[posi]);
			printf("\n Descripcion de profesion ...........: %s ",prof[posi][0]);
			printf("\n Siglas de profesion ................: %s ",prof[posi][1]);
			printf("\n Estado de la profesion..............: %s ",prof[posi][2]);

			band=1;
			
			printf("\n Descripcion de nueva profesion....: ");
			gets(prof[posi][0]);
	
			printf("\n Siglas de nueva profesion...: ");
			gets(prof[posi][1]);
			
			printf("\n Estado de nueva profesion...: ");
			gets(prof[posi][2]);
			
		}

	}
	if(band==0)
	{
		printf("\n EL REGISTRO NO EXISTE !!!!!");
	}		
}
void Eliminacion()
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
			printf("\n Codigo de profesion ................: %i ",codi[posi]);
			printf("\n Descripcion de profesion ...........: %s ",prof[posi][0]);
			printf("\n Siglas de profesion ................: %s ",prof[posi][1]);
			printf("\n Estado de la profesion..............: %s ",prof[posi][2]);
			
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
void Consulta_individual()
{
	char auxi[50];
	int posi=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	printf("\n CONSULTA INDIVIDUAL DE DATOS");
	printf("\n Codigo de profesion a buscar...: ");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<cprof;posi++)
	{
		if(codi[posi]==dato)
		{
			printf("\n Codigo de profesion ................: %i ",codi[posi]);
			printf("\n Descripcion de profesion ...........: %s ",prof[posi][0]);
			printf("\n Siglas de profesion ................: %s ",prof[posi][1]);
			printf("\n Estado de la profesion..............: %s ",prof[posi][2]);
			
			band=1;
		}

	}
	if(band==0)
	{
		printf("\n EL REGISTRO NO EXISTE !!!!!");
	}	
}
void Consulta_General()
{
	int posi=0;
	printf("\n PRESENTACION GENERAL DE DATOS");
	printf("\n CODIGO			DESCRIPCION			SIGLAS			ESTADO");
	for(posi=0;posi<cprof;posi++)
	{
		printf("\n %i			%s					%s",codi[posi],prof[posi][0],prof[posi][1],prof[posi][2]);
	}
}
void Ordenar_Ascendente_codigo()
{
	char auxi[40];
	int posi=0;
	int posj=0;
	int dato=0;
	printf("\n ORDENAMIENTO DE DATO DE DATOS POR CODIGO ASCENDENTE");
	for(posi=0;posi<cprof-1;posi++)
	{
		for(posj=posi+1;posj<cprof;posj++)
		{
			if(codi[posi]>codi[posj])
			{
				dato=codi[posi];
				codi[posi]=codi[posj];
				codi[posj]=dato;
				
				strcpy(auxi,prof[posi][0]);
				strcpy(prof[posi][0],prof[posj][0]);
				strcpy(prof[posj][0],auxi);
				
				strcpy(auxi,prof[posi][1]);
				strcpy(prof[posi][1],prof[posj][1]);
				strcpy(prof[posj][1],auxi);
				
				strcpy(auxi,prof[posi][2]);
				strcpy(prof[posi][2],prof[posj][2]);
				strcpy(prof[posj][2],auxi);				
			}
		}	
	}
	Consulta_General();
}
void Ordenar_descendente_codigo()
{
	char auxi[40];
	int posi=0;
	int posj=0;
	int dato=0;
	printf("\n ORDENAMIENTO DE DATO DE DATOS POR CODIGO DESCENDENTE");
	for(posi=0;posi<cprof-1;posi++)
	{
		for(posj=posi+1;posj<cprof;posj++)
		{
			if(codi[posi]<codi[posj])
			{
				dato=codi[posi];
				codi[posi]=codi[posj];
				codi[posj]=dato;
				
				strcpy(auxi,prof[posi][0]);
				strcpy(prof[posi][0],prof[posj][0]);
				strcpy(prof[posj][0],auxi);
				
				strcpy(auxi,prof[posi][1]);
				strcpy(prof[posi][1],prof[posj][1]);
				strcpy(prof[posj][1],auxi);
				
				strcpy(auxi,prof[posi][2]);
				strcpy(prof[posi][2],prof[posj][2]);
				strcpy(prof[posj][2],auxi);			
			}
		}	
	}
	Consulta_General();	
}
void Ordenar_Ascendente_descripcion()
{
	char auxi[40];
	int posi=0;
	int posj=0;
	int dato=0;
	printf("\n ORDENAMIENTO DE DATO DE DATOS POR DESCRIPCION ASCENDENTE");
	for(posi=0;posi<cprof-1;posi++)
	{
		for(posj=posi+1;posj<cprof;posj++)
		{
			if(strcmp(prof[posi][0],prof[posj][0])>0)
			{
				dato=codi[posi];
				codi[posi]=codi[posj];
				codi[posj]=dato;
				
				strcpy(auxi,prof[posi][0]);
				strcpy(prof[posi][0],prof[posj][0]);
				strcpy(prof[posj][0],auxi);
				
				strcpy(auxi,prof[posi][1]);
				strcpy(prof[posi][1],prof[posj][1]);
				strcpy(prof[posj][1],auxi);
				
				strcpy(auxi,prof[posi][2]);
				strcpy(prof[posi][2],prof[posj][2]);
				strcpy(prof[posj][2],auxi);				
			}
		}	
	}
	Consulta_General();	
}
void Ordenar_descendente_descripcion()
{
	char auxi[40];
	int posi=0;
	int posj=0;
	int dato=0;
	printf("\n ORDENAMIENTO DE DATO DE DATOS POR DESCRIPCION DESCENDENTE");
	
	for(posi=0;posi<cprof-1;posi++)
	{
		for(posj=posi+1;posj<cprof;posj++)
		{
			if(strcmp(prof[posi][0],prof[posj][0])<0)
			{
				dato=codi[posi];
				codi[posi]=codi[posj];
				codi[posj]=dato;
				
				strcpy(auxi,prof[posi][0]);
				strcpy(prof[posi][0],prof[posj][0]);
				strcpy(prof[posj][0],auxi);
				
				strcpy(auxi,prof[posi][1]);
				strcpy(prof[posi][1],prof[posj][1]);
				strcpy(prof[posj][1],auxi);
				
				
				strcpy(auxi,prof[posi][2]);
				strcpy(prof[posi][2],prof[posj][2]);
				strcpy(prof[posj][2],auxi);	
							
			}
		}	
	}
	Consulta_General();		
}


/* 
TAREA 
REALIZAR UN MANTENIMIENTO DE PROFESION
int codi[100]   codigo numericos ejemplos 1 , 2 , 3
char prof[100][30]  descripciones ejemplo "ingeneniero", "doctor", "Ababogado"
char sigl[100][5]	siglas ejemplos "ing", "dr"  "ab"
char esta[100]    estado dos valos 'A'   o 'I'
 MUjica Toaza Mario Joel
*/
