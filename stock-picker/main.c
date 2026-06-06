#include <stdio.h>

// Takes an array and works out best days to buy sell
int main() {
  int stock_prices[] = {17, 3, 6, 9, 15, 8, 6, 1, 19};
  int buy_day = 0;
  int sell_day = 0;
  for (int i = 0; i < (sizeof(stock_prices) / sizeof(stock_prices[0])); i++)
  {
    for (int x = i + 1; x < (sizeof(stock_prices) / sizeof(stock_prices[0])); x++)
    {
      if (stock_prices[x] - stock_prices[i] > stock_prices[sell_day] - stock_prices[buy_day]) {
        buy_day = i;
        sell_day = x;
      }
    }
  }
  printf("Buy Day: %i | Sell Day: %i | Profit: £%i\n", buy_day, sell_day, stock_prices[sell_day] - stock_prices[buy_day]);

  return 0;
}