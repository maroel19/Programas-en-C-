#include <stdio.h>
int main() {
int b,i,j,k, v[12];
for(i=0;i<12;i++)

scanf("%d",&v[i]);
printf("fin del llenado\n");
printf("ingrese numero a buscar ");
scanf("%d",&b);
i= 0;
j= 12-1;
do {
k= (i+j)/2;
if (v[k]<=b )
i=k+1;
if (v[k]>=b )
j= k-1;
} while (i<=j);
printf("elemento %d esta en %d\n",v[k],k);
return 0;
}
