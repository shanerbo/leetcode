/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (19.04%)
 * Likes:    1220
 * Dislikes: 210
 * Total Accepted:    139.1K
 * Total Submissions: 729.6K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 *
 *
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: []
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
   private:
    vector<vector<string>> ret;
    int len = INT_MAX;
    string target;
    unordered_map<string, int> map;
    void dfs(int currLen, vector<string> path, string& currWord,
             vector<string>& wordList) {
        if (currWord.compare(target) == 0) {
            if (currLen <= len) {
                len = currLen;
                ret.push_back(path);
            }
            return;
        }

        for (int i = 0; i < wordList.size(); i++) {
            if (validStr(wordList[i])) {
                if (isLadder(currWord, wordList[i])) {
                    map[currWord] = 1;
                    path.push_back(wordList[i]);
                    dfs(currLen + 1, path, wordList[i], wordList);
                    map[currWord] = 0;
                    path.pop_back();
                } else {
                    continue;
                }
            } else {
                continue;
            }
        }
    }
    bool validStr(string str) { return map[str] != 1; }
    bool isLadder(string str1, string str2) {
        int diff = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (diff > 1) {
                return false;
            }
            if (str1[i] != str2[i]) {
                diff++;
            }
        }
        return diff == 1;
    }

   public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        target = endWord;
        if (wordList.size() == 0) {
            return ret;
        }

        for (auto const& str : wordList) {
            map[str] = 0;
        }
        map[beginWord] = 0;
        vector<string> path;
        path.push_back(beginWord);
        dfs(1, path, beginWord, wordList);
        for (auto it = ret.begin(); it != ret.end();) {
            if ((*it).size() > len) {
                it = ret.erase(it);
            } else {
                it++;
            }
        }
        return ret;
    }
};
// @lc code=end
