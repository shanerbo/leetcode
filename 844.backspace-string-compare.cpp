/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (46.72%)
 * Likes:    883
 * Dislikes: 55
 * Total Accepted:    85.7K
 * Total Submissions: 183.2K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it in O(N) time and O(1) space?
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        if(S.empty() && T.empty()){
            return true;
        }
        string s, t;
        stack<char>ss, ts;
        for(auto const c: S){
            if(c == '#' && !ss.empty()){
                ss.pop();
            }else if(c != '#'){
                ss.push(c);
            }
            
        }
        for(auto const&c: T){
            if(c == '#' && !ts.empty()){
                ts.pop();
            }else if(c != '#'){
            ts.push(c);
            }
        }
        while(!ss.empty()){

                s+=ss.top();
                ss.pop();
            
        }
        while(!ts.empty()){
                t+=ts.top();
                ts.pop();
        }
        return s == t;
    }
};
// @lc code=end

