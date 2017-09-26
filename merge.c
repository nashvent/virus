#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE *fp1 = fopen("candidatos/bueno", "r");
  FILE *fp2 = fopen("candidatos/otroBueno", "r");
  FILE *fp3 = fopen("candidatos/mezcla", "w");
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


  return 0;
}
