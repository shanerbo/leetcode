/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (49.66%)
 * Likes:    2069
 * Dislikes: 132
 * Total Accepted:    407.9K
 * Total Submissions: 820.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * Note:
 *
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 *
 *
 */

// @lc code=start
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto const& substrs : strs) {
            string str = substrs;
            sort(str.begin(), str.end());
            // sort string O(nlogn)
            map[str].push_back(substrs);
        }
        vector<vector<string>> ret;
        for (auto const& [key, value] : map) {
            ret.push_back(value);
        }
        return ret;
    }
};
// @lc code=end
