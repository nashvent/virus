#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *lista_archivos; 
  char nombre_archivo[256];
  int num_archivos;
    
  system("dir *.exe /B > lista_archivos"); // todos los *.exe
    
  lista_archivos=fopen("lista_archivos", "r");
        
  num_archivos=0;
  while(fgets(nombre_archivo, 256, lista_archivos)!=NULL){
    printf("%s", nombre_archivo);
    num_archivos++;
  }
  printf("\nTotal de archivos: %d\n", num_archivos);
  fclose(lista_archivos);

    
  /*abro el archivo*/
  FILE *archivo;
  int caracter;

  archivo = fopen("programa.exe","r");
	
  if (archivo == NULL)
    printf("\nError de apertura del archivo. \n\n");
  else
    {
      printf("\nEl contenido del archivo del archivo es \n\n");
      system (nombre_archivo);
      /*while((caracter = fgetc(archivo)) != EOF)
	printf("%c",caracter);*/
    }
  printf("\n");
  fclose(archivo);

  return 0;
}
