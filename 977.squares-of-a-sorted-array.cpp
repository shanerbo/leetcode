/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.82%)
 * Likes:    589
 * Dislikes: 59
 * Total Accepted:    127.4K
 * Total Submissions: 177.3K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> sortedSquares(vector<int> &A) {
        vector<int> res(A.size());
        if (A.empty()) {
            return res;
        }
        int l = 0, r = A.size() - 1;
        for (int i = A.size() - 1; i >= 0 && l <= r; --i) {
            if (abs(A[l]) >= abs(A[r])) {
                res[i] = A[l] * A[l++];
            } else {
                res[i] = A[r] * A[r--];
            }
        }
        return res;
    }
};
// @lc code=end
