/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (72.50%)
 * Likes:    1314
 * Dislikes: 72
 * Total Accepted:    73.1K
 * Total Submissions: 100.7K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 
 * A string S of lowercase letters is given.  We want to partition this string
 * into as many parts as possible so that each letter appears in at most one
 * part, and return a list of integers representing the size of these parts.
 * 
 * 
 * Example 1:
 * 
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits S into less parts.
 * 
 * 
 * 
 * Note:
 * S will have length in range [1, 500].
 * S will consist of lowercase letters ('a' to 'z') only.
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> partitionLabels(string S) {
        vector<int> map(26, 0); // it indicates the last position for each letter has beeon found
        vector<int> res;
        for (int i = 0; i < S.length(); ++i) {
            map[S[i] - 'a'] = i;
        }
        int start = 0;
        int last = 0;
        for (int j = 0; j < S.length(); ++j) {
            last = max(map[S[j] - 'a'], last);
            if (j == last) {
                res.push_back(last - start + 1);
                start = last + 1;
            }
        }
        return res;
    }
};
// @lc code=end
