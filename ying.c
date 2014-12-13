#include<stdio.h>
#include<string.h>

void main()
 {
 int chtom(char *p);
 int n;
char s[10]; 
printf("please inpout string:");
scanf("%s",s);
if (*s=='-')
n=-chtom(s+1);
else
n=chtom(s);
printf("the num is:%d",n);
printf("\n");
}




int chtom(char *p)
{
  int num=0;
  int j,k,len; 
 len=strlen(p);
    for(;  len>0      ;p++)
   {
 k=*p-48; //the char is saved as ASCII!
printf("\n");
  j=(--len);
while(j-->0)
{
  k=k*10;
}
    num=num+k;
  }
return(num);
} 
