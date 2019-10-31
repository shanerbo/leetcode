/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 *
 * https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/
 *
 * algorithms
 * Medium (51.46%)
 * Likes:    274
 * Dislikes: 102
 * Total Accepted:    33.6K
 * Total Submissions: 65.2K
 * Testcase Example:  '[2,1,2,4,2,2]\n[5,2,6,2,3,2]'
 *
 * In a row of dominoes, A[i] and B[i] represent the top and bottom halves of
 * the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on
 * each half of the tile.)
 * 
 * We may rotate the i-th domino, so that A[i] and B[i] swap values.
 * 
 * Return the minimum number of rotations so that all the values in A are the
 * same, or all the values in B are the same.
 * 
 * If it cannot be done, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
 * Output: 2
 * Explanation: 
 * The first figure represents the dominoes as given by A and B: before we do
 * any rotations.
 * If we rotate the second and fourth dominoes, we can make every value in the
 * top row equal to 2, as indicated by the second figure.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
 * Output: -1
 * Explanation: 
 * In this case, it is not possible to rotate the dominoes to make one row of
 * values equal.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A[i], B[i] <= 6
 * 2 <= A.length == B.length <= 20000
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    int minDominoRotations(vector<int> &A, vector<int> &B) {
        vector<int> a(7, 0);
        vector<int> b(7, 0);
        vector<int> same(7, 0);
        int res = INT_MAX;
        // sanity check
        if (A.size() != B.size()) {
            return -1;
        }
        if (A.size() == 0) {
            return 0;
        }
        for (int i = 0; i < A.size(); i++) {
            a[A[i]]++;
            b[B[i]]++;
            if (A[i] == B[i]) {
                same[A[i]]++;
            }
        }
        for (int i = 0; i < 7; i++) {
            if (a[i] + b[i] - same[i] == A.size()) {
                int flipA = A.size() - a[i];
                int flipB = A.size() - b[i];
                res = min(min(flipA, flipB), res);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
