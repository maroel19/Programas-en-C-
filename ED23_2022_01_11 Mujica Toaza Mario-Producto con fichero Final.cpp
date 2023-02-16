/*MANTENIMIENTO DE PRODUCTO*/
/*ARCHIVO CABECERAS*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
/*DECLARACACION DE FUNCION*/
char menu_producto();
void Ingreso();
void Modificacion();
void Eliminacion();
void Consulta_individual();
void Consulta_General();
void Ordenar_Ascendente_codigo();
void Ordenar_descendente_codigo();
void Ordenar_Ascendente_descripcion();
void Ordenar_descendente_descripcion();
void guardar_dato();
void cargar_dato();


void poscf(int colu, int fila);
void bp();
void marco(int col1,int fil1,int col2, int fil2);
void pantalla();
/*DECLARACION DE VARIABLES*/
struct sproducto
{
	int codi;
	char desc[50];
	float pcom;
	float pinc;
	float pven;
	int stoc;
}prod[100];

int cpro;
int spro=1;

int main()
{
	char resu;
	cargar_dato();
	do
	{
		pantalla();
		resu=menu_producto();
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
				Ordenar_Ascendente_descripcion();
				break;
			case '7':
				Ordenar_descendente_descripcion();
		}
	}while(resu!='0');
	
}
/*DESARROLLO DE LAS FUNCIONES*/
char menu_producto()
{
	char opci;	
	poscf(10,9); printf("          MENU PRINCIPAL");
	poscf(10,10);printf("Ingreso..............................[1]");
	poscf(10,11);printf("Modificacion.........................[2]");
	poscf(10,12);printf("Eliminacion..........................[3]");
	poscf(10,13);printf("Consulta individual..................[4]");
	poscf(10,14);printf("Ordenar Ascendente por descripcion...[6]");
	poscf(10,15);printf("Ordenar descendente por descripcion. [7]");
	poscf(10,16);printf("Salir................................[0]");
	poscf(10,17);printf("Elija la opcion: ");
	opci=getch();
	return opci;
}

