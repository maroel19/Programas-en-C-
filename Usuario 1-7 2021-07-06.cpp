#include<stdio.h>
#include<conio.h>
#include<primero.h>

void ingreso_usuario();
void modificar_usuario();
void eliminar_usuario();
void consulta_individual_usuario();
void consulta_general_usuario();
void pantalla();

struct usuario
{
	int  codi;
	char cedu[10];
	char nomb[25];
	char apel[25];
	char alia[25];
	char clav[25];
	char esta;
}usua[100];
int cusu; // CONTADOR DE USUARIO
int pmar[6]={205,186,201,200,187,188};
int main()
{
	char opci;
	do
	{
		pantalla();
		posxy(10,8); printf("            MENU USUARIO");
		posxy(10,10); printf("Ingreso de usuario.................[ 1 ]");
		posxy(10,12); printf("Modificacion de usuario............[ 2 ]");
		posxy(10,14); printf("Eliminacion de usuario.............[ 3 ]");
		posxy(10,16); printf("Consuta individual de usuario......[ 4 ]");
		posxy(10,18); printf("Salir..............................[ 0 ]");
		posxy(10,20);printf("Elija la opcion:");
		opci=getche();
		switch(opci)
		{
			case '1':
					ingreso_usuario();
                    break;
			case '2':
                    modificar_usuario();
                    break;
			case '3':
                    eliminar_usuario();
                    break;
			case '4':
                    consulta_individual_usuario();
		}
	}while(opci!='0');
}
/*
DESARROLLO DE FUNCIONES DE USUARIO
*/
void ingreso_usuario()
{
	pantalla();
	posxy(17,8); printf("INGRESO DE DATOS DEL USUARIO");
	
	posxy(5,10); printf("Codigo...:%i",cusu+1);
	usua[cusu].codi=cusu+1;
	posxy(5,12); printf("Cedula...:");
	gets(usua[cusu].cedu);
	posxy(5,14); printf("Nombre...:");
	gets(usua[cusu].nomb);
	posxy(5,16); printf("Apellido.:");
	gets(usua[cusu].apel);
	posxy(5,18); printf("Alia.....:");
	gets(usua[cusu].alia);
	posxy(5,20); printf("Clave....:");
	gets(usua[cusu].clav);
	posxy(5,22); printf("Estado...:");
	usua[cusu].esta=getche();
	cusu++;
}
void modificar_usuario()
{
	posxy(17,8); printf("MODIFICACION DE DATOS DEL USUARIO");
}
void eliminar_usuario()
{
	posxy(17,8); printf("ELIMINACION DE DATOS DEL USUARIO");
}
void consulta_individual_usuario()
{
    posxy(10,8); printf("CONSULTA INDIVIDUAL DE DATOS DEL USUARIO");
}
void consulta_general_usuario()
{
    int posi=0;
	posxy(70,1); printf("CONSULTA GENERAL DE DATOS DEL USUARIO");
	posxy(61,2); printf("Codigo");
	posxy(68,2); printf("Apellido");
	posxy(92,2); printf("Nombre");
	posxy(113,2); printf("Estado");
	posxy(61,3); printf("----------------------------------------------------------");
	for(posi=0;posi<cusu;posi++)
	{
		posxy(61,4+posi); printf("%i",usua[posi].codi);
		posxy(68,4+posi); printf("%s",usua[posi].apel);
		posxy(92,4+posi); printf("%s",usua[posi].nomb);
		posxy(113,4+posi); printf("%c",usua[posi].esta);
	}
}
void pantalla()
{
    bp();
	marco(0,0,59,29,pmar);
    marco(60,0,119,29,pmar);
	marco(1,1,58,6,pmar);
	marco(1,25,58,28,pmar);
	posxy(18,2); printf("UNIVERSIDAD DE GUAYAQUIL");
	posxy(9,3); printf(" TECNOLOGIA DE LA INFORMACION");
	posxy(18,4); printf("SEMESTRE 1  PARALELO 1-7");
	posxy(13,5); printf("PROGRAMADOR: Vera Caicedo David");
	consulta_general_usuario();
}

/*
DATOS DEL USUARIO
--------
CODIGO      ENTERO
CEDULA      CADENA
NOMBRE      CADENA
APELLIDO    CADENA
ALIAS       CADENA
CLAVE       CADENA
ESTADO      CARACTER

retorno-- nombre de la funcion-- parametros
void abc ()
int abc (int a)
flaot   abc (int a, flat b, int c)
char abc (char a[25], int b, float c, char d)
char* abc ()



*/
