/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (33.44%)
 * Likes:    1106
 * Dislikes: 126
 * Total Accepted:    117.6K
 * Total Submissions: 350.7K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        int freq = nums.size() / 3;
        vector<int> res;
        if (nums.empty()) {
            return res;
        }
        // since we are trying to find numbers appear more than n/3 which means the result has at most two element
        int m1 = 0, m2 = 1, count1 = 0, count2 = 0;
        // key idea: the number of majority two number' counts substract by non-majority number will not less than 0; if less than 0, it is not majority number
        for (auto const &n : nums) {
            if (n == m1) {
                count1++;
            } else if (n == m2) {
                count2++;
            } else if (count1 == 0) { // if count is zero, which mean, m1 is not the majortiy number
                m1 = n;
                count1 = 1;
            } else if (count2 == 0) {
                m2 = n;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        // we found major two number, check if it is greater than n/3
        count1 = count2 = 0;
        for (auto const &n : nums) {
            if (n == m1) {
                count1++;
            }
            if (n == m2) {
                count2++;
            }
        }
        if (count1 > freq) {
            res.emplace_back(m1);
        }
        if (count2 > freq) {
            res.emplace_back(m2);
        }
        return res;
    }
};
// @lc code=end
