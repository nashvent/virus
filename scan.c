#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

struct threeNum
{
    int n1, n2, n3;
};

int main() {
    struct dirent *de;
    //DIR *dr = opendir("c:/");
    DIR *dr = opendir("./candidatos");
    if (dr == NULL){
        printf("No existe" );
        return 0;
    }
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);
    closedir(dr);


    /*

  int n;
  struct threeNum num;
  FILE *fptr;

  if ((fptr = fopen("./../candidatos/as.exe","wb")) == NULL){
    printf("Error! opening file");
    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  for(n = 1; n < 5; ++n)
    {
      num.n1 = n;
      num.n2 = 5*n;
      num.n3 = 5*n + 1;
      fwrite(&num, sizeof(struct threeNum), 1, fptr);
    }
  fclose(fptr);


  char ch;
  FILE *fpw;
  fpw = fopen("./../candidatos/he.txt","w");

  if(fpw == NULL)
    {
      printf("Error");
      exit(1);
    }

  printf("Enter any character: ");
  scanf("%c",&ch);

  /* You can also use fputc(ch, fpw);*/
    /*  fprintf(fpw,"%c",ch);
  fclose(fpw);



*/
    
  return 0;
}
