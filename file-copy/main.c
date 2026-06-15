#include <stdio.h>
#include <stdlib.h>

int main(int argc, FILE* argv[]) {
  FILE *file_one = argv[0];
  file_one = fopen("file_one.txt", "wb+");

  if (file_one == NULL)
  {
    printf("Failed to open file\n");
    exit(0);
  }  

  fprintf(file_one, "hey there its been a while\n");
  fprintf(file_one, "dodge this\n");

  char c = fgetc(file_one);

  if (c == EOF)
  {
    if (feof(file_one) == EOF)
      printf("End of File\n");
    else
      printf("Unable to Read\n");
  }

  while (c != EOF)
  {
    printf("%c", c);
  }
  
  fclose(file_one);

  return 0;
}