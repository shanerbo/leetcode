/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.35%)
 * Likes:    1202
 * Dislikes: 3643
 * Total Accepted:    364K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */
class Solution {
  public:
    string convert(string s, int numRows) {
        string res;
        if (numRows < 2) {
            return s;
        }
        int totalJump = 2 * numRows - 2;
        int gap = numRows - 1;
        for (int i = 0; i < numRows; i++) {
            int loc = i;
            int firstGap = (gap - i) * 2;
            int secondGap;
            if (firstGap == totalJump) {
                secondGap = firstGap;
            } else if (firstGap == 0) {
                firstGap = totalJump;
                secondGap = totalJump;
            } else {
                secondGap = totalJump - firstGap;
            }
            res += s[loc];

            while (loc < s.length()) {
                loc += firstGap;
                if (loc < s.length()) {
                    res += s[loc];
                } else {
                    break;
                }
                loc += secondGap;

                if (loc < s.length()) {
                    res += s[loc];
                } else {
                    break;
                }
            }
        }
        return res;
    }
};