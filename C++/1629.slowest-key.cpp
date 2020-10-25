/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 *
 * https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/
 *
 * algorithms
 * Medium (44.84%)
 * Likes:    169
 * Dislikes: 44
 * Total Accepted:    12.5K
 * Total Submissions: 27.2K
 * Testcase Example:  '"00110110"\n2'
 *
 * Given a binary string s and an integer k.
 *
 * Return True if every binary code of length k is a substring of s. Otherwise,
 * return False.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "00110110", k = 2
 * Output: true
 * Explanation: The binary codes of length 2 are "00", "01", "10" and "11".
 * They can be all found as substrings at indicies 0, 1, 3 and 2
 * respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "00110", k = 2
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "0110", k = 1
 * Output: true
 * Explanation: The binary codes of length 1 are "0" and "1", it is clear that
 * both exist as a substring.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "0110", k = 2
 * Output: false
 * Explanation: The binary code "00" is of length 2 and doesn't exist in the
 * array.
 *
 *
 * Example 5:
 *
 *
 * Input: s = "0000000001011100", k = 4
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^5
 * s consists of 0's and 1's only.
 * 1 <= k <= 20
 *
 *
 */
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
// @lc code=start
class Solution {
public:
  char slowestKey(vector<int> &t, string k) {
    char res;

    if (t.size() == 1)
      return k[0];
    if (t.empty())
      return res;
    int maxLen = INT_MIN;
    int startTime = 0;
    for (size_t i = 0; i < t.size(); ++i) {
      int len = t[i] - startTime;
      startTime = t[i];
      if (len >= maxLen) {
        maxLen = len;
        res = k[i];
      }
    }
    return res;
  }
};
// @lc code=end
