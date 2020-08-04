/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (32.04%)
 * Likes:    979
 * Dislikes: 132
 * Total Accepted:    82.8K
 * Total Submissions: 257.5K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]] 
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]] 
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    bool isPalindrome(string s) const {
        string::iterator l = s.begin();
        string::iterator r = s.end() - 1;
        while (l <= r) {
            if (*l != *r) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

  public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> res;
        unordered_map<string, int> map;
        if (words.empty()) {
            return res;
        }
        if (words.size() < 2) {
            return res;
        }
        for (int i = 0; i < words.size(); ++i) {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            map[tmp] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            auto word = words[i];
            if (word.length() == 0) {
                for (auto const &item : map) {
                    if (isPalindrome(item.first) && item.second != i) {
                        res.push_back({i, item.second});
                    }
                }
            }
            for (int j = 0; j < word.length(); j++) {
                string str1 = word.substr(0, j);
                string str2 = word.substr(j);
                if (map.count(str1) && isPalindrome(str2) && map[str1] != i) {
                    vector<int> ans = {i, map[str1]};
                    res.emplace_back(ans);
                }
                if (map.count(str2) && isPalindrome(str1) && map[str2] != i) {
                    res.push_back({map[str2], i});
                }
            }
        }
        return res;
    }
};
// @lc code=end
