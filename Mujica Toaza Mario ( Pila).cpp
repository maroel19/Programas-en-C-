
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<semestreug.h>
struct sproducto
{
	int codi2;
	char nomb2[50];
	char edad2[50];
	char estatu2[50];
	char estado2[50];
}prod[100];
int cpro;
int spro=1;

struct sdato 
{
	int codi1;
	char nomb1[50];
	char edad1[50];
	char estatu1[50];
	char estado1;
	struct sdato *sigu;
};
typedef struct sdato *ldat;   
int csec=1;



char menu();
void Ingresolista(ldat &list);
void Ingresoarreglo(ldat &list);
void Eliminacionlista(ldat &list);
void Eliminacionarreglo(ldat &list);
void Consulta_Generallista(ldat list);
void pantalla(ldat list); 
 



int main()
{
	ldat list=NULL; 
	char resu;
	do
	{
		pantalla(list);
		resu=menu();
		switch(resu)
		{
			case '1':
				Ingresolista(list);	
				break;
			case '2':
				Eliminacionlista(list);
				break;
			case '3':
				Ingresoarreglo(list);	
				break;
			case '4':
				Eliminacionarreglo(list);
				break;
				
		}
	}while(resu!='0');
	
}

char menu()
{
	char opci;	
	poscf(10,9); printf("          MENU PRINCIPAL COLAS"); 
	poscf(10,10);printf("Agregar objeto a cola (Lista).....[1]");
	poscf(10,11);printf("Quitar objeto de cola (lista).....[2]");
	poscf(10,12);printf("Agregar objeto a cola (arreglos)..[3]");
	poscf(10,13);printf("Quitar objeto de cola (arreglo)...[4]");
	poscf(10,14);printf("Salir.............................[0]");
	poscf(10,15);printf("ELIJA LA OPCION: ");
	opci=getch();
	return opci;
}

void Ingresolista(ldat &list)
{
	ldat lis1;
	ldat lis2;
	int lcod=0;
	char lnomb[50];
	char ledad[50];
	char lestatu[50];
	char lestado;
	char auxi[50];
	pantalla(list);
	poscf(5,9);printf("       INGRESO DE DATOS DEL CLIENTE");
	
	poscf(8,11);printf("Codigo de alumno..............: %i",csec);
	lcod=csec; 
	
	poscf(5,12);printf("Nombre de alumno..............: ");
	gets(lnomb);
	
	poscf(5,13);printf("Edad de estudiante................: ");
	gets(ledad);
	
	poscf(5,14);printf("Estatura de estudiante............: ");
	gets(lestatu);
	
	poscf(5,15);printf("Estado C(CASADO) o S(SOLTERO).....: ");
	lestado=getche();
	

	lis1=new(struct sdato); 
	lis1->codi1=lcod;
	strcpy(lis1->nomb1,lnomb);
	strcpy(lis1->edad1,ledad);
	strcpy(lis1->estatu1,lestatu);
	lis1->estado1=lestado;
	lis1->sigu=NULL;
	
	if(list==NULL)  
	{
		list=lis1;   
	}
	else 
	{
		lis2=list;   
		while(lis2->sigu!=NULL)
		{
			lis2=lis2->sigu;
		}
		lis2->sigu=lis1;
	}		
	csec++;
}

void Ingresoarreglo(ldat &list)
{
	char auxi[50];
	pantalla(list);
	poscf(5,9);printf("       INGRESO DE DATOS DEL CLIENTE");
	
	poscf(8,11);printf("Codigo de estudiante.........: %i",spro);
	prod[cpro].codi2=spro; 
	
	poscf(5,12);printf("Nombre de estudiante..............: ");
	gets(prod[cpro].nomb2);
	
	poscf(5,13);printf("Edad de estudiante................: ");
	gets(prod[cpro].edad2);
	
	poscf(5,14);printf("Estatura de estudiante............: ");
	gets(prod[cpro].estatu2);
	
	poscf(5,15);printf("Estado C(CASADO) o S(SOLTERO).....: ");
	gets(prod[cpro].estado2);
				
	cpro++;	
	spro++;
}


