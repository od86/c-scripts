#include <stdio.h>

int main() {
  int stockPrices[] = {17, 3, 6, 9, 15, 8, 6, 1, 19};
  int buyDay = 0;
  int sellDay = 0;
  for (int i = 0; i < (sizeof(stockPrices) / sizeof(stockPrices[0])); i++)
  {
    for (int x = i + 1; x < (sizeof(stockPrices) / sizeof(stockPrices[0])); x++)
    {
      if (stockPrices[x] - stockPrices[i] > stockPrices[sellDay] - stockPrices[buyDay]) {
        buyDay = i;
        sellDay = x;
      }
    }
  }
  printf("Buy Day: %i | Sell Day: %i | Profit: £%i\n", buyDay, sellDay, stockPrices[sellDay] - stockPrices[buyDay]);
}