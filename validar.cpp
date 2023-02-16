#include<stdio.h>
#include<semestreug.h>
#include<stdlib.h>


int main()
{
	char auxi[20];
	int num1=0;
	int num2=0;
	int num3=0;
	num1=entero(25,7,"Numero 1:",18,60,2);
	num2=entero(25,8,"Numero 2:",18,60,2);
	num3=entero(25,9,"Numero 3:",18,60,2);
	
	poscf(5,15);printf("Numero 1: %i",num1);	
	poscf(5,16);printf("Numero 2: %i",num2);
	poscf(5,17);printf("Numero 3: %i",num3);
}


