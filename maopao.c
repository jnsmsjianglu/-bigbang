#include<stdio.h>
void main()
{
int a[11];
int i,j,min,temp;
printf("please input 10 integers:\n");
scanf("%d",&a[i]);

printf("these 10 intergers are:\n");
for(i=0;i<10;i++)
printf("%5d",a[i]);
for(i=0;i<=9;i++)
 {
  min=i;
  for(j=i+1;j<=10;j++)
   if(a[min]>a[j])
       min=j;
      temp=a[i];
      a[i]=a[min];
      a[min]=temp;
}
printf("\n the sorted 10 numbers:\n");
for(i=0;i<10;i++)
    printf("%5d",a[i]);
printf("\n");
}
