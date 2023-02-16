/*cliente
codi entero
cedula  cadena
nomb   cadena
apel   cadena
dire    cadena
sexo   caracter
imai  cadena
tele    cadena
saldo   decimal
esta   caracter

/*MANTENIMIENTO DE MARCA*/
/*ARCHIVO CABECERAS*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<semestreug.h>

/*Declaracion de lista*/
struct sdato // estructura del nodo//
{
	int codi;
	char desc[50];
	char esta;
	struct sdato *sigu;
};

typedef struct sdato *ldat;   //declaracion de una lista//


int csec=1;

/*DECLARACACION DE FUNCION*/
char menu();
char menu_modificar();
void Ingreso(ldat &list);
void Modificacion(ldat &list);
void Eliminacion(ldat &list);
void Consulta_individual(ldat list);
void Consulta_General(ldat list);
void Ordenar(ldat &list);
void guardar_dato(ldat list);
void cargar_dato(ldat &list);
void pantalla(ldat list); 
 
/*DECLARACION DE VARIABLES*/


int main()
{
	ldat list=NULL;  //creando la lista
	char resu;
	cargar_dato(list);
	do
	{
		pantalla(list);
		resu=menu();
		switch(resu)
		{
			case '1':
				Ingreso(list);	
				break;
			case '2':
				Modificacion(list);
				break;
			case '3':
				Eliminacion(list);
				break;
			case '4':
				Consulta_individual(list);
				break;
			case '5':
				Ordenar(list);
				break;
		}
	}while(resu!='0');
	
}
/*DESARROLLO DE LAS FUNCIONES*/
char menu()
{
	char opci;	
	poscf(10,9); printf("          MENU PRINCIPAL"); 
	poscf(10,10);printf("Ingreso..............................[1]");
	poscf(10,11);printf("Modificacion.........................[2]");
	poscf(10,12);printf("Eliminacion..........................[3]");
	poscf(10,13);printf("Consulta individual..................[4]");
	poscf(10,14);printf("Ordenar..............................[5]");
	poscf(10,15);printf("Salir................................[0]");
	poscf(10,16);printf("Elija la opcion: ");
	opci=getch();
	return opci;
}

void Ingreso(ldat &list)
{
	ldat lis1;
	ldat lis2;
	int vcod=0;
	char vdes[50];
	char vest;
	pantalla(list);
	poscf(3,9);printf("       INGRESO DE DATOS");
	
	poscf(10,11);printf("Codigo de marca................: %i",csec);
	vcod=csec; 
	
	poscf(10,12);printf("Descripcion de marca...........: ");
	gets(vdes);
	
	poscf(10,13);printf("Estado A(activo) o I(inactivo).: ");
	vest=getche();
	
	//creando un nodo//
	lis1=new(struct sdato); 
	lis1->codi=vcod;
	strcpy(lis1->desc,vdes);
	lis1->esta=vest;
	lis1->sigu=NULL;
	
	if(list==NULL)  
	{
		list=lis1;   //primer nodo
	}
	else 
	{
		lis2=list;   //mas de dos nodos
		while(lis2->sigu!=NULL)
		{
			lis2=lis2->sigu;
		}
		lis2->sigu=lis1;
	}		
	csec++;
	guardar_dato(list);	
}

