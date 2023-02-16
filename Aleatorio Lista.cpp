/*SE REQUIERE REALIZAR UN PROGRAMA DONDE SE SE GENERE N NUMEROS ENTEROS POSITIVOS EN UNA LISTA Y 
ESTO SE PUEDA RALIZAR EN LA FUNCION INGRESO

LA MODIFICACION Y ELIMINACION SE LA PUEDE REALIZAR POR LA POSICION O POR EL VALOR 
SI ES POR POSICION SE BORRARA O MODIFICARA 1 VALOR A LA VEZ 
SI ES POR VALOR SE ELIMINARA O MODIFICARA LOS QUE CUMPLAN LA CONDICION
*/ 
//ARCHIVOS CABECERAS//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semestreug.h>
//DECLARACION DE lISTA//
struct sdato
{
	int valo;
   struct sdato *sigu;
}aval[1000];
typedef struct sdato *lval ;
//DECLARACION DE FUNCIONES//
char menu();
void ingreso(lval &list);
void modificar(lval &list);
void eliminar(lval &list);
void consulta_individual(lval list);
void consulta_general(lval list);
void ordenamiento(lval list);

void pantalla(lval list);
void guardar_dato(lval list);
void cargar_dato(lval &list);

//DECLARACION DE VARIABLE//
int nreg; //NUMERO DE REGISTRO
int linf=0;
int lsup=168;
int pagi=1;
int npag=0;
int main()
{
	lval list=NULL;   //CRACION DE LA LISTA VACIA
	char resu;

	cargar_dato(list);
	do
	{
		pantalla(list);
		resu=menu();
		switch(resu)
		{
			case '1':
				ingreso(list);
				break;
			case '2':
				modificar(list);
				break;
			case '3':
				eliminar(list);
				break;
			case '4':
				consulta_general(list);
				break;	
			case 'S':
				if(nreg>lsup)
				{
					linf=linf+168;
					lsup=lsup+168;
					pagi++;
				}
				break;
				
			case 'A':
				if(linf>0)
				{
					linf=linf-168;
					lsup=lsup-168;
					pagi--;
				}	
		}
	}while(resu!= '0');
}
//DESARROLLO DE FUNCION//
char menu()
{
	char opci;
	poscf(3,10);printf("                MENU PRESENTACION");
	poscf(3,11);printf("Ingresar........................................[ 1 ]");
	poscf(3,12);printf("Modificar.......................................[ 2 ]");
	poscf(3,13);printf("Eliminar........................................[ 3 ]");
	poscf(3,14);printf("Consulta general................................[ 4 ]");
	poscf(3,15);printf("Salir...........................................[ 0 ]");
	poscf(3,16);printf("Elija la opcion:");
	opci=getche();
	return opci;
}
void ingreso(lval &list)
{
	char auxi[50];
	int dato;
	int con1=0;
	pantalla(list);
	poscf(3,10);printf("INGRESO DE DATOS");
	poscf(3,12);printf("Cantidad de numeros a generar: ");
	gets(auxi);
	dato=atoi(auxi);
	for(con1=0;con1<dato;con1++)
	{
		aval[nreg].valo=(rand()%1000)+1;
		nreg++;
	}
	guardar_dato(list);
	poscf(3,27);printf("Numero Generado con exito.....                       ");
	poscf(3,28);printf("presione cualquier tecla para continuar                ");
	getch();	
}
void modificar(lval &list)
{
	pantalla(list);
	char auxi[50];
	char resp;
	int posi=0;
	int band=0;
	int dato=0;
	int nume;
	pantalla(list);
	poscf(3,10);printf("\n MODIFICACION DE DATOS POR POSICION");
	poscf(3,11);printf("INGRESE POSICION A MODIFICAR[%i-%i].: ", linf,lsup);
	gets(auxi);
	dato=atoi(auxi);
	poscf(3,13);printf("Numero[%i]:%i",dato,nume);
	getch();
}
void eliminar(lval &list)
{ 
	lval lis1;
	lval lis2=NULL;
	char auxi[50];
	char resp;
	int posi=0;
	int posj=0;
	int band=0;
	int ban1=0;
	int dato=0;
	pantalla(list);
	poscf(3,10);printf("ELIMINACION DE DATOS");
	poscf(3,11);printf("Numero a eliminar.........: ");
	gets(auxi);
	dato=atoi(auxi);
	lis1=list;
	while((lis1!=NULL) && (band==0))
	{
		if(dato==lis1->valo)
		{
			poscf(3,14);printf("Numero.................: %i",lis1->valo);
			
			band=1;
			
			poscf(3,27);printf("Esta seguro de guardar el registro S(si) o N(No):");
			resp=toupper(getch());   //tolower()
			if(resp=='S')      //if(resp=='S' ||resp=='s')
			{
				if(!ban1)
				{//SE ELIMINAN CUALQUIER NODO MENOS EL PRIMERO
					//LINEAS DE ELIMINAR//
					lis2->sigu=lis1->sigu; 
					delete(lis1);		
				}
				else
				{//SE ELIMINA EL PRIMER NODO
					if(lis1->sigu==NULL) //si esto es verdad, hay un solo nodo
					{
						delete(lis1);
						list=NULL;
					}
					else // hay mas de un solo nodo
					{
						lis2=lis1;
						lis1=lis1->sigu;
						free(lis2); //delete(lis2);
						list=lis1;
					}
				}
				poscf(3,27);printf("Registro eliminado con exito.....                       ");
				poscf(3,28);printf("presione cualquier tecla para continuar                 ");
				getch();
			}	
		}
		else
		{
			lis2=lis1;
			ban1++;
		}
		lis1=lis1->sigu;
	}
	if(band==0)
	{
		poscf(3,13);printf("DATO A BUSCAR NO EXISTE!!!!");
	}
}
void consulta_general(lval list)
{
	int valo;
	int colu=0;
	int fila=0;
	int posi=0;
	poscf(62,1);printf("COl 1.");
	poscf(70,1);printf("COl 2.");
	poscf(78,1);printf("COl 3.");
	poscf(86,1);printf("COl 4.");
	poscf(94,1);printf("COl 5.");
	poscf(102,1);printf("COl 6.");
	poscf(110,1);printf("COl 7.");
	for(posi=0;posi<nreg;posi++)
	{
		if(fila==24)
		{
			colu=colu+8;
			fila=0;
		}
		poscf(62+colu,3+fila);printf("%i",valo);
		fila++;
	}	
}
void pantalla(lval list)
{
	int posi=0;
	npag=(nreg/168)+1;
	bp();
	marco(0,0,59,29);
	marco(60,0,119,29);
	marco(1,1,58,7);
	poscf(2,2);printf("               UNIVERSIDAD DE GUAYAQUIL");
	poscf(2,3);printf("             TECNOLOGIA DE LA INFORMACION");
	poscf(2,4);printf("                 ESTRUCTURA DE DATOS");
	poscf(2,5);printf("                   SEGUNDO SEMESTRE");
	poscf(2,6);printf("                 Ramirez Ramirez David ");
	poscf(62,28);printf("Anterior              %i Pagina  %i             Siguiente",pagi,npag);
	consulta_general(list);
	for(posi=0;posi<58;posi++)
	{
		poscf(61+posi,2);printf("=");
		poscf(61+posi,27);printf("=");
	}
}
void guardar_dato(lval list)
{
	FILE *fichero;
	struct saux
	{
		int valo;
	}fich;
	fichero=fopen("aleatoriolista.txt","wb");
	while(list!=NULL)
	{
		fich.valo=list->valo;
		fwrite(&fich,sizeof(fich),1,fichero);
		list=list->sigu;
	}
	fclose(fichero);
}

void cargar_dato(lval &list) //FICHERO A LISTA
{
	FILE *fichero;
	lval lis1;
	lval lis2;
	struct saux
	{
		int valo;
	}fich;
	fichero=fopen("aleatoriolista.txt","rb");
	if(fichero)
	{
		while(fread(&fich,sizeof(fich),1,fichero)!=0)
		{
			lis1=new(struct sdato); 
			lis1->valo=fich.valo; 
			lis1->sigu=NULL;
		
			if (list==NULL) 
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
		}	
	}
	fclose(fichero);
}
