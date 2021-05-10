/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int l = 0, r = nums1.size(), m = nums1.size(), n = nums2.size();
    if (m > n) {
      return findMedianSortedArrays(nums2, nums1);
    }
    while (l <= r) {
      int mid = (l + r) / 2;
      int mid_2 = (m + n) / 2 - mid;
      int left_max_1 = mid == 0 ? INT_MIN : nums1[mid - 1];
      int right_min_1 = mid == m ? INT_MAX : nums1[mid];

      int left_max_2 = mid_2 == 0 ? INT_MIN : nums2[mid_2 - 1];
      int right_min_2 = mid_2 == n ? INT_MAX : nums2[mid_2];
      if (left_max_1 <= right_min_2 and left_max_2 <= right_min_1) {
        if (((m + n) & 1) == 1) {
          return min(right_min_1, right_min_2);
        } else {
          return (max(left_max_2, left_max_1) + min(right_min_1, right_min_2)) /
                 2.0;
        }
      } else if (left_max_2 > right_min_1) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return 0.0;
  }
};
// @lc code=end