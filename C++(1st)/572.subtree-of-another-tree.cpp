/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (42.52%)
 * Likes:    1433
 * Dislikes: 55
 * Total Accepted:    127.8K
 * Total Submissions: 300.3K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * Example 2:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
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
    bool validSubtree(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        } else {
            if (s->val == t->val) {
                if (validSubtree(s->left, t->left) && validSubtree(s->right, t->right)) {
                    return true;
                }
            }
            return false;
        }
    }

  public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!t || !s) {
            return false;
        }
        if (validSubtree(s, t)) {
            return true;
        }
        if (isSubtree(s->left, t)) {
            return true;
        }
        if (isSubtree(s->right, t)) {
            return true;
        }
        return false;
    }
};
// @lc code=end