void Modificacion(ldat &list)
{
	ldat lis1;
	int posi=0;
	int vcod;
	char vdes[50];
	char auxi[50];
	char vest;
	char resu; 
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	pantalla(list);
	poscf(10,9);printf("MODIFICACION DE DATOS       ");
	poscf(10,11);printf("Codigo de marca a modificar.........:");
	gets(auxi);
	dato=atoi(auxi); 
	lis1=list;
	while(lis1!=NULL)
	{
		if(lis1->codi==dato)
		{
			poscf(10,12);printf("Codigo  ...................: %i ",lis1->codi);
			poscf(10,13);printf("Descripcion ...............: %s ",lis1->desc);
			poscf(10,14);printf("Estado ....................: %c ",lis1->esta);
			strcpy(vdes,lis1->desc);
			vest=lis1->esta;
			band=1;
			
			 
			do
			{
				poscf(10,17);printf("Modificacion de datos");
			    poscf(10,18);printf("[1-Descripcion]-[2-Estado]-[0-Salir]");
			    poscf(10,19);printf("Elija la opcion:");
			    resu=getch();
			    switch(resu)
		        {
			        case '1':
				        poscf(10,13);printf("Descripcion ...............:          ");
				        poscf(10,13);printf("Descripcion ...............: ");
				        gets(vdes);
				    break;
			        case '2':
			        	poscf(10,14);printf("Estado ....................:          ");
			        	poscf(10,14);printf("Estado ....................: ");
			        	vest=getche();
		     	}
			}while(resu!='0');
			poscf(10,17);printf("                                         ");
			poscf(10,18);printf("                                         ");
			poscf(10,19);printf("Desea actualizar el registro S o N:");
			resu=toupper(getch());
			if(resu=='S')
			{
				strcpy(lis1->desc,vdes);
				lis1->esta=vest;
				guardar_dato(list);
				poscf(10,17);printf("                                       ");	
				poscf(10,18);printf("Registro actualizado");
				poscf(10,19);printf("Presione cualquier tecla para continuar"); 
				getch();
			}
		}
		lis1=lis1->sigu; 
	}
	if(band==0)
	{
		poscf(10,19);printf("EL REGISTRO NO EXISTE !!!!!");
	}
	
}

void Eliminacion(ldat &list)
{
	ldat lis1;
	ldat lis2;
	lis2=NULL;
	char auxi[50];
	char resu;
	int posi=0;
	int posj=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	pantalla(list);
	poscf(10,9);printf( "ELIMINAR DATOS       ");
	poscf(10,11);printf("Codigo de marca a Eliminar.........:");
	gets(auxi);
	dato=atoi(auxi); 
	lis1=list;
	while(lis1!=NULL)
	{
		if(lis1->codi==dato)
		{
			poscf(10,12);printf("Codigo  ...................: %i ",lis1->codi);
			poscf(10,13);printf("Descripcion ...............: %s ",lis1->desc);
			poscf(10,14);printf("Estado ....................: %c ",lis1->esta);
			band=1;
			
			poscf(10,19);printf("Desea Eliminar el registro S o N:");
			resu=toupper(getch());
			if(resu=='S')
			{
				if(lis2!=NULL) //elimina cualquier nodo menos el primero 
				{
					lis2->sigu=lis1->sigu;
				    delete(lis1);
						
				}
				else
				{
					if(lis1->sigu==NULL)
					{
						list=NULL;
					}
					else
					{
						lis2=lis1;
						lis1=lis1->sigu;
						free(lis2);
						list=lis1;
					}
				}
				guardar_dato(list);
				poscf(10,21);printf("El registro fue eliminado              ");
				poscf(10,22);printf("Presione cualquier tecla para continuar");
				getch();
				break;
			}
		}
		else
		{
			lis2=lis1;
		}
		lis1=lis1->sigu;

	}
	if(band==0)
	{
		poscf(10,19);printf("EL REGISTRO NO EXISTE !!!!!");
	}
	
		
}
void Consulta_individual(ldat list)
{
	ldat lis1;
	ldat lis2;
	char auxi[50];
	pantalla(list);
	int posi=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	pantalla(list);
	poscf(10,9);printf( "CONSULTA INDIVIDUAL       ");
	poscf(10,11);printf("Codigo de marca a buscar.........:");
	gets(auxi);
	dato=atoi(auxi); 
	lis1=list;
	while(lis1!=NULL)
	{
		if(lis1->codi==dato)
		{
			poscf(10,12);printf("Codigo  ...................: %i ",lis1->codi);
			poscf(10,13);printf("Descripcion ...............: %s ",lis1->desc);
			poscf(10,14);printf("Estado ....................: %c ",lis1->esta);
			band=1;
			poscf(10,16);printf("El registro fue consultado             ");
			poscf(10,17);printf("Presione cualquier tecla para continuar");
			getch();
		}
		lis1=lis1->sigu;

	}
	if(band==0)
	{
		poscf(10,12);printf("EL REGISTRO NO EXISTE !!!!!");
	}	
	
}
void Consulta_General(ldat list)
{
	int posi=0;
	poscf(60,1);printf("Cod");
	poscf(66,1);printf("Descripcion");
	poscf(100,1);printf("Estado");
	while(list!=NULL)
	{
		poscf(60,3+posi);printf("%i",list->codi);
		poscf(66,3+posi);printf("%s",list->desc);
		poscf(100,3+posi);printf("%c",list->esta);
		list=list->sigu;  //saltar al siguiente nodo//
		posi++;
	}
}

