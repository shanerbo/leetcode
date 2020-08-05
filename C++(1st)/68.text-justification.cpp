/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (24.65%)
 * Likes:    449
 * Dislikes: 1199
 * Total Accepted:    110K
 * Total Submissions: 443.4K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 * 
 * Note:
 * 
 * 
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        if (maxWidth == 0) {
            return res;
        }
        if (words.size() == 0) {
            return res;
        }
        vector<string> wordCandidate;
        int size = 0;
        int stringLen = 0;
        int wordCount = 0;
        queue<string> q;
        for (auto const &word : words) {
            q.push(word);
        }
        while (q.size() > 0) {
            string top = q.front();
            // next word can be added to vector
            if (wordCandidate.size() == 0) {
                if (size + top.length() <= maxWidth) {
                    size += top.length();
                    stringLen += top.length();
                    wordCount++;
                    wordCandidate.push_back(q.front());
                    q.pop();
                }
            } else if (size + 1 + top.length() <= maxWidth) {
                size += 1 + top.length();
                stringLen += top.length();
                wordCount++;
                wordCandidate.push_back(q.front());
                q.pop();
            } else { // can't add more string, need to format string
                int spaceLeft = maxWidth - stringLen;
                int spaceBetweenWords = 0;
                string ans = "";
                int even = 0;
                for (int z = 0; z < wordCandidate.size(); ++z) {
                    string w = wordCandidate[z];
                    ans += w;
                    if (wordCount == 1) {
                        spaceBetweenWords = spaceLeft;
                    } else {
                        if (spaceLeft % (wordCount - 1) == 0) {
                            spaceBetweenWords = spaceLeft / (wordCount-- - 1);
                        } else {
                            spaceBetweenWords = (spaceLeft / (wordCount-- - 1)) + 1; // if there are 7 space left ,there are 5 word, 7/4 = 1
                        }
                        spaceLeft -= spaceBetweenWords;
                    }
                    ans.append(spaceBetweenWords, ' ');
                }

                res.push_back(ans);
                wordCandidate.clear();
                size = 0;
                stringLen = 0;
                wordCount = 0;
            }
        }
        if (wordCandidate.size() > 0) {
            string ans = "";

            for (int i = 0; i < wordCandidate.size() - 1; i++) {
                ans += wordCandidate[i] + ' ';
            }
            ans += wordCandidate[wordCandidate.size() - 1];
            if (ans.length() < maxWidth) {
                int spaceLeft = maxWidth - ans.length();
                ans.append(spaceLeft, ' ');
            }

            res.push_back(ans);
        }

        return res;
    }
};
// @lc code=end
// ["Science","is","what","we","understand","well","enough","to","explain", "to","a","computer.","Art","is","everything","else","we","do"]\n20