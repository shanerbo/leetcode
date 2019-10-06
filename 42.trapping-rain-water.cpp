/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (44.96%)
 * Likes:    4548
 * Dislikes: 80
 * Total Accepted:    355.9K
 * Total Submissions: 791K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 */

// @lc code=start
// approach 1
// scan from mid
class Solution {
   public:
    int trap(vector<int>& height) {
        int ret = 0;
        for (auto it = height.begin(); it != height.end(); ++it) {
            auto l = height.begin(), r = height.end() - 1;
            auto lm = *l, rm = *r;
            while (l < it) {
                lm = max(lm, *l);
                l++;
            }
            while (r > it) {
                rm = max(rm, *r);
                r--;
            }

            auto rain = (min(lm, rm) - *it) >= 0 ? (min(lm, rm) - *it) : 0;
            ret += rain;
        }
        return ret;
    }
};
// @lc code=end
