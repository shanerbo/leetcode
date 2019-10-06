/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (43.42%)
 * Likes:    1225
 * Dislikes: 72
 * Total Accepted:    258.5K
 * Total Submissions: 594.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // bfs
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }
        deque<TreeNode*> toSearch;  // deque can push front or push back
        toSearch.push_back(root);
        bool left2right = true;
        vector<int> level;  // contain all int's

        while (toSearch.size() != 0) {
            for (auto const& node : toSearch) {
                level.push_back(node->val);
            }
            ret.push_back(level);  // push to ret
            level.clear();         // free all elements in level vector

            for (int i = toSearch.size() - 1; i >= 0; --i) {
                if (left2right) {
                    // if previous order is left to right, we need to reverse
                    // the order;
                    if (toSearch[i]->right) {
                        toSearch.push_back(toSearch[i]->right);
                    }
                    if (toSearch[i]->left) {
                        toSearch.push_back(toSearch[i]->left);
                    }
                    toSearch.erase(toSearch.begin() + i);
                } else {
                    if (toSearch[i]->left) {
                        toSearch.push_back(toSearch[i]->left);
                    }
                    if (toSearch[i]->right) {
                        toSearch.push_back(toSearch[i]->right);
                    }
                    toSearch.erase(toSearch.begin() + i);
                }
            }
            left2right = !left2right;
        }
        return ret;
    }
};
// @lc code=end
