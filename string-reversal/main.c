#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse_str(char forward_str[]) {
  char *reversed_str = (char *)malloc(strlen(forward_str));

  for (int i = strlen(forward_str) - 1; i > -1; i--)
  {
    reversed_str[strlen(forward_str) - i - 1] = forward_str[i];
  }

  return reversed_str;
}

int main() {
  char passed_str[] = "Hello world";
  char* reversed_str = reverse_str(passed_str);

  printf("%s\n", reversed_str);
  free(reversed_str);

  return 0;
}