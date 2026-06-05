#include <stdio.h>

// Bubble sort algorithm
int main() {
  int unsortedArr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  for (int i = 0; i < (sizeof(unsortedArr) / sizeof(unsortedArr[0])); i++)
  {
    for (int x = 0; x < (sizeof(unsortedArr) / sizeof(unsortedArr[0])) - 1; x++)
    {
      if (unsortedArr[x] > unsortedArr[x + 1]) {
        int greater = unsortedArr[x];
        unsortedArr[x] = unsortedArr[x + 1];
        unsortedArr[x + 1] = greater;
      }
    }
  }
  for (int i = 0; i < (sizeof(unsortedArr) / sizeof(unsortedArr[0])); i++)
  {
    printf("%i ", unsortedArr[i]);
  }
  printf("\n");
}