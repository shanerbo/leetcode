/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (45.36%)
 * Likes:    560
 * Dislikes: 180
 * Total Accepted:    228.3K
 * Total Submissions: 502.7K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

// @lc code=start
class Solution {

  public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return {};
        }
        if (rowIndex == 0) {
            return {1};
        }
        vector<int> ret(rowIndex + 1, 0);
        for (int i = 0; i <= rowIndex; ++i) {
            ret[i] = 1;
            for (int j = i - 1; j > 0; --j) {
                ret[j] += ret[j - 1];
            }
        }
        return ret;
    }
};
// @lc code=end
