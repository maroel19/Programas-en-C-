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
	float prec;
	int stoc;
}apro[100];

int npro;
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
	poscf(10,9);printf("       INGRESO DE DATOS");
	
	poscf(7,10);printf("Codigo de producto.........: %i",spro);
	apro[npro].codi=spro;  
	
	poscf(7,11);printf("Descripcion de producto....: ");
	gets(apro[npro].desc);
	
	poscf(7,12);printf("Precio de compra...........: ");
	gets(auxi);						
	apro[npro].prec=atof(auxi);	
	
	poscf(7,14);printf("Stock.....................: ");
	gets(auxi);						
	apro[npro].stoc=atoi(auxi);
			
	npro++;	
	spro++;
	void guardar_dato();
}
void Modificacion()
{
pantalla();
	char auxi[50];
	int posi=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	poscf(10,8);printf(" MODIFICAR DE DATOS");
	poscf(10,9);printf(" Codigo de producto a modificar...: ");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<npro;posi++)
	{
		if(apro[posi].codi==dato)
		{
			poscf(10,10);printf("Codigo  ...................: %i ",apro[posi].codi);
			poscf(10,11);printf("Descripcion ...............: %s ",apro[posi].desc);
			poscf(10,12);printf("Precio de compra ..........: %f ",apro[posi].prec);
			poscf(10,13);printf("Stock de compra ...........: %i ",apro[posi].stoc);
			band=1;
			
			poscf(10,15);printf("Nueva Descripcion .........: ");
			gets(apro[posi].desc);
			
			poscf(10,16);printf("Nuevo Precio de compra...........: ");
			gets(auxi);						
			apro[posi].prec=atof(auxi);	
			
			poscf(10,17);printf("Nuevo Stock.....................: ");
			gets(auxi);						
			apro[posi].stoc=atoi(auxi);
			void guardar_dato();
		}

	}
	if(band==0)
	{
		poscf(10,9);printf("EL REGISTRO NO EXISTE !!!!!");
	}		
}
void Eliminacion()
{
	pantalla();
	char auxi[50];
	int posi=0;
	int posj=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	poscf(10,9);printf("ELIMINAR DE DATOS");
	poscf(10,10);printf("Codigo de producto a eliminar...: ");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<npro;posi++)
	{
		if(apro[posi].codi==dato)
		{
			poscf(10,11);printf("Codigo  ...................: %i ",apro[posi].codi);
			poscf(10,12);printf("Descripcion ...............: %s ",apro[posi].desc);
			poscf(10,13);printf("Precio de compra ..........: %f ",apro[posi].prec);
			poscf(10,16);printf("Stock de compra ...........: %i ",apro[posi].stoc);
			band=1;
			
			for(posj=posi;posj<npro;posj++)
			{
				apro[posj].codi=apro[posj+1].codi;
				strcpy(apro[posj].desc,apro[posj+1].desc);
				apro[posj].prec=apro[posj+1].prec;
				apro[posj].stoc=apro[posj+1].stoc;
				
			}
			posi=posj;
			npro--;
		}
		void guardar_dato();

	}
	if(band==0)
	{
		poscf(10,9);printf("EL REGISTRO NO EXISTE !!!!!");
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
	for(posi=0;posi<npro;posi++)
	{
		if(apro[posi].codi==dato)
		{
			poscf(10,10);printf("Codigo  ...................: %i ",apro[posi].codi);
			poscf(10,11);printf("Descripcion ...............: %s ",apro[posi].desc);
			poscf(10,12);printf("Precio de venta ...........: %f ",apro[posi].prec);
			poscf(10,13);printf("Stock de compra ...........: %i ",apro[posi].stoc);
			band=1;
		}

	}
	if(band==0)
	{
		poscf(10,9);printf("EL REGISTRO NO EXISTE !!!!!");
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
	for(posi=0;posi<npro-1;posi++)
	{
		for(posj=posi+1;posj<npro;posj++)
		{
			if(strcmp(apro[posi].desc,apro[posj].desc)>0)
			{
				dent=apro[posi].codi;
				apro[posi].codi=apro[posj].codi;
				apro[posj].codi=dent;
				
				strcpy(auxi,apro[posi].desc);
				strcpy(apro[posi].desc,apro[posj].desc);
				strcpy(apro[posj].desc,auxi);

				ddec=apro[posi].prec;
				apro[posi].prec=apro[posj].prec;
				apro[posj].prec=ddec;
				
				dent=apro[posi].stoc;
				apro[posi].stoc=apro[posj].stoc;
				apro[posj].stoc=dent;
			}
		}	
	}
		
}
void Ordenar_descendente_descripcion()
{
	char auxi[40];
	int posi=0;
	int posj=0;
	int dent=0;
	float ddec=0;
	
	//printf("\n ORDENAMIENTO DE DATO DE DATOS POR DESCRIPCION ASCENDENTE");
	for(posi=0;posi<npro-1;posi++)
	{
		for(posj=posi+1;posj<npro;posj++)
		{
			if(strcmp(apro[posi].desc,apro[posj].desc)<0)
			{
				dent=apro[posi].codi;
				apro[posi].codi=apro[posj].codi;
				apro[posj].codi=dent;
				
				strcpy(auxi,apro[posi].desc);
				strcpy(apro[posi].desc,apro[posj].desc);
				strcpy(apro[posj].desc,auxi);
			
				ddec=apro[posi].prec;
				apro[posi].prec=apro[posj].prec;
				apro[posj].prec=ddec;

				dent=apro[posi].stoc;
				apro[posi].stoc=apro[posj].stoc;
				apro[posj].stoc=dent;
			}
		}	
	}
	Consulta_General();			
}
void Consulta_General()
{
	int posi=0;
	poscf(60,1);printf("Cod");
	poscf(66,1);printf("Descripcion");
	poscf(100,1);printf("P.Venta");
	poscf(110,1);printf("Stock");
	for(posi=0;posi<npro;posi++)
	{
		poscf(60,3+posi);printf("%i",apro[posi].codi);
		poscf(66,3+posi);printf("%s",apro[posi].desc);
		poscf(100,3+posi);printf("%f",apro[posi].prec);
		poscf(110,3+posi);printf("%i",apro[posi].stoc);
	}
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
	poscf(16,6);printf(" PADILLA GOMEZ ROGELIO");
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
	while(cont<npro)
	{
		fich.codi=apro[cont].codi;
		strcpy(fich.desc,apro[cont].desc);
		fich.pven=apro[cont].prec;
		fich.stoc=apro[cont].stoc;
		fwrite(&fich,sizeof(fich),1,fproducto);
		cont++;
	}
	fclose(fproducto);
}

void cargar_dato()
{
	FILE *fproducto;
	struct sprod
	{
		int codi;
		char desc[50];
		float prec;
		int stoc;
	}fich;
	npro=0;
	fproducto=fopen("producto.txt","rb");
	while(fread(&fich,sizeof(fich),1,fproducto)!=0)
	{
		apro[npro].codi=fich.codi;
		strcpy(apro[npro].desc,fich.desc);
		apro[npro].prec=fich.prec;
		apro[npro].stoc=fich.stoc;
		spro=fich.codi+1;
		npro++;
	}
	fclose(fproducto);
}
