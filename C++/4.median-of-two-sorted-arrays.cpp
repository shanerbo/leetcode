/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.51%)
 * Likes:    5240
 * Dislikes: 763
 * Total Accepted:    528.7K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 * Example 2:
 *
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */
#include <algorithm>
#include <bitset>
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

using namespace std;
// @lc code=start
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    int i = 0;
    int j = 0;
    int count = 0;
    int target = (nums1.size() + nums2.size());
    int prev = 0;

    while (true) {

      int n = 0;

      int x = INT_MAX;
      int y = INT_MAX;

      if (i < nums1.size())
        x = nums1[i];
      if (j < nums2.size())
        y = nums2[j];

      if (x == INT_MAX && y == INT_MAX)
        break;

      if (x < y) {
        n = x;
        i++;
      } else {
        n = y;
        j++;
      }

      if (count == target / 2) {
        if (target % 2 != 0) {
          return n;
        } else {
          return (double)(prev + n) / 2;
        }
      }
      prev = n;
      count++;
    }
    return 0;
  }
};
// @lc code=end
