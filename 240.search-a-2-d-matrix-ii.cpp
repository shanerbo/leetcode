/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (41.59%)
 * Likes:    1923
 * Dislikes: 54
 * Total Accepted:    216.6K
 * Total Submissions: 520.1K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */

// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() < 1) {
            return false;
        } else {
            int i = matrix.size();
            int j = matrix[0].size();
            for (int i = 0; i < matrix.size(); ++i) {
                // cout << i << endl;
                int j = matrix[0].size() - 1;
                for (; j >= 0; --j) {
                    if (matrix[i].back() < target) { // the last element smaller than target no need to search this row
                        break;
                    } else { // this row may contain target;
                        if (matrix[i][j] == target) {
                            return true;
                        } else if (matrix[i][j] > target) {
                            continue;
                        } else if (matrix[i][j] < target) {
                            break;
                        }
                    }
                }
            }
            return false;
        }
    }
};
// @lc code=end
