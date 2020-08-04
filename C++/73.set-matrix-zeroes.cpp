/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (40.97%)
 * Likes:    1315
 * Dislikes: 228
 * Total Accepted:    240.9K
 * Total Submissions: 587.6K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output:
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output:
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 *
 *
 * Follow up:
 *
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 *
 *
 */

// @lc code=start
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        bool firstCol = false;
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) firstCol = true;
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    /*
                    -------------------         -------------------
                    |1|2|3|4|5|6|7|8|9|         |1|2|0|4|0|6|0|8|0|
                    -------------------         -------------------
                    |1|2|3|4|5|6|0|8|9|         |0|2|3|4|5|6|0|8|9|
                    -------------------  =====> -------------------
                    |1|2|3|4|0|6|7|8|0|         |0|2|3|4|0|6|7|8|0|
                    -------------------         -------------------
                    |1|2|0|4|5|6|7|8|9|         |0|2|0|4|5|6|7|8|9|
                    -------------------         -------------------
                    */
                }
            }
        }
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j > 0; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (firstCol) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end
