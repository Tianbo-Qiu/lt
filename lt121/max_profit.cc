// lt121: Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <algorithm>
#include <vector>

// Given the prices array, returns the max profit from one buy and one sale.
int maxProfit(std::vector<int>& prices) {
  // we have to sale at some point
  // and on every possible day to sale, we want to buy on a day before it that
  // has the minimum price to maximize the profit
  if (prices.size() <= 1) return 0;
  int minBuy = prices[0];                    // the minimum price to buy so far
  int maxProfit = 0;                         // the maximum profit so far
  for (int i = 1; i < prices.size(); ++i) {  // if we sale on day i
    maxProfit = std::max(maxProfit, prices[i] - minBuy);
    minBuy = std::min(minBuy, prices[i]);
  }
  return maxProfit;
}
