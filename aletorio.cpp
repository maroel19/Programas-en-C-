#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
   int i;
   int num1;
   int num2;
   int num3;
   int num4;
   cout << "20 numeros generados aleatoriamente:\n";
   /*
   primera columna los numero que se genera la funcion rand()
   segunda columna los numero que se genera la funcion rand() desde 0 menor a 10
   tercera columna los numero que se genera la funcion rand() desde 0 hasta  10
   cuarta columna los numero que se genera la funcion rand() desde 10 hasta  20
   */
   for(i=1; i<=20; i++)
   {
   		num1=rand();
   		num2=rand()%10;
   		num3=rand()%11;
   		num4=(rand()%11)+10;
   		cout << num1 <<"\t\t"<<num2<<"\t\t"<<num3<<"\t\t"<<num4<< endl;
   }
           
   system("pause");
}