void Ordenar(ldat &list)
{
	ldat lis1;
	ldat lis2;
	int vcod;
	char vdes[50];
	char vest;
	//printf("\n ORDENAMIENTO DE DATO DE DATOS POR DESCRIPCION ASCENDENTE");
	lis1=list;
	while(lis1!=NULL)
	{
		lis2=lis1->sigu;
		while(lis2!=NULL)
		{
			if(strcmp(lis1->desc,lis2->desc)>0)
			{
				vcod=lis1->codi;
				lis1->codi=lis2->codi;
				lis2->codi=vcod;
				
				strcpy(vdes,lis1->desc);
				strcpy(lis1->desc,lis2->desc);
				strcpy(lis2->desc,vdes);
				
				vest=lis1->esta;
				lis1->esta=lis2->esta;
				lis2->esta=vest;
			}
			lis2=lis2->sigu;
		}	
		lis1=lis1->sigu;
	}
	Consulta_General(list);		
}
/*FUNCIONES DE MEJORA DE APARIENCIA*/

void pantalla(ldat list)
{
	bp();
	marco(0,0,58,29);
	marco(59,0,119,29);
	marco(1,1,57,7);
	poscf(16,2);printf("UNIVERSIDAD DE GUAYAQUIL");
	poscf(14,3);printf("TECNOLOGIA DE LA INFORMACION");
	poscf(16,4);printf("      SEMESTRE 2");
	poscf(16,5);printf("   ESTRUCTURA DE DATO");
	poscf(16,6);printf("   Mujica Toaza Mario Joel "); 
	poscf(60,2);printf("===========================================================");
	poscf(60,27);printf("===========================================================");
	poscf(60,28);printf("Anterior                                          Siguiente");
	Consulta_General(list);
}


void guardar_dato(ldat list)
{
	FILE *fichero;
	struct saux
	{
		int codi;
		char desc[50];
		char esta;
	}fich;
	fichero=fopen("marca.txt","wb");
	while(list!=NULL)
	{
		fich.codi=list->codi;
		strcpy(fich.desc,list->desc);
		fich.esta=list->esta;
		fwrite(&fich,sizeof(fich),1,fichero);
		list=list->sigu;
	}
	fclose(fichero);
}

void cargar_dato(ldat &list)
{
	FILE *fichero;
	ldat lis1;
	ldat lis2;
	struct saux
	{
		int codi;
		char desc[50];
		char esta;
	}fich;
	fichero=fopen("marca.txt","rb");
	while(fread(&fich,sizeof(fich),1,fichero)!=0)
	{
		//creando un nodo//
	    lis1=new(struct sdato); 
	    lis1->codi=fich.codi;
	    strcpy(lis1->desc,fich.desc);
	    lis1->esta=fich.esta;
		csec=fich.codi+1;
		
		lis1->sigu=NULL;
	    
	    if(list==NULL)  
	   {
		list=lis1;   //primer nodo
	   }
	    else 
	   {
		 lis2=list;   //mas de dos nodos
		 while(lis2->sigu!=NULL)
		 {
			lis2=lis2->sigu;
		 }
		 lis2->sigu=lis1;
    	}
	}
	fclose(fichero);
	
}
