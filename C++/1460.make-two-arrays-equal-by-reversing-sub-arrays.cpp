/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Sub-arrays
 *
 * https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/description/
 *
 * algorithms
 * Easy (73.61%)
 * Likes:    241
 * Dislikes: 59
 * Total Accepted:    31.9K
 * Total Submissions: 43.9K
 * Testcase Example:  '[1,2,3,4]\n[2,4,1,3]'
 *
 * Given two integer arrays of equal length target and arr.
 *
 * In one step, you can select any non-empty sub-array of arr and reverse it.
 * You are allowed to make any number of steps.
 *
 * Return True if you can make arr equal to target, or False otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: target = [1,2,3,4], arr = [2,4,1,3]
 * Output: true
 * Explanation: You can follow the next steps to convert arr to target:
 * 1- Reverse sub-array [2,4,1], arr becomes [1,4,2,3]
 * 2- Reverse sub-array [4,2], arr becomes [1,2,4,3]
 * 3- Reverse sub-array [4,3], arr becomes [1,2,3,4]
 * There are multiple ways to convert arr to target, this is not the only way
 * to do so.
 *
 *
 * Example 2:
 *
 *
 * Input: target = [7], arr = [7]
 * Output: true
 * Explanation: arr is equal to target without any reverses.
 *
 *
 * Example 3:
 *
 *
 * Input: target = [1,12], arr = [12,1]
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: target = [3,7,9], arr = [3,7,11]
 * Output: false
 * Explanation: arr doesn't have value 9 and it can never be converted to
 * target.
 *
 *
 * Example 5:
 *
 *
 * Input: target = [1,1,1,1,1], arr = [1,1,1,1,1]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * target.length == arr.length
 * 1 <= target.length <= 1000
 * 1 <= target[i] <= 1000
 * 1 <= arr[i] <= 1000
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
  bool canBeEqual(vector<int> &T, vector<int> &A) {
    if (T.size() != A.size()) {
      return false;
    }
    unordered_map<int, int> cnt;
    unordered_map<int, int> cnt2;
    for (auto const &n : T) {
      cnt[n]++;
    }
    for (auto const &n : A) {
      cnt2[n]++;
    }

    for (auto const &n : cnt) {
      if (cnt2.find(n.first) == cnt2.end()) {
        return false;
      }
      if (n.second != cnt2[n.first]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
