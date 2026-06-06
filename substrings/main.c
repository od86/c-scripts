#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// 2d Array of words = {{'h', 'e', 'l', 'l', 'o'}, {'w', 'o', 'r', 'l', 'd'}}
// 1d Array of ints for number of times each word has appeared = {1, 3}

// This does NOT work
// Im so confused on how to do this, in C its so difficult
// I need to code in ruby again
int main() {
  char str[] = "Hello World";

  char words[sizeof(str) / 2][sizeof(str)];
  int word_counter = 0;

  for (int i = 0; i < strlen(str); i++)
  {
    if (isalpha(str[i])) {
      words[word_counter][i] = str[i];
    } else {
      word_counter++;
      continue;
    }
  }

  // printf("%li\n", sizeof(words) / sizeof(words[0]));

  for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
  {
    for (int x = 0; x < sizeof(words[i]) / sizeof(words[i][0]); x++)
    {
      printf("%c", words[i][x]);
    }
    printf("\n");
  }

  return 0;
}  