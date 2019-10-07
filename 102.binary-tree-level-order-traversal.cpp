/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.33%)
 * Likes:    1824
 * Dislikes: 48
 * Total Accepted:    442.1K
 * Total Submissions: 877.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        } else {
            deque<TreeNode *> nodeQueue = {root};
            vector<int> level;
            while (nodeQueue.size() != 0) {
                for (auto &node : nodeQueue) {
                    level.push_back(node->val); // assign all integer in same level
                }
                ret.push_back(level); // push into ret;
                level.clear();        // free the whole vector
                int size = nodeQueue.size();
                for (int i = 0; i < size; ++i) {
                    if (nodeQueue.front()->left) {
                        nodeQueue.push_back(nodeQueue.front()->left);
                    }
                    if (nodeQueue.front()->right) {
                        nodeQueue.push_back(nodeQueue.front()->right);
                    }
                    nodeQueue.pop_front();
                }
            }
            return ret;
        }
    }
};
// @lc code=end
