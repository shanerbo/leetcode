/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.88%)
 * Likes:    6437
 * Dislikes: 376
 * Total Accepted:    1.1M
 * Total Submissions: 3.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::map<char, int> dict;
        int len = 0;
        int max = 0;
        auto start = s.begin();
        for (auto c = start; c != s.end(); ++c)
        {
            if (dict.find(*c) != dict.end())
            {
                len = 1;
                c = start++;
                dict.clear();
            }
            else
            {
                len++;
            }
            dict.insert({*c, 0});
            max = std::max(max, len);
        }
        return max;
    }
};
