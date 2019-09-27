/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (45.00%)
 * Likes:    1641
 * Dislikes: 1383
 * Total Accepted:    685.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int newX = 0, tmp = x;
        if (x < 0)
        {
            return false;
        }
        else
        {
            while (tmp)
            {
                if (newX >= INT_MAX / 10)
                {
                    return false;
                }

                newX = newX * 10 + tmp % 10;
                tmp /= 10;
            }
            return newX == x;
        }
    }
};
