/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 *
 * https://leetcode.com/problems/most-common-word/description/
 *
 * algorithms
 * Easy (42.89%)
 * Likes:    396
 * Dislikes: 996
 * Total Accepted:    88K
 * Total Submissions: 204.8K
 * Testcase Example:  '"Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]'
 *
 * Given a paragraph and a list of banned words, return the most frequent word
 * that is not in the list of banned words.  It is guaranteed there is at least
 * one word that isn't banned, and that the answer is unique.
 * 
 * Words in the list of banned words are given in lowercase, and free of
 * punctuation.  Words in the paragraph are not case sensitive.  The answer is
 * in lowercase.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * Explanation: 
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent
 * non-banned word in the paragraph. 
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"), 
 * and that "hit" isn't the answer even though it occurs more because it is
 * banned.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= paragraph.length <= 1000.
 * 0 <= banned.length <= 100.
 * 1 <= banned[i].length <= 10.
 * The answer is unique, and written in lowercase (even if its occurrences in
 * paragraph may have uppercase symbols, and even if it is a proper noun.)
 * paragraph only consists of letters, spaces, or the punctuation symbols
 * !?',;.
 * There are no hyphens or hyphenated words.
 * Words only consist of letters, never apostrophes or other punctuation
 * symbols.
 * 
 * 
 */

// @lc code=start
class Solution {
  private:
    void toLower(string &s) {
        for (auto &c : s) {
            c = tolower(c);
        }
    }

  public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        unordered_map<string, int> map;
        string res = "";
        int maxFreq = INT_MIN;
        if (paragraph.length() == 0) {
            return res;
        }
        string s = "";
        for (int i = 0; i < banned.size(); ++i) {
            toLower(banned[i]);
            map[banned[i]] = -1;
        }

        for (int i = 0; i <= paragraph.length(); ++i) {
            if (isalpha(paragraph[i]) && paragraph[i] != '\0') {
                s += paragraph[i];
            } else {
                toLower(s);
                if (map.count(s) && map[s] == -1) {
                    s = "";
                    continue;
                }
                map[s]++;
                if (maxFreq <= map[s] && s != "\0") {
                    maxFreq = map[s];
                    res = s;
                }
                s = "";
            }
        }
        return res;
    }
};
// @lc code=end
