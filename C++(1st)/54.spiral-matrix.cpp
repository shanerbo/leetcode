/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (31.73%)
 * Likes:    1438
 * Dislikes: 458
 * Total Accepted:    277.2K
 * Total Submissions: 873.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;

        if (matrix.size() == 0) {
            return res;
        }
        int width = matrix[0].size();
        int height = matrix.size();
        int total = width * height;
        char direction = 'r';
        int row = 0, col = 0;
        while (total > 0) {
            switch (direction) {
            case 'r': {
                direction = 'd';
                int tmpWidth = width;
                while (tmpWidth-- > 0) {
                    res.push_back(matrix[row][col++]);
                    total--;
                }
                col--;
                row++;
                height--;
                break;
            }
            case 'd': {
                direction = 'l';
                int tmpHeight = height;
                while (tmpHeight-- > 0) {
                    res.push_back(matrix[row++][col]);
                    total--;
                }
                row--;
                col--;
                width--;
                break;
            }
            case 'l': {
                direction = 'u';
                int tempWidth = width;
                while (tempWidth-- > 0) {
                    res.push_back(matrix[row][col--]);
                    total--;
                }
                col++;
                row--;
                height--;
                break;
            }
            case 'u': {
                direction = 'r';
                int tempHeight = height;
                while (tempHeight-- > 0) {
                    res.push_back(matrix[row--][col]);
                    total--;
                }
                row++;
                col++;
                width--;
                break;
            }

            default:
                break;
            }
        }
        return res;
    }
};
// @lc code=end
