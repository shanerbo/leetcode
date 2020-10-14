/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (74.07%)
 * Likes:    1335
 * Dislikes: 78
 * Total Accepted:    262.5K
 * Total Submissions: 350.5K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 *
 * You may return any answer array that satisfies this condition.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 *
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
  vector<int> sortArrayByParity(vector<int> &A) {
    int left = 0, right = A.size();
    while (left < right) {
      if (A[left] % 2 == 1 && A[right] % 2 == 0) {
        swap(A[left++], A[right--]);
      } else if (A[left] % 2 == 1 && A[right] % 2 == 1) {
        swap(A[left], A[--right]);
      } else if (A[left] % 2 == 0 && A[right] % 2 == 0) {
        swap(A[++left], A[right]);
      } else {
        left++;
        right--;
      }
    }
    return A;
  }
};
// @lc code=end
