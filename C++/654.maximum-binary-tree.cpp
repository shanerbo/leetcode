/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (77.44%)
 * Likes:    1325
 * Dislikes: 175
 * Total Accepted:    104.3K
 * Total Submissions: 134.6K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 * 
 * The root is the maximum number in the array. 
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number. 
 * 
 * 
 * 
 * 
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 * 
 * 
 * Example 1:
 * 
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * Note:
 * 
 * The size of the given array will be in the range [1,1000].
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *construct(vector<int> nums, int s, int e) {
        if (s == e) {
            return new TreeNode(nums[s]);
        }
        if (s > e) {
            return nullptr;
        }
        int p = s;
        int mid = nums[s];
        for (int i = s; i <= e; i++) {
            if (nums[i] > mid) {
                p = i;
                mid = nums[i];
            }
        }
        TreeNode *root = new TreeNode(mid);
        root->left = construct(nums, s, p - 1);
        root->right = construct(nums, p + 1, e);
        return root;
    }

  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return construct(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
