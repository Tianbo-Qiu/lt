// lt 13: Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <unordered_map>

// Returns the decimal representation of a Roman integer string
// I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000
// number is read from right to left:
// if the current number is no less than the last one, add it (e.g. III => 3)
// otherwise, substruct it (e.g IV => 4)
// assuming there is no IIV otherwise we need compare with the max digit so far
// instead of the last digit
int romainToInt(std::string s) {
  std::unordered_map<char, int> map = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
  int res = 0, len = s.size();
  for (int i = len - 1; i >= 0; --i) {
    if (i == len - 1 || map[s[i]] >= map[s[i + 1]])
      res += map[s[i]];
    else
      res -= map[s[i]];
  }

  return res;
}
