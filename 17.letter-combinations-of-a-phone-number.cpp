/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.15%)
 * Likes:    2613
 * Dislikes: 337
 * Total Accepted:    452.7K
 * Total Submissions: 1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
class Solution {
   private:
    string word;
    void dfs(vector<string>& map, vector<string>& ret, const string& digits,
             string& word, int position) {
        if (position == digits.size()) {
            ret.push_back(word);
            return;  ////// DO NOT FORGET RETURN IN DFS
        }
        int keyNumber = digits[position] - '0';
        for (int i = 0; i < map[keyNumber].size(); ++i) {
            word.push_back(map[keyNumber][i]);
            dfs(map, ret, digits, word, position + 1);
            word.pop_back();  // need to remove last char for next iteration
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.size() > 0) {
            /* code */
            vector<string> map({"", "", "abc", "def", "ghi", "jkl", "mno",
                                "pqrs", "tuv", "wxyz"});
            dfs(map, ret, digits, word, 0);
            return ret;

        } else {
            return ret;
        }
    }
};
