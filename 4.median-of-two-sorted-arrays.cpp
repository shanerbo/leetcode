/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.36%)
 * Likes:    5061
 * Dislikes: 732
 * Total Accepted:    511.5K
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
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        std::vector<int> l;
        int i = 0, j = 0, k = 0;
        int l1 = nums1.size(), l2 = nums2.size();
        while (i < l1 && j < l2)
        {
            if (nums1[i] < nums2[j])
            {
                l.push_back(nums1[i++]);
            }
            else
            {
                l.push_back(nums2[j++]);
            }
        }
        while (i < l1)
        {
            l.push_back(nums1[i++]);
        }
        while (j < l2)
        {
            l.push_back(nums2[j++]);
        }
        return (l.size()) % 2 == 0 ? (l[(l.size()) / 2] + l[((l.size()) / 2) - 1]) / 2.0 : l[(l.size() / 2)];
    }
};
