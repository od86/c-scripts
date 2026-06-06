#include <stdio.h>

// Bubble sort algorithm
int main() {
  int unsorted_arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  for (int i = 0; i < (sizeof(unsorted_arr) / sizeof(unsorted_arr[0])); i++)
  {
    for (int x = 0; x < (sizeof(unsorted_arr) / sizeof(unsorted_arr[0])) - 1; x++)
    {
      if (unsorted_arr[x] > unsorted_arr[x + 1]) {
        int greater = unsorted_arr[x];
        unsorted_arr[x] = unsorted_arr[x + 1];
        unsorted_arr[x + 1] = greater;
      }
    }
  }
  for (int i = 0; i < (sizeof(unsorted_arr) / sizeof(unsorted_arr[0])); i++)
  {
    printf("%i ", unsorted_arr[i]);
  }
  printf("\n");

  return 0;
}