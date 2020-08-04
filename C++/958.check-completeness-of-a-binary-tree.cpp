/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
 *
 * https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (49.99%)
 * Likes:    441
 * Dislikes: 9
 * Total Accepted:    30.7K
 * Total Submissions: 60.9K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a binary tree, determine if it is a complete binary tree.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [1,2,3,4,5,6]
 * Output: true
 * Explanation: Every level before the last is full (ie. levels with
 * node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are
 * as far left as possible.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [1,2,3,4,5,null,7]
 * Output: false
 * Explanation: The node with value 7 isn't as far left as possible.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The tree will have between 1 and 100 nodes.
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
    bool isCompleteTree(TreeNode *root) {
        if (!root) {
            return false;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        bool missing = false;
        while (!queue.empty()) {
            TreeNode *tmp = queue.front();
            queue.pop();
            if (tmp->left && missing) {
                return false;
            } else if (!tmp->left) {
                missing = true;
            } else {
                queue.push(tmp->left);
            }
            if (tmp->right && missing) {
                return false;
            } else if (!tmp->right) {
                missing = true;
            } else {
                queue.push(tmp->right);
            }
        }
        return true;
    }
};