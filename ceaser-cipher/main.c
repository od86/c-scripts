#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[] = "What a string";
  int shifter = 5;
  
  for (int i = 0; i < strlen(str); i++) {
    if (!isalpha(str[i]))
    {
      continue;
    }

    if (str[i] + shifter > 122) {
      str[i] = 97 + ((str[i] + shifter) - 122);
      continue;
    }

    if (str[i] + shifter > 90 && str[i] == toupper(str[i])) {
      str[i] = 64 + ((str[i] + shifter) - 90);
      continue;
    }

    str[i] = str[i] + shifter;
  }

  for (int i = 0; i < strlen(str); i++)
  {
    printf("%c", str[i]);
  }

  printf("\n");

  return 0;
}