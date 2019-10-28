/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (31.24%)
 * Likes:    2151
 * Dislikes: 169
 * Total Accepted:    236.8K
 * Total Submissions: 755.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
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
  private:
    int maxSum = INT_MIN;
    int bst(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = max(bst(root->left), 0);
        int right = max(bst(root->right), 0);

        maxSum = max(maxSum, left + right + root->val);
        // the path is from left to root then to right;
        return max(left, right) + root->val;
        // if path need go to upper level, you have to choose one of greater path, because you can't go left->root->right then go upper level;
    }

  public:
    int maxPathSum(TreeNode *root) {
        bst(root);
        return maxSum;
    }
};
// @lc code=end
