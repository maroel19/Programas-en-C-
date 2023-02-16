/*SE REQUIERE REALIZAR UN PROGRAMA DONDE SE SE GENERE N NUMEROS ENTEROS POSITIVOS EN UNA LISTA Y 
ESTO SE PUEDA RALIZAR EN LA FUNCION INGRESO

LA MODIFICACION Y ELIMINACION SE LA PUEDE REALIZAR POR LA POSICION O POR EL VALOR 
SI ES POR POSICION SE BORRARA O MODIFICARA 1 VALOR A LA VEZ 
SI ES POR VALOR SE ELIMINARA O MODIFICARA LOS QUE CUMPLAN LA CONDICION
*/ 
/*ARCHIVOS CABECERAS*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semestreug.h>
/*DECLARACION DE lISTA*/
struct sdato
{
	int lsup; 
	int linf;
	int pagi;
	int cpag;
	int valo;
	int cnum; 
	int anum;
	struct sdato *sigu; // Puntero del nodo
};
typedef struct sdato *lval ;
/*DECLARACION DE FUNCIONES*/
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

/*DECLARACION DE VARIABLE*/
int anum;
int cnum;
int lsup; 
int linf;
int pagi;
int cpag;
int main()
{
	int lsup; 
	int linf;
	int pagi;
	int cpag;
	int cnum; 
	int anum;
	int nume;
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
			case '5':
				ordenamiento(list);
				break;
			case 'S':
				if(lsup<cnum)
				{
					linf=linf+144;
					lsup=lsup+144;
					pagi++;
				}
				break;
			case 'A':
				if(linf>=144)
				{
					linf=linf-144;
					lsup=lsup-144;
					pagi--;
				}
		}
	}while(resu!= '0');
}
/*DESARROLLO DE FUNCION*/
char menu()
{
	char opci;
	poscf(3,10);printf("                MENU PRESENTACION");
	poscf(3,11);printf("Ingresar........................................[ 1 ]");
	poscf(3,12);printf("Modificar.......................................[ 2 ]");
	poscf(3,13);printf("Eliminar........................................[ 3 ]");
	poscf(3,14);printf("Consulta general................................[ 4 ]");
	poscf(3,15);printf("Oredenamiento ..................................[ 5 ]");
	poscf(3,16);printf("Salir...........................................[ 0 ]");
	poscf(3,17);printf("Elija la opcion:");
	opci=getche();
	return opci;
}
void ingreso(lval &list)
{
	char auxi[50];
	int i;
	int valo;
	int anum;
	int cnum;
	int nume;
	pantalla(list);
	poscf(3,10);printf("INGRESO DE DATOS");
	poscf(3,11);printf("Cantidad de numeros a generar: ");  
	gets(auxi);
	valo=atoi(auxi);
	for(i=0; i<=valo; i++)
   {
   	anum[cnum].nume=(rand()%100)+1;
   	cnum++;
	}
	cpag=(cnum/144)+1;
	guardar_dato(list);	
}
void modificar(lval &list)
{
	char auxi[50];
	char resp;
	int posi=0;
	int band=0;
	int dato=0;
	int anum;
	int cnum;
	int nume;
	pantalla(list);
	printf("\n MODIFICACION DE DATOS POR POSICION");
	printf("INGRESE POSICION A MODIFICAR[%i-%i].: ", linf,lsup);
	gets(auxi);
	dato=atoi(auxi);
	poscf(3,13);printf("Numero[%i]:%i",dato,anum[dato].nume);
	getch();
}
void eliminar(lval &list)
/*{
	ldat lis1;
	ldat lis2=NULL;
	char auxi[50];
	char resp;
	int posi=0;
	int posj=0;
	int band=0;
	int ban1=0;
	int dato=0; //CODIGO DEL PRODUCTO A BUSCAR
	pantalla(list);
	poscf(3,10);printf("EKIMINAR DE DATOS");
	poscf(3,12);printf("Codigo a eliminar.........: ");
	gets(auxi);
	dato=atoi(auxi);
	lis1=list;
	while((lis1!=NULL)&& (band==0))
	{
		if(dato==lis1->codi)
		{
			poscf(3,14);printf("Codigo...................: %i",lis1->codi);
			poscf(3,15);printf("Descrpcion...............: %s",lis1->desc);
			poscf(3,16);printf("Estado...................: %c",lis1->esta);
			
			band=1;
			
			poscf(3,27);printf("Esta usted seguro de eliminar el registro S(si) o N (No)");
			resp=toupper(getch());   //tolower()
			if(resp=='S')      //if(resp=='S' ||resp=='s')
			{

				if(ban1>0)
				{//SE ELIMINAS CUALQUIER NODO MENOS EL PRIMERO
					lis2->sigu=lis1->sigu;
					delete(lis1);
				}
				else
				{//SE ELIMINA EL PRIMER NODO
					if(lis1->sigu==NULL)
					{
						delete(lis1);
						list=NULL;
					}
					else
					{
						lis2=lis1;
						lis1=lis1->sigu;
						free(lis2);    // delete(lis2);
						list=lis1;
					}
					
				}
				guardar_dato(list);
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
		printf("\n DATO A BUSCAR NO EXISTE!!!!");
	}
	
}*/
/*void consulta_individual(lval list)
{
	char auxi[50];
	int band=0;
	int dato=0; //CODIGO DEL PRODUCTO A BUSCAR
	pantalla(list);
	poscf(3,10);printf("CONSULTA INDIVIDUAL DE DATOS");
	poscf(3,12);printf("Codigo de Buscar.........: ");
	gets(auxi);
	dato=atoi(auxi);
	while(list!=NULL)
	{
		if(dato==list->codi)
		{
			poscf(3,14);printf("Codigo...................: %i",list->codi);
			poscf(3,15);printf("Descrpcion...............: %s",list->desc);
			poscf(3,16);printf("Estado...................: %c",list->esta);
			poscf(3,28);printf("presione cualquier tecla para continuar                 ");
			getch();
			band=1;
		}
		list=list->sigu;
	}
	if(band==0)
	{
		poscf(3,27);printf("Registro eliminado con exito.....                       ");
		poscf(3,28);printf("presione cualquier tecla para continuar                 ");
		getch();
	}
}
void consulta_general(ldat list)
{
	int posi=0;
	int posy=0;
	int colu=0;
	int fila=0;
	poscf(60,1);printf("Numero");
	poscf(70,1);printf("Numero");
	poscf(80,1);printf("Numero");
	poscf(90,1);printf("Numero");
	poscf(100,1);printf("Numero");
	poscf(110,1);printf("Numero");
	posi=linf;
	while(posi<cnum && posi<lsup)
	{
		if(posy==24)
		{
			colu=colu+10;
			fila=0;
			posy=0;
		}
	poscf(60+colu,3+fila);printf("%i",anum[posi].nume);
	posi++;
	posy++;
	fila++;
	}
}*/
void ordenamiento(lval list)
{/*
	ldat lis1;
	ldat lis2;
	int vcod;
	char vdes[50];
	char vest;
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
*/}

