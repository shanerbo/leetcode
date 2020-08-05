/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.74%)
 * Likes:    1349
 * Dislikes: 97
 * Total Accepted:    383.8K
 * Total Submissions: 839.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */
class Solution {
   public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int diff = target - (nums[0] + nums[1] + nums[2]);
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (it != nums.begin() && *(it - 1) == *it) {
                continue;
            }
            if (target <= 0 && *it > 0) {
                break;
            }
            auto l = it + 1, r = nums.end() - 1;
            while (l < r) {
                int sum = *it + *l + *r;
                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else if (sum == target) {
                    return target;
                }
                int newDiff = target - sum;
                diff = abs(newDiff) <= abs(diff) ? newDiff : diff;
            }
        }
        return target - diff;
    }
};
