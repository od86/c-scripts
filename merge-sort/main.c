#include <stdio.h>
#include <unistd.h>

// sort the left half
// sort the right half
// merge them together

// Okay so the goal is to split them up and merge them together
// It doesnt have to been in order just so it works

// {8, 3, 4, 5}, 0, 1, 3
// 8 = 0 - 4 = 2 - M = 1;
// {8, 3}
// 0, 2, 4
// {8, 3, 4, 5, 0} 0 = 8, 1 = 3, 2 = 4, 3 = 5, 4 = 0 // l = 0, m == r
// {8, 3, 4} 0 = 8, 1 = 3, 2 = 4 // l = 0, m = 1, r = 2
// {8, 3} 0 = 8, 1 = 3 // l = 0, m = 0, r = 1
void merge(int n[], int l, int m, int r) {
  int x, y, z;
  int lsize = (m - l) + 1;
  int rsize = r - m;
  int lside[lsize], rside[rsize];

  for (x = 0; x < lsize; x++)
    lside[x] = n[l + x];

  for (y = 0; y < rsize; y++)
    rside[y] = n[m + 1 + y];

  x = 0;
  y = 0;
  z = l;

  while (x < lsize && y < rsize)
  {
    if (lside[x] <= rside[y])
    {
      n[z] = lside[x];
      x++;
    }
    else
    {
      n[z] = rside[y];
      y++;
    }

    z++;
  }

  while (x < lsize)
  {
    n[z] = lside[x];
    x++;
    z++;
  }
  
  while (y < rsize)
  {
    n[z] = rside[y];
    y++;
    z++;
  }
}

int merge_sort(int n[], int l, int r) {
  if (l < r)
  {
    int m = (l + r) / 2;
    merge_sort(n, l, m);
    merge_sort(n, m + 1, r);

    merge(n, l, m, r);
  }
}

int main() {
  int n[] = {8, 3, 5, 4};
  int s = sizeof(n) / sizeof(n[0]);

  merge_sort(n, 0, s - 1);
  for (int i = 0; i < s; i++)
    printf("%i ", n[i]);
  printf("\n");
  
  return 0;
}