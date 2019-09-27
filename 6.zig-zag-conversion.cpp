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
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ret;
        int order = 0, reverse = 0;
        if (numRows == 0 || numRows == 1)
            return s;
        std::vector<std::vector<char>> matrix(numRows);
        for (int i = 0; i < s.length(); ++i)
        {
            matrix[order].push_back(s[i]);
            if (order != 0 && (order + 1 == numRows || reverse == 1))
            {
                order--;
                reverse = 1;
            }
            else
            {
                order++;
                reverse = 0;
            }
        }
        for (auto const &it : matrix)
        {
            for (auto i = it.begin(); i != it.end(); ++i)
            {
                ret += *i;
            }
        }

        return ret;
    }
};