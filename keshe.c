#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit key1=P1^4;
sbit key2=P1^5;
sbit key3=P1^6;
sbit dula=P2^7;
sbit wela=P2^6;
sbit SPK=P1^0;


 uchar code table[]={
 0x3f,0x06,0x5b,0x4f,
 0x66,0x6d,0x7d,0x07,
 0x7f,0x6f,0x77,0x7c,
 0x39,0x5e,0x79,0x71,0x40
};

void delay(uint);
void spk(uchar);
void beep();
void DelayUs2x(unsigned char t);
void DelayMs(unsigned char t);

unsigned int year=2014;
unsigned char numt0,num,num1,num2=1,month=12,day=23;


void spk(uchar numspk)
{
    if(numspk==30)
     {   
       beep();
         

     }
      
   
}


void display(uchar numdis,uchar fnumdis,uchar snumdis)
{
  uchar mshi,mge,fshi,fge,sshi,sge;
  mshi=numdis/10;
  mge=numdis%10;
  fshi=fnumdis/10;
  fge=fnumdis%10;
  sshi=snumdis/10;
  sge=snumdis%10;
  

  dula=1;                 
  P0=table[mshi];
  dula=0;
  P0=0xff;
  wela=1;
  P0=0xbf;
  wela=0;
  delay(1);


  dula=1;
  P0=table[mge];
  dula=0;
  P0=0xff;
  wela=1;
  P0=0x7f;
  wela=0;
  delay(1);






  dula=1;
  P0=table[16];
  dula=0;
  P0=0xff;
  wela=1;
  P0=0xdf;
  wela=0;
  delay(2);
  



  dula=1;                 
  P0=table[fshi];
  dula=0;
  P0=0xff;
  wela=1;
  P0=0xf7;
  wela=0;
  delay(1);


  dula=1;
  P0=table[fge];
  dula=0;
  P0=0xff;
  wela=1;
  P0=0xef;
  wela=0;
  delay(1);




  dula=1;                 
  P0=table[16];
  dula=0;
  P0=0xff;
  wela=1;
  P0=0xfb;
  wela=0;
  delay(1);




  dula=1;                 
  P0=table[sshi];
  dula=0;
  P0=0xff;
  wela=1;
  P0=0xfe;
  wela=0;
  delay(1);


  dula=1;
  P0=table[sge];
  dula=0;
  P0=0xff;
  wela=1;
  P0=0xfd;
  wela=0;
  delay(1);
}



void delay(uint xms)
{
  uint i,j;
  for(i=xms;i>0;i--)
      for(j=250;j>0;j--);
}

void init()
{
  TMOD=0x01;
  TH0=(65536-45872)/256;
  TL0=(65536-45872)%256;
  EA=1;
  ET0=1;
  TR0=1;
}


void keyscan()
{   
if(key1==0)
{
  delay(5);
  if(key1==0)
     {
        num++;
        if(num==60)
            num=0;
         while(!key1);
          
     }
}


if(key2==0)
{
  delay(5);
  if(key2==0)
  {    
       num1++;
    if(num1==60)
       num1=0;
       
   while(!key2);
}

}


if(key3==0)
{
  delay(5);                            
  if(key3==0)
  {    
       num2++;
    if(num2==24)
       {
        num2=0;
        day++;
       }
       
   while(!key3); 
  }
 }

}
               
 void main()
{ 

                                    
  init();
  while(1)
{
 keyscan();
 display(num,num1,num2);
 spk(num1);
}
}



void T0_time() interrupt 1
{
  TH0=(65536-45872)/256;
  TL0=(65536-45872)%256;
  //delay(10);
  numt0++;
  if(numt0==20)
   {
      numt0=0;
      num++;
      if(num==60)
         {
           num=0;
           num1++;
         if(num1==60)
                 {
                      num1=0;
                      num2++;
                  if(num2==24) num2=0;
                  }
          }
         
   }
}



void beep()
{
 
 unsigned int i;

 
      {
   for(i=0;i<500;i++)
      {
        DelayUs2x(200); 
        DelayUs2x(200); 
        SPK=!SPK;  
       }
   for(i=0;i<500;i++)
      {
        DelayMs(1);  
         SPK=!SPK;
       }
          
     }
}

void DelayUs2x(unsigned char t)
{   
 while(--t);
}

void DelayMs(unsigned char t)
{
     
 while(t--)
 {
     
     DelayUs2x(245);
     DelayUs2x(245);
 }
}

