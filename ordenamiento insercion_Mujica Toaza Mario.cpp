#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<semestreug.h>

/*DECLARACION DE VARIABLES*/
struct sdat
{
	int nume;
	
}anum[1000];

int cnum=0;
int lsup=144;
int linf=0;
int pagi=1;
int cpag=0;

/*DECLARACACION DE FUNCION*/
char menu();
char menu_modificar();
void Ingreso();
void Modificacion();
void Eliminacion();
void pantalla();
void cargar_dato();
void guardar_dato();
void ordenar_insercion();

int main()
{
	char resu;
	//cargar_dato();
	do
	{
		pantalla();
		resu=menu();
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
				ordenar_insercion();
				break;
				break;
			case'S':
				if(lsup<cnum)
				{
					linf=linf+144;
				    lsup=lsup+144;
				    pagi++;
				}
				break;
			case'A':
				if(linf>=144)
				{
					linf=linf-144;
				    lsup=lsup-144;
				    pagi--;
				}
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
	poscf(10,13);printf("ordenamiento_insercion...............[4]");
	poscf(10,15);printf("Salir................................[0]");
	poscf(10,16);printf("Elija la opcion: ");
	opci=toupper(getch());
	return opci;
}
void Ingreso()
{
	char auxi[10];
	int cant;
	int posi;
	pantalla();
	poscf(3,9);printf("       INGRESO DE DATOS");
	
	poscf(3,11);printf("Cantidad de numeros a generar: ");
	gets(auxi);
	cant=atoi(auxi);
	/*NUMERO ENTRE 1 Y 100*/
	for(posi=0;posi<cant;posi++)
	{
		anum[cnum].nume=rand()%101+1;
        cnum++;
		
	}
	cpag=(cnum/144)+1;
	guardar_dato();	
}



void Modificacion()
{
		
	struct sprod
	{
		int nume;
	}fich;
	int posi=0;
	char auxi[50];
	char resu;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	pantalla();
	poscf(3,9);printf("MODIFICAR DE DATOS POR POSICION");
	poscf(3,11);printf("INGRESE POSICION A MODIFICAR [%i - %i]...: ", linf, lsup);
	gets(auxi);
	dato=atoi(auxi); 
	poscf(3,13);printf("Numero[%i]:%i",dato,anum[dato].nume);
	getch();
	for(posi=0;posi<cnum;posi++)
	{
		if(anum[posi].nume==dato)
		{
			poscf(3,13);printf("Numero[%i]:%i",dato,anum[dato].nume);
				    
			{
				anum[posi].nume=fich.nume;
			}	
			

		}
	}
	if(band==0)
	{
		poscf(10,19);printf("EL REGISTRO NO EXISTE !!!!!");
	}
	poscf(10,24);system ("pause");	
	
}


void Eliminacion()
{
	char auxi[50];
	pantalla();
	char resp;
	int nume;
	int posi=0;
	int posj=0;
	int dato=0;
	int band=0; // 0 SIGNIFICA QUE NO SE ENCONTRO EL DATO
	poscf(3,9);printf("ELIMINAR DE DATOS POR POSICION");
	poscf(3,11);printf("INGRESE POSICION A Eliminar [%i - %i]...: ", linf, lsup);
	gets(auxi);
	dato=atoi(auxi); 
	for(posi=0;posi<cnum;posi++)
	{
		
		if(anum[posi].nume==dato)
		{
	        poscf(3,13);printf("Numero[%i]:%i",dato,anum[posi].nume);
	        band=0;
			poscf(10,19);printf("Desea Eliminar el registro S o N:");
			resp=getch();
			if(resp=='S' || resp=='s')
			{
				for(posj=posi;posj<cnum;posj++)
				{
					anum[posj].nume=anum[posj+1].nume;
					
				}
				posi=posj;
				cnum--;
				guardar_dato();
				poscf(10,21);printf("El registro fue eliminado              ");
				poscf(10,22);printf("Presione cualquier tecla para continuar");
				getch();
			}
		}
	}
	if(band==0)
	{
		poscf(10,19);printf("EL NUMERO NO EXISTE !!!!!");
	}
}
	void ordenar_insercion()
	{
		int con1;
		int con2;
		int nume;
		for(con1=1;con1<cnum;con1++)
		{
			nume=anum[con1].nume;
			for(con2=con1-1;(con2>=0)&&(nume<anum[con2].nume);con2--)
			{
				anum[con2+1].nume=anum[con2].nume;
				}
				anum[con2+1].nume=nume;
			}
			
		}
	
	void Consulta_General()
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
	poscf(16,6);printf("    Mujica Toaza Mario Joel ");
	poscf(60,2);printf("===========================================================");
	poscf(60,27);printf("===========================================================");
	poscf(60,28);printf("Anterior             %i Pagina %i                 Siguiente",pagi,cpag);
	Consulta_General();
}

void guardar_dato()
{
	FILE *fproducto;
	struct pagi
	{
		int nume;
	}fich;
	int cont=0;
	fproducto=fopen("numeros.txt","wb");
	while(cont<cnum)
	{
		fich.nume=anum[cont].nume;
		fwrite(&fich,sizeof(fich),1,fproducto);
		cont++;
	}
	fclose(fproducto);
}

void cargar_dato()
{
	FILE *fproducto;
	struct pagi
	{
		int nume;

	}fich;
	cpag=0;
	fproducto=fopen("numeros.txt","rb");
	while(fread(&fich,sizeof(fich),1,fproducto)!=0)
	{
		anum[cnum].nume=fich.nume;
		cpag=fich.nume+1;
		cnum++;
	}
	fclose(fproducto);
}




