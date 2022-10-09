// lt118: Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/
#include <vector>
using std::vector;

// Generates a Pascal's triangle of the given height.
// height 0: [], length 0
// height 1: [1], length 1
// height 2: [1, 1], length 2
// height 3: [1, 2, 1], lenth 3
// height 4: [1, 3, 3, 1], length 4
// height 5: [1, 4, 6, 4, 1], length 5
// height 6: [1, 5, 10, 10, 5, 1], length 6
// height n: ..................... length n
// height n+ 1: [1, sums from height n, 1], length 1 + (n - 1) + 1 = n + 1
vector<vector<int>> generate(int numRows) {
  vector<vector<int>> rows;
  if (numRows >= 1) rows.push_back({1});
  if (numRows >= 2) rows.push_back({1, 1});
  for (int i = 3; i <= numRows; ++i) {
    vector<int> row;
    for (int j = 0; j < i; ++j) {
      if (j == 0 || j == i - 1)
        // two ones at ends
        row.push_back(1);
      else
        // sum from last level
        row.push_back(rows.back()[j] + rows.back()[j - 1]);
    }
    rows.push_back(row);
  }
  return rows;
}
