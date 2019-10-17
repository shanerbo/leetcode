/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (35.97%)
 * Likes:    971
 * Dislikes: 55
 * Total Accepted:    131K
 * Total Submissions: 364K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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
class Solution0 {
  private:
    void dfs(TreeNode *root, TreeNode *&pre, TreeNode *&first, TreeNode *&second) {
        if (!root) {
            return;
        } else {
            dfs(root->left, pre, first, second);
            if (pre && pre->val > root->val) {
                if (!first)
                    first = pre;
                second = root;
            }
            pre = root;
            dfs(root->right, pre, first, second);
        }
    }

  public:
    void recoverTree(TreeNode *root) {
        if (!root) {
            return;
        } else {
            // inorder traversal
            TreeNode *pre = nullptr, *first = nullptr, *second = nullptr;
            dfs(root, pre, first, second);
            if (first)
                swap(first->val, second->val);
        }
    }
};
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
    vector<int> order;
    vector<TreeNode *> list;
    void inorder(TreeNode *root) {
        if (root == nullptr) {
            return;
        } else {
            inorder(root->left);
            order.push_back(root->val);
            list.push_back(root);
            inorder(root->right);
        }
    }

  public:
    void
    recoverTree(TreeNode *root) {
        inorder(root);
        sort(order.begin(), order.end());
        for (int i = 0; i < list.size(); ++i) {
            list[i]->val = order[i];
        }
    }
};
// @lc code=end
