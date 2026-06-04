#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Convert temp from F to C
int main() {
  char tempType;
  float num;

  printf("Type(C/F/K): ");
  scanf("%s", &tempType);

  printf("Temperature: ");
  scanf("%f", &num);

  tempType = toupper(tempType);

  if (tempType == 'C') {
    printf("\n%.2f°C | %.2f°F | %.2f°K\n", num, (num * 9.0 / 5) + 32, num + 273.15);
  } else if (tempType == 'F') {
    printf("\n%.2f°C | %.2f°F | %.2f°K\n", (num - 32) * (5.0 / 9), num, ((num - 32) * (5.0 / 9)) + 273.15);
  } else if (tempType == 'K') {
    printf("\n%.2f°C | %.2f°F | %.2f°K\n", num - 273.15, ((num - 273.15) * (9.0 / 5)) + 32, num);
  }
}