void Ingreso()
{
	char auxi[50];
	pantalla();
	poscf(2,9);printf("       INGRESO DE DATOS");
	
	poscf(10,10);printf("Codigo de producto.........: %i",spro);
	prod[cpro].codi=spro;  
	
	poscf(10,11);printf("Descripcion de producto....: ");
	gets(prod[cpro].desc);
	
	poscf(10,12);printf("Precio de compra...........: ");
	gets(auxi);						
	prod[cpro].pcom=atof(auxi);	
	
	poscf(10,13);printf("Porcentaje de incremento...: ");
	gets(auxi);						
	prod[cpro].pinc=atof(auxi);	
		
	prod[cpro].pven=prod[cpro].pcom+(prod[cpro].pcom *(prod[cpro].pinc/100.0));
	
	poscf(10,14);printf("Stock.....................: ");
	gets(auxi);						
	prod[cpro].stoc=atoi(auxi);
	
		
	cpro++;	
	spro++;
	guardar_dato();	
}
void Modificacion()
{
		pantalla();
	char auxi[50];
	int posi=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	poscf(10,8);printf("MODIFICAR DE DATOS");
	poscf(10,9);printf("Codigo de producto a modificar...: ");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<cpro;posi++)
	{
		if(prod[posi].codi==dato)
		{
			poscf(10,10);printf("Codigo  ...................: %i ",prod[posi].codi);
			poscf(10,11);printf("Descripcion ...............: %s ",prod[posi].desc);
			poscf(10,12);printf("Precio de compra ..........: %f ",prod[posi].pcom);
			poscf(10,13);printf("porcentaje de incremento ..: %f ",prod[posi].pinc);
			poscf(10,14);printf("Precio de venta ...........: %f ",prod[posi].pven);
			poscf(10,15);printf("Stock de compra ...........: %i ",prod[posi].stoc);
			band=1;
			
			poscf(10,16);printf("Nueva Descripcion .........: ");
			gets(prod[posi].desc);
			
			poscf(10,17);printf("Nuevo Precio de compra...........: ");
			gets(auxi);						
			prod[posi].pcom=atof(auxi);	
			
			poscf(10,18);printf("Nuevo Porcentaje de incremento...: ");
			gets(auxi);						
			prod[posi].pinc=atof(auxi);	
				
			prod[cpro].pven=prod[cpro].pcom+(prod[cpro].pcom*(prod[cpro].pinc/100));
			
			poscf(10,19);printf("Nuevo Stock.....................: ");
			gets(auxi);						
			prod[posi].stoc=atoi(auxi);
			
			guardar_dato();
		}

	}
	if(band==0)
	{
		poscf(10,10);printf(" EL REGISTRO NO EXISTE !!!!!");
	}		
}
void Eliminacion()
{
	pantalla();
	char auxi[50];
	char resp;
	int posi=0;
	int posj=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	poscf(10,8);printf("ELIMINAR DE DATOS");
	poscf(10,9);printf("Codigo de producto a eliminar...: ");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<cpro;posi++)
	{
		if(prod[posi].codi==dato)
		{
			poscf(10,10);printf("Codigo  ...................: %i ",prod[posi].codi);
			poscf(10,11);printf("Descripcion ...............: %s ",prod[posi].desc);
			poscf(10,12);printf("Precio de compra ..........: %f ",prod[posi].pcom);
			poscf(10,13);printf("Porcentaje de incremento ..: %f ",prod[posi].pinc);
			poscf(10,14);printf("Precio de venta ...........: %f ",prod[posi].pven);
			poscf(10,15);printf("Stock de compra ...........: %i ",prod[posi].stoc);
			band=1;
			
			poscf(3,27);printf("Desea Eliminar el registro S o N:");
			resp=getch();
			if(resp=='S' || resp=='s')
			{
				for(posj=posi;posj<cpro;posj++)
				{
					prod[posj].codi=prod[posj+1].codi;
					strcpy(prod[posj].desc,prod[posj+1].desc);
					prod[posj].pcom=prod[posj+1].pcom;
					prod[posj].pinc=prod[posj+1].pinc;
					prod[posj].pven=prod[posj+1].pven;
					prod[posj].stoc=prod[posj+1].stoc;
					
				}
				posi=posj;
				cpro--;
				guardar_dato();
				poscf(3,27);printf("El registro fue eliminado              ");
				poscf(3,28);printf("Presione cualquier tecla para continuar");
				getch();
			}
		}

	}
	if(band==0)
	{
		poscf(10,10);printf("EL REGISTRO NO EXISTE !!!!!");
	}		
}
void Consulta_individual()
{
		pantalla();
	char auxi[50];
	int posi=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	poscf(10,8);printf("CONSULTA INDIVIDUAL DE DATOS");
	poscf(10,9);printf("Codigo de producto a buscar...: ");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<cpro;posi++)
	{
		if(prod[posi].codi==dato)
		{
			poscf(10,10);printf("Codigo  ...................: %i ",prod[posi].codi);
			poscf(10,11);printf("Descripcion ...............: %s ",prod[posi].desc);
			poscf(10,12);printf("Precio de compra ..........: %f ",prod[posi].pcom);
			poscf(10,13);printf("Porcentaje de incremento ..: %f ",prod[posi].pinc);
			poscf(10,14);printf("Precio de venta ...........: %f ",prod[posi].pven);
			poscf(10,15);printf("Stock de compra ...........: %i ",prod[posi].stoc);
			band=1;
		}

	}
	if(band==0)
	{
		poscf(10,9);printf("EL REGISTRO NO EXISTE !!!!!");
	}	
}
void Consulta_General()
{
	int posi=0;
	poscf(60,1);printf("Cod");
	poscf(66,1);printf("Descripcion");
	poscf(100,1);printf("P.Venta");
	poscf(110,1);printf("Stock");
	for(posi=0;posi<cpro;posi++)
	{
		poscf(60,3+posi);printf("%i",prod[posi].codi);
		poscf(66,3+posi);printf("%s",prod[posi].desc);
		poscf(100,3+posi);printf("%f",prod[posi].pven);
		poscf(110,3+posi);printf("%i",prod[posi].stoc);
	}
}

