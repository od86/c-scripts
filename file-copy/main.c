#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc) {
  printf("Enter name of file a: ");
  // get file name a
  printf("Enter name of file b: ");
  // get file name b

  // open file a and b
  FILE *file_a = fopen("a.txt", "r");
  FILE *file_b = fopen("b.txt", "w");

  if (file_a == NULL || file_b == NULL)
  {
    if (file_a == NULL)
      printf("Failed to open file a while attempting to read.\n");

    if (file_b == NULL)
      printf("Failed to open file b while attempting to write.\n");

    exit(0);
  }

  while (1)
  {
    char c = fgetc(file_a);

    if (feof(file_a))
      break;

    fputc(c, file_b);
  }

  fclose(file_a);
  fclose(file_b);

  return 0;
}