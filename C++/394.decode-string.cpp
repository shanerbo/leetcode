/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (46.74%)
 * Likes:    2049
 * Dislikes: 111
 * Total Accepted:    142.2K
 * Total Submissions: 302.5K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * Examples:
 * 
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    string decodeString(string s) {
        string res;
        stack<string> words;
        if (s.length() == 0) {
            return res;
        }
        int n;
        string str;
        for (int i = 0; i < s.length();) {
            if (isdigit(s[i])) {
                string num;
                while (isdigit(s[i])) {
                    num += s[i++];
                }
                words.push(num);
            } else if (isalpha(s[i])) {
                string seq;
                while (isalpha(s[i])) {
                    seq += s[i++];
                }
                words.push(seq);
            } else {
                string t(1, s[i++]);
                words.push(t);
            }
        }
        while (words.size() > 0) {
            string top = words.top();
            words.pop();
            if (top == "]" || top == "[") {
                continue;
            } else if (isalpha(top[0])) {
                words.pop();
                auto test = words.top();
                int time;
                if (test == "]" || test == "[") {
                    time = 0;
                } else {
                    cout << test << endl;
                    time = stoi(test);
                }
                words.pop();
                string tmp;
                for (int i = 0; i < time; i++) {
                    tmp += top;
                }

                if (words.size() > 0 && words.top() != "]") {
                    string local = words.top();
                    words.pop();
                    words.push(local + tmp);
                } else {
                    res = tmp + res;
                }
            }
        }

        return res;
    }
};
// @lc code=end
