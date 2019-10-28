/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (40.56%)
 * Likes:    1826
 * Dislikes: 75
 * Total Accepted:    154.4K
 * Total Submissions: 379.1K
 * Testcase Example:  '"()())()"'
 *
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 * 
 * Example 1:
 * 
 * 
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ")("
 * Output: [""]
 * 
 */

// @lc code=start
class Solution {

  private:
    bool check(string &s) {
        int count = 0;
        for (auto const &c : s) {
            if (c == '(') {
                count++;
            }
            if (c == ')' && count-- == 0) { // no '('
                return false;
            }
        }
        return count == 0;
    };

  public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, bool> visited;
        // sanity check
        if (s.length() < 0) {
            return res;
        }
        queue<string> q;
        q.push(s);
        int maxLen = 0;
        bool found = false;
        while (q.size() > 0) {
            s = q.front();
            q.pop();
            if (check(s)) {
                res.push_back(s);
                found = true;
                if (maxLen > s.length()) {
                    break;
                }
                maxLen = max(maxLen, (int)s.length());
                // this will make sure we generate smallest results
            }

            if (found) {
                continue;
            }
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '(' && s[i] != ')') {
                    continue;
                }
                string t = s.substr(0, i) + s.substr(i + 1);
                // cout << t << endl;
                if (visited.find(t) == visited.end()) {
                    // if t already tested we have to skip it
                    // use set to track it
                    visited[t] = true;
                    q.push(t);
                }
            }
        }

        return res;
    }
};
// @lc code=end
