// lt69: Sqrt(x)
// https://leetcode.com/problems/sqrtx/
#include <cmath>

// Given a non-negative integer, returns the square root of x.
// The decimal digits are truncated in the result.
int mySqrt(int x) {
  double t = x;  // start with x
  // update until the error is acceptable
  // the diff is between t * t and x rather than t_k and t_k+1 which can be
  // really small 1e-2
  while (t * t - x >= 1) t = 0.5 * (t + x / t);
  return t;
}
