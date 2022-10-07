// lt70: Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

// Returns the number of distinct ways to climb n stairs.
// Each time climb 1 or 2 steps.
int climbStairs(int n) {
  // f(n) = f(n-1) + f(n-2)
  // with memorization of last two numbers
  if (n <= 1) return 1;  // so that f(2) = 2
  int a = 1, b = 1;      // and we memorize them
  // if n = 2, iterate once
  for (int i = 1; i < n; ++i) {
    int c = a + b;
    a = b;
    b = c;
  }
  return b;
}
