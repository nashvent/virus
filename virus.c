#include <stdio.h>
#include <stdlib.h>
int file_length(FILE *f){
    int pos;
    int end;
    pos = ftell (f);
    fseek (f, 0, SEEK_END);
    end = ftell (f);
    fseek (f, pos, SEEK_SET);
    return end;
}

int checkMySize(){
  
  FILE *fp;
  long file_size;
  int size;
  fp = fopen("virus.exe", "rb");
  if(fp == NULL){
    //printf("\n No se puede abrir archivo");
    return 0;
  }
  size = file_length(fp);
  //printf("\n El tamaño es %d", size);
  fclose(fp);
  return size;
}

int main(){
  int mysize=42193;
  if(checkMySize()>mysize){
    printf("hackeado-nuevo size: %d",checkMySize());
  }
  else{
    printf("No hackeado");
  }


  system("mkdir .hola");//supuesta carpeta oculta










  
  /*
  FILE *fp;

  fp = fopen("file.txt","w+");
  fputs("This is tutorialspoint.com", fp);
  
  fseek( fp, 20, SEEK_SET );
  fputs(" C Programming Language", fp);
  fclose(fp);
*/
  /* 
  FILE *fp1 = fopen("virus.exe", "r");
  FILE *fp2 = fopen("scan.exe", "r");
  FILE *fp3 = fopen("viruscan.exe", "w");
  char c;
 
  if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
    {
      puts("NO SE PUEDE");
      exit(0);
    }
  // Copy contents of first file to file3.txt
  while ((c = fgetc(fp1)) != EOF)
    fputc(c, fp3);
  // Copy contents of second file to file3.txt
  while ((c = fgetc(fp2)) != EOF)
    fputc(c, fp3);
 
  printf("Merged");
 
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
*/
   
  return 0;
}
 
 
