/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (36.74%)
 * Likes:    2751
 * Dislikes: 147
 * Total Accepted:    393.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

// @lc code=start
// class Solution {
//   private:
//     int maxSubString = 0;
//     unordered_map<string, bool> wordDictDict;
//     unordered_map<string, bool> dp;
//     bool dfs(string s) {
//         if (dp.find(s) != dp.end()) {
//             return dp[s];
//         }
//         if (s.empty() || wordDictDict.find(s) != wordDictDict.end()) {
//             return true;
//         } else {
//             bool found = false;
//             for (int i = 1; i <= maxSubString && !found; ++i) {
//                 auto left = s.substr(0, i);
//                 if (wordDictDict.find(left) != wordDictDict.end()) {
//                     found |= dfs(s.substr(i));
//                 }
//             }
//             dp[s] = found;
//             return found;
//         }
//     }

//   public:
//     bool wordBreak(string s, vector<string> &wordDict) {
//         if (wordDict.size() < 1 || s.length() < 1) {
//             return false;
//         }
//         int len = 0;
//         for (auto &word : wordDict) {
//             len = word.length();
//             wordDictDict[word] = true;
//             maxSubString = max(len, maxSubString);
//         }

//         return dfs(s);
//     }
// };
class Solution {
  private:
    int maxSubString = 0;
    unordered_map<string, bool> wordDictDict;
    unordered_map<string, bool> dp;

    bool dfs(string s) {
        if (dp.count(s))
            return dp[s];
        if (s.empty()) {
            return true;
        } else {
            bool found = false;
            for (int i = 1; i <= maxSubString && !found; i++) {
                if (wordDictDict[s.substr(0, i)]) {
                    // cout << s.substr(0, i) << endl;
                    found |= dfs(s.substr(i));
                }
            }
            dp[s] = found;
            return found;
        }
    }

  public:
    bool wordBreak(string s, vector<string> &wordDict) {
<<<<<<< HEAD
=======
        int maxSubString = 0;
        int minSubString = INT_MAX;

        unordered_map<string, bool> wordDictDict;
        vector<bool> dp(s.length() + 1, false);
>>>>>>> 951092b99eb2bafee822978fa5386e7a1c0d4c4e
        if (wordDict.size() < 1 || s.length() < 1) {
            return false;
        }
        int len = 0;
        for (auto &word : wordDict) {
            len = word.length();
            wordDictDict[word] = true;
            maxSubString = max(len, maxSubString);
<<<<<<< HEAD
        }
        return dfs(s);
=======
            minSubString = min(minSubString, len);
        }
        dp[0] = true;
        for (int i = 0; i <= s.length(); ++i) {
            for (int j = i; j >= 0 && i - 2 * j <= maxSubString; --j) {
                if (dp[j] && wordDictDict[s.substr(j, i - j)]) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.length()];
>>>>>>> 951092b99eb2bafee822978fa5386e7a1c0d4c4e
    }
};
// @lc code=end
