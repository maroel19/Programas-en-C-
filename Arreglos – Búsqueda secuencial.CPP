#include<iostream>
#include<conio.h>
#define MAX 50
void leerarray(int,int[]);
int buscasecuencial(int,int[],int);
void main()
{
int x[MAX],elem,n;
cout<<"Ingrese limite del arreglo";
cin>>n;
leerarray(n,x);
cout<<"Ingrese elemento a buscar ";
cin>>elem;
if(buscasecuencial(n,x,elem)==1)
cout<<"Elemento encontrado ";
else
cout<<"Elemento no encontrado ";
getch();
}
void leerarray(int n,int a[])
{ for(int i=0;i<n;i++)
{
cout<<"Ingrese elemento "<<i<<":";
cin>>a[i];
}
}
int buscasecuencial(int n,int a[],int ele)
{
for(int i=0;i<n;i++)
if(ele==a[i])return 1;
return 0;
}
