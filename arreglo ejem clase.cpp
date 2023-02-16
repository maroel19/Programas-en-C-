#include <stdio.h>
int main(int argc, char** argv){
	int arreglo[N]={5,2,4,1,3};
	int i,clave,j;  //las variables para comparar la posición del arreglo 
   //Recorrer el arreglo
	for (i = 1; i < N; i++){	   
		clave = *(arreglo+i);
		j = i-1;
		//Comparar el valor selecionado con todos los valores anteriores
		while (j >= 0 && *(arreglo+j) > clave){
			//Insertar el valor donde corresponda
			*(arreglo+j+1) = *(arreglo+j);
			j = j-1;
		}
		*(arreglo+j+1) = clave;
		mostrarLista(arreglo);
	}    
	mostrarLista(arreglo);  
	return 0;
}
