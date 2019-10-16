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
  private:
    bool validString(string a, string b) {
        int i = 0, j = a.length() - 1, diff = 0;
        while (i <= j) {
            if (a[i] != b[i]) {
                diff++;
            }
            if (i != j && a[j] != b[j]) {
                diff++;
            }
            if (diff > 1) {
                return false;
            }
            i++;
            j--;
        }
        return diff == 1;
    }

  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        deque<string> toSearch; // start with beginWord
        toSearch.push_back(beginWord);
        int ret = 1;
        while (toSearch.size() > 0) {
            int size = toSearch.size();
            for (int i = 0; i < size; ++i) {
                string word = toSearch.front();
                toSearch.pop_front();
                if (word == endWord) {
                    return ret;
                } else {
                    dict.erase(word); // remove this word from dictionary
                    int wordLen = word.length();
                    string tempWord;
                    for (int j = 0; j < wordLen; ++j) {
                        tempWord = word;
                        for (char c = 'a'; c <= 'z'; c++) {
                            tempWord[j] = c;
                            // cout << tempWord << endl;
                            if (dict.find(tempWord) != dict.end()) {
                                toSearch.push_back(tempWord);
                            }
                        }
                    }
                }
            }
            ret++;
        }
        return 0;
    }
};
// @lc code=end
