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
    vector<int> arr;
    int i = 0, j = 0;
    int sizeI = nums1.size(), sizeJ = nums2.size();
    while (i < sizeI && j < sizeJ) {
      if (nums1[i] < nums2[j]) {
        arr.push_back(nums1[i++]);
      } else {
        arr.push_back(nums2[j++]);
      }
    }
    while (i < sizeI) {
      arr.push_back(nums1[i++]);
    }
    while (j < sizeJ) {
      arr.push_back(nums2[j++]);
    }
    return arr.size() % 2 == 0
               ? (arr[arr.size() / 2.0] + arr[arr.size() / 2 - 1]) / 2.0
               : arr[arr.size() / 2.0];
  }
};
// @lc code=end
