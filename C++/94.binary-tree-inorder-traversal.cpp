/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (63.11%)
 * Likes:    3287
 * Dislikes: 138
 * Total Accepted:    755.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {}
};
/*
 * recursive
 */
// class Solution {
// public:
//   vector<int> inorderTraversal(TreeNode *root) {
//     vector<int> res;
//     this->helper(res, root);
//     return res;
//   }

// private:
//   void helper(vector<int> &res, TreeNode *root) {
//     if (!root) {
//       return;
//     }
//     helper(res, root->left);
//     res.push_back(root->val);
//     helper(res, root->right);
//   }
// };
// @lc code=end
