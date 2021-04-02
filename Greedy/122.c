int maxProfit(int* prices, int pricesSize) {
  if (pricesSize == 1) {
    return 0;
  } else {
    int profit = 0;
    int buy;
    int mark = 0;
    for (int i = 0; i < pricesSize - 1; ++i) {
      if (prices[i] < prices[i + 1]) {
        if (mark == 0) {
          buy = prices[i];
          mark = 1;
        }
      } else {
        if (mark == 1) {
          profit += prices[i] - buy;
          mark = 0;
        }
      }
    }
    if (mark == 1) {
      profit += prices[pricesSize - 1] - buy;
    }
    return profit;
  }
}
