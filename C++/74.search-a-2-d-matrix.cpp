/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = matrix.size() - 1; i >= 0; --i) {
      if (matrix[i][0] > target) {
        continue;
      }
      for (int j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == target) {
          return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end
