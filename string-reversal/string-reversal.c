#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseStr(char forwardStr[]) {
  char *reversedStr = (char *)malloc(strlen(forwardStr));

  for (int i = strlen(forwardStr) - 1; i > -1; i--)
  {
    reversedStr[strlen(forwardStr) - i - 1] = forwardStr[i];
  }

  return reversedStr;
}

int main() {
  char passedStr[] = "Hello world";
  char* reversedStr = reverseStr(passedStr);

  printf("%s\n", reversedStr);
  free(reversedStr);

  return 0;
}