void Eliminacionlista(ldat &list)
{
	
	ldat lis1;
	ldat lis2;
	lis2=NULL;
	char auxi[50];
	char resu; 
	int dato=0;
	int band=0; 
	pantalla(list);
	poscf(5,9);printf( "ELIMINAR DATOS DEL ESTUDIANTE     ");
	poscf(5,10);printf("Presione cualquier tecla para continuar");

	gets(auxi);
	dato=atoi(auxi); 
	lis1=list;
	while(lis1!=NULL)
	{

		
		    if(lis2!=NULL) 
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
		    poscf(5,12);printf("El registro del estudiante fue eliminado  ");
		    poscf(5,13);printf("Presione cualquier tecla para continuar");
		    getch();
		    break;
		
	}
} 


void Eliminacionarreglo(ldat &list)
{
	char auxi[50];
	pantalla(list);
	char resp;
	int posi=0;
	int posj=0;
	int dato=0;
	int band=0; 
	poscf(5,9);printf( "ELIMINAR DATOS DEL ESTUDIANTE     ");
	poscf(5,10);printf("Presione cualquier tecla para continuar");
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<cpro;posi++)
	{
				for(posj=posi;posj<cpro;posj++)
				{
					prod[posj].codi2=prod[posj+1].codi2;
					strcpy(prod[posj].nomb2,prod[posj+1].nomb2);
					strcpy(prod[posj].edad2,prod[posj+1].edad2);
					strcpy(prod[posj].estatu2,prod[posj+1].estatu2);
					strcpy(prod[posj].estado2,prod[posj+1].estado2);

					
				}
				posi=posj;
				cpro--;
				poscf(5,12);printf("El registro del estudiante fue eliminado ");
				poscf(5,13);printf("Presione cualquier tecla para continuar");
				getch();
	}

}

void Consulta_Generallista(ldat list1)
{
	
	int posi=0;
	poscf(60,3);printf("Cod");
	poscf(65,3);printf("Nombre");
	poscf(80,3);printf("Edad");
	poscf(90,3);printf("Estatura");
	poscf(110,3);printf("Estado");
	while(list1!=NULL)
	{
		poscf(60,4+posi);printf("%i",list1->codi1);
		poscf(65,4+posi);printf("%s",list1->nomb1);
		poscf(80,4+posi);printf("%s",list1->edad1);
		poscf(90,4+posi);printf("%s",list1->estatu1);
		poscf(110,4+posi);printf("%c",list1->estado1);
		list1=list1->sigu; 
		posi++;
	}
	
}

void Consulta_Generalarreglo(ldat list)
{
	int posi=0;
	poscf(60,16);printf("Cod");
	poscf(65,16);printf("Nombre");
	poscf(80,16);printf("Edad");
	poscf(90,16);printf("Estatura");
	poscf(110,16);printf("Estado");
	for(posi=0;posi<cpro;posi++)
	{
		poscf(60,17+posi);printf("%i",prod[posi].codi2);
		poscf(65,17+posi);printf("%s",prod[posi].nomb2);
		poscf(80,17+posi);printf("%s",prod[posi].edad2);
		poscf(90,17+posi);printf("%s",prod[posi].estatu2);
		poscf(110,17+posi);printf("%s",prod[posi].estado2);
	}
}


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
	poscf(16,6);printf("    Mujica Toaza Mario");
	poscf(60,1);printf("                   CONSULTA GENERAL LISTA                  ");
	poscf(60,2);printf("===========================================================");
	poscf(60,14);printf("                   CONSULTA GENERAL ARREGLO               ");
	poscf(60,15);printf("===========================================================");
	poscf(60,27);printf("===========================================================");
	poscf(60,28);printf("Anterior                                          Siguiente");
	Consulta_Generallista(list);
	Consulta_Generalarreglo(list);
}
