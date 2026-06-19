#include <stdio.h>

// Return the sum of all whole positive nums smaller than n
int sum_of_natural_nums(int n) {
  if (n == 1)
    return 1;

  return n + sum_of_natural_nums(n - 1);
}

// Return number in fibonacci sequence at n spot
int fibonacci(int n) {
  if (n < 2)
    return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int collatz(int n) {
  int count = 0;
  printf("count = %i\n", count);
  if (n == 1)
    return 1;
  else if (n % 2 == 0)
    return count + collatz(n / 2);
  else if (n % 3 == 0)
    return count + collatz((n * 3) + 1);

  return count;
}

int main() {
  int i = 8;
  // printf("Sum of natural nums for %i = %i\n", i, sum_of_natural_nums(i));
  // printf("Fibonacci at %i = %i\n", i, fibonacci(i));
  printf("Collatz conjecture for %i = %i\n", i, collatz(i));

  return 0;
}