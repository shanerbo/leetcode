/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  int trap(vector<int> &height) {
    int l_max = 0, r_max = 0, l = 0, r = height.size() - 1, res = 0;
    while (l < r) {
      int curr_l = height[l], curr_r = height[r];
      if (curr_l < l_max) {
        res += (l_max - curr_l);
      } else {
        l_max = curr_l;
      }
      if (curr_r < r_max) {
        res += (r_max - curr_r);
      } else {
        r_max = curr_r;
      }
      if (l_max <= r_max) {
        l++;
      } else {
        r--;
      }
    }
    return res;
  }
};
// @lc code=end
