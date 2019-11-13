/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (25.75%)
 * Likes:    1884
 * Dislikes: 901
 * Total Accepted:    305.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
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
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
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
 * Output: 0
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
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        for (auto const &w : wordList) {
            dict.insert(w);
        }

        queue<string> q;
        q.push(beginWord);
        int res = 0;
        if (dict.find(endWord) == dict.end()) {
            return res;
        }
        while (q.size() > 0) {
            int size = q.size();
            res++;
            for (int k = 0; k < size; ++k) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return res;
                }
                for (int i = 0; i < word.length(); ++i) {
                    string tmpWord = word;
                    for (int j = 0; j <= 26; ++j) {
                        tmpWord[i] = j + 'a';
                        if (dict.count(tmpWord) > 0) {
                            q.push(tmpWord);
                            dict.erase(tmpWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
