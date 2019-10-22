/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (66.18%)
 * Likes:    251
 * Dislikes: 18
 * Total Accepted:    25.2K
 * Total Submissions: 38.1K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 * 
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2.  Elements that don't appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 * 
 * 
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * Constraints:
 * 
 * 
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * Each arr2[i] is distinct.
 * Each arr2[i] is in arr1.
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        vector<int> location(1001, -1);
        for (auto const &num : arr2) {
            location[num] = 0;
        }
        vector<int> res;
        for (auto const &num : arr1) {
            location[num]++;
        }
        for (auto const &num : arr2) {
            for (int i = 0; i < location[num]; i++) {
                res.push_back(num);
            }
            location[num] = -1;
        }
        for (int i = 0; i < 1001; ++i) {
            if (location[i] != -1) {
                for (int j = 0; j <= location[i]; j++) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
