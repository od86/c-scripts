#include <stdio.h>
#include <stdlib.h>

void read_file(FILE *file) {
  file = fopen("test.txt", "r");

  if (file == NULL)
  {
    printf("Failed to open file when attempting to read\n");
    exit(0);
  }

  while (1)
  {
    char c = fgetc(file);

    if (feof(file))
      break;

    printf("%c", c);
  }

  fclose(file);
}

void write_to_file(FILE *file) {
  file = fopen("test.txt", "w");

  if (file == NULL)
  {
    printf("Failed to open file when attempting to write\n");
    exit(0);
  }

  fprintf(file, " Mankind's greatest fear is mankind itself.\n");
  fprintf(file, "  - Gendo Ikari\n");

  fclose(file);
}

int main(int argc, FILE* argv[]) {
  FILE *file = argv[0];
  write_to_file(file);
  read_file(file);

  return 0;
}