/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.30%)
 * Likes:    3136
 * Dislikes: 372
 * Total Accepted:    504.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// @lc code=start
class Solution {
  private:
    int binarySearch(int begin, int end, vector<int> &nums, int target) {
        int mid = (begin + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (begin == end) {
            return -1;
        }
        if (nums[begin] <= nums[mid]) // begin to mid is normal
        {
            if (nums[begin] <= target && target <= nums[mid]) {
                return binarySearch(begin, mid - 1, nums, target);
            } else {
                return binarySearch(mid + 1, end, nums, target);
            }
        } else {
            if (nums[mid] <= target && nums[end] >= target) {
                return binarySearch(mid + 1, end, nums, target);
            } else {
                return binarySearch(begin, mid - 1, nums, target);
            }
        }
    }

  public:
    int search(vector<int> &nums, int target) {
        if (nums.size() < 1) {
            return -1;
        }
        int i = binarySearch(0, nums.size() - 1, nums, target);
        return i;
    }
};
// @lc code=end
