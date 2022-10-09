// lt119: Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/
#include <cmath>
#include <vector>

// Returns the i'th row of Pascal's Triangle.
// Binomial Theorem
// (x + y)^n = x^n + .. c(n, m)x^(n-m)y^m + ... + y^n
// where c(n, m) denotes n choose m = n! / (m!(n-m)!)
// [1]: (x + y)^0 = 1x^0
// [1, 1]: (x + y)^1 = 1x + 1y
// [1, 2, 1]: (x + y)^2 = 1x^2 + 2xy + 1y^2
// [1, 3, 3, 1]: (x + y)^3 = 1x^3 + 3x^2y + 3xy^2 + y^3
// [1, 4, 6, 4, 1]: (x + y)^4 = ...
//
// c(n, m) itself is time consuming to calculate
// but we can infer c(n, m) from c(n, m-1) =>
// c(n, m) / c(n, m - 1) = n - m + 1 / m
std::vector<int> getRow(int n) {
  std::vector<int> res{1};
  for (int m = 1; m <= n; ++m) {
    // we need a long here to hold temporary result
    res.push_back((long)res.back() * (n - m + 1) / m);
  }
  return res;
}