void pantalla(lval list)
{
	bp();
	marco1(0,0,59,29);
	marco1(60,0,119,29);
	marco1(1,1,58,7);
	poscf(2,2);printf("               UNIVERSIDAD DE GUAYAQUIL");
	poscf(2,3);printf("             TECNOLOGIA DE LA INFORMACION");
	poscf(2,4);printf("                 ESTRUCTURA DE DATOS");
	poscf(2,5);printf("                   SEGUNDO SEMESTRE");
	poscf(2,6);printf("                 PADILLA GOMEZ ROGELIO");
	poscf(62,28);printf("Anterior                                       Siguiente");
	consulta_general(list);
	
}
void guardar_dato(lval list)
/*{
	FILE *fichero;
	struct saux
	{
		int codi;
		char desc[50];
		char esta;
	}fich;
	fichero=fopen("presentacion.txt","wb");
	while(list!=NULL)
	{
		fich.codi=list->codi;
		strcpy(fich.desc,list->desc);
		fich.esta=list->esta;
		fwrite(&fich,sizeof(fich),1,fichero);
		list=list->sigu;
	}
	fclose(fichero);
}*/
void cargar_dato(lval &list)
/*{
	FILE *fichero;
	ldat lis1;
	ldat lis2;
	struct saux
	{
		int codi;
		char desc[50];
		char esta;
	}fich;
	sreg=1;
	fichero=fopen("presentacion.txt","rb");
	if(fichero)
	{
		while(fread(&fich,sizeof(fich),1,fichero)!=0)
		{
			lis1=new(struct sdato); //CREANDO EL NODO
			lis1->codi=fich.codi;
			strcpy(lis1->desc,fich.desc);
			lis1->esta=fich.esta;
			lis1->sigu=NULL;
			
			if(list==NULL)  //LISTA ESTA VACIA
			{
				list=lis1;	// COLOCACION DEL PRIMER NODO EN LA LISTA
			}
			else
			{
				lis2=list;				//COLOCACION DEL NODOS A PARTIR DEL SEGUNDO
				while(lis2->sigu!=NULL)	
				{
					lis2=lis2->sigu;		
				}
				lis2->sigu=lis1;
			}		
			sreg=fich.codi+1;
		}	
	}
	fclose(fichero);
}*/
