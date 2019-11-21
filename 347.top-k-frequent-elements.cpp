/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (57.31%)
 * Likes:    2047
 * Dislikes: 135
 * Total Accepted:    272.5K
 * Total Submissions: 473.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        if (nums.empty() || k == 0) {
            return {};
        }
        vector<int> res;
        unordered_map<int, int> map;
        for (auto const &n : nums) {
            map[n]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto const &m : map) {
            bucket[m.second].push_back(m.first);
        }
        for (int i = bucket.size() - 1; i > 0 && k > 0; --i) {
            if (bucket[i].size() > 0) {
                for (auto const c : bucket[i]) {
                    res.push_back(c);
                    k--;
                    if (k == 0) {
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