void Ordenar_Ascendente_descripcion()
{
	char auxi[40];
	int posi=0;
	int posj=0;
	int dent=0;
	float ddec=0;
	
	//printf("\n ORDENAMIENTO DE DATO DE DATOS POR DESCRIPCION ASCENDENTE");
	for(posi=0;posi<cpro-1;posi++)
	{
		for(posj=posi+1;posj<cpro;posj++)
		{
			if(strcmp(prod[posi].desc,prod[posj].desc)>0)
			{
				dent=prod[posi].codi;
				prod[posi].codi=prod[posj].codi;
				prod[posj].codi=dent;
				
				strcpy(auxi,prod[posi].desc);
				strcpy(prod[posi].desc,prod[posj].desc);
				strcpy(prod[posj].desc,auxi);
			
				ddec=prod[posi].pcom;
				prod[posi].pcom=prod[posj].pcom;
				prod[posj].pcom=ddec;
				
				ddec=prod[posi].pinc;
				prod[posi].pinc=prod[posj].pinc;
				prod[posj].pinc=ddec;
				
				ddec=prod[posi].pven;
				prod[posi].pven=prod[posj].pven;
				prod[posj].pven=ddec;
				
				dent=prod[posi].stoc;
				prod[posi].stoc=prod[posj].stoc;
				prod[posj].stoc=dent;
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
	int dent=0;
	float ddec=0;
	
	//printf("\n ORDENAMIENTO DE DATO DE DATOS POR DESCRIPCION ASCENDENTE");
	for(posi=0;posi<cpro-1;posi++)
	{
		for(posj=posi+1;posj<cpro;posj++)
		{
			if(strcmp(prod[posi].desc,prod[posj].desc)<0)
			{
				dent=prod[posi].codi;
				prod[posi].codi=prod[posj].codi;
				prod[posj].codi=dent;
				
				strcpy(auxi,prod[posi].desc);
				strcpy(prod[posi].desc,prod[posj].desc);
				strcpy(prod[posj].desc,auxi);
			
				ddec=prod[posi].pcom;
				prod[posi].pcom=prod[posj].pcom;
				prod[posj].pcom=ddec;
				
				ddec=prod[posi].pinc;
				prod[posi].pinc=prod[posj].pinc;
				prod[posj].pinc=ddec;
				
				ddec=prod[posi].pven;
				prod[posi].pven=prod[posj].pven;
				prod[posj].pven=ddec;
				
				dent=prod[posi].stoc;
				prod[posi].stoc=prod[posj].stoc;
				prod[posj].stoc=dent;
			}
		}	
	}
	Consulta_General();		
}
/*FUNCIONES DE MEJORA DE APARIENCIA*/
void poscf(int colu, int fila)
{
	COORD coord;
	coord.X=colu;
	coord.Y=fila;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void bp()
{
	system("cls");
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
	marco(0,0,58,29);
	marco(59,0,119,29);
	marco(1,1,57,7);
	poscf(16,2);printf("UNIVERSIDAD DE GUAYAQUIL");
	poscf(14,3);printf("TECNOLOGIA DE LA INFORMACION");
	poscf(16,4);printf("      SEMESTRE 2");
	poscf(16,5);printf("   ESTRUCTURA DE DATO");
	poscf(16,6);printf(" Mujica Toaza Mario Joel");
	poscf(60,2);printf("===========================================================");
	poscf(60,27);printf("===========================================================");
	poscf(60,28);printf("Anterior                                          Siguiente");
	Consulta_General();
}


void guardar_dato()
{
	FILE *fproducto;
	struct spro
	{
		int codi;
		char desc[50];
		float pcom;
		float pinc;
		float pven;
		int stoc;
	}fich;
	int cont=0;
	fproducto=fopen("producto.txt","wb");
	while(cont<cpro)
	{
		fich.codi=prod[cont].codi;
		strcpy(fich.desc,prod[cont].desc);
		fich.pcom=prod[cont].pcom;
		fich.pinc=prod[cont].pinc;
		fich.pven=prod[cont].pven;
		fich.stoc=prod[cont].stoc;
		fwrite(&fich,sizeof(fich),1,fproducto);
		cont++;
	}
	fclose(fproducto);
}
/*
wb  CREAR ARCHIVO; SI EL ARCHIVO YA EXISTE LO BORRA Y LO VUELVE A CREAR VACIO
rb  APERTURA EL ARCHIVO SOLO LECTURA
ab  AGREGA INFORMACION AL FICHERO
r+b	PERMITE CONSULTAR Y SOBREESCRIBE EN EL FICHERO

*/
void cargar_dato()
{
	FILE *fproducto;
	struct sprod
	{
		int codi;
		char desc[50];
		float pcom;
		float pinc;
		float pven;
		int stoc;
	}fich;
	cpro=0;
	fproducto=fopen("producto.txt","rb");
	while(fread(&fich,sizeof(fich),1,fproducto)!=0)
	{
		prod[cpro].codi=fich.codi;
		strcpy(prod[cpro].desc,fich.desc);
		prod[cpro].pcom=fich.pcom;
		prod[cpro].pinc=fich.pinc;
		prod[cpro].pven=fich.pven;
		prod[cpro].stoc=fich.stoc;
		spro=fich.codi+1;
		cpro++;
	}
	fclose(fproducto);
}